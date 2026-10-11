
// ADDRESS a4648

void FUN_000a4648(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  float fStack_b0;
  float fStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined1 auStack_98 [8];
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  float afStack_78 [2];
  float fStack_70;
  undefined2 uStack_68;
  undefined2 uStack_66;
  undefined2 uStack_64;
  undefined2 uStack_62;
  undefined2 uStack_60;
  undefined1 auStack_5c [4];
  int iStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  
  uStack_b8 = *(undefined4 *)(param_2 + 0x28);
  fStack_b0 = *(float *)(param_2 + 0x14) * *(float *)(param_2 + 0x34);
  uStack_b4 = *(undefined4 *)(param_2 + 0x2c);
  fStack_ac = *(float *)(param_2 + 0x18) * *(float *)(param_2 + 0x38);
  uStack_a8 = 0;
  uStack_a4 = 0;
  uStack_a0 = 0x3f800000;
  uStack_9c = 0x3f800000;
  if ((fStack_b0 != 0.0) && (fStack_ac != 0.0)) {
    if (*(int *)(param_2 + 0xc) == 0) {
      if (*(float *)(param_2 + 0x4c) <= 0.0) {
        return;
      }
      fVar3 = *(float *)(param_2 + 4);
    }
    else {
      fVar3 = *(float *)(param_2 + 4);
    }
    uStack_c0 = *(undefined4 *)(param_2 + 0x1c);
    fStack_b0 = fStack_b0 * fVar3;
    uStack_bc = *(undefined4 *)(param_2 + 0x20);
    func_0x000a2c18(*(undefined4 *)(param_2 + 0x24),auStack_98,&uStack_b8,param_2 + 0x50,&uStack_c0)
    ;
    iVar1 = func_0x000a2e40(param_2 + 0x60,auStack_98);
    if (iVar1 != 0) {
      func_0x000a2d8c(afStack_78,&uStack_a8,param_2 + 0x50);
      uStack_68 = 0;
      uStack_66 = 3;
      uStack_64 = 4;
      uStack_62 = 5;
      uStack_60 = 6;
      iVar1 = func_0x0002abc0(2,*param_1);
      if (iVar1 == 1) {
        uStack_40 = uStack_90;
        uStack_44 = uStack_8c;
        uStack_50 = uStack_88;
        uStack_54 = uStack_84;
        fVar3 = *(float *)(param_2 + 0x14);
        uStack_48 = uStack_80;
        uStack_4c = uStack_7c;
        uVar2 = func_0x000a0c78(param_2 + 0x40);
        func_0x0002a050(2,&iStack_58,auStack_5c);
        func_0x00043d8c(afStack_78[0] * fVar3,fStack_70 * fVar3,2,
                        (int)*(short *)(iStack_58 + *param_1 * 0x24 + 0x1e),
                        (int)(short)(int)*(float *)(param_2 + 0x10),(char)((uint)uVar2 >> 0x18),
                        uStack_48,uStack_4c,uStack_50,uStack_54,(ushort)((uint)uVar2 >> 8) & 0xff,
                        (ushort)uVar2 & 0xff,0);
      }
    }
  }
  return;
}



// ADDRESS a1838

void FUN_000a1838(float param_1,uint *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  
  iVar1 = func_0x0014746c(param_3,param_4);
  pfVar3 = (float *)(param_3 + iVar1 * 0x24);
  if ((iVar1 == 0) || (*(float *)(param_3 + iVar1 * 0x24) <= param_1)) {
    *param_2 = 2;
    param_2[4] = (uint)pfVar3;
  }
  else {
    pfVar4 = (float *)(param_3 + (iVar1 + -1) * 0x24);
    param_2[5] = (uint)pfVar3;
    param_2[4] = (uint)pfVar4;
    fVar5 = *pfVar3;
    fVar6 = *pfVar4;
    param_2[3] = (uint)(fVar5 - fVar6);
    param_2[2] = (uint)((param_1 - *pfVar4) / (fVar5 - fVar6));
    fVar5 = pfVar4[1];
    if ((((uint)fVar5 & 0x80000000) != 0) || ((float)param_2[2] <= 0.0)) {
      *param_2 = 2;
    }
    else {
      if (((uint)fVar5 >> 4 & 0xf) == 1) {
        param_2[1] = 1;
        fVar5 = pfVar4[1];
      }
      else if (((uint)pfVar3[1] & 0xf) == 1) {
        param_2[1] = 1;
        fVar5 = pfVar4[1];
      }
      uVar2 = 1;
      if (((uint)fVar5 >> 0xc & 0xf) != 1) {
        uVar2 = (uint)(((uint)pfVar3[1] >> 8 & 0xf) == 1);
      }
      *param_2 = uVar2;
    }
  }
  return;
}



