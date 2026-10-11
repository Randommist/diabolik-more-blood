
// ADDRESS 9ec24

void FUN_0009ec24(undefined8 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int in_t0;
  uint in_t1;
  uint in_t2;
  int in_t3;
  int *piVar2;
  int *piVar3;
  
  iVar1 = (int)((ulonglong)param_1 >> 0x20);
  piVar3 = (int *)(param_2 + param_3 * 0x170);
  piVar2 = piVar3 + 0x35;
  if (in_t3 != 0) {
    FUN_0009eb04(piVar3);
  }
  FUN_000a312c(piVar2,param_4 * 0xe4 + 0x3a5748,param_5);
  if (*piVar3 == 0) {
    piVar3[0x2b] = (int)param_1;
    piVar3[0x2a] = 0;
    piVar3[0x29] = 0;
    piVar3[0x2e] = 0x3f800000;
    piVar3[0x2d] = 0x3f800000;
    piVar3[0x2c] = 0x3f800000;
    piVar3[0x31] = 0x3f800000;
    piVar3[0x30] = 0x3f800000;
    piVar3[0x2f] = 0x3f800000;
    *piVar3 = 1;
    piVar3[0x32] = iVar1;
  }
  else {
    piVar3[0x32] = iVar1;
  }
  piVar3[0x33] = *(int *)(param_4 * 0xe4 + 0x3a573c);
  iVar1 = func_0x000a0bc4(param_5);
  piVar3[0x34] = iVar1;
  piVar3[3] = in_t1 & 0xff;
  if ((piVar3[4] & in_t2) == 0) {
    piVar3[4] = piVar3[4] | in_t2;
  }
  piVar3[5] = in_t0;
  piVar3[2] = 0;
  FUN_000a324c(piVar2,in_t1 & 0xff);
  FUN_000a32a0(piVar2,1);
  return;
}



// ADDRESS 9ed94

void FUN_0009ed94(undefined8 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_t0;
  uint in_t1;
  uint in_t2;
  int in_t3;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = func_0x0009fb5c(param_4);
  puVar4 = (undefined4 *)(param_2 + param_3 * 0x170);
  puVar4[0x34] = param_5;
  puVar3 = puVar4 + 0x35;
  if (in_t3 != 0) {
    FUN_0009eb04(puVar4);
  }
  func_0x000a0c58(puVar3,0x9c);
  if (iVar1 != 0) {
    puVar4[0x38] = iVar1;
    uVar2 = func_0x000a121c(iVar1,param_5);
    func_0x000a1588(puVar4 + 0x39,iVar1,uVar2);
  }
  *puVar4 = 1;
  puVar4[0x33] = *(undefined4 *)(param_4 * 0xe4 + 0x3a573c);
  puVar4[3] = in_t1 & 0xff;
  if ((puVar4[4] & in_t2) == 0) {
    puVar4[4] = puVar4[4] | in_t2;
  }
  puVar4[5] = in_t0;
  puVar4[2] = 0;
  puVar4[0x2a] = 0;
  puVar4[0x29] = 0;
  puVar4[0x2b] = (int)param_1;
  puVar4[0x32] = (int)((ulonglong)param_1 >> 0x20);
  puVar4[0x2e] = 0x3f800000;
  puVar4[0x2d] = 0x3f800000;
  puVar4[0x2c] = 0x3f800000;
  puVar4[0x31] = 0x3f800000;
  puVar4[0x30] = 0x3f800000;
  puVar4[0x2f] = 0x3f800000;
  FUN_000a324c(puVar3,in_t1 & 0xff);
  FUN_000a32a0(puVar3,1);
  return;
}



// ADDRESS 9fd3c

void FUN_0009fd3c(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  func_0x00015704(param_3 * 0xe4 + 0x3a571c,param_4);
  FUN_0009ec24((float)(int)*(short *)(param_1 * 4 + 0x14b394a),
               *(undefined4 *)(param_1 * 4 + 0x3a71cc),param_2,param_3,param_4);
  return;
}



// ADDRESS 9f75c

void FUN_0009f75c(int param_1,int param_2)

{
  param_1 = param_1 + param_2 * 0x170;
  if (*(int *)(param_1 + 0xe0) != 0) {
    func_0x000a3494(param_1 + 0xd4,param_1 + 0xa4,param_1 + 0xb0,param_1 + 0xbc);
  }
  return;
}



// ADDRESS 9eb04

void FUN_0009eb04(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0x3a5710;
  iVar4 = 0;
  iVar3 = 0;
  do {
    iVar4 = iVar4 + 1;
    if (param_1[0x33] == *(int *)(iVar2 + 0x2c)) {
      if (*param_1 != 1) {
        return;
      }
      uVar1 = func_0x000a31e8(param_1 + 0x35);
      func_0x0009e874(iVar3 + 0x3a5748,uVar1);
      return;
    }
    iVar3 = iVar3 + 0xe4;
    iVar2 = iVar2 + 0xe4;
  } while (iVar4 < 0x1e);
  return;
}



// ADDRESS a312c

void FUN_000a312c(undefined4 param_1,int param_2,undefined4 param_3)

{
  func_0x000a0c58(param_1,0x9c);
  if (param_2 != 0) {
    func_0x000a3180(param_1,param_2,param_3);
  }
  return;
}



// ADDRESS a324c

void FUN_000a324c(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    func_0x000a3208(param_1,1);
    return;
  }
  func_0x000a3218(param_1,1);
  return;
}



// ADDRESS a32a0

void FUN_000a32a0(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    func_0x000a3208(param_1,2);
    return;
  }
  func_0x000a3218(param_1,2);
  return;
}


