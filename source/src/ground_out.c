#include "ground_out.h"
#include "ball_motion.h"
#include <string.h>

typedef struct {
    uint8_t tick, reception, disabled, padding;
    BS2Point3 samples[3], bounds[2];
    int32_t radius, steps, max_speed;
} CollisionQuery;

_Static_assert(sizeof(CollisionQuery) == 76, "ground collision resource layout");
_Static_assert(sizeof(BS2GroundOut) == 20, "ground play resource layout");

typedef struct {
    BS2RunnerArrival runner;
    int32_t speed;
} FirstBaseRun;

_Static_assert(sizeof(FirstBaseRun) == 40, "first base run resource layout");

/* CBBMovable::MoveNext (0xcf264), level run to first. X/Z snap within one
   speed radius. Otherwise bb_get_distance2DHV divides by |dx| + |dz|. */
void bs2_move_runner_to_first(BS2Point3 *p, const BS2Point3 *dest, int32_t speed) {
    if (!p || !dest || speed <= 0) return;
    int32_t dx = (int32_t)((uint32_t)dest->x - (uint32_t)p->x);
    int32_t dz = (int32_t)((uint32_t)dest->z - (uint32_t)p->z);
    if (!dx && !dz) return;
    uint32_t square = (uint32_t)dx*(uint32_t)dx + (uint32_t)dz*(uint32_t)dz;
    if ((int32_t)square <= (int32_t)((uint32_t)speed*(uint32_t)speed)) {
        p->x = dest->x;
        p->z = dest->z;
        return;
    }
    int64_t distance = (dx < 0 ? -(int64_t)dx : dx) + (dz < 0 ? -(int64_t)dz : dz);
    int32_t x_step = (int32_t)((uint32_t)dx*(uint32_t)speed);
    int32_t z_step = (int32_t)((uint32_t)dz*(uint32_t)speed);
    p->x = (int32_t)((uint32_t)p->x + (uint32_t)(x_step/distance));
    p->z = (int32_t)((uint32_t)p->z + (uint32_t)(z_step/distance));
}

int bs2_runner_at_base(const BS2RunnerArrival *runner) {
    if (!runner) return 0;
    const BS2Point3 *p = &runner->position, *d = &runner->destination;
    /* CBBMovable::IsArrive first checks all three destination coordinates.
       CCLRunnerAIMain::IsArrive then compares only the base's X and Z. */
    return p->x == d->x && p->y == d->y && p->z == d->z &&
           p->x == runner->base.x && p->z == runner->base.z;
}

int bs2_find_ground_out(const uint8_t *data, size_t size, int group, unsigned order,
                        int batter, unsigned outs, BS2GroundOut *result) {
    uint32_t count;
    if (!result || !data || size < 8 || memcmp(data, "GRO3", 4)) return -1;
    memcpy(&count, data+4, sizeof(count));
    if (count > (size-8)/sizeof(*result)) return -1;
    size_t table_end = 8+count*sizeof(*result);
    for (size_t offset=8; offset<table_end; offset+=sizeof(*result)) {
        BS2GroundOut play;
        memcpy(&play, data+offset, sizeof(play));
        const BS2FlyOut *f = &play.field;
        if (f->group != group || f->order != order || f->batter != batter || f->starting_outs != outs)
            continue;
        if (group < 3 || group > 5 || outs >= 3 || f->fielder >= 9 ||
            !play.provisional_tick || play.provisional_tick > f->out_tick || !f->catch_tick ||
            f->catch_tick >= play.throw_tick || play.throw_tick >= f->out_tick ||
            f->out_tick > f->end_tick || !play.query_count || play.query_offset < table_end ||
            f->map_offset >= size || play.query_offset > f->map_offset ||
            play.query_count*sizeof(CollisionQuery)+sizeof(FirstBaseRun) != f->map_offset-play.query_offset) return -1;
        *result = play;
        return 1;
    }
    return 0;
}

int bs2_step_ground_out(BS2AtBat *ab, BS2GroundDefense *defense, const BS2GroundOut *ground,
                        const uint8_t *data, size_t size, unsigned tick) {
    if (!ab || !defense || !ground || !data || ab->batting_slot >= 9 ||
        !ab->play[0x11] || ab->play[0x1c] || ab->play[0x1f] ||
        ground->query_offset > size || ground->query_count > (size-ground->query_offset)/sizeof(CollisionQuery))
        return -1;
    const BS2FlyOut *field = &ground->field;
    uint8_t *p = ab->play;
    if (field->starting_outs >= 3 || p[6] != field->starting_outs + (p[0xb] == 13)) return -1;

    size_t run_offset = ground->query_offset+ground->query_count*sizeof(CollisionQuery);
    FirstBaseRun run;
    if (size-run_offset < sizeof(run) || !field->out_tick) return -1;
    memcpy(&run, data+run_offset, sizeof(run));
    if (run.speed <= 0 || run.runner.position.y || run.runner.destination.y) return -1;
    if (!defense->runner_ticks) defense->runner_position = run.runner.position;
    /* Defender AI tests possession before this frame's runner update. A retired
       runner receives a new destination later in the same original frame. */
    unsigned run_until = tick < field->out_tick ? tick : field->out_tick-1u;
    while (defense->runner_ticks < run_until) {
        bs2_move_runner_to_first(&defense->runner_position, &run.runner.destination, run.speed);
        ++defense->runner_ticks;
    }

    while (defense->next_query < ground->query_count) {
        CollisionQuery q;
        memcpy(&q, data+ground->query_offset+defense->next_query*sizeof(q), sizeof(q));
        if (q.tick > tick) break;
        if (q.steps != 5 || q.reception > 1 || !q.tick) return -1;
        BS2Flight flight = {(const uint8_t *)q.samples, 3, 0};
        BS2MovingBall ball = {&flight, 1, 0, q.disabled, {0}};
        if (bs2_ball_collision(&ball, q.bounds, q.radius, q.steps, q.max_speed, NULL) >= 0) {
            if (q.reception && defense->pickup_tick) defense->received_tick = q.tick;
            if (!q.reception) defense->pickup_tick = q.tick;
        }
        ++defense->next_query;
    }
    if ((tick >= field->catch_tick && defense->pickup_tick != field->catch_tick) ||
        (tick >= field->out_tick && defense->received_tick != field->out_tick)) return -1;
    if (tick >= ground->provisional_tick && p[0xb] == 0) {
        p[0x1e] = 1;
        p[0xb] = 6;
    }
    if (tick < field->out_tick) return 0;
    if (p[0xb] != 13) {
        run.runner.position = defense->runner_position;
        if (bs2_runner_at_base(&run.runner)) return -1;
        p[0xb] = 13; /* CheckRunnerSafeOrOut -> JudgeOut for the batter-runner at first. */
        ++p[6];
    }
    return tick < field->end_tick ? 0 : bs2_finish_field_out(ab);
}
