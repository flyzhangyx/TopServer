#include"../head/SERVER.h"
int AcceptClient()
{
    int sin_size;
    SOCKET clnt;
    SOCKADDR_IN a;
    sin_size=sizeof(struct sockaddr_in);
    while(1)
    {
        listen(server_sockfd,1);///�ȴ��ͻ����������󵽴�
        if((clnt=accept(server_sockfd,(struct sockaddr *)&a,&sin_size))==-1)
        {
            perror("accept");
            return -1;
        }
        cln_num++;
        printf("\naccept num %d client %s\n",cln_num,inet_ntoa(a.sin_addr));
        if(cln_num<20000)
        {
            cln b;
            b.remote_socket=clnt;
            b.ADDR=a;
            sprintf(b.USERID,"%d",cln_num);
            newOnlineUser(b);
            StartThread(&b);
        }
        else
        {
            printf("�����û�������");

        }
    }
    return 1;
}