#include"../head/SERVER.h"
int StartThread(cln *a)
{
    CloseHandle(CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)SendMsg2AllServer,a,0,NULL));
    return 0;
}
