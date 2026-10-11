
// ADDRESS a11c4

void FUN_000a11c4(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = func_0x000a0bc4(param_2);
    func_0x000a121c(param_1,uVar1);
    return;
  }
  FUN_000a132c(param_1,0);
  return;
}



// ADDRESS a1588

void FUN_000a1588(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  func_0x000a0c58(param_1,0x70);
  uVar1 = param_3[1];
  *param_1 = *param_3;
  param_1[1] = uVar1;
  param_1[2] = 0;
  uVar1 = func_0x000a1290(param_2,param_3);
  param_1[3] = uVar1;
  param_1[4] = 3;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = param_3[5];
  param_1[9] = param_3[6];
  param_1[10] = param_3[7];
  uVar1 = param_3[8];
  param_1[0xc] = 0;
  param_1[0xb] = uVar1;
  param_1[0xd] = 0x42c80000;
  return;
}



// ADDRESS a132c

int FUN_000a132c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4) + param_2 * 0x2c;
  if (iVar1 == 0) {
    func_0x000028a4(0x153ab0);
  }
  return iVar1;
}



// ADDRESS a14cc

void FUN_000a14cc(undefined4 param_1,int *param_2,int param_3)

{
  func_0x000a1378(param_1,*param_2 + param_3);
  return;
}



// ADDRESS a242c

void FUN_000a242c(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uStack_30;
  
  func_0x000a23f0(param_1,param_4);
  uVar1 = func_0x000a1630(*(undefined4 *)(param_4 + 8),param_2,param_3);
  *(undefined4 *)(param_1 + 8) = uVar1;
  if (*(int *)(param_1 + 0xc) == 0) {
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_3 + 0x18);
  }
  *(float *)(param_1 + 0x14) = (float)*(int *)(param_3 + 0x20);
  *(float *)(param_1 + 0x18) = (float)*(int *)(param_3 + 0x24);
  if (*(int *)(param_3 + 0x44) != 0) {
    uStack_30 = 0x3f800000;
    func_0x000a1d5c(*(undefined4 *)(param_1 + 8),param_1 + 0x1c,param_2,param_3 + 0x40);
    func_0x000a1d5c(*(undefined4 *)(param_1 + 8),param_1 + 0x28,param_2,param_3 + 0x48);
    func_0x000a1d5c(*(undefined4 *)(param_1 + 8),param_1 + 0x34,param_2,param_3 + 0x50);
    func_0x000a1bb4(*(undefined4 *)(param_1 + 8),param_1 + 0x24,param_2,param_3 + 0x58);
    func_0x000a1bb4(*(undefined4 *)(param_1 + 8),&uStack_30,param_2,param_3 + 0x60);
    *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) / *(float *)(param_1 + 0x14);
    *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x20) / *(float *)(param_1 + 0x18);
    func_0x000a2048(param_1,param_2,param_3 + 0x68);
    *(undefined4 *)(param_1 + 0x4c) = uStack_30;
    fVar6 = *(float *)(param_1 + 0x28) * *(float *)(param_4 + 0x34);
    *(float *)(param_1 + 0x28) = fVar6;
    fVar5 = *(float *)(param_1 + 0x2c) * *(float *)(param_4 + 0x38);
    *(float *)(param_1 + 0x2c) = fVar5;
    if (*(float *)(param_4 + 0x24) == 0.0) {
      fVar3 = *(float *)(param_4 + 0x28);
    }
    else {
      fVar7 = *(float *)(param_4 + 0x1c) * *(float *)(param_4 + 0x14) * *(float *)(param_4 + 0x34);
      fVar8 = *(float *)(param_4 + 0x20) * *(float *)(param_4 + 0x18) * *(float *)(param_4 + 0x38);
      fVar6 = fVar6 - fVar7;
      fVar5 = fVar5 - fVar8;
      fVar3 = (float)func_0x000c8ae0();
      fVar2 = (float)func_0x000c8c08(*(undefined4 *)(param_4 + 0x24));
      fVar4 = fVar3 * fVar6 - fVar2 * fVar5;
      fVar5 = fVar2 * fVar6 + fVar3 * fVar5;
      *(float *)(param_1 + 0x28) = fVar4;
      fVar6 = fVar4 + fVar7;
      *(float *)(param_1 + 0x2c) = fVar5;
      fVar5 = fVar5 + fVar8;
      *(float *)(param_1 + 0x28) = fVar6;
      *(float *)(param_1 + 0x2c) = fVar5;
      fVar3 = *(float *)(param_4 + 0x28);
    }
    *(float *)(param_1 + 0x28) = fVar6 + fVar3;
    *(float *)(param_1 + 0x2c) = fVar5 + *(float *)(param_4 + 0x2c);
    *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0x24) + *(float *)(param_4 + 0x24);
    *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) * *(float *)(param_4 + 0x34);
    *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x38) * *(float *)(param_4 + 0x38);
    *(float *)(param_1 + 0x40) = *(float *)(param_1 + 0x40) * *(float *)(param_4 + 0x40);
    *(float *)(param_1 + 0x44) = *(float *)(param_1 + 0x44) * *(float *)(param_4 + 0x44);
    *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0x48) * *(float *)(param_4 + 0x48);
    *(float *)(param_1 + 0x4c) = *(float *)(param_1 + 0x4c) * *(float *)(param_4 + 0x4c);
  }
  return;
}



