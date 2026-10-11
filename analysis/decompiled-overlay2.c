
// ADDRESS a3180

void FUN_000a3180(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xc) = param_2;
  uVar1 = func_0x000a11c4(param_2,param_3);
  func_0x000a1588(param_1 + 0x10,param_2,uVar1);
  return;
}



// ADDRESS a330c

int FUN_000a330c(float param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = *param_2;
  iVar2 = 1;
  param_1 = fVar4 + param_1;
  fVar3 = (float)func_0x000a3304();
  if (fVar3 <= 0.0) {
    iVar2 = 0;
  }
  else if (param_1 < fVar3) {
    if (0.0 <= param_1) {
      if (param_1 < fVar4) {
        fVar4 = param_1;
      }
    }
    else {
      iVar1 = func_0x000a3284(param_2);
      if (iVar1 == 0) {
        iVar2 = func_0x000a32d8(param_2);
        if (iVar2 != 0) {
          param_1 = 0.0;
        }
        iVar2 = 0;
      }
      else {
        do {
          param_1 = fVar3 + param_1;
          fVar4 = param_1;
        } while (param_1 < 0.0);
      }
    }
  }
  else {
    iVar1 = func_0x000a3284(param_2);
    if (iVar1 == 0) {
      iVar2 = func_0x000a32d8(param_2);
      if (iVar2 != 0) {
        param_1 = fVar3;
      }
      iVar2 = 0;
    }
    else {
      fVar4 = 0.0;
      do {
        param_1 = param_1 - fVar3;
      } while (fVar3 < param_1);
    }
  }
  if (iVar2 == 0) {
    *param_2 = param_1;
  }
  else {
    func_0x000a356c(param_2);
    func_0x000a36e0(fVar4,param_2,param_2 + 4);
    func_0x000a3574(param_2);
    *param_2 = param_1;
  }
  return iVar2;
}



// ADDRESS a3494

undefined4 FUN_000a3494(float *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  undefined1 auStack_a0 [128];
  
  fVar3 = *param_1;
  fVar2 = (float)func_0x000a3304();
  if (fVar3 <= fVar2) {
    uVar1 = func_0x000a31e8(param_1);
    func_0x000a2190(*param_1,auStack_a0,uVar1,param_2,param_3);
    func_0x000a356c(param_1);
    FUN_000a391c(param_1,param_1 + 4,auStack_a0);
    func_0x000a3574(param_1);
    return 1;
  }
  return 0;
}



// ADDRESS a391c

void FUN_000a391c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  float *pfVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int aiStack_140 [2];
  undefined1 auStack_138 [8];
  undefined4 uStack_130;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_110;
  float fStack_10c;
  float fStack_104;
  float fStack_100;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  undefined1 auStack_b8 [128];
  int iStack_38;
  uint uStack_34;
  
  aiStack_140[1] = 1;
  aiStack_140[0] = func_0x000a3654(*(undefined4 *)(param_3 + 8),param_1,param_2,1);
  if (aiStack_140[0] != -1) {
    func_0x000a242c(auStack_138,*(undefined4 *)(param_1 + 0xc),param_2,param_3);
    iVar1 = func_0x000a16e8(auStack_138,param_3);
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_2 + 8);
      if (iVar1 == 0) {
        iStack_38 = param_2;
        uStack_130 = func_0x000a163c(*(undefined4 *)(param_3 + 8),*(undefined4 *)(param_1 + 0xc),
                                     param_2);
        fStack_110 = fStack_110 - fStack_124 * fStack_104 * fStack_11c;
        fStack_10c = fStack_10c - fStack_120 * fStack_100 * fStack_118;
        iVar1 = func_0x000a132c(*(undefined4 *)(param_1 + 0xc),aiStack_140[0]);
        uVar9 = *(uint *)(iVar1 + 0x28);
        func_0x000a357c(param_1,param_2);
        uVar8 = 0;
        uVar6 = uVar9;
        if (uVar9 != 0) {
          do {
            uVar6 = uVar6 - 1;
            iVar2 = func_0x000a14cc(*(undefined4 *)(param_1 + 0xc),iVar1 + 0x24,uVar6);
            if ((*(uint *)(iVar2 + 0x10) & 0x100) == 0) {
              puVar5 = auStack_138;
              if (*(int *)(iVar2 + 0x14) != 0) {
                puVar5 = auStack_b8;
                uStack_34 = uVar6;
                func_0x000a23f0(puVar5,auStack_138);
                uVar7 = *(undefined4 *)(param_1 + 0xc);
                uVar3 = func_0x000a14cc(uVar7,iVar1 + 0x24,*(int *)(iVar2 + 0x14) + -1);
                func_0x000a389c(puVar5,uVar7,iVar1,uVar3);
                uVar6 = uStack_34;
              }
              FUN_000a391c(param_1,iVar2,puVar5);
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar9);
        }
        func_0x000a35c0(param_1,iStack_38);
      }
      else if (iVar1 != 5) {
        if (iVar1 == 3) {
          func_0x000a41a8(*(undefined4 *)(param_1 + 0xc),aiStack_140,auStack_138);
        }
        else if (iVar1 == 2) {
          pfVar4 = (float *)func_0x000a14ec(*(undefined4 *)(param_1 + 0xc),aiStack_140,0);
          fStack_f8 = fStack_f8 * *pfVar4;
          fStack_f4 = fStack_f4 * pfVar4[1];
          fStack_f0 = fStack_f0 * pfVar4[2];
          fStack_ec = fStack_ec * pfVar4[3];
          func_0x000a4648(0,auStack_138);
        }
        else if (iVar1 == 1) {
          func_0x000a4178(*(undefined4 *)(param_1 + 0xc),aiStack_140,auStack_138);
        }
      }
    }
  }
  return;
}



// ADDRESS 9f7a0

void FUN_0009f7a0(void)

{
  return;
}


