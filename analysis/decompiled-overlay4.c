
// ADDRESS a1290

uint FUN_000a1290(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = func_0x000a126c();
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      iVar2 = FUN_000a132c(param_1,uVar3);
      if (param_2 == iVar2) {
        return uVar3;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 0xffffffff;
}



// ADDRESS a1378

int FUN_000a1378(int param_1,int param_2)

{
  return *(int *)(param_1 + 0xc) + param_2 * 0x70;
}



// ADDRESS a1d5c

undefined4 FUN_000a1d5c(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  
  uStack_30 = 2;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  iStack_20 = 0;
  uStack_1c = 0;
  if (*(int *)(param_4 + 4) != 0) {
    uVar1 = func_0x000a150c(param_3,param_4,0);
    func_0x000a1838(param_1,&uStack_30,uVar1,*(undefined4 *)(param_4 + 4));
  }
  if (iStack_20 != 0) {
    func_0x00147b44(param_2,&uStack_30,param_3,0xa1414);
    return 1;
  }
  return 0;
}



// ADDRESS a1bb4

undefined4 FUN_000a1bb4(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  
  uStack_30 = 2;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  iStack_20 = 0;
  uStack_1c = 0;
  if (*(int *)(param_4 + 4) != 0) {
    uVar1 = func_0x000a150c(param_3,param_4,0);
    func_0x000a1838(param_1,&uStack_30,uVar1,*(undefined4 *)(param_4 + 4));
  }
  if (iStack_20 != 0) {
    func_0x00147520(param_2,&uStack_30,param_3,&SUB_000a1400);
    return 1;
  }
  return 0;
}



// ADDRESS a11c4

void FUN_000a11c4(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = func_0x000a0bc4(param_2);
    FUN_000a121c(param_1,uVar1);
    return;
  }
  FUN_000a132c(param_1,0);
  return;
}



// ADDRESS a121c

undefined4 FUN_000a121c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_0x000a1100();
  if (iVar1 != -1) {
    uVar2 = FUN_000a132c(param_1,iVar1);
    return uVar2;
  }
  return 0;
}


