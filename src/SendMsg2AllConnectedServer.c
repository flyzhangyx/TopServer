#include"../head/SERVER.h"
extern pthread_mutex_t t;
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
        pthread_mutex_lock(&t);
        if(len<=0)
        {
            delete_out_user(*a);
            pthread_mutex_unlock(&t);
            free(a);
            return 0;
        }
        printf("\nRecFrom %s: Len = %d\t|%s",inet_ntoa((a->ADDR.sin_addr)),len,reccln);
        if(reccln[0]=='H'&&reccln[1]=='B'&&reccln[2]=='A')
        {
            pthread_mutex_unlock(&t);
            continue;
        }
        Server = onlineUserHead->next;
        while(Server!=NULL)
        {
            printf("(*-*)");
            if((a->ADDR.sin_port==Server->USER_socket_udp.sin_port)&&!strcmp(inet_ntoa((a->ADDR.sin_addr)),inet_ntoa((Server->USER_socket_udp.sin_addr))))
            {
                Server = Server->next;
                continue;
            }
            len=send(Server->USER_socket,reccln,721,0);
            if(len==SOCKET_ERROR)
            {
                USER tmp = Server;
                Server = Server ->next;
                cln tmpcln;
                sprintf(tmpcln.USERID,"%s",tmp->USERID);
                delete_out_user(tmpcln);
            }
            else
            {
                Server = Server ->next;
            }
        }
        pthread_mutex_unlock(&t);
        printf("\n");
    }
    return 0;
}