// ADDRESS a16e8

undefined4 FUN_000a16e8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = func_0x000a22e4();
  if ((iVar1 != 0) && (iVar1 = func_0x000a2e40(param_1 + 0x60,param_2 + 0x60), iVar1 != 0)) {
    return 1;
  }
  return 0;
}



// ADDRESS a163c

float FUN_000a163c(float param_1,undefined4 param_2,int param_3)

{
  float fVar1;
  float fStack_10;
  
  fVar1 = *(float *)(param_3 + 0x34);
  if (0.0 <= fVar1) {
    fStack_10 = param_1 - *(float *)(param_3 + 0x30);
  }
  else {
    fStack_10 = param_1 + *(float *)(param_3 + 0x30);
  }
  if (*(int *)(param_3 + 0x3c) == 0) {
    if ((fVar1 != 100.0) && (fVar1 != 0.0)) {
      fStack_10 = fStack_10 * (100.0 / fVar1);
    }
    return fStack_10;
  }
  func_0x000a1bb4(fStack_10,&fStack_10,param_2,param_3 + 0x38);
  return fStack_10;
}



// ADDRESS a2190

void FUN_000a2190(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  int iVar1;
  undefined4 *in_t0;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  param_2[3] = 0;
  *param_2 = *(undefined4 *)(param_3 + 0xc);
  param_2[1] = 1.0 / *(float *)(param_3 + 0x10);
  param_2[5] = (float)*(int *)(param_3 + 0x14);
  iVar1 = *(int *)(param_3 + 0x18);
  param_2[2] = param_1;
  param_2[4] = 0;
  param_2[9] = 0;
  param_2[8] = 0;
  param_2[7] = 0;
  param_2[6] = (float)iVar1;
  param_2[0xc] = 0;
  param_2[0xb] = 0;
  param_2[10] = 0;
  param_2[0xf] = 0x3f800000;
  param_2[0xe] = 0x3f800000;
  param_2[0xd] = 0x3f800000;
  param_2[0x13] = 0x3f800000;
  param_2[0x12] = 0x3f800000;
  param_2[0x11] = 0x3f800000;
  param_2[0x10] = 0x3f800000;
  param_2[0x15] = 0;
  param_2[0x14] = 0;
  param_2[0x17] = 0x3f800000;
  param_2[0x16] = 0x3f800000;
  if (param_4 != (undefined4 *)0x0) {
    uVar2 = param_4[1];
    uVar3 = param_4[2];
    param_2[10] = *param_4;
    param_2[0xb] = uVar2;
    param_2[0xc] = uVar3;
    param_2[4] = param_4[2];
  }
  if (param_5 != (undefined4 *)0x0) {
    uVar2 = param_5[1];
    uVar3 = param_5[2];
    param_2[0xd] = *param_5;
    param_2[0xe] = uVar2;
    param_2[0xf] = uVar3;
  }
  if (in_t0 != (undefined4 *)0x0) {
    uVar2 = in_t0[1];
    uVar3 = in_t0[2];
    uVar4 = in_t0[3];
    param_2[0x10] = *in_t0;
    param_2[0x11] = uVar2;
    param_2[0x12] = uVar3;
    param_2[0x13] = uVar4;
  }
  func_0x000a22e4();
  return;
}



// ADDRESS a389c

void FUN_000a389c(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (*(int *)(param_4 + 0x14) != 0) {
    uVar1 = FUN_000a14cc(param_2,param_3 + 0x24,*(int *)(param_4 + 0x14) + -1);
    FUN_000a389c(param_1,param_2,param_3,uVar1);
  }
  func_0x000a174c(param_1,param_2,param_4);
  return;
}


