#include"../head/SERVER.h"
int StartThread(cln *a)
{
    CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)SendMsg2AllServer,a,0,NULL);
    //printf("�û�%d�ѽ���,�߳��ѿ���",cln_num);
    return 0;
}
