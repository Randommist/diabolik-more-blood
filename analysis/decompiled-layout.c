
// ADDRESS 5b4b4

undefined4 FUN_0005b4b4(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  int iStack_88;
  int iStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  undefined4 uStack_68;
  uint uStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  float fStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [4];
  
  if (param_1 == (int *)0x0) {
    return 0xffffffff;
  }
  iVar1 = func_0x0005a7a0(param_1);
  if (iVar1 != 1) {
    return 0xffffffff;
  }
  param_1[1] = 0;
  param_1[0x11] = 0;
  if (*(int *)param_1[3] == 0) {
    return 0xffffffff;
  }
  iStack_24 = 0;
  uStack_a0 = param_2;
  func_0x0005b258(0,(int *)param_1[3],&uStack_a0,&iStack_24);
  if (iStack_24 < 1) {
    return 1;
  }
  iVar1 = func_0x00051d14(iStack_24 * 0x34,1,0,0x14c348);
  *param_1 = iVar1;
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  func_0x00138210(iVar1,0,iStack_24 * 0x34);
  iStack_88 = *param_1;
  uStack_64 = param_1[4];
  iStack_60 = param_1[5];
  iStack_5c = param_1[6];
  iStack_58 = param_1[7];
  iStack_54 = param_1[8];
  iStack_50 = param_1[9];
  iStack_4c = param_1[10];
  iStack_48 = param_1[0xb];
  iStack_44 = param_1[0xc];
  iStack_3c = param_1[0xe];
  iStack_40 = param_1[0xd];
  iStack_38 = param_1[0xf];
  iStack_34 = param_1[0x10];
  if ((uStack_64 & 4) != 0) {
    iStack_4c = 0x3f800000;
    iStack_48 = 0x3f800000;
  }
  uStack_94 = 0;
  uStack_90 = 0;
  uStack_9c = 0;
  uStack_98 = 0;
  uStack_8c = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  uStack_80 = 0;
  uStack_7c = 0;
  uStack_68 = 0;
  iStack_84 = iStack_88;
  func_0x000a66b0(param_2,auStack_1c,&uStack_20);
  uStack_28 = uStack_20;
  if (0xf < iStack_60) {
    iStack_60 = iRam0031f244;
  }
  iVar1 = iStack_60 * 0x1c;
  uStack_a0 = param_2;
  iStack_78 = func_0x000584bc(*(undefined4 *)(param_1[3] + iVar1 + 8));
  iStack_74 = func_0x000584c4(*(undefined4 *)(param_1[3] + iVar1 + 8));
  if ((uStack_64 & 4) == 0) {
    fStack_2c = (float)iStack_34 / (float)iStack_74;
  }
  else {
    fStack_2c = 1.0;
  }
  iStack_70 = iStack_78;
  iStack_6c = func_0x00058c90(*(undefined4 *)(param_1[3] + iVar1 + 8));
  iVar2 = iStack_78;
  if (iStack_6c != 0) {
    iVar2 = func_0x00058c74(*(undefined4 *)(param_1[3] + iVar1 + 8));
    iVar2 = iStack_6c - iVar2;
  }
  iStack_30 = param_1[3] + iVar1;
  iStack_6c = iVar2;
  FUN_0005bac0(0,param_1,&uStack_a0);
  FUN_0005b81c(param_1,&uStack_a0);
  return 1;
}



// ADDRESS 5b81c

void FUN_0005b81c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  uVar3 = *(uint *)(param_2 + 0x60);
  if (uVar3 < 6) {
    if (uVar3 == 1) {
      fVar8 = *(float *)(param_1 + 0x48);
      fVar9 = *(float *)(param_2 + 0x24);
      iVar2 = 0;
      if (0 < *(int *)(param_2 + 0x20)) {
        iVar5 = 0;
        do {
          iVar7 = *(int *)(param_2 + 0x1c) + iVar5;
          iVar2 = iVar2 + 1;
          *(float *)(iVar7 + 0x18) = *(float *)(iVar7 + 0x18) + (fVar8 - fVar9);
          iVar5 = iVar5 + 0x34;
        } while (iVar2 < *(int *)(param_2 + 0x20));
        uVar1 = *(undefined4 *)(param_2 + 0x18);
        goto LAB_0005baa8;
      }
    }
    else if (uVar3 == 2) {
      fVar8 = *(float *)(param_1 + 0x48);
      fVar9 = *(float *)(param_2 + 0x24);
      fVar10 = *(float *)(param_2 + 0x58);
      fVar12 = *(float *)(param_2 + 0x74);
      fVar11 = *(float *)(param_1 + 0x4c);
      iVar2 = *(int *)(param_2 + 0x78);
      iVar5 = *(int *)(param_2 + 0x50);
      if (*(int *)(param_2 + 0x48) != 1) {
        iVar5 = *(int *)(param_2 + 0x34) + iVar5;
      }
      iVar7 = 0;
      if (0 < *(int *)(param_2 + 0x20)) {
        iVar4 = 0;
        do {
          iVar6 = *(int *)(param_2 + 0x1c) + iVar4;
          iVar7 = iVar7 + 1;
          *(float *)(iVar6 + 0x18) = *(float *)(iVar6 + 0x18) + (fVar8 - fVar9) * 0.5;
          iVar6 = *(int *)(param_2 + 0x1c) + iVar4;
          *(float *)(iVar6 + 0x1c) =
               *(float *)(iVar6 + 0x1c) +
               (fVar11 - (float)(iVar2 + -1) * (float)iVar5 * fVar10 * fVar12) * 0.5;
          iVar4 = iVar4 + 0x34;
        } while (iVar7 < *(int *)(param_2 + 0x20));
        uVar1 = *(undefined4 *)(param_2 + 0x18);
        goto LAB_0005baa8;
      }
    }
    else if (uVar3 == 3) {
      fVar8 = *(float *)(param_1 + 0x48);
      iVar2 = 0;
      iVar5 = 0;
      if (0 < *(int *)(param_2 + 0x20)) {
        do {
          iVar7 = *(int *)(param_2 + 0x1c) + iVar5;
          iVar2 = iVar2 + 1;
          *(float *)(iVar7 + 0x18) = *(float *)(iVar7 + 0x18) + fVar8;
          iVar5 = iVar5 + 0x34;
        } while (iVar2 < *(int *)(param_2 + 0x20));
        uVar1 = *(undefined4 *)(param_2 + 0x18);
        goto LAB_0005baa8;
      }
    }
    else if (uVar3 == 4) {
      fVar10 = *(float *)(param_1 + 0x4c);
      fVar8 = *(float *)(param_2 + 0x24);
      fVar9 = *(float *)(param_1 + 0x48);
      iVar2 = 0;
      iVar5 = 0;
      if (0 < *(int *)(param_2 + 0x20)) {
        do {
          iVar7 = *(int *)(param_2 + 0x1c) + iVar5;
          iVar2 = iVar2 + 1;
          *(float *)(iVar7 + 0x18) = *(float *)(iVar7 + 0x18) + fVar9;
          iVar7 = *(int *)(param_2 + 0x1c) + iVar5;
          *(float *)(iVar7 + 0x1c) = *(float *)(iVar7 + 0x1c) + (fVar10 - fVar8);
          iVar5 = iVar5 + 0x34;
        } while (iVar2 < *(int *)(param_2 + 0x20));
        uVar1 = *(undefined4 *)(param_2 + 0x18);
        goto LAB_0005baa8;
      }
    }
    else {
      if (uVar3 != 5) {
        uVar1 = *(undefined4 *)(param_2 + 0x18);
        goto LAB_0005baa8;
      }
      fVar8 = *(float *)(param_1 + 0x4c);
      fVar10 = *(float *)(param_2 + 0x24);
      fVar9 = *(float *)(param_1 + 0x48);
      iVar2 = 0;
      if (0 < *(int *)(param_2 + 0x20)) {
        iVar5 = 0;
        do {
          iVar7 = *(int *)(param_2 + 0x1c) + iVar5;
          iVar2 = iVar2 + 1;
          *(float *)(iVar7 + 0x18) = *(float *)(iVar7 + 0x18) + fVar9;
          iVar7 = *(int *)(param_2 + 0x1c) + iVar5;
          *(float *)(iVar7 + 0x1c) = *(float *)(iVar7 + 0x1c) + (fVar8 - fVar10) * 0.5;
          iVar5 = iVar5 + 0x34;
        } while (iVar2 < *(int *)(param_2 + 0x20));
      }
    }
    uVar1 = *(undefined4 *)(param_2 + 0x18);
  }
  else {
    uVar1 = *(undefined4 *)(param_2 + 0x18);
  }
LAB_0005baa8:
  *(undefined4 *)(param_2 + 0x20) = 0;
  *(undefined4 *)(param_2 + 0x1c) = uVar1;
  *(undefined4 *)(param_2 + 0x24) = 0;
  *(undefined4 *)(param_2 + 0x38) = 0;
  return;
}



