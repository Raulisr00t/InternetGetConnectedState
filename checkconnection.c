#include <windows.h>
#include <stdio.h>
#include <wininet.h>
// This API -> InternetGetConnectedState uses InternetGetConnectedStateEx function and it works not correctly , Check It when you develop user's internet connection depended apps

int CheckConnection() {
    DWORD flag;
    BOOL connected = InternetGetConnectedState(&flag, 0);
    
    if (connected == TRUE) {
        printf("[+] Internet Connection is UP\n");
        return EXIT_SUCCESS;
    }
    
    else {
        printf("[+] NO Internet Connection\n");
        return EXIT_FAILURE;
    }
}

int main(int argc, char **argv) {
    CheckConnection();
    
    return 0;
}
