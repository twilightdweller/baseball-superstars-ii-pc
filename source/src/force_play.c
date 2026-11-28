#include "force_play.h"
#include "ball_motion.h"
#include <string.h>

_Static_assert(sizeof(BS2ForcePlay) == 24, "occupied-base play layout");

int bs2_find_force_play(const uint8_t *data, size_t size, int group, unsigned order,
                        int batter, int lead_batter, const BS2AtBat *ab, BS2ForcePlay *result) {
    uint32_t count;
    if (!data || size < 8 || memcmp(data, "DPL1", 4) || !ab || !result) return -1;
    if (!ab->first_base_slot || ab->second_base_slot || ab->first_base_slot > 9 || ab->batting_slot != ab->first_base_slot%9)
        return 0;
    memcpy(&count, data+4, 4);
    if (count > (size-8)/sizeof(*result)) return -1;
    size_t table_end = 8+count*sizeof(*result);
    for (size_t i=8; i<table_end; i+=sizeof(*result)) {
        BS2ForcePlay p;
        memcpy(&p, data+i, sizeof(p));
        const BS2FlyOut *f = &p.field;
        if (f->group != group || f->order != order || f->batter != batter ||
            p.lead_batter != lead_batter || f->starting_outs != ab->play[6]) continue;
        if (f->starting_outs > 2 || !f->catch_tick || f->catch_tick >= p.throw_tick ||
            p.throw_tick >= f->out_tick || f->out_tick > f->end_tick ||
            !p.clear_first_tick || p.clear_first_tick > f->end_tick ||
            !p.provisional_tick || p.provisional_tick > f->out_tick || !p.query_count ||
            p.query_offset < table_end || p.query_offset > f->map_offset || f->map_offset >= size ||
            f->map_offset-p.query_offset != p.query_count*sizeof(BS2FieldQuery)+2*sizeof(BS2BaseRun)) return -1;
        if (f->starting_outs == 2) {
            if (p.second_tick || p.relay_tick) return -1;
        } else if (p.throw_tick >= p.second_tick || p.second_tick >= p.relay_tick ||
                   p.relay_tick >= f->out_tick || p.clear_first_tick < p.second_tick) return -1;
        *result = p;
        return 1;
    }
    return 0;
}

static int invalid_play(BS2ForceDefense *d) {
    d->invalid = 1;
    return -1;
}

int bs2_step_force_play(BS2AtBat *ab, BS2ForceDefense *d, const BS2ForcePlay *p,
                        const uint8_t *data, size_t size, unsigned until) {
    if (!ab || !d || !p || !data || d->invalid || !ab->play[0x11] || ab->play[0x1c] || ab->play[0x1f] ||
        p->field.map_offset > size || p->query_offset > p->field.map_offset ||
        p->field.map_offset-p->query_offset != p->query_count*sizeof(BS2FieldQuery)+2*sizeof(BS2BaseRun) ||
        ab->play[6] != p->field.starting_outs+d->outs_made || p->field.starting_outs > 2) return -1;
    BS2BaseRun routes[2];
    memcpy(routes, data+p->field.map_offset-sizeof(routes), sizeof(routes));
    int relay = p->second_tick != 0;
    unsigned catch_count = relay ? 3u : 2u;
    const unsigned catches[3] = {p->field.catch_tick, relay ? p->second_tick : p->field.out_tick, p->field.out_tick};
    if (d->tick == 0) {
        if (!ab->first_base_slot || ab->second_base_slot || ab->batting_slot != ab->first_base_slot%9 ||
            routes[0].speed <= 0 || routes[1].speed <= 0) return -1;
        d->lead = routes[0].runner.position;
        d->batter = routes[1].runner.position;
    }
    if (until > p->field.end_tick) until = p->field.end_tick;
    while (d->tick < until) {
        unsigned tick = ++d->tick;
        if (tick == p->provisional_tick) {
            ab->play[0xb] = 6;
            ab->play[0x1e] = 1;
        }
        while (d->next_query < p->query_count) {
            BS2FieldQuery q;
            memcpy(&q, data+p->query_offset+d->next_query*sizeof(q), sizeof(q));
            if (q.tick > tick) break;
            if (q.tick != tick || q.stage >= catch_count || q.steps != 5) return invalid_play(d);
            ++d->next_query;
            if (!bs2_field_contact(&q)) continue;
            if (q.stage != d->possessions || tick != catches[q.stage]) return invalid_play(d);
            ++d->possessions;
        }
        if (d->possessions < catch_count && tick >= catches[d->possessions]) return invalid_play(d);
        if (tick == p->second_tick || tick == p->field.out_tick) {
            int batter_out = tick == p->field.out_tick;
            BS2RunnerArrival race = routes[batter_out].runner;
            race.position = batter_out ? d->batter : d->lead;
            if (d->possessions != d->outs_made+2 || bs2_runner_at_base(&race)) return invalid_play(d);
            ++d->outs_made;
            ++ab->play[6];
            ab->play[0xb] = 13;
        }
        /* Original defender decisions precede both runners' strides. */
        if (relay) {
            if (tick < p->second_tick)
                bs2_move_runner_to_base(&d->lead, &routes[0].runner.destination, routes[0].speed);
            if (tick == p->clear_first_tick) ab->first_base_slot = 0;
        } else if (ab->first_base_slot) {
            bs2_move_runner_to_base(&d->lead, &routes[0].runner.destination, routes[0].speed);
            routes[0].runner.position = d->lead;
            int arrived = bs2_runner_at_base(&routes[0].runner);
            if (arrived != (tick == p->clear_first_tick)) return invalid_play(d);
            if (arrived) {
                ab->second_base_slot = ab->first_base_slot;
                ab->first_base_slot = 0;
            }
        }
        if (tick < p->field.out_tick) bs2_move_runner_to_base(&d->batter, &routes[1].runner.destination, routes[1].speed);
    }
    return d->tick == p->field.end_tick ? bs2_finish_field_play(ab) : 0;
}