// ADDRESS 5bac0

undefined4 FUN_0005bac0(int param_1,int param_2,int *param_3)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int *piVar8;
  int iVar9;
  uint *puVar10;
  int unaff_s4;
  char cVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  undefined8 uVar18;
  int iStack_a8;
  int iStack_a4;
  float fStack_a0;
  int iStack_9c;
  undefined4 uStack_98;
  int iStack_94;
  int *piStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  int iStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  int iStack_48;
  float fStack_44;
  
  fVar12 = (float)param_3[1];
  piStack_90 = (int *)param_3[0x1c];
  fVar13 = (float)param_3[2];
  iVar5 = *piStack_90;
  fVar15 = 0.0;
  puVar10 = (uint *)(param_3 + 0xf);
  cVar11 = param_1 == 1;
  uStack_4c = 0x14c354;
  uStack_50 = 0x14c35c;
  uStack_54 = 0x14c364;
  uStack_58 = 0x14c36c;
  uStack_5c = 0x14c374;
  uStack_60 = 0x14c37c;
  uStack_64 = 0x14c384;
  uStack_68 = 0x14c38c;
  uStack_6c = 0x14c394;
  uStack_70 = 0x14c39c;
  uStack_74 = 0x14c3a4;
  iStack_78 = 0x31f240;
  uStack_7c = 0x14c3ac;
  uStack_80 = 0x14c3b4;
  uStack_84 = 0x14c3bc;
  uStack_88 = 0x14c3c4;
  fVar16 = 1.0;
  uStack_8c = 0x14c340;
  iStack_48 = param_1;
  do {
    bVar2 = false;
    if ((iVar5 == 0) || (iVar5 = func_0x000584cc(piStack_90[2],*param_3,&uStack_98), iVar5 == 1)) {
      return 0;
    }
    if (iVar5 == -1) {
      *param_3 = *param_3 + 1;
LAB_0005c778:
      piVar8 = (int *)param_3[0x1c];
    }
    else {
      if (iStack_94 == 1) {
        pcVar6 = (char *)*param_3;
        cVar1 = *pcVar6;
        if (cVar1 == '#') {
          pcVar7 = pcVar6 + 1;
          *param_3 = (int)pcVar7;
          if (*pcVar7 == 'n') {
            *param_3 = (int)(pcVar6 + 2);
            FUN_0005b81c(param_2,param_3);
          }
          else {
            iVar5 = func_0x00138430(pcVar7,uStack_4c,6);
            if (iVar5 == 0) {
              *param_3 = *param_3 + 6;
              iVar5 = func_0x000b429c(0);
              param_3[0x11] = iVar5;
              func_0x0005b018(param_3,0x5d);
            }
            else {
              iVar5 = func_0x00138430(*param_3,uStack_50,6);
              if (iVar5 == 0) {
                *param_3 = *param_3 + 6;
                iVar5 = func_0x000b429c(1);
                param_3[0x11] = iVar5;
                func_0x0005b018(param_3,0x5d);
              }
              else {
                iVar5 = func_0x00138430(*param_3,uStack_54,5);
                if (iVar5 == 0) {
                  *param_3 = *param_3 + 5;
                  iVar5 = func_0x000b429c(2);
                  param_3[0x11] = iVar5;
                  func_0x0005b018(param_3,0x5d);
                }
                else {
                  iVar5 = func_0x00138430(*param_3,uStack_58,6);
                  if (iVar5 == 0) {
                    *param_3 = *param_3 + 6;
                    param_3[0x11] = *(int *)(param_2 + 0x18);
                    func_0x0005b018(param_3,0x5d);
                  }
                  else {
                    iVar5 = func_0x00138430(*param_3,uStack_5c,6);
                    if (iVar5 == 0) {
                      *param_3 = *param_3 + 6;
                      if ((*puVar10 & 4) == 0) {
                        uVar18 = func_0x00137930(*param_3);
                        iVar5 = func_0x00142a90((int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
                        param_3[0x15] = iVar5;
                        param_3[0x16] = iVar5;
                      }
                      else {
                        param_3[0x15] = (int)fVar16;
                        param_3[0x16] = (int)fVar16;
                      }
                      func_0x0005b018(param_3,0x5d);
                    }
                    else {
                      iVar5 = func_0x00138430(*param_3,uStack_60,7);
                      if (iVar5 == 0) {
                        *param_3 = *param_3 + 7;
                        fVar17 = fVar16;
                        if ((*puVar10 & 4) == 0) {
                          uVar18 = func_0x00137930(*param_3);
                          fVar17 = (float)func_0x00142a90((int)uVar18,
                                                          (int)((ulonglong)uVar18 >> 0x20));
                        }
                        param_3[0x15] = (int)fVar17;
                        func_0x0005b018(param_3,0x5d);
                      }
                      else {
                        iVar5 = func_0x00138430(*param_3,uStack_64,7);
                        if (iVar5 == 0) {
                          *param_3 = *param_3 + 7;
                          fVar17 = fVar16;
                          if ((*puVar10 & 4) == 0) {
                            uVar18 = func_0x00137930(*param_3);
                            fVar17 = (float)func_0x00142a90((int)uVar18,
                                                            (int)((ulonglong)uVar18 >> 0x20));
                          }
                          param_3[0x16] = (int)fVar17;
                          func_0x0005b018(param_3,0x5d);
                        }
                        else {
                          iVar5 = func_0x00138430(*param_3,uStack_68,4);
                          if (iVar5 == 0) {
                            FUN_0005b81c(param_2,param_3);
                            *param_3 = *param_3 + 4;
                            iVar5 = func_0x0013794c();
                            param_3[3] = (int)(float)iVar5;
                            param_3[1] = (int)(float)iVar5;
                            func_0x0005b054(param_3,0x5d,0x2c);
                            iVar5 = func_0x0013794c(*param_3);
                            param_3[4] = (int)(float)iVar5;
                            param_3[2] = (int)(float)iVar5;
                            func_0x0005b018(param_3,0x5d);
                            FUN_0005b0a0(param_2,param_3);
                          }
                          else {
                            iVar5 = func_0x00138430(*param_3,uStack_6c,5);
                            if (iVar5 == 0) {
                              FUN_0005b81c(param_2,param_3);
                              *param_3 = *param_3 + 5;
                              iVar5 = func_0x0013794c();
                              param_3[3] = (int)(float)iVar5;
                              param_3[1] = (int)(float)iVar5;
                              func_0x0005b018(param_3,0x5d);
                              FUN_0005b0a0(param_2,param_3);
                            }
                            else {
                              iVar5 = func_0x00138430(*param_3,uStack_70,5);
                              if (iVar5 == 0) {
                                FUN_0005b81c(param_2,param_3);
                                *param_3 = *param_3 + 5;
                                iVar5 = func_0x0013794c();
                                param_3[4] = (int)(float)iVar5;
                                param_3[2] = (int)(float)iVar5;
                                func_0x0005b018(param_3,0x5d);
                                FUN_0005b0a0(param_2,param_3);
                              }
                              else {
                                iVar5 = func_0x00138430(*param_3,uStack_74,5);
                                if (iVar5 == 0) {
                                  *param_3 = *param_3 + 5;
                                  iVar5 = func_0x0013794c();
                                  if (iVar5 < 0x10) {
                                    param_3[0x10] = iVar5;
                                  }
                                  else {
                                    iVar5 = *(int *)(iStack_78 + 4);
                                    param_3[0x10] = iVar5;
                                  }
                                  iVar5 = iVar5 * 0x1c;
                                  iVar3 = func_0x000584bc(*(undefined4 *)
                                                           (*(int *)(param_2 + 0xc) + iVar5 + 8));
                                  param_3[10] = iVar3;
                                  iVar3 = func_0x000584c4(*(undefined4 *)
                                                           (*(int *)(param_2 + 0xc) + iVar5 + 8));
                                  param_3[0xb] = iVar3;
                                  fVar17 = fVar16;
                                  if ((param_3[0xf] & 4U) == 0) {
                                    fVar17 = (float)param_3[0x1b] / (float)param_3[0xb];
                                  }
                                  param_3[0x1d] = (int)fVar17;
                                  param_3[0xc] = param_3[10];
                                  iVar3 = func_0x00058c90(*(undefined4 *)
                                                           (*(int *)(param_2 + 0xc) + iVar5 + 8));
                                  param_3[0xd] = iVar3;
                                  if (iVar3 == 0) {
                                    iVar3 = param_3[10];
                                  }
                                  else {
                                    iVar3 = func_0x00058c74(*(undefined4 *)
                                                             (*(int *)(param_2 + 0xc) + iVar5 + 8));
                                    iVar3 = param_3[0xd] - iVar3;
                                  }
                                  param_3[0xd] = iVar3;
                                  param_3[0x1c] = *(int *)(param_2 + 0xc) + iVar5;
                                  func_0x0005b018(param_3,0x5d);
                                }
                                else {
                                  iVar5 = func_0x00138430(*param_3,uStack_7c,7);
                                  if (iVar5 == 0) {
                                    *param_3 = *param_3 + 7;
                                    iVar5 = func_0x0013794c();
                                    param_3[0x17] = iVar5;
                                    func_0x0005b018(param_3,0x5d);
                                  }
                                  else {
                                    iVar5 = func_0x00138430(*param_3,uStack_80,6);
                                    if (iVar5 == 0) {
                                      *param_3 = *param_3 + 6;
                                      uVar18 = func_0x00137930();
                                      iVar5 = func_0x00142a90((int)uVar18,
                                                              (int)((ulonglong)uVar18 >> 0x20));
                                      param_3[0x19] = iVar5;
                                      func_0x0005b018(param_3,0x5d);
                                    }
                                    else {
                                      iVar5 = func_0x00138430(*param_3,uStack_84,6);
                                      if (iVar5 == 0) {
                                        *param_3 = *param_3 + 6;
                                        iVar5 = func_0x0013794c();
                                        param_3[0x11] = iVar5;
                                        if (0x62 < iVar5) {
                                          param_3[0x11] = *(int *)(param_2 + 0x18);
                                        }
                                        func_0x0005b018(param_3,0x5d);
                                      }
                                      else {
                                        iVar5 = func_0x00138430(*param_3,uStack_88,6);
                                        if (iVar5 == 0) {
                                          *param_3 = *param_3 + 6;
                                          iVar5 = func_0x0013794c();
                                          param_3[0x18] = iVar5;
                                          if (0x62 < iVar5) {
                                            param_3[0x18] = *(int *)(param_2 + 0x34);
                                          }
                                          func_0x0005b018(param_3,0x5d);
                                        }
                                        else {
                                          iVar5 = func_0x00138430(*param_3,uStack_8c,5);
                                          if (iVar5 == 0) {
                                            *param_3 = *param_3 + 5;
                                            cVar11 = '\x01';
                                            if (param_3[0xe] == 0) {
                                              FUN_0005b154(param_2,param_3);
                                            }
                                            iVar5 = FUN_0005bac0(1,param_2,param_3);
                                            if (iVar5 == 0) {
                                              return 0;
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          bVar2 = true;
        }
        else if (((cVar1 == '\\') && (pcVar6[1] == 'n')) || ((cVar1 == '\r' && (pcVar6[1] == '\n')))
                ) {
          *param_3 = (int)(pcVar6 + 2);
          FUN_0005b81c(param_2,param_3);
        }
        else if ((cVar1 == '\r') || (cVar1 == '\n')) {
          *param_3 = (int)(pcVar6 + 1);
          FUN_0005b81c(param_2,param_3);
        }
        else if (iStack_48 == 1) {
          if ((cVar11 == '\x01') && (cVar1 == ',')) {
            iStack_a8 = param_3[1];
            *param_3 = (int)(pcVar6 + 1);
            iStack_a4 = param_3[2];
            fStack_a0 = (float)param_3[0x15];
            cVar11 = '\x02';
            iStack_9c = param_3[0x16];
            iVar5 = FUN_0005affc(puVar10);
            if (iVar5 == 0) {
              param_3[1] = (int)(((float)param_3[1] - fVar12) * 0.5 + fVar12);
              fVar14 = (float)param_3[0x15];
              fVar17 = (float)param_3[0x16];
            }
            else {
              param_3[2] = (int)(((float)param_3[2] - fVar13) * 0.5 + fVar13);
              fVar14 = (float)param_3[0x15];
              fVar17 = (float)param_3[0x16];
            }
            param_3[0x15] = (int)(fVar14 * (float)param_3[0x1a]);
            bVar2 = true;
            param_3[0x16] = (int)(fVar17 * (float)param_3[0x1a]);
            unaff_s4 = param_3[6];
          }
          else if ((cVar11 == '\x02') && (cVar1 == ']')) {
            *param_3 = (int)(pcVar6 + 1);
            iVar5 = FUN_0005affc(puVar10);
            iVar3 = param_3[6];
            if (iVar5 == 0) {
              for (; unaff_s4 != iVar3; unaff_s4 = unaff_s4 + 0x34) {
                *(float *)(unaff_s4 + 0x18) = *(float *)(unaff_s4 + 0x18) - fVar15 * 0.5;
                *(float *)(unaff_s4 + 0x1c) =
                     *(float *)(unaff_s4 + 0x1c) -
                     (float)param_3[0xb] * (float)param_3[0x16] * (float)param_3[0x1d];
                iVar3 = param_3[6];
              }
            }
            else {
              for (; unaff_s4 != iVar3; unaff_s4 = unaff_s4 + 0x34) {
                iVar5 = param_3[10];
                fVar16 = (float)param_3[0x1d];
                *(float *)(unaff_s4 + 0x1c) = *(float *)(unaff_s4 + 0x1c) - fVar15 * 0.5;
                *(float *)(unaff_s4 + 0x18) =
                     *(float *)(unaff_s4 + 0x18) + (float)iVar5 * fStack_a0 * fVar16;
                iVar3 = param_3[6];
              }
            }
            param_3[1] = iStack_a8;
            param_3[2] = iStack_a4;
            param_3[0x15] = (int)fStack_a0;
            param_3[0x16] = iStack_9c;
            return 1;
          }
        }
      }
      if (!bVar2) {
        if (param_3[0xe] == 0) {
          FUN_0005b154(param_2,param_3);
        }
        fStack_44 = fVar16;
        iVar5 = func_0x00058c30(*(undefined4 *)(param_3[0x1c] + 8),uStack_98);
        iVar3 = func_0x00058c6c(*(undefined4 *)(param_3[0x1c] + 8));
        iVar9 = param_3[6];
        *(int *)(iVar9 + 0x18) = param_3[1];
        fVar17 = (float)param_3[2];
        iVar4 = func_0x00058c74(*(undefined4 *)(param_3[0x1c] + 8));
        fVar16 = fStack_44;
        *(float *)(iVar9 + 0x1c) = fVar17 - (float)iVar4;
        *(float *)(iVar9 + 0x18) =
             *(float *)(iVar9 + 0x18) +
             (float)param_3[10] * (float)param_3[0x15] * (float)param_3[0x1d] * 0.5;
        *(float *)(iVar9 + 0x1c) =
             *(float *)(iVar9 + 0x1c) +
             (float)param_3[0xb] * (float)param_3[0x16] * (float)param_3[0x1d] * 0.5;
        *(float *)(iVar9 + 0x20) = (float)param_3[0x15] * (float)param_3[0x1d];
        fVar17 = (float)param_3[0x16];
        fVar14 = (float)param_3[0x1d];
        *(float *)(iVar9 + 0x10) = (float)iVar5;
        *(float *)(iVar9 + 0x14) = (float)iVar3;
        *(float *)(iVar9 + 0x24) = fVar17 * fVar14;
        *(int *)(iVar9 + 0x28) = *(int *)(param_3[0x1c] + 0x18) + param_3[0x11] * 0x40;
        *(int *)(iVar9 + 0xc) = param_3[0x1c];
        *(undefined4 *)(iVar9 + 0x2c) = uStack_98;
        *(int *)(iVar9 + 0x30) = iStack_94;
        if (0.0 < (float)param_3[0x19]) {
          iVar3 = param_3[5];
        }
        else {
          iVar3 = 0;
        }
        *(int *)(iVar9 + 4) = iVar3;
        iVar3 = FUN_0005affc(puVar10);
        iVar4 = param_3[0x12];
        if (iVar3 == 0) {
          iVar3 = param_3[0x13];
          fVar17 = (float)param_3[0x15] * (float)param_3[0x1d];
          if (iVar4 < 1) {
            if (iVar4 < 0) {
LAB_0005c6a0:
              fVar17 = (float)((int)(float)iVar5 + iVar3) * fVar17;
            }
            else {
              fVar17 = (float)(param_3[10] + iVar3) * fVar17;
            }
          }
          else {
            if (1 < iVar4) goto LAB_0005c6a0;
            fVar17 = (float)iVar3 * fVar17;
          }
          param_3[1] = (int)((float)param_3[1] + fVar17);
        }
        else {
          iVar5 = param_3[0x14];
          if (iVar4 != 1) {
            iVar5 = param_3[0xd] + iVar5;
          }
          fVar17 = (float)iVar5 * (float)param_3[0x16] * (float)param_3[0x1d];
          param_3[2] = (int)((float)param_3[2] + fVar17);
        }
        param_3[6] = param_3[6] + 0x34;
        param_3[8] = param_3[8] + 1;
        if (cVar11 == '\x02') {
          iVar5 = *(int *)(param_2 + 4);
          fVar15 = fVar17 + fVar15;
        }
        else {
          param_3[9] = (int)((float)param_3[9] + fVar17);
          param_3[5] = (int)((float)param_3[5] + (float)param_3[0x19] * *(float *)(param_2 + 0x50));
          iVar5 = *(int *)(param_2 + 4);
        }
        *(int *)(param_2 + 4) = iVar5 + 1;
        *param_3 = *param_3 + iStack_94;
        goto LAB_0005c778;
      }
      piVar8 = (int *)param_3[0x1c];
    }
    iVar5 = *piVar8;
  } while( true );
}



// ADDRESS 5b154

void FUN_0005b154(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0005affc(param_2 + 0x3c);
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_2 + 0xc);
    if (*(int *)(param_1 + 8) != 0) {
      iVar1 = *(int *)(param_2 + 0x50);
      if (*(int *)(param_2 + 0x48) != 1) {
        iVar1 = *(int *)(param_2 + 0x2c) + iVar1;
      }
      *(float *)(param_2 + 8) =
           *(float *)(param_2 + 8) +
           (float)iVar1 * *(float *)(param_2 + 0x58) * *(float *)(param_2 + 0x74);
    }
  }
  else {
    iVar1 = *(int *)(param_2 + 0x4c);
    if (*(int *)(param_2 + 0x48) != 1) {
      iVar1 = *(int *)(param_2 + 0x28) + iVar1;
    }
    *(float *)(param_2 + 4) =
         *(float *)(param_2 + 4) -
         (float)iVar1 * *(float *)(param_2 + 0x54) * *(float *)(param_2 + 0x74);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_2 + 0x10);
  }
  FUN_0005b0a0(param_1,param_2);
  return;
}



// ADDRESS 5b0a0

void FUN_0005b0a0(int param_1,int param_2)

{
  int iVar1;
  
  if ((*(uint *)(param_2 + 0x3c) & 2) != 0) {
    iVar1 = FUN_0005affc(param_2 + 0x3c);
    if (iVar1 == 0) {
      *(float *)(param_2 + 8) =
           *(float *)(param_2 + 8) +
           (float)*(int *)(param_2 + 0x2c) *
           *(float *)(param_2 + 0x58) * *(float *)(param_2 + 0x68) * *(float *)(param_2 + 0x74);
    }
    else {
      *(float *)(param_2 + 4) =
           *(float *)(param_2 + 4) -
           (float)*(int *)(param_2 + 0x28) *
           *(float *)(param_2 + 0x54) * *(float *)(param_2 + 0x68) * *(float *)(param_2 + 0x74);
    }
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  *(undefined4 *)(param_2 + 0x38) = 1;
  return;
}



// ADDRESS 5affc

undefined4 FUN_0005affc(int param_1)

{
  return *(undefined4 *)(*(int *)(param_1 + 0x24) * 4 + 0x31f518);
}



// ADDRESS 5a8e4

undefined4 FUN_0005a8e4(undefined8 param_1,undefined8 param_2,int *param_3)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  float fVar9;
  uint uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined4 uStack_90;
  undefined1 auStack_8c [4];
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  int iStack_4c;
  
  fVar13 = (float)((ulonglong)param_2 >> 0x20);
  fVar12 = (float)param_2;
  fVar11 = (float)((ulonglong)param_1 >> 0x20);
  fVar9 = (float)param_1;
  if (param_3 == (int *)0x0) {
    return 0xffffffff;
  }
  if (1.0 < fVar9) {
    fVar9 = 1.0;
  }
  fVar9 = fVar9 * 255.0;
  if (1.0 < fVar11) {
    fVar11 = 1.0;
  }
  fVar11 = fVar11 * 255.0;
  if (1.0 < fVar12) {
    fVar12 = 1.0;
  }
  fVar12 = fVar12 * 255.0;
  if (1.0 < fVar13) {
    fVar13 = 1.0;
  }
  if (2.1474836e+09 <= fVar9) {
    fVar9 = fVar9 - 2.1474836e+09;
  }
  if (2.1474836e+09 <= fVar11) {
    fVar11 = fVar11 - 2.1474836e+09;
  }
  if (2.1474836e+09 <= fVar12) {
    uVar10 = (int)(fVar12 - 2.1474836e+09) + 0x80000000;
  }
  else {
    uVar10 = (uint)fVar12;
  }
  fVar11 = (float)((int)fVar9 << 0x10 | (int)fVar11 << 8 | uVar10);
  piVar7 = (int *)0x0;
  iVar6 = 0;
  func_0x0004b304(4);
  func_0x0004b2c4();
  iVar3 = *param_3;
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  iVar5 = 0;
  fVar9 = (float)param_3[0x11];
  if (0 < param_3[1]) {
    do {
      fStack_50 = fVar13;
      fVar13 = *(float *)(iVar3 + 4) - 10.0;
      if (fVar9 < fVar13) {
        iVar2 = param_3[1];
      }
      else {
        fVar9 = fVar9 - fVar13;
        if (fVar9 < 10.0) {
          fVar9 = fVar9 / 10.0;
        }
        else {
          fVar9 = 1.0;
        }
        if (iVar3 == 0) {
          iVar2 = param_3[1];
        }
        else {
          iVar2 = func_0x000586e8(*(undefined4 *)(*(int *)(iVar3 + 0xc) + 8),
                                  *(undefined4 *)(iVar3 + 0x2c),&uStack_90,auStack_8c);
          if (iVar2 == 0) {
            iVar2 = func_0x00058a18(*(undefined4 *)(*(int *)(iVar3 + 0xc) + 8),
                                    *(undefined4 *)(iVar3 + 0x2c),uStack_90,&iStack_88);
            fStack_70 = *(float *)(iVar3 + 0x10) * -0.5 * *(float *)(iVar3 + 0x20) +
                        *(float *)(iVar3 + 0x18);
            fStack_6c = *(float *)(iVar3 + 0x14) * -0.5 * *(float *)(iVar3 + 0x24) +
                        *(float *)(iVar3 + 0x1c);
            fStack_68 = *(float *)(iVar3 + 0x10) * 0.5 * *(float *)(iVar3 + 0x20) +
                        *(float *)(iVar3 + 0x18);
            fStack_64 = *(float *)(iVar3 + 0x14) * -0.5 * *(float *)(iVar3 + 0x24) +
                        *(float *)(iVar3 + 0x1c);
            fStack_60 = *(float *)(iVar3 + 0x10) * 0.5 * *(float *)(iVar3 + 0x20) +
                        *(float *)(iVar3 + 0x18);
            fStack_5c = *(float *)(iVar3 + 0x14) * 0.5 * *(float *)(iVar3 + 0x24) +
                        *(float *)(iVar3 + 0x1c);
            fStack_58 = *(float *)(iVar3 + 0x10) * -0.5 * *(float *)(iVar3 + 0x20) +
                        *(float *)(iVar3 + 0x18);
            fStack_54 = *(float *)(iVar3 + 0x14) * 0.5 * *(float *)(iVar3 + 0x24) +
                        *(float *)(iVar3 + 0x1c);
            piVar4 = (int *)(*(int *)(*(int *)(iVar3 + 0xc) + 0xc) + iVar2);
            fVar13 = fVar9 * 255.0 * fStack_50;
            if ((piVar7 != piVar4) || (iVar6 != *(int *)(iVar3 + 0x28))) {
              func_0x0004b380();
              func_0x0004b304(4);
              uVar8 = 0;
              if (*(float *)(iVar3 + 0x20) == 1.0) {
                if (*(float *)(iVar3 + 0x24) == 1.0) {
                  uVar8 = 2;
                  goto LAB_0005ad8c;
                }
                iVar6 = *piVar4;
              }
              else {
LAB_0005ad8c:
                iVar6 = *piVar4;
              }
              func_0x0004b5e8(uVar8,iVar6 + 0x20,*(undefined4 *)(iVar3 + 0x28),piVar4[1]);
              iVar6 = *(int *)(iVar3 + 0x28);
              piVar7 = piVar4;
            }
            pfVar1 = (float *)func_0x0004b328(1);
            if (2.1474836e+09 <= fVar13) {
              fVar13 = fVar13 - 2.1474836e+09;
            }
            fVar11 = (float)((uint)fVar11 & 0xffffff | (int)fVar13 << 0x18);
            iStack_4c = iVar5;
            FUN_0004b4ac(fStack_70,0);
            *pfVar1 = (float)iStack_88;
            pfVar1[2] = fVar11;
            pfVar1[1] = (float)iStack_84;
            FUN_0004b4ac(fStack_68,0,pfVar1 + 6);
            pfVar1[6] = (float)(iStack_88 + iStack_80);
            pfVar1[8] = fVar11;
            pfVar1[7] = (float)iStack_84;
            FUN_0004b4ac(fStack_60,0,pfVar1 + 0xc);
            pfVar1[0xc] = (float)(iStack_88 + iStack_80);
            pfVar1[0xe] = fVar11;
            pfVar1[0xd] = (float)(iStack_84 + iStack_7c);
            FUN_0004b4ac(fStack_58,0,pfVar1 + 0x12);
            pfVar1[0x12] = (float)iStack_88;
            pfVar1[0x14] = fVar11;
            pfVar1[0x13] = (float)(iStack_84 + iStack_7c);
            iVar2 = param_3[1];
            iVar5 = iStack_4c;
          }
          else {
            iVar2 = param_3[1];
          }
        }
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 0x34;
      fVar9 = (float)param_3[0x11];
      fVar13 = fStack_50;
    } while (iVar5 < iVar2);
  }
  fVar9 = fVar9 + 1.0;
  param_3[0x11] = (int)fVar9;
  if (99999.0 < fVar9) {
    param_3[0x11] = (int)(fVar9 - 89999.0);
  }
  iVar3 = 0;
  iVar6 = 0;
  do {
    if (*(int *)(param_3[3] + iVar6) != 0) {
      func_0x000589a4(((int *)(param_3[3] + iVar6))[2]);
    }
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 0x1c;
  } while (iVar3 < 0x10);
  func_0x0004b380();
  return 1;
}



// ADDRESS 5749c

void FUN_0005749c(void)

{
  undefined4 uVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int unaff_s3;
  short *psVar5;
  
  psVar5 = (short *)(unaff_s3 + 0x5b20);
  iVar4 = 0;
  psVar3 = psVar5;
  do {
    if (((*psVar3 == 1) && (iVar2 = *(int *)(psVar3 + 0x2a) + -1, -1 < *(int *)(psVar3 + 0x2a))) &&
       (*(int *)(psVar3 + 0x2a) = iVar2, iVar2 < 1)) {
      func_0x00057098(iVar4);
    }
    iVar4 = iVar4 + 1;
    psVar3 = psVar3 + 0x40;
  } while (iVar4 < 0x40);
  iVar4 = 0;
  do {
    if ((*psVar5 == 1) && (*(int *)(psVar5 + 0x3e) != 0)) {
      func_0x0004b0f4(*(int *)(psVar5 + 0x1c) + 1);
      uVar1 = FUN_00051974(*(float *)(psVar5 + 0x14) + *(float *)(psVar5 + 0x18),0);
      func_0x0004b3f8(uVar1);
      FUN_0005a8e4((float)*(int *)(psVar5 + 0x24) / 127.0,(float)*(int *)(psVar5 + 0x28) / 127.0,
                   *(undefined4 *)(psVar5 + 0x3e),*(int *)(psVar5 + 0x1c) + 1,
                   *(int *)(psVar5 + 0x28),*(undefined4 *)(psVar5 + 0x22));
      func_0x0004b564();
    }
    iVar4 = iVar4 + 1;
    psVar5 = psVar5 + 0x40;
  } while (iVar4 < 0x40);
  func_0x0005a044(0x3b4348);
  return;
}



// ADDRESS 57520

void FUN_00057520(void)

{
  undefined4 uVar1;
  int unaff_s0;
  short *unaff_s1;
  int unaff_s2;
  short *unaff_s3;
  float unaff_f20;
  
  do {
    if ((*unaff_s3 == unaff_s0) && (*(int *)(unaff_s3 + 0x3e) != 0)) {
      func_0x0004b0f4(*(int *)(unaff_s3 + 0x1c) + 1);
      uVar1 = FUN_00051974(*(float *)(unaff_s3 + 0x14) + *(float *)(unaff_s3 + 0x18));
      func_0x0004b3f8(uVar1);
      FUN_0005a8e4((float)*(int *)(unaff_s3 + 0x24) / unaff_f20,
                   (float)*(int *)(unaff_s3 + 0x28) / unaff_f20,*(undefined4 *)(unaff_s3 + 0x3e),
                   *(int *)(unaff_s3 + 0x1c) + 1,*(int *)(unaff_s3 + 0x28),
                   *(undefined4 *)(unaff_s3 + 0x22));
      func_0x0004b564();
    }
    unaff_s2 = unaff_s2 + 1;
    unaff_s1 = unaff_s1 + 0x40;
    unaff_s3 = unaff_s1;
  } while (unaff_s2 < 0x40);
  func_0x0005a044(0x3b4348);
  return;
}



// ADDRESS 4b4ac

void FUN_0004b4ac(undefined8 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  uRam01565444 = (undefined4)((ulonglong)param_1 >> 0x20);
  uRam01565440 = (undefined4)param_1;
  uRam0156544c = 0x3f800000;
  uRam01565448 = param_2;
  FUN_00051b30(0x1565450,0x15653f0);
  *(float *)(param_3 + 0xc) = (float)(int)(short)(int)fRam01565450;
  iVar1 = (int)fRam01565454;
  *(undefined4 *)(param_3 + 0x14) = 0x46fffe00;
  *(float *)(param_3 + 0x10) = (float)(int)(short)iVar1;
  return;
}



// ADDRESS 51974

undefined4 FUN_00051974(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_f16;
  
  func_0x00051594(0x35c1c0);
  func_0x00051824(0x35c1c0,0x35c1c0);
  func_0x00051920(0x35c1c0,0x35c1c0);
  func_0x00051878(0x35c1c0,0x35c1c0);
  func_0x000518cc(in_f16,0x35c1c0,0x35c1c0);
  func_0x000517d0(param_1,param_2,0x35c1c0,0x35c1c0);
  return 0x35c1c0;
}



// ADDRESS 51b30

void FUN_00051b30(void)

{
  func_0x00145818();
  return;
}



// ADDRESS b494c

undefined4 FUN_000b494c(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined2 uStack_180;
  undefined1 uStack_17e;
  undefined1 auStack_17c [2];
  short sStack_17a;
  undefined1 auStack_178 [2];
  undefined1 auStack_176 [4];
  undefined2 uStack_172;
  undefined2 uStack_170;
  undefined1 uStack_168;
  undefined1 uStack_167;
  undefined1 uStack_166;
  undefined1 uStack_165;
  undefined1 uStack_164;
  undefined1 uStack_163;
  undefined1 uStack_162;
  undefined2 uStack_e0;
  undefined1 uStack_de;
  undefined1 auStack_dc [2];
  undefined1 auStack_da [2];
  undefined1 auStack_d8 [2];
  undefined1 auStack_d6 [4];
  undefined2 uStack_d2;
  undefined2 uStack_d0;
  undefined1 uStack_c8;
  undefined1 uStack_c7;
  undefined1 uStack_c6;
  undefined1 uStack_c5;
  undefined1 uStack_c4;
  undefined1 uStack_c3;
  undefined1 uStack_c2;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  
  uStack_3c = param_1;
  iVar4 = func_0x0013833c(param_1,0x15a7c0);
  if (iVar4 != 0) {
    iVar4 = (int)sRam015d4bea;
    uStack_40 = 0x15d4bf4;
    uStack_38 = 0x15a7a8;
    if (sRam015d57b2 == 0) {
      iVar5 = func_0x0006ea24(0,0x15a7a8,0x3f800000);
      if (((0xe < (iVar4 + iVar5) * 0x10000 >> 0x10) || (cRam015d57ac != '\0')) &&
         (sRam003ad7c0 != 1)) {
        sRam015d4bea = 0;
        func_0x00137734(uStack_40,0x15a7c0);
        func_0x00137734(0x15d51d0,0x15a7c0);
        cRam015d57ac = '\0';
        sRam015d4bf2 = 0;
      }
      iVar4 = FUN_00035404();
      func_0x00045e30(&uStack_180);
      uStack_168 = 10;
      uStack_180 = 1;
      FUN_000b41c4(auStack_17c,&sStack_17a,auStack_178,auStack_176);
      uVar2 = uStack_38;
      uVar3 = uStack_3c;
      uStack_172 = 0;
      uStack_170 = 0;
      sStack_17a = sStack_17a + sRam015d4bea * ((short)uRam0031f344 + (short)uRam0031f328);
      uStack_167 = uRam003b40fb;
      uStack_166 = uRam003b40fd;
      uStack_165 = uRam003b40ff;
      uStack_164 = uRam003b40fc;
      uStack_163 = uRam003b40fe;
      uStack_162 = uRam003b4100;
      uStack_17e = 2;
      if (cRam003b40f8 == '\x01') {
        uStack_17e = 1;
      }
      sRam015d4bec = sRam015d4bea;
      func_0x0006ea5c(uStack_3c);
      FUN_00045c04((float)(10 - iVar4) / 15.0,0x15a7b4,uRam0031f31c,(int)(char)uRam0031f334,
                   (int)(short)uRam0031f328);
      func_0x00045eb0(0x15a7b4,&uStack_180);
      FUN_00045f80(0x15a7b4,uVar3);
      FUN_00046148(0x15a7b4);
      uVar1 = uStack_40;
      func_0x001382e0(uStack_40,0x15d51d0);
      FUN_00045f80(uVar2,uVar1);
      FUN_00046148(uVar2);
      func_0x00137734(0x15d51d0,uVar3);
      sRam015d4bf2 = sRam015d4bf2 + 1;
    }
    else {
      iVar5 = func_0x0006ea24(0,0x15a7a8,0x3f800000);
      if ((0x11 < (iVar4 + iVar5) * 0x10000 >> 0x10) || (cRam015d57ac != '\0')) {
        sRam015d4bea = 0;
        func_0x00137734(uStack_40,0x15a7c0);
        func_0x00137734(0x15d51d0,0x15a7c0);
        cRam015d57ac = '\0';
        sRam015d4bf2 = 0;
      }
      iVar4 = FUN_00035404();
      func_0x00045e30(&uStack_e0);
      uStack_e0 = 1;
      uStack_c8 = 10;
      FUN_000b41c4(auStack_dc,auStack_da,auStack_d8,auStack_d6);
      uVar3 = uStack_3c;
      uStack_d2 = 0;
      uStack_d0 = 0x80;
      uStack_c7 = uRam003b40fb;
      uStack_c6 = uRam003b40fd;
      uStack_c5 = uRam003b40ff;
      uStack_c4 = uRam003b40fc;
      uStack_c3 = uRam003b40fe;
      uStack_c2 = uRam003b4100;
      uStack_de = 2;
      if (cRam003b40f8 == '\x01') {
        uStack_de = 1;
      }
      sRam015d4bec = sRam015d4bea;
      func_0x0006ea98(uStack_3c);
      FUN_00045c04((float)(10 - iVar4) / 15.0,0x15a7b4,uRam0031f31c,(int)(char)uRam0031f334,
                   (int)(short)uRam0031f328);
      func_0x00045eb0(0x15a7b4,&uStack_e0);
      FUN_00045f80(0x15a7b4,uVar3);
      FUN_00046148(0x15a7b4);
      uVar2 = uStack_40;
      func_0x001382e0(uStack_40,0x15d51d0);
      uVar1 = uStack_38;
      FUN_00045f80(uStack_38,uVar2);
      FUN_00046148(uVar1);
      func_0x00137734(0x15d51d0,uVar3);
      sRam015d4bf2 = sRam015d4bf2 + 1;
    }
  }
  return 0;
}



// ADDRESS b4d74

void FUN_000b4d74(char *param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  char cVar8;
  short sVar9;
  uint uVar10;
  char *pcVar11;
  char *pcVar12;
  
  uVar6 = func_0x001383b4();
  sRam015d4bee = 0;
  cVar8 = *param_1;
  do {
    pcVar11 = param_1 + 1;
    uVar10 = uVar6 - 1;
    if (cVar8 == '#') {
      iVar7 = func_0x00138430(pcVar11,0x15a7d4,6);
      uVar4 = uRam0031f328;
      pcVar12 = param_1 + 2;
      uVar10 = uVar6 - 2;
      if (iVar7 == 0) {
        iVar7 = sRam003ad7c4 * 0xe;
        sVar2 = (short)uRam0031f344;
        sVar3 = (short)uRam0031f324;
        sVar1 = sRam015d4bee / 2;
        *(undefined2 *)(iVar7 + 0x3ad78c) = 0;
        sVar9 = sRam015d4bea * (sVar2 + (short)uVar4);
        *(short *)(iVar7 + 0x3ad78e) = sVar1 * (sVar2 + sVar3);
        *(short *)(iVar7 + 0x3ad790) = sVar9;
        uVar5 = func_0x0013794c(param_1 + 7);
        iVar7 = sRam003ad7c4 * 0xe;
        *(undefined2 *)(iVar7 + 0x3ad792) = uVar5;
        *(undefined2 *)(iVar7 + 0x3ad794) = 1;
        *(undefined2 *)(iVar7 + 0x3ad796) = 1;
        sRam003ad7c4 = sRam003ad7c4 + 1;
        *(undefined2 *)(iVar7 + 0x3ad798) = 0;
LAB_000b503c:
        cVar8 = *pcVar11;
      }
      else {
        iVar7 = func_0x00138430(pcVar11,0x15a7dc,6);
        uVar4 = uRam0031f328;
        if (iVar7 == 0) {
          iVar7 = sRam003ad7c4 * 0xe;
          sVar2 = (short)uRam0031f344;
          sVar3 = (short)uRam0031f324;
          sVar1 = sRam015d4bee / 2;
          *(undefined2 *)(iVar7 + 0x3ad78c) = 1;
          sVar9 = sRam015d4bea * (sVar2 + (short)uVar4);
          *(short *)(iVar7 + 0x3ad78e) = sVar1 * (sVar2 + sVar3);
          *(short *)(iVar7 + 0x3ad790) = sVar9;
          uVar5 = func_0x0013794c(param_1 + 7);
          iVar7 = sRam003ad7c4 * 0xe;
          *(undefined2 *)(iVar7 + 0x3ad792) = uVar5;
          *(undefined2 *)(iVar7 + 0x3ad794) = 2;
          *(undefined2 *)(iVar7 + 0x3ad796) = 1;
          sRam003ad7c4 = sRam003ad7c4 + 1;
          *(undefined2 *)(iVar7 + 0x3ad798) = 0;
          goto LAB_000b503c;
        }
        iVar7 = func_0x00138430(pcVar11,0x15a7e4,5);
        uVar4 = uRam0031f328;
        if (iVar7 == 0) {
          iVar7 = sRam003ad7c4 * 0xe;
          sVar1 = sRam015d4bee / 2;
          sVar2 = (short)uRam0031f344;
          sVar3 = (short)uRam0031f324;
          *(undefined2 *)(iVar7 + 0x3ad78c) = 2;
          sVar9 = sRam015d4bea;
          *(undefined2 *)(iVar7 + 0x3ad792) = 0;
          *(undefined2 *)(iVar7 + 0x3ad794) = 0;
          *(short *)(iVar7 + 0x3ad78e) = sVar1 * (sVar2 + sVar3);
          *(undefined2 *)(iVar7 + 0x3ad796) = 1;
          sRam003ad7c4 = sRam003ad7c4 + 1;
          *(undefined2 *)(iVar7 + 0x3ad798) = 0;
          *(short *)(iVar7 + 0x3ad790) = sVar9 * (sVar2 + (short)uVar4);
          goto LAB_000b503c;
        }
        iVar7 = func_0x00138430(pcVar11,0x15a7ec,6);
        if (iVar7 == 0) {
          uRam003ad7c0 = 1;
          goto LAB_000b503c;
        }
        cVar8 = *pcVar11;
      }
      if (cVar8 == 'n') {
        sRam015d4bee = 0;
        sRam015d4bea = sRam015d4bea + 1;
      }
      else {
        while (cVar8 != ']') {
          uVar10 = uVar10 - 1;
          cVar8 = *pcVar12;
          pcVar12 = pcVar12 + 1;
        }
      }
    }
    else {
      sRam015d4bee = sRam015d4bee + 1;
      pcVar12 = pcVar11;
    }
    if (uVar10 < 3) {
      sRam015d4bea = sRam015d4bea + 1;
      return;
    }
    cVar8 = *pcVar12;
    uVar6 = uVar10;
    param_1 = pcVar12;
  } while( true );
}



// ADDRESS b41c4

void FUN_000b41c4(short *param_1,short *param_2,short *param_3,short *param_4)

{
  if (param_1 != (short *)0x0) {
    *param_1 = sRam014a5552 + sRam014a554e / 2;
  }
  if (param_2 != (short *)0x0) {
    *param_2 = sRam014a5554 + sRam014a5550 / 2;
  }
  if (param_3 != (short *)0x0) {
    *param_3 = sRam014a554e;
  }
  if (param_4 != (short *)0x0) {
    *param_4 = sRam014a5550;
  }
  return;
}



// ADDRESS b4368

/* WARNING: Removing unreachable block (ram,0x000b4690) */
/* WARNING: Removing unreachable block (ram,0x000b46c4) */
/* WARNING: Removing unreachable block (ram,0x000b46cc) */
/* WARNING: Removing unreachable block (ram,0x000b46a8) */
/* WARNING: Removing unreachable block (ram,0x000b46b0) */
/* WARNING: Removing unreachable block (ram,0x000b46d0) */
/* WARNING: Removing unreachable block (ram,0x000b46b8) */
/* WARNING: Removing unreachable block (ram,0x000b46dc) */
/* WARNING: Removing unreachable block (ram,0x000b46e0) */
/* WARNING: Removing unreachable block (ram,0x000b46e8) */
/* WARNING: Removing unreachable block (ram,0x000b46f0) */
/* WARNING: Removing unreachable block (ram,0x000b4750) */
/* WARNING: Removing unreachable block (ram,0x000b4758) */
/* WARNING: Removing unreachable block (ram,0x000b4760) */
/* WARNING: Removing unreachable block (ram,0x000b4768) */

void FUN_000b4368(void)

{
  int iVar1;
  int iVar2;
  short sStack_e0;
  undefined1 uStack_de;
  undefined1 auStack_dc [2];
  short sStack_da;
  undefined1 auStack_d8 [2];
  undefined1 auStack_d6 [4];
  undefined2 uStack_d2;
  undefined2 uStack_d0;
  char cStack_c8;
  undefined1 uStack_c7;
  undefined1 uStack_c6;
  undefined1 uStack_c5;
  undefined1 uStack_c4;
  undefined1 uStack_c3;
  undefined1 uStack_c2;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  func_0x00045e30(&sStack_e0);
  iVar1 = FUN_00035404();
  uRam015d57b2 = 0;
  uStack_3c = 0x15d4bf4;
  uStack_40 = 0x15d51d0;
  iVar2 = func_0x000375bc(0,0x3f800000);
  if (iVar2 < 2) {
    if (iVar2 < 0) goto LAB_000b4478;
    if (0 < iVar2) {
      sStack_e0 = 1;
      goto LAB_000b4478;
    }
  }
  else if (iVar2 != 3) goto LAB_000b4478;
  sStack_e0 = 0x3c;
LAB_000b4478:
  if (sRam003d0e6c < sStack_e0) {
    sRam003d0e6c = sStack_e0;
  }
  cStack_c8 = '\n';
  FUN_000b41c4(auStack_dc,&sStack_da,auStack_d8,auStack_d6);
  uStack_d2 = 0;
  uStack_d0 = 0x80;
  uStack_c7 = uRam003b40fb;
  uStack_c6 = uRam003b40fd;
  uStack_c5 = uRam003b40ff;
  uStack_c4 = uRam003b40fc;
  uStack_c3 = uRam003b40fe;
  uStack_c2 = uRam003b4100;
  uStack_de = 2;
  if (cRam003b40f8 == '\x01') {
    uStack_de = 1;
  }
  func_0x0004579c(0x15a7a8,(int)cStack_c8,0x46);
  func_0x00045a48(0x15a7a8,0x31f314);
  func_0x00045af4((int)fRam0031f48c,0x15a7a8,2,0,0);
  FUN_00045c04(0,0x15a7a8,uRam0031f31c,(int)(char)uRam0031f334,(int)(short)uRam0031f328);
  func_0x00045eb0(0x15a7a8,&sStack_e0);
  FUN_00045f80(0x15a7a8,uStack_3c);
  FUN_00046148(0x15a7a8);
  sStack_e0 = 1;
  uStack_d0 = 0;
  sStack_da = sStack_da + sRam015d4bec * ((short)uRam0031f344 + (short)uRam0031f328);
  func_0x0004579c(0x15a7b4,(int)cStack_c8,0x46);
  func_0x00045a48(0x15a7b4,0x31f314);
  func_0x00045af4((int)fRam0031f488,0x15a7b4,2,0,0);
  FUN_00045c04((float)(10 - iVar1) / 15.0,0x15a7b4,uRam0031f31c,(int)(char)uRam0031f334,
               (int)(short)uRam0031f328);
  func_0x00045eb0(0x15a7b4,&sStack_e0);
  FUN_00045f80(0x15a7b4,uStack_40);
  FUN_00046148(0x15a7b4);
  func_0x000470d0(0x15a7b4,0xb3dbc,0);
  func_0x000b432c();
  uRam003d0e40 = 1;
  return;
}



// ADDRESS 26574

void FUN_00026574(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_1d0 [452];
  
  iVar1 = func_0x0006ea8c();
  if (iVar1 == 1) {
    func_0x0006e9d0(param_1);
  }
  else {
    func_0x00137734(auStack_1d0,0x14a5c4,*(char *)(iRam003d0e5c + 5) * 0x597c + 0x1309766,param_1);
    func_0x00138494(0x3b4180,auStack_1d0,0x1c2);
    FUN_00045f80(0x14a578,param_1);
    FUN_00046148(0x14a578);
  }
  return;
}



// ADDRESS 26e54

int FUN_00026e54(char param_1,short param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sStack_d0;
  undefined1 auStack_ce [2];
  short asStack_cc [10];
  char acStack_b8 [12];
  short sStack_ac;
  short sStack_aa;
  short sStack_a8;
  short sStack_a6;
  short sStack_a2;
  short sStack_a0;
  char cStack_98;
  undefined1 uStack_97;
  undefined1 uStack_96;
  undefined1 uStack_95;
  undefined1 uStack_94;
  undefined1 uStack_93;
  undefined1 uStack_92;
  
  iVar2 = func_0x0006ea8c();
  iVar3 = 0;
  if (iVar2 == 1) {
    return 1;
  }
  iVar4 = 0;
  func_0x00045e30(&sStack_d0);
  iVar2 = func_0x000455c8(0x14a578);
  if (iVar2 < 0) {
    func_0x0004579c(0x14a578,(int)cRam003b40fa,0x78);
    func_0x00045a48(0x14a578,0x31f274);
    func_0x00045af4(0x14a578,2,0,0);
    func_0x000470d0(0x14a578,0xbba88,0);
  }
  if (param_1 == '\x01') {
    iVar3 = 2;
    auStack_ce[0] = 2;
    acStack_b8[10] = 2;
    acStack_b8[8] = '\x01';
    acStack_b8[9] = '\0';
    sStack_ac = sRam003b40f0;
    sStack_aa = sRam003b40f2;
    sStack_a8 = sRam003b40f4;
    sStack_a6 = sRam003b40f6;
    cStack_98 = cRam003b40fa;
    sStack_d0 = param_2;
    if (cRam003b40f9 == '\0') {
      sStack_a2 = 0;
      sStack_a0 = 0;
    }
    else {
      cVar1 = func_0x00035440(0);
      sStack_a2 = (short)cVar1;
      cVar1 = func_0x00035440(1);
      sStack_a0 = (short)cVar1;
    }
    uStack_97 = 0;
    uStack_94 = 0;
    uStack_96 = 0;
    uStack_93 = 0;
    uStack_95 = 0;
    uStack_92 = 0;
    iVar4 = param_2 + 1;
  }
  iVar2 = iVar3 * 0x20;
  if (cRam003b40f9 == '\0') {
    asStack_cc[iVar3 * 0x10 + 5] = 0;
    asStack_cc[iVar3 * 0x10 + 6] = 0;
  }
  else {
    cVar1 = func_0x00035440(0);
    asStack_cc[iVar3 * 0x10 + 5] = (short)cVar1;
    cVar1 = func_0x00035440(1);
    asStack_cc[iVar3 * 0x10 + 6] = (short)cVar1;
  }
  *(short *)(auStack_ce + iVar2 + -2) = param_2;
  asStack_cc[iVar3 * 0x10] = sRam003b40f0;
  asStack_cc[iVar3 * 0x10 + 1] = sRam003b40f2;
  asStack_cc[iVar3 * 0x10 + 2] = sRam003b40f4;
  asStack_cc[iVar3 * 0x10 + 3] = sRam003b40f6;
  acStack_b8[iVar2] = cRam003b40fa;
  if (cRam003b40f8 == '\x01') {
    auStack_ce[iVar2] = 1;
    func_0x000b3b54();
  }
  else {
    auStack_ce[iVar2] = 2;
  }
  acStack_b8[iVar2 + 1] = cRam003b40fb;
  acStack_b8[iVar2 + 2] = cRam003b40fd;
  acStack_b8[iVar2 + 3] = cRam003b40ff;
  acStack_b8[iVar2 + 4] = cRam003b40fc;
  acStack_b8[iVar2 + 5] = cRam003b40fe;
  acStack_b8[iVar2 + 6] = cRam003b4100;
  func_0x00025a88((int)cRam003b40fa);
  if (cRam003b40fa == '\n') {
    cStack_98 = '\0';
    asStack_cc[iVar3 * 0x10 + 3] = asStack_cc[iVar3 * 0x10 + 3] + 200;
    asStack_cc[iVar3 * 0x10 + 5] = 0;
    asStack_cc[iVar3 * 0x10 + 6] = 0;
  }
  func_0x00045eb0(0x14a578,&sStack_d0);
  func_0x00045cd4(0x14a578,7,0xffffffff);
  FUN_00045c04(0,0x14a578,uRam0031f27c,(int)(char)uRam0031f294,(int)(short)uRam0031f288);
  uRam003d0e40 = 1;
  return (iVar4 + param_2) * 0x10000 >> 0x10;
}



// ADDRESS 35404

int FUN_00035404(void)

{
  return (int)cRam014b3551;
}



// ADDRESS 3611c

void FUN_0003611c(void)

{
  int unaff_s0;
  int unaff_s1;
  int unaff_s2;
  
  *(undefined1 *)(unaff_s1 + 8) = 0;
  *(undefined2 *)(unaff_s0 + 0x40f0) = 0xf0;
  *(undefined2 *)(unaff_s1 + 2) = 0x88;
  *(undefined2 *)(unaff_s1 + 4) = 0x1e0;
  *(undefined2 *)(unaff_s1 + 6) = 0x110;
  *(undefined1 *)(unaff_s1 + 0xb) = 0;
  *(undefined1 *)(unaff_s1 + 0xd) = 0;
  *(undefined1 *)(unaff_s1 + 0xf) = 0;
  *(undefined1 *)(unaff_s1 + 0xc) = 0;
  *(undefined1 *)(unaff_s1 + 0xe) = 0;
  *(undefined1 *)(unaff_s1 + 0x10) = 0;
  func_0x00137734(unaff_s1 + 0x62,0x14ad04);
  *(undefined1 *)(unaff_s1 + 0x8b) = 0;
  *(undefined2 *)(unaff_s2 + 0x1c6) = 0;
  *(undefined2 *)(unaff_s2 + 0x1c8) = 0;
  *(undefined2 *)(unaff_s2 + 0x1ca) = 0;
  *(undefined2 *)(unaff_s2 + 0x206) = 0;
  *(undefined2 *)(unaff_s2 + 0x1fe) = 0;
  *(undefined2 *)(unaff_s2 + 0x200) = 0;
  *(undefined1 *)(unaff_s2 + 0x1f8) = 0;
  func_0x00137734(0x1ee6b8,0x14ad14);
  uRam001ee6d6 = 0xff;
  func_0x00072fa8();
  return;
}



// ADDRESS 45c04

void FUN_00045c04(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4,int param_5)

{
  undefined4 uVar1;
  int in_t0;
  
  uVar1 = func_0x000455c8(param_2,param_5 << 0x10,in_t0 << 0x10);
  func_0x00045b84(param_1,uVar1,param_3,(int)param_4,(param_5 << 0x10) >> 0x10);
  return;
}



// ADDRESS 45f80

int FUN_00045f80(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  undefined4 uVar2;
  
  uVar2 = func_0x000455c8();
  sVar1 = func_0x00045efc(uVar2,param_2);
  return (int)sVar1;
}



// ADDRESS 46148

void FUN_00046148(void)

{
  undefined4 uVar1;
  
  uVar1 = func_0x000455c8();
  func_0x00046054(uVar1);
  return;
}



// ADDRESS 47e04

/* WARNING: Type propagation algorithm not settling */

void FUN_00047e04(short param_1)

{
  char cVar1;
  int iVar2;
  short sVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  short sStack_c0;
  short asStack_be [5];
  short sStack_b4;
  short sStack_b2;
  
  iVar9 = (int)param_1;
  func_0x00045e30(asStack_be + 1);
  iVar2 = iVar9 * 0x710;
  asStack_be[1] = 5;
  func_0x0003eefc(*(undefined4 *)(iVar2 + 0x14c6b18),iVar9,iVar2 + 0x14c651d,&sStack_c0,asStack_be);
  sStack_c0 = sStack_c0 + *(short *)(iVar2 + 0x14c6afe);
  asStack_be[0] = asStack_be[0] + *(short *)(iVar2 + 0x14c6b00);
  iVar5 = (int)*(char *)(iVar2 + 0x14c6508);
  if (iVar5 < 5) {
    psVar10 = (short *)(iVar2 + iVar5 * 0x20 + 0x14c6b54);
    iVar9 = (int)*(char *)(iVar2 + 0x14c6b3c);
    for (; iVar5 < 6; iVar5 = iVar5 + 1) {
      if (*psVar10 < 0) {
        if ((char)psVar10[1] != '\x01') {
          return;
        }
        cVar1 = (char)psVar10[0xc];
      }
      else {
        cVar1 = (char)psVar10[0xc];
      }
      if (cVar1 != -1) {
        iVar9 = (int)cVar1;
      }
      iVar6 = iVar9 * 0x84;
      iVar7 = (*(int *)(iVar6 + 0x1563968) + (int)*(short *)(iVar6 + 0x1563970)) * 0x10000 >> 0x10;
      iVar8 = (*(int *)(iVar6 + 0x156396c) + (int)*(short *)(iVar6 + 0x1563972)) * 0x10000 >> 0x10;
      if (*(short *)(iVar6 + 0x1563976) == 3) {
        iVar7 = (int)(short)((iVar7 * sStack_c0) / (*(short *)(iVar6 + 0x156397c) - iVar7));
        iVar8 = (int)(short)((iVar8 * asStack_be[0]) / (*(short *)(iVar6 + 0x156397e) - iVar8));
      }
      if ((*(byte *)(iVar2 + 0x14c6b0c) & 2) == 0) {
        bVar4 = *(byte *)(iVar2 + 0x14c6b0c);
      }
      else {
        if (sStack_c0 + iVar7 < (int)psVar10[4]) {
          psVar10[4] = (short)(sStack_c0 + iVar7);
        }
        if (asStack_be[0] + iVar8 < (int)psVar10[5]) {
          psVar10[5] = (short)(asStack_be[0] + iVar8);
          bVar4 = *(byte *)(iVar2 + 0x14c6b0c);
        }
        else {
          bVar4 = *(byte *)(iVar2 + 0x14c6b0c);
        }
      }
      if ((bVar4 & 4) != 0) {
        if ((int)psVar10[4] < sStack_c0 + iVar7) {
          psVar10[4] = (short)(sStack_c0 + iVar7);
        }
        if ((int)psVar10[5] < asStack_be[0] + iVar8) {
          psVar10[5] = (short)(asStack_be[0] + iVar8);
        }
      }
      psVar10 = psVar10 + 0x10;
    }
  }
  else {
    iVar5 = *(char *)(iVar2 + 0x14c6b3c) * 0x84;
    iVar6 = (*(int *)(iVar5 + 0x1563968) + (int)*(short *)(iVar5 + 0x1563970)) * 0x10000 >> 0x10;
    iVar7 = (*(int *)(iVar5 + 0x156396c) + (int)*(short *)(iVar5 + 0x1563972)) * 0x10000 >> 0x10;
    if (*(short *)(iVar5 + 0x1563976) == 3) {
      iVar6 = (int)(short)((iVar6 * sStack_c0) / (*(short *)(iVar5 + 0x156397c) - iVar6));
      iVar7 = (int)(short)((iVar7 * asStack_be[0]) / (*(short *)(iVar5 + 0x156397e) - iVar7));
    }
    sStack_c0 = sStack_c0 + (short)iVar6;
    asStack_be[0] = asStack_be[0] + (short)iVar7;
    if ((*(byte *)(iVar2 + 0x14c6b0c) & 2) == 0) {
      bVar4 = *(byte *)(iVar2 + 0x14c6b0c);
    }
    else {
      if (sStack_c0 < *(short *)(iVar2 + 0x14c6b2c)) {
        sStack_b4 = sStack_c0;
      }
      if (asStack_be[0] < *(short *)(iVar2 + 0x14c6b2e)) {
        bVar4 = *(byte *)(iVar2 + 0x14c6b0c);
        sStack_b2 = asStack_be[0];
      }
      else {
        bVar4 = *(byte *)(iVar2 + 0x14c6b0c);
      }
    }
    sVar3 = sStack_b2;
    if ((bVar4 & 4) != 0) {
      if (*(short *)(iVar2 + 0x14c6b2c) < sStack_c0) {
        sStack_b4 = sStack_c0;
      }
      sVar3 = asStack_be[0];
      if (asStack_be[0] <= *(short *)(iVar2 + 0x14c6b2e)) {
        sVar3 = sStack_b2;
      }
    }
    sStack_b2 = sVar3;
    if ((sStack_b4 != -5000) || (sStack_b2 != -5000)) {
      func_0x0004743c(iVar9,asStack_be + 1);
    }
  }
  return;
}



// ADDRESS 144d78

void FUN_00144d78(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_001454b4(uRam003b22d8,param_1,param_2,param_3);
  return;
}



// ADDRESS 1454b4

void FUN_001454b4(int param_1,uint param_2,int param_3,int param_4)

{
  int in_t0;
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = param_3 + in_t0 + -1;
  uVar3 = (param_2 + param_4) - 1;
  uVar4 = iVar2 * 0x400 | uVar3;
  *(uint *)(param_1 + 0xac) = param_2;
  *(int *)(param_1 + 0xb0) = param_3;
  *(uint *)(param_1 + 0xb4) = uVar3;
  *(int *)(param_1 + 0xb8) = iVar2;
  if (*(int *)(param_1 + 0xa8) != 0) {
    puVar1 = *(uint **)(param_1 + 8);
    *puVar1 = param_3 << 10 | param_2 | 0xd4000000;
    *(uint **)(param_1 + 8) = puVar1 + 4;
    puVar1[1] = uVar4 | 0xd5000000;
    puVar1[2] = 0x15000000;
    puVar1[3] = uVar4 | 0x16000000;
  }
  return;
}


