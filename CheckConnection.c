//Reversed function of inside InternetGetConnectedStateExW


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CheckConnection(void)

{
  char cVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  LSTATUS regvalue;
  undefined4 uVar5;
  uint uVar6;
  LPVOID pv;
  uint uVar7;
  undefined1 local_138 [32];
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88 [2];
  undefined8 local_80;
  DWORD local_78;
  uint local_74;
  int local_70;
  undefined4 local_6c;
  LPVOID local_68;
  int local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  int local_50 [2];
  LPCRITICAL_SECTION local_48;
  ulonglong local_40;
  LARGE_INTEGER local_38;
  ulonglong local_30;
  
  local_30 = DAT_180268540 ^ (ulonglong)local_138;
  if ((DAT_180269152 & 2) != 0) {
    FUN_1801ecb68(0x1e,&DAT_18022c618);
  }
  local_48 = (LPCRITICAL_SECTION)&DAT_18026ab58;
  local_6c = 0;
  local_78 = 0;
  local_68 = (LPVOID)0x0;
  local_40 = 0;
  local_70 = 0;
  local_50[0] = 0;
  local_5c = 0;
  local_58 = 0;
  local_e8 = 0;
  local_38.QuadPart = 0;
  local_54 = 0;
  local_60 = 0;
  if (DAT_18026bb3c != 0) {
    LOCK();
    UNLOCK();
    goto LAB_18001fbb5;
  }
  iVar2 = Ordinal_793(0x1000002d);
  uVar6 = 0;
  if (iVar2 == 2) {
    cVar1 = Ordinal_791(0x20000001);
    DAT_18026b948 = 1;
    if (cVar1 == '\0') goto LAB_18001fc6e;
  }
  else {
LAB_18001fc6e:
    DAT_18026b948 = uVar6;
  }
  iVar2 = Ordinal_793(0x1000002d);
  if (iVar2 == 2) {
    cVar1 = Ordinal_791(0x20000002);
    DAT_18026b94c = 1;
    if (cVar1 == '\0') goto LAB_18001fc8d;
  }
  else {
LAB_18001fc8d:
    DAT_18026b94c = uVar6;
  }
  BVar3 = QueryPerformanceFrequency(&local_38);
  if (BVar3 == 0) {
    if ((DAT_180269152 & 2) != 0) {
      uVar5 = FUN_1800530c0();
      LogEvent(0x1f,&DAT_18022c618,uVar5);
    }
    goto LAB_180020d29;
  }
  DAT_18026b9e8 = local_38;
  iVar2 = FUN_180067028(&local_6c);
  if ((DAT_180269152 & 2) != 0) {
    FUN_1801ecfd0(0x20,&DAT_18022c618,iVar2,local_6c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_18026ab58);
  local_40 = CONCAT44(local_40._4_4_,1);
  if (DAT_18026bb3c != 0) {
    FUN_18000ba60(&local_48);
    goto LAB_18001fbb5;
  }
  iVar4 = FUN_1800c7480();
  if (iVar4 < 0) {
    DAT_18026bb38 = FUN_180067d30(iVar4);
    goto LAB_18001fbb5;
  }
  FUN_180120c14();
  if ((DAT_18026bc8c == 0) && (iVar4 = FUN_18010e190(), -1 < iVar4)) {
    DAT_18026bc8c = 1;
  }
  if (DAT_18026b94c != 0) {
    DAT_180268694 = 1;
    DAT_180268698 = 1;
    DAT_18026869c = 1;
    DAT_1802686a0 = 1;
  }
  DAT_1802693d4 = 0;
  FUN_18010c1f4();
  FUN_1801225f8();
  iVar4 = FUN_180110fa8();
  if ((iVar4 < 0) || (iVar4 = FUN_1800ca5bc(&DAT_18026b944), iVar4 < 0)) {
LAB_180020f5f:
    DAT_18026bb38 = FUN_180067d30(iVar4);
  }
  else {
    if (DAT_18026b944 != 0) {
      iVar4 = FUN_1800b22e4(0,0,0,&local_e8);
      if (iVar4 < 0) goto LAB_180020f5f;
      if (local_e8 != 0) {
        DAT_18026bca4 = 1;
      }
    }
    DAT_18026bb38 = FUN_18011c7dc();
    if (DAT_18026bb38 == 0) {
      FUN_18006ac90();
      FUN_18006cb58();
      if ((((DAT_18026b93c != 0) || (DAT_18026b944 != 0)) || (DAT_18026bac4 != 0)) ||
         (DAT_18026b97c != 0)) {
        DAT_18026b9a0 = 1;
      }
      local_78 = 4;
      regvalue = RegGetValueW((HKEY)0xffffffff80000001,
                              L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet Settings",
                              L"EnableZlibDeflate",0x10,(LPDWORD)0x0,&DAT_18026bab0,&local_78);
      if (regvalue == 0) {
        DAT_18026bab0 = (uint)(DAT_18026bab0 != 0);
      }
      else if (DAT_18026b944 != 0) {
        DAT_18026bab0 = 1;
      }
      DAT_18026bb38 = 0;
      Ordinal_650(&DAT_180204dd0,1,1,&DAT_180268678);
      if (DAT_18026b93c == 0) {
        DAT_180268678 = 0xffffffff;
      }
      DAT_18026bb38 = FUN_180133804();
      if (DAT_18026bb38 == 0) {
        FUN_180102150();
        DAT_1802686cc =
             Registry_function("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet Settings",
                               "SOFTWARE\\Policies\\Microsoft\\Windows\\CurrentVersion\\Internet Set tings"
                               ,"CertificateRevocation",1);
        local_f8 = 0;
        iVar4 = Ordinal_650(&DAT_180204dc0,0,1,&local_f8);
        if (-1 < iVar4) {
          DAT_18026bda8 = (uint)(local_f8 != 0);
        }
        Ordinal_650(&DAT_180204bb0,1,1,&DAT_1802686d4);
        Ordinal_650(&DAT_180204db0,1,1,&DAT_1802686b8);
        Ordinal_650(&DAT_180204ab0,1,1,&DAT_1802686bc);
        Ordinal_650(&DAT_180204b60,1,1,&DAT_18026bdb0);
        local_e0 = 0;
        iVar4 = Ordinal_650(&DAT_180204da0,0,1,&local_e0);
        if (-1 < iVar4) {
          DAT_18026bda4 = (uint)(local_e0 != 0);
        }
        local_dc = 0;
        iVar4 = Ordinal_650(&DAT_180204d90,0,1,&local_dc);
        if (-1 < iVar4) {
          DAT_180268758 = (uint)(local_dc != 0);
        }
        local_d8 = 0;
        iVar4 = Ordinal_650(&DAT_180204d80,0,1,&local_d8);
        if (iVar4 < 0) {
          DAT_18026b98c = 1;
          FUN_18014a994(&DAT_180204d80);
        }
        else {
          DAT_18026b98c = (uint)(local_d8 != 0);
        }
        local_d4 = 0;
        iVar4 = Ordinal_650(&DAT_180204d70,0,1,&local_d4);
        if (-1 < iVar4) {
          DAT_18026b990 = (uint)(local_d4 != 0);
        }
        local_e4 = 0;
        iVar4 = Ordinal_650(&DAT_180204d60,0,1,&local_e4);
        if (-1 < iVar4) {
          DAT_180268750 = (uint)(local_e4 != 0);
        }
        local_cc = 0;
        iVar4 = Ordinal_650(&DAT_180204b70,0,1,&local_cc);
        if (-1 < iVar4) {
          _DAT_18026bd94 = (uint)(local_cc != 0);
        }
        local_c8 = 0;
        iVar4 = Ordinal_650(&DAT_180204d50,0,1,&local_c8);
        if (-1 < iVar4) {
          DAT_1802686ec = (uint)(local_c8 != 0);
        }
        uVar5 = 1;
        local_c4 = 0;
        iVar4 = Ordinal_650(&DAT_180204b90,0,1,&local_c4);
        if (-1 < iVar4) {
          DAT_18026ba88 = (uint)(local_c4 != 0);
        }
        if ((DAT_18026b93c == 0) && (DAT_18026b944 == 0)) {
          uVar5 = 0;
        }
        if ((DAT_18026ba88 == 0) || (DAT_18026ba88 = 1, DAT_1802686ec == 0)) {
          DAT_18026ba88 = uVar6;
        }
        local_c0 = 0;
        DAT_18026bd84 = uVar5;
        iVar4 = Ordinal_650(&DAT_180204d40,0,1,&local_c0);
        if (-1 < iVar4) {
          DAT_18026bda0 = (uint)(local_c0 != 0);
        }
        Ordinal_650(&DAT_180204d30,1,1,&DAT_1802686dc);
        DAT_1802686e0 = 0x40000;
        Ordinal_650(&DAT_180204aa0,1,1,&DAT_1802686e0);
        Ordinal_650(&DAT_180204d20,1,1,&DAT_1802686a8);
        Ordinal_650(&DAT_180204b00,1,1,&DAT_18026875c);
        if (DAT_18026b944 != 0) {
          DAT_1802686f0 = 0xc;
          DAT_1802686b4 = 6;
          DAT_1802686f4 = 6;
        }
        Ordinal_650(&DAT_180204ae0,1,1,&DAT_1802686b4);
        if (DAT_1802686b4 < 2) {
          DAT_1802686b4 = 2;
        }
        if (0x80 < DAT_1802686b4) {
          DAT_1802686b4 = 0x80;
        }
        Ordinal_650(&DAT_180204d10,1,1,&DAT_1802686f4);
        if (DAT_1802686f4 < 2) {
          DAT_1802686f4 = 2;
        }
        if (0x80 < DAT_1802686f4) {
          DAT_1802686f4 = 0x80;
        }
        Ordinal_650(&DAT_180204d00,1,1,&DAT_1802686f0);
        if (DAT_1802686f0 < 2) {
          DAT_1802686f0 = 2;
        }
        if (0x80 < DAT_1802686f0) {
          DAT_1802686f0 = 0x80;
        }
        Ordinal_650(&DAT_180204ac0,1,1,&DAT_1802686b0);
        Ordinal_650(&DAT_180204cf0,1,1,&DAT_180268680);
        if (DAT_180268680 < 5000) {
          DAT_180268680 = 5000;
        }
        if (86400000 < DAT_180268680) {
          DAT_180268680 = 86400000;
        }
        Ordinal_650(&DAT_180204ce0,1,1,&DAT_18026867c);
        if (DAT_18026867c == 0) {
          DAT_18026867c = 1;
        }
        if (100 < DAT_18026867c) {
          DAT_18026867c = 100;
        }
        Ordinal_650(&DAT_180204b50,1,1,&DAT_180268690);
        if (DAT_180268690 < 5000) {
          DAT_180268690 = 5000;
        }
        if (86400000 < DAT_180268690) {
          DAT_180268690 = 86400000;
        }
        Ordinal_650(&DAT_180204cd0,1,1,&DAT_18026868c);
        if (DAT_18026868c < 5000) {
          DAT_18026868c = 5000;
        }
        if (86400000 < DAT_18026868c) {
          DAT_18026868c = 86400000;
        }
        local_bc = 0;
        iVar4 = Ordinal_650(&DAT_180204cc0,0,1,&local_bc);
        if (-1 < iVar4) {
          DAT_18026bcd8 = (uint)(local_bc != 0);
        }
        local_b8 = 0;
        iVar4 = Ordinal_650(&DAT_180204bc0,0,1,&local_b8);
        if (-1 < iVar4) {
          DAT_18026ba40 = (uint)(local_b8 != 0);
        }
        iVar4 = FUN_18006c804(&PTR_DAT_1802681e0);
        DAT_18026b988 = (uint)(iVar4 == 0);
        iVar4 = FUN_18006c804(&PTR_DAT_180268290);
        local_74 = 0;
        DAT_18026b99c = (uint)(iVar4 == 0);
        iVar4 = Ordinal_650(&DAT_180204cb0,1,1,&local_74);
        if (-1 < iVar4) {
          DAT_180268740 = (ulonglong)local_74 * 10000000;
        }
        iVar4 = Ordinal_650(&DAT_180204ca0,1,1,&local_74);
        if (-1 < iVar4) {
          DAT_180268738 = (ulonglong)local_74 * 10000000;
        }
        DAT_18026bce8 =
             Registry_function("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet Settings",
                               "SOFTWARE\\Policies\\Microsoft\\Windows\\CurrentVersion\\Internet Set tings"
                               ,"DisableCachingOfSSLPages",0);
        local_b4 = 0;
        iVar4 = Ordinal_650(&DAT_180204bd0,0,1,&local_b4);
        if (-1 < iVar4) {
          DAT_180268728 = (uint)(local_b4 != 0);
        }
        local_b0 = 0;
        iVar4 = Ordinal_650(&DAT_180204c90,0,1,&local_b0);
        if (-1 < iVar4) {
          DAT_18026bd80 = (uint)(local_b0 != 0);
        }
        local_ac = 0;
        iVar4 = Ordinal_650(&DAT_180204af0,0,1,&local_ac);
        if (-1 < iVar4) {
          DAT_18026bd7c = (uint)(local_ac != 0);
        }
        local_a8 = 0;
        iVar4 = Ordinal_650(&DAT_180204c80,0,1,&local_a8);
        if (-1 < iVar4) {
          DAT_18026bce0 = (uint)(local_a8 != 0);
        }
        local_a4 = 0;
        iVar4 = Ordinal_650(&DAT_180204c70,0,1,&local_a4);
        if (-1 < iVar4) {
          DAT_18026bcdc = (uint)(local_a4 != 0);
        }
        local_a0 = 0;
        iVar4 = Ordinal_650(&DAT_180204c60,0,1,&local_a0);
        if (-1 < iVar4) {
          DAT_18026bcc8 = (uint)(local_a0 != 0);
        }
        local_9c = 0;
        iVar4 = Ordinal_650(&DAT_180204b40,0,1,&local_9c);
        if (-1 < iVar4) {
          _DAT_18026bdac = (uint)(local_9c != 0);
        }
        iVar4 = FUN_18006c804(&PTR_DAT_180268300);
        local_98 = 0;
        DAT_1802686c8 = (uint)(iVar4 == 0);
        iVar4 = Ordinal_650(&DAT_180204b30,0,1,&local_98);
        if (-1 < iVar4) {
          DAT_18026ba80 = (uint)(local_98 != 0);
        }
        local_94 = 0;
        iVar4 = Ordinal_650(&DAT_180204c50,0,1,&local_94);
        if (-1 < iVar4) {
          DAT_18026b9a4 = (uint)(local_94 != 0);
        }
        FUN_1800a95c4(&PTR_DAT_1801f3410,&DAT_18026bd20,&DAT_18026bd10,&DAT_18026bd00);
        FUN_1800a95c4(&PTR_DAT_1801f3440,&DAT_18026bd18,&DAT_18026bd08,0);
        DAT_18026bb38 = FUN_18012078c();
        if (DAT_18026bb38 == 0) {
          if ((DAT_180269150 & 1) != 0) {
            FUN_1801d7fc0(0x21,&DAT_18022c618,DAT_18026bcb8,DAT_18026bcb0);
          }
          DAT_18026bab8 = FUN_18011eb54();
          DAT_18026bab4 = FUN_180122d48();
          FUN_180035508();
          DAT_18026bb38 = FUN_18011cf94();
          if ((DAT_18026bb38 == 0) && (DAT_18026bb38 = FUN_1800ab1bc(), DAT_18026bb38 == 0)) {
            iVar4 = FUN_1800aa540();
            if (iVar4 < 0) {
LAB_180020d18:
              DAT_18026bb38 = 8;
            }
            else {
              DAT_18026bb38 = FUN_18012945c();
              if (DAT_18026bb38 == 0) {
                FUN_1801171d0();
                FUN_1800ff950(&DAT_180269420);
                iVar4 = Ordinal_650(&DAT_180204ad0,1,1,&DAT_1802686e4);
                if ((-1 < iVar4) && (1 < DAT_1802686e4)) {
                  DAT_1802686e4 = 0;
                }
                DAT_18026b9e0 = 0;
                local_78 = 4;
                regvalue = RegGetValueW((HKEY)0xffffffff80000002,
                                        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet Set tings"
                                        ,L"DisableHttp2ConnectionSharing",0x10,(LPDWORD)0x0,
                                        &local_5c,&local_78);
                if (regvalue == 0) {
                  DAT_18026b9e0 = (uint)(local_5c != 0);
                }
                DAT_18026bb38 = 0;
                if ((DAT_180269152 & 2) != 0) {
                  LogEvent(0x22,&DAT_18022c618,DAT_18026b9e0);
                }
                local_78 = 4;
                regvalue = RegGetValueW((HKEY)0xffffffff80000001,
                                        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet Set tings"
                                        ,L"EnableTlsAnonymousClientAuthFallback",0x10,(LPDWORD)0x0 ,
                                        &local_58,&local_78);
                if (regvalue == 0) {
                  DAT_18026ba58 = (uint)(local_58 != 0);
                }
                DAT_18026bb38 = 0;
                local_78 = 4;
                regvalue = RegGetValueW((HKEY)0xffffffff80000002,
                                        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet Set tings"
                                        ,L"DisableProxyAuthenticationSchemes",0x10,(LPDWORD)0x0,
                                        &local_54,&local_78);
                if (regvalue == 0) {
                  DAT_18026b994 = local_54;
                }
                DAT_18026bb38 = 0;
                if ((DAT_180269152 & 2) != 0) {
                  LogEvent(0x23,&DAT_18022c618,DAT_18026b994);
                }
                local_78 = 4;
                regvalue = RegGetValueW((HKEY)0xffffffff80000002,
                                        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet Set tings"
                                        ,L"DisableProxyLinkLocalNameResolution",0x10,(LPDWORD)0x0,
                                        &local_60,&local_78);
                if (regvalue == 0) {
                  DAT_18026ba98 = (uint)(local_60 != 0);
                }
                DAT_18026bb38 = 0;
                if ((DAT_180269152 & 2) != 0) {
                  LogEvent(0x24,&DAT_18022c618,DAT_18026ba98);
                }
                DAT_18026ba54 = 0;
                iVar4 = Registry_function("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet S ettings"
                                          ,
                                          "SOFTWARE\\Policies\\Microsoft\\Windows\\CurrentVersion\\I nternet Settings"
                                          ,"EnableInsecureTlsFallback",0);
                DAT_18026ba54 = (uint)(iVar4 != 0);
                if ((DAT_180269152 & 2) != 0) {
                  LogEvent(0x25,&DAT_18022c618);
                }
                DAT_18026bb38 = FUN_180124ec0();
                if ((DAT_18026bb38 == 0) && (DAT_18026bb38 = FUN_180034b88(), DAT_18026bb38 == 0))  {
                  iVar4 = FUN_1800fb584();
                  if (-1 < iVar4) {
                    local_78 = 4;
                    iVar4 = FUN_18011e0cc();
                    if (iVar4 < 0) {
                      DAT_180268718 = 1;
                    }
                    local_78 = 4;
                    regvalue = RegGetValueW((HKEY)0xffffffff80000002,
                                            L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet  Settings"
                                            ,L"AutoProxyQueryWithFullUrl",0x10,(LPDWORD)0x0,
                                            &local_70,&local_78);
                    if (regvalue != 0) {
                      local_70 = 0;
                    }
                    DAT_18026bb38 = 0;
                    DAT_18026ba44 = (uint)(local_70 != 0);
                    iVar4 = Ordinal_650(&DAT_180204c40,1,1,&DAT_18026bc90);
                    if (iVar4 < 0) {
                      DAT_18026bc90 = 0;
                    }
                    Ordinal_650(&DAT_180204c30,1,1,&DAT_180268714);
                    iVar4 = FUN_1801242c8();
                    if (-1 < iVar4) {
                      DAT_18026bb38 = WinHttpCreateProxyManager(0xff,0,DAT_18026ba90,&DAT_18026baa 0)
                      ;
                      if (DAT_18026bb38 == 0) {
                        iVar4 = FUN_18011a56c(&local_68);
                        if ((iVar4 < 0) || (iVar4 = CustomFree(DAT_18026baa0,local_68), iVar4 < 0) )
                        goto LAB_180020f9c;
                        uVar5 = FUN_180010568(FUN_180034870,0);
                        DAT_18026bb38 = FUN_180067d30(uVar5);
                        if (DAT_18026bb38 == 0) {
                          if (iVar2 != 0) {
                            DAT_18026b9c4 = local_6c;
                            DAT_18026b9c8 = 1;
                          }
                          DAT_18026bb38 = FUN_18011b954();
                          if (DAT_18026bb38 == 0) {
                            local_80 = 0;
                            iVar2 = FUN_18010f8e8(&local_80);
                            if (iVar2 < 0) goto LAB_180020d18;
                            DAT_18026bb38 = FUN_1800d0488();
                            if (DAT_18026bb38 == 0) {
                              uVar7 = 1;
                              local_90 = 0;
                              iVar2 = Ordinal_650(&DAT_180204b10,0,1,&local_90);
                              if (-1 < iVar2) {
                                uVar7 = (uint)(local_90 == 0);
                              }
                              DAT_180268724 = uVar7;
                              cVar1 = Ordinal_791(0x10000019);
                              if ((cVar1 != '\0') ||
                                 ((uVar7 = uVar6, DAT_18026b93c == 0 &&
                                  (iVar2 = FUN_18012bca4(), iVar2 != 0)))) {
                                uVar7 = 1;
                              }
                              if ((DAT_18026b93c != 0) || (DAT_18026b944 != 0)) {
                                DAT_18026ba84 = 1;
                              }
                              DAT_18026bd70 = (uint)(DAT_18026b93c != 0);
                              local_8c = 0;
                              DAT_18026bca0 = uVar7;
                              iVar2 = Ordinal_650(&DAT_180204ba0,0,1,&local_8c);
                              if (-1 < iVar2) {
                                DAT_18026bd70 = (uint)(local_8c != 0);
                              }
                              if ((DAT_18026b93c != 0) || (DAT_18026b944 != 0)) {
                                uVar6 = 1;
                              }
                              DAT_18026b9fc = 0;
                              DAT_18026b9f4 = uVar6;
                              if ((DAT_18026b93c != 0) || (DAT_18026b944 != 0)) {
                                DAT_18026b9fc = 1;
                                local_88[0] = 0;
                                iVar2 = Ordinal_650(&DAT_180204c20,0,1,local_88);
                                if (-1 < iVar2) {
                                  DAT_18026b9fc = (uint)(local_88[0] != 0);
                                }
                              }
                              local_f4 = 0;
                              iVar2 = Ordinal_650(&DAT_180204c10,0,1,&local_f4);
                              if (-1 < iVar2) {
                                DAT_18026ba5c = (uint)(local_f4 != 0);
                              }
                              local_f0 = 0;
                              iVar2 = Ordinal_650(&DAT_180204b20,0,1,&local_f0);
                              if (-1 < iVar2) {
                                DAT_18026b9f0 = (uint)(local_f0 != 0);
                              }
                              local_ec = 0;
                              iVar2 = Ordinal_650(&DAT_180204c00,0,1,&local_ec);
                              if (-1 < iVar2) {
                                DAT_18026bcd4 = (uint)(local_ec != 0);
                              }
                              if ((DAT_18026b944 != 0) || (iVar2 = FUN_180111904(), iVar2 != 0)) {
                                DAT_18026bcd0 = 2;
                              }
                              Ordinal_650(&DAT_180204b80,1,1,&DAT_18026bcd0);
                              DAT_18026bcd0 = DAT_18026bcd0 & 2;
                              local_d0 = 0;
                              iVar2 = Ordinal_650(&DAT_180204bf0,0,1,&local_d0);
                              if (-1 < iVar2) {
                                _DAT_18026bccc = (uint)(local_d0 != 0);
                              }
                              local_78 = 4;
                              if (((DAT_18026bab8 == 0) && (DAT_18026bab4 == 0)) &&
                                 (regvalue = RegGetValueW((HKEY)0xffffffff80000001,
                                                                                                                    
                                                  L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\In ternet Settings"
                                                  ,L"EnableTcpFastOpen",0x10,(LPDWORD)0x0,
                                                  &DAT_18026b9f8,&local_78), regvalue == 0)) {
                                DAT_18026b9f8 = (uint)(DAT_18026b9f8 != 0);
                              }
                              DAT_18026bb38 = FUN_180129b84();
                              if (DAT_18026bb38 == 0) {
                                if (DAT_18026b968 == 0) {
                                  uVar5 = FUN_180128164();
                                  DAT_18026bb38 = FUN_180067d30(uVar5);
                                  if (DAT_18026bb38 != 0) goto LAB_180020d29;
                                  DAT_180268710 = 0xffffffff;
                                }
                                DAT_18026bb38 = 0;
                                if (DAT_18026b960 == 0) {
                                  uVar5 = FUN_1801265b4();
                                  DAT_18026bb38 = FUN_180067d30(uVar5);
                                  if (DAT_18026bb38 != 0) goto LAB_180020d29;
                                  DAT_18026870c = 0xffffffff;
                                }
                                DAT_18026bb38 = 0;
                                if (DAT_18026b958 == 0) {
                                  uVar5 = FUN_18012ab30();
                                  DAT_18026bb38 = FUN_180067d30(uVar5);
                                  if (DAT_18026bb38 != 0) goto LAB_180020d29;
                                  DAT_180268708 = 0xffffffff;
                                }
                                DAT_18026bb38 = 0;
                                FUN_180035404(0);
                                DAT_18026bc68 = 0;
                                DAT_18026bc64 = 0;
                                local_78 = 4;
                                regvalue = RegGetValueW((HKEY)0xffffffff80000002,
                                                                                                                
                                                  L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\In ternet Settings"
                                                  ,L"EdpEnforcementOverride",0x10,(LPDWORD)0x0,
                                                  local_50,&local_78);
                                if (regvalue == 0) {
                                  DAT_18026bc68 = 1;
                                  DAT_18026bc64 = (uint)(local_50[0] != 0);
                                }
                                DAT_18026bb38 = 0;
                                if ((DAT_180269152 & 2) != 0) {
                                  FUN_1801f0e70(0x26);
                                }
                                if (((DAT_18026b940 != 0) || (DAT_18026b948 != 0)) ||
                                   (DAT_18026b94c != 0)) {
                                  DAT_18026b9dc = 1;
                                }
                                iVar2 = FUN_18008b2c0();
                                if (iVar2 == 0) {
                                  FUN_180037520();
                                }
                                if ((DAT_180269152 & 2) != 0) {
                                  LogEvent(0x27,&DAT_18022c618,iVar2 == 0);
                                }
                                local_78 = 0x104;
                                RegGetValueA((HKEY)0xffffffff80000001,
                                             "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet  Settings"
                                             ,"QuicTestHost",2,(LPDWORD)0x0,&DAT_18026bb60,&local_ 78
                                            );
                                DAT_18026bb38 = 0;
                                if ((DAT_180269152 & 2) != 0) {
                                  FUN_1801eb9f8(0x28,&DAT_18022c618,&DAT_18026bb60);
                                }
                                DAT_18026b970 = 1;
                              }
                            }
                          }
                        }
                      }
                      goto LAB_180020d29;
                    }
                  }
LAB_180020f9c:
                  DAT_18026bb38 = FUN_180067d30(iVar4);
                }
              }
            }
          }
        }
      }
    }
  }
LAB_180020d29:
  if (DAT_18026bda4 != 0) {
    DAT_1802686f8 = 1;
    DAT_1802686fc = 1;
  }
  LOCK();
  UNLOCK();
  DAT_18026bb3c = 1;
  if ((int)local_40 != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_18026ab58);
    local_40 = local_40 & 0xffffffff00000000;
  }
LAB_18001fbb5:
  if ((DAT_180269152 & 2) != 0) {
    LogEvent(0x29,&DAT_18022c618,DAT_18026bb38);
  }
  if (((int)local_40 != 0) && (local_48 != (LPCRITICAL_SECTION)0x0)) {
    LeaveCriticalSection(local_48);
  }
  if (local_68 != (LPVOID)0x0) {
    pv = local_68;
    if ((DAT_180269150 & 0x10) != 0) {
      FUN_1801ecb80(0x11,&DAT_180228370,&local_68);
      pv = local_68;
    }
    local_68 = (LPVOID)0x0;
    if (pv != (LPVOID)0x0) {
      CoTaskMemFree(pv);
    }
    if ((DAT_180269150 & 0x10) != 0) {
      FUN_1801ecb68(0x12,&DAT_180228370);
    }
  }
  
  VerifyStackCookie(local_30 ^ (ulonglong)local_138);

  return;
}

