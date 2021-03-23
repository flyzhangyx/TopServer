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
        printf("\nRecFrom %s: Len = %d\t|%s",inet_ntoa((a->ADDR.sin_addr)),len,reccln);
        Server = onlineUserHead->next;
        while(Server!=NULL)
        {
            if((a->ADDR.sin_port==Server->USER_socket_udp.sin_port)&&!strcmp(inet_ntoa((a->ADDR.sin_addr)),inet_ntoa((Server->USER_socket_udp.sin_addr))))
            {
                Server = Server->next;
                continue;
            }

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
