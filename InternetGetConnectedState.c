BOOL InternetGetConnectedState(longlong flags,undefined4 param2)

{
  BOOL isconnected;
  
                    /* 0x11d6b0  293  InternetGetConnectedState
                       If debug/log flag is set, log the function call with parameters */
  if ((debug_flags & 8) != 0) {
    FirstLogFunction(0x18,&log_context,flags,param2);
  }
  if ((flags == 0) && ((debug_flags & 8) != 0)) {
    SecondLogFunction(0x19,&log_context);
  }
                    /* // Main call to the extended version of the function */
  isconnected = InternetGetConnectedStateExW(flags,0,0,param2);
  if ((debug_flags & 8) != 0) {
    LogEvent(26,&log_context,isconnected);
  }
  return isconnected;
}
