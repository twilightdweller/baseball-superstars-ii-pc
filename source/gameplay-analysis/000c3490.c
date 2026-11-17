/* CCLProjection::operator=; research only, not buildable source */

/* CCLProjection::TEMPNAMEPLACEHOLDERVALUE(CCLProjection const&) */

CCLProjection * __thiscall CCLProjection::operator=(CCLProjection *this,CCLProjection *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (this != param_1) {
    memcpy(this + 4,param_1 + 4,0x40);
    memcpy(this + 0x44,param_1 + 0x44,0x40);
    memcpy(this + 0x84,param_1 + 0x84,0x40);
    uVar1 = *(undefined4 *)(param_1 + 200);
    uVar2 = *(undefined4 *)(param_1 + 0xcc);
    *(undefined4 *)(this + 0xc4) = *(undefined4 *)(param_1 + 0xc4);
    *(undefined4 *)(this + 200) = uVar1;
    *(undefined4 *)(this + 0xcc) = uVar2;
    uVar1 = *(undefined4 *)(param_1 + 0xd4);
    uVar2 = *(undefined4 *)(param_1 + 0xd8);
    *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
    *(undefined4 *)(this + 0xd4) = uVar1;
    *(undefined4 *)(this + 0xd8) = uVar2;
    uVar1 = *(undefined4 *)(param_1 + 0xe0);
    uVar2 = *(undefined4 *)(param_1 + 0xe4);
    *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
    *(undefined4 *)(this + 0xe0) = uVar1;
    *(undefined4 *)(this + 0xe4) = uVar2;
    uVar1 = *(undefined4 *)(param_1 + 0xec);
    uVar2 = *(undefined4 *)(param_1 + 0xf0);
    *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
    *(undefined4 *)(this + 0xec) = uVar1;
    *(undefined4 *)(this + 0xf0) = uVar2;
    uVar1 = *(undefined4 *)(param_1 + 0xf8);
    uVar2 = *(undefined4 *)(param_1 + 0xfc);
    *(undefined4 *)(this + 0xf4) = *(undefined4 *)(param_1 + 0xf4);
    *(undefined4 *)(this + 0xf8) = uVar1;
    *(undefined4 *)(this + 0xfc) = uVar2;
  }
  return this;
}


