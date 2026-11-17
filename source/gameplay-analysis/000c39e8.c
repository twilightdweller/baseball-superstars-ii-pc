/* CCLProjection::glOrtho; research only, not buildable source */

/* CCLProjection::glOrtho(long, long, long, long, long, long) */

void __thiscall
CCLProjection::glOrtho
          (CCLProjection *this,long param_1,long param_2,long param_3,long param_4,long param_5,
          long param_6)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xe4) = 0;
  *(long *)(this + 0xe8) = param_5;
  *(long *)(this + 0xec) = param_6;
  *(long *)(this + 0xf0) = param_1;
  *(long *)(this + 0xf4) = param_2;
  *(long *)(this + 0xfc) = param_4;
  *(long *)(this + 0xf8) = param_3;
  iVar1 = DAT_000c3b00;
  *(undefined4 *)(this + 0xdc) = 1;
  puVar4 = *(uint **)(iVar1 + 0xc3a38 + DAT_000c3b04);
  uVar3 = param_2 - param_1;
  *puVar4 = -(param_2 + param_1);
  puVar4[2] = param_3 - param_4;
  puVar4[3] = -(param_3 + param_4);
  puVar4[1] = uVar3;
  puVar4[4] = param_6 - param_5;
  puVar4[5] = -(param_6 + param_5);
  uVar2 = __aeabi_ldivmod(DAT_000c3af0,DAT_000c3af4,uVar3,(int)uVar3 >> 0x1f);
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x44) = uVar2;
  uVar3 = *puVar4;
  uVar2 = __aeabi_ldivmod(uVar3 << 0x12,((int)uVar3 >> 0x1f) << 0x12 | uVar3 >> 0xe,puVar4[1],
                          (int)puVar4[1] >> 0x1f);
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x50) = uVar2;
  uVar2 = __aeabi_ldivmod(DAT_000c3af0,DAT_000c3af4,puVar4[2],(int)puVar4[2] >> 0x1f);
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x58) = uVar2;
  uVar3 = puVar4[3];
  uVar2 = __aeabi_ldivmod(uVar3 << 0x12,((int)uVar3 >> 0x1f) << 0x12 | uVar3 >> 0xe,puVar4[2],
                          (int)puVar4[2] >> 0x1f);
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x60) = uVar2;
  *(undefined4 *)(this + 0x68) = 0;
  uVar2 = __aeabi_ldivmod(DAT_000c3af8,DAT_000c3afc,puVar4[4],(int)puVar4[4] >> 0x1f);
  *(undefined4 *)(this + 0x6c) = uVar2;
  uVar3 = puVar4[5];
  uVar2 = __aeabi_ldivmod(uVar3 << 0x12,((int)uVar3 >> 0x1f) << 0x12 | uVar3 >> 0xe,puVar4[4],
                          (int)puVar4[4] >> 0x1f);
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x70) = uVar2;
  *(undefined4 *)(this + 0x80) = 0x40000;
  return;
}


