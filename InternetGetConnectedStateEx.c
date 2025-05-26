
void InternetGetConnectedStateExW
               (uint *status,LPWSTR connection_name,int connection_name_len,int param4)

{
  uint uVar1;
  char cVar2;
  DWORD error_code;
  int iVar3;
  int isconnectedstate;
  undefined4 result;
  undefined8 uVar4;
  uint uVar5;
  int use_connection_name;
  int iVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined1 auStack_88 [32];
  int local_68;
  int local_60;
  int local_58;
  undefined2 *default_connection;
  undefined8 local_48;
  ulonglong stack_cookie;
  
                    /* 0x1ec50  296  InternetGetConnectedStateExW */
                    /* Stack Protection Setup */
  stack_cookie = DAT_180268540 ^ (ulonglong)auStack_88;
  if ((DAT_180269150 & 8) != 0) {
    local_68 = connection_name_len;
    local_60 = param4;
    FUN_1801d8c40(0x1c,&DAT_180204130,status,connection_name);
  }
                    /* Initialize Local Vars
                       Default fallback connection name pointer */
  default_connection = &DAT_18022b110;
  isconnectedstate = 0;
  use_connection_name = 0;
  local_48 = 0;
  puVar7 = (undefined2 *)0x0;
  if (status != (uint *)0x0) {
    *status = 0;
  }
  if (connection_name != (LPWSTR)0x0) {
    *connection_name = L'\0';
  }
                    /* Check If system is in "Offline Mode" */
  cVar2 = FUN_18014e8a0();
  if (cVar2 == '\0') {
                    /* If not offline, use fallback connectivity check */
    result = FUN_180148fe4(status,connection_name,connection_name_len);
    if ((DAT_180269150 & 8) != 0) {
                    /* Log the result if needed */
      FUN_1801ea750(0x1d,&DAT_180204130,result);
    }
  }
  else {
    error_code = CheckConnection();
    if (error_code == 0) {
      if (param4 == 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_18026ac70);
        iVar3 = FUN_18001eacc(&default_connection);
        puVar8 = default_connection;
        uVar5 = 0x10;
        if (iVar3 == 0) {
          iVar3 = FUN_18001e860();
          puVar8 = (undefined2 *)0x0;
          iVar6 = 0;
          if (iVar3 != 0) {
            uVar5 = 0x12;
            isconnectedstate = FUN_18001efc8(0,0,0);
            puVar8 = puVar7;
            iVar6 = use_connection_name;
            if ((connection_name != (LPWSTR)0x0) && (connection_name_len != 0)) {
              LoadStringW(DAT_18026b860,0xfad,connection_name,connection_name_len);
            }
          }
        }
        else {
          uVar5 = 0x11;
          iVar6 = 1;
          isconnectedstate = FUN_18001efc8(default_connection,0,0);
        }
        if (isconnectedstate != 0) {
          iVar6 = 1;
        }
        uVar1 = uVar5 | 4;
        if (isconnectedstate == 0) {
          uVar1 = uVar5;
        }
        local_58 = iVar6;
        if ((((connection_name != (LPWSTR)0x0) && (connection_name_len != 0)) &&
            (puVar8 != (undefined2 *)0x0)) &&
           (isconnectedstate = FUN_1800fec64(connection_name,connection_name_len,puVar8,0x101),
           isconnectedstate < 0)) {
          if ((DAT_180269150 & 8) != 0) {
            FUN_1801ea750(0x21,&DAT_180204130,isconnectedstate);
          }
          *connection_name = L'\0';
          error_code = 0x7a;
          if (isconnectedstate != -0x7ff8ff86) {
            error_code = 0x57;
          }
          SetLastError(error_code);
        }
        if (status != (uint *)0x0) {
          uVar5 = uVar1 | 0x40;
          if (local_58 == 0) {
            uVar5 = uVar1;
          }
          *status = uVar5;
        }
        if ((DAT_180269150 & 8) != 0) {
          FUN_1801ea750(0x22,&DAT_180204130,iVar3);
        }
        SetLastError(0);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_18026ac70);
        if ((default_connection != &DAT_18022b110) && (default_connection != (undefined2 *)0x0)) {
          if (DAT_18026c328 == 0) {
            HeapFree(DAT_18026c330,0,default_connection);
          }
          else {
            FUN_1801f2010(default_connection);
          }
        }
        goto LAB_18001edfc;
      }
                    /* ERROR Invalid Parametr */
      SetLastError(0x57);
      if (((byte)DAT_180269148 & 8) != 0) {
        FUN_1801ea750(0x1f,&DAT_180204130,0x57);
      }
      if ((DAT_180269150 & 8) != 0) {
        uVar4 = 0x20;
        goto LAB_18001ef6f;
      }
    }
    else {
      SetLastError(error_code);
      if ((DAT_180269150 & 8) != 0) {
        uVar4 = 0x1e;
LAB_18001ef6f:
        FUN_1801ea750(uVar4,&DAT_180204130,0);
      }
    }
  }
  FUN_180021f70(&default_connection);
LAB_18001edfc:
  FUN_18014bd50(stack_cookie ^ (ulonglong)auStack_88);
  return;
}

