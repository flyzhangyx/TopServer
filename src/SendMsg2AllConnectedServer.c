#include"../head/SERVER.h"
DWORD WINAPI SendMsg2AllServer(LPVOID b)
{
    cln* a=(cln*)b;
    char reccln[721];
    int len;
    USER Server;
    while(1)
    {
        memset(reccln,0,721);
        len=recv(a->remote_socket,reccln,721,0);
        if(len<=0)
        {
            delete_out_user(*a);
            break;
        }
        printf("\n%d:%s",len,reccln);
        Server = onlineUserHead->next;
        while(Server!=NULL)
        {
            len=send(Server->USER_socket,reccln,721,0);
            if(len==SOCKET_ERROR)
            {
                USER temp = Server;
                Server = Server ->next;
                cln tempcln;
                sprintf(tempcln.USERID,"%s",temp->USERID);
                delete_out_user(tempcln);
            }
            else
            {
                Server = Server ->next;
            }
        }
    }
    return 0;
}
