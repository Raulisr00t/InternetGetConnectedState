
void InternetGetConnectedStateExW
               (uint *status,LPWSTR connection_name,int connection_name_len,int param4)

{
  uint uVar1;
  char returned_char;
  DWORD error_code;
  int r;
  int isconnectedstate;
  undefined4 result;
  undefined8 uVar2;
  uint flags;
  int use_connection_name;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
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
    Log(0x1c,&DAT_180204130,status,connection_name);
  }
                    /* Initialize Local Vars
                       Default fallback connection name pointer */
  default_connection = &DAT_18022b110;
  isconnectedstate = 0;
  use_connection_name = 0;
  local_48 = 0;
  puVar4 = (undefined2 *)0x0;
  if (status != (uint *)0x0) {
    *status = 0;
  }
  if (connection_name != (LPWSTR)0x0) {
    *connection_name = L'\0';
  }
                    /* Check If system is in "Offline Mode" */
  returned_char = IsOfflineModeEnabled();
  if (returned_char == '\0') {
                    /* If not offline, use fallback connectivity check
                       Called if not offline; sets status, maybe checks adapter/DNS. */
    result = FallbackConnectivityCheck(status,connection_name,connection_name_len);
    if ((DAT_180269150 & 8) != 0) {
                    /* Log the result if needed */
      LogEvent(0x1d,&DAT_180204130,result);
    }
  }
  else {
    error_code = CheckConnection();
    if (error_code == 0) {
      if (param4 == 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_18026ac70);
        r = GetConfiguredConnection(&default_connection);
        puVar5 = default_connection;
        flags = 0x10;
        if (r == 0) {
          r = CheckForLANConnection();
          puVar5 = (undefined2 *)0x0;
          iVar3 = 0;
          if (r != 0) {
            flags = 0x12;
            isconnectedstate = TestInternetConnectivity(0,0,0);
            puVar5 = puVar4;
            iVar3 = use_connection_name;
            if ((connection_name != (LPWSTR)0x0) && (connection_name_len != 0)) {
              LoadStringW(DAT_18026b860,0xfad,connection_name,connection_name_len);
            }
          }
        }
        else {
          flags = 0x11;
          iVar3 = 1;
                    /* Final Internet Connectionn Test I assume */
          isconnectedstate = TestInternetConnectivity(default_connection,0,0);
        }
        if (isconnectedstate != 0) {
          iVar3 = 1;
        }
        uVar1 = flags | 4;
        if (isconnectedstate == 0) {
          uVar1 = flags;
        }
        local_58 = iVar3;
        if ((((connection_name != (LPWSTR)0x0) && (connection_name_len != 0)) &&
            (puVar5 != (undefined2 *)0x0)) &&
           (isconnectedstate = FUN_1800fec64(connection_name,connection_name_len,puVar5,0x101),
           isconnectedstate < 0)) {
          if ((DAT_180269150 & 8) != 0) {
            LogEvent(0x21,&DAT_180204130,isconnectedstate);
          }
          *connection_name = L'\0';
          error_code = 0x7a;
          if (isconnectedstate != -0x7ff8ff86) {
            error_code = 0x57;
          }
          SetLastError(error_code);
        }
        if (status != (uint *)0x0) {
          flags = uVar1 | 0x40;
          if (local_58 == 0) {
            flags = uVar1;
          }
          *status = flags;
        }
        if ((DAT_180269150 & 8) != 0) {
          LogEvent(0x22,&DAT_180204130,r);
        }
        SetLastError(0);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_18026ac70);
        if ((default_connection != &DAT_18022b110) && (default_connection != (undefined2 *)0x0)) {
          if (DAT_18026c328 == 0) {
            HeapFree(DAT_18026c330,0,default_connection);
          }
          else {
            CustomFree(default_connection);
          }
        }
        goto CleanUP;
      }
                    /* ERROR Invalid Parametr */
      SetLastError(0x57);
      if (((byte)DAT_180269148 & 8) != 0) {
        LogEvent(0x1f,&DAT_180204130,0x57);
      }
      if ((DAT_180269150 & 8) != 0) {
        uVar2 = 0x20;
        goto LAB_18001ef6f;
      }
    }
    else {
      SetLastError(error_code);
      if ((DAT_180269150 & 8) != 0) {
        uVar2 = 0x1e;
LAB_18001ef6f:
        LogEvent(uVar2,&DAT_180204130,0);
      }
    }
  }
  CleanupConnectionPointer(&default_connection);

CleanUP:

  VerifyStackCookie(stack_cookie ^ (ulonglong)auStack_88);
  
  return;
}