// ADDRESS 147b44

void FUN_00147b44(float *param_1,int *param_2,undefined4 param_3,code *param_4)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined1 *puVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined1 auStack_a0 [24];
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  float afStack_70 [6];
  undefined1 auStack_58 [36];
  
  puVar8 = auStack_a0;
  iStack_88 = *param_2;
  iStack_80 = param_2[2];
  iStack_84 = param_2[1];
  iStack_7c = param_2[3];
  iStack_78 = param_2[4];
  iStack_74 = param_2[5];
  pfVar2 = (float *)(*param_4)(param_3,*(undefined4 *)(iStack_78 + 8));
  if (iStack_88 == 2) {
    uVar7 = 0;
    do {
      uVar7 = uVar7 + 1;
      *param_1 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      param_1 = param_1 + 1;
    } while (uVar7 < 3);
  }
  else {
    fVar9 = (float)func_0x000a1994(&iStack_88,param_3);
    pfVar3 = (float *)(*param_4)(param_3,*(undefined4 *)(iStack_74 + 8));
    if (iStack_88 == 0) {
      uVar7 = 0;
      do {
        fVar10 = *pfVar2;
        fVar11 = *pfVar3;
        uVar7 = uVar7 + 1;
        pfVar2 = pfVar2 + 1;
        pfVar3 = pfVar3 + 1;
        *param_1 = fVar10 + (fVar11 - fVar10) * fVar9;
        param_1 = param_1 + 1;
      } while (uVar7 < 3);
    }
    else {
      afStack_70[0] = *pfVar2;
      afStack_70[1] = pfVar2[1];
      afStack_70[2] = pfVar2[2];
      afStack_70[3] = *pfVar3;
      afStack_70[4] = pfVar3[1];
      afStack_70[5] = pfVar3[2];
      if ((*(uint *)(iStack_78 + 4) >> 0xc & 0xf) == 1) {
        pfVar4 = (float *)(*param_4)(param_3,*(undefined4 *)(iStack_78 + 0x1c));
        afStack_70[0] = afStack_70[0] + *pfVar4;
        afStack_70[1] = afStack_70[1] + pfVar4[1];
        afStack_70[2] = afStack_70[2] + pfVar4[2];
      }
      if ((*(uint *)(iStack_74 + 4) >> 8 & 0xf) == 1) {
        pfVar4 = (float *)(*param_4)(param_3,*(undefined4 *)(iStack_74 + 0x18));
        afStack_70[3] = afStack_70[3] + *pfVar4;
        afStack_70[4] = afStack_70[4] + pfVar4[1];
        afStack_70[5] = afStack_70[5] + pfVar4[2];
      }
      uVar7 = *(uint *)(iStack_78 + 4) >> 0x10 & 0xff;
      if (uVar7 == 0) {
        iVar5 = func_0x000a28e4(auStack_58,8,3,pfVar2);
        if (iVar5 != 0) {
          fVar9 = (float)func_0x000a26c8(fVar9,auStack_58,8);
        }
      }
      else {
        uVar6 = func_0x000a1400(param_3,*(undefined4 *)(iStack_78 + 0x20));
        fVar9 = (float)func_0x000a26c8(fVar9,uVar6,uVar7);
      }
      fVar10 = 1.0 - fVar9;
      uVar7 = 0;
      do {
        pfVar4 = (float *)(puVar8 + 0x30);
        fVar11 = *pfVar2;
        pfVar1 = (float *)(puVar8 + 0x3c);
        fVar12 = *pfVar3;
        uVar7 = uVar7 + 1;
        pfVar2 = pfVar2 + 1;
        puVar8 = puVar8 + 4;
        pfVar3 = pfVar3 + 1;
        *param_1 = fVar11 * fVar10 * fVar10 * fVar10 + *pfVar4 * 3.0 * fVar9 * fVar10 * fVar10 +
                   *pfVar1 * 3.0 * fVar9 * fVar9 * fVar10 + fVar12 * fVar9 * fVar9 * fVar9;
        param_1 = param_1 + 1;
      } while (uVar7 < 3);
    }
  }
  return;
}



// ADDRESS a3fc0

int FUN_000a3fc0(undefined4 param_1,undefined4 param_2,float *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  
  puVar1 = (uint *)func_0x000a3f70();
  uVar2 = *puVar1;
  if (uVar2 != 0) {
    fVar4 = param_3[2] * *param_3;
    if (2.1474836e+09 <= fVar4) {
      uVar3 = (int)(fVar4 - 2.1474836e+09) + 0x80000000;
    }
    else {
      uVar3 = (uint)fVar4;
    }
    if (uVar2 <= uVar3) {
      uVar3 = uVar2 - 1;
    }
    return puVar1[1] + uVar3 * 4;
  }
  return 0;
}


