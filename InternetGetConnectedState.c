BOOL InternetGetConnectedState(longlong flag,longlong some_param)

{
  BOOL isconnected;
  
                    /* 0x11d6b0  293  InternetGetConnectedState */
  if ((DAT_180269150 & 8) != 0) {
    FUN_1801ed788(0x18,&DAT_18022f798,flag,some_param & 0xffffffffU);
  }
  if ((flag == 0) && ((DAT_180269150 & 8) != 0)) {
    FUN_1801ecb68(0x19,&DAT_18022f798);
  }
                    /* Checking Internet Connection via InternetGetConnectedStateEx API */
  isconnected = InternetGetConnectedStateExW(flag,0,0,some_param & 0xffffffffU);
  if ((DAT_180269150 & 8) != 0) {
    FUN_1801ea750(26,&DAT_18022f798,isconnected);
  }
  return isconnected;
}
