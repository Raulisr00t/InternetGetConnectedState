
int IsOfflineModeEnabled(void)

{
  int offline;
  int result;
  
  if (DAT_180268fe8 == 1) { // variable equals to 1 mainly if offline
    offline = 1;
  }
  else {
    if ((DAT_180268fe8 != 2) && (result = ApiSetQueryApiSetPresence(&DAT_1801f6658), -1 < result))  {
      DAT_180268fe8 = 2;
      return 0;
    }
    offline = 0;
  }
                    /* 
                    2 - > Cache that we're online 
                    1 - > Cache that's we're offline
                    */
  return offline;
}
