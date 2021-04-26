#include"../head/SERVER.h"
extern pthread_mutex_t t;
int newOnlineUser(cln a)
{
    USER newuser=NULL;
    int n=0;
    do
    {
        newuser=(USER)malloc(sizeof(struct user));
        n++;
    }
    while(newuser==NULL&&n<100);
    if(n>99)
    {
        printf("can't add newuser");
        return -1;
    }
    ///******根据接口给节点初始化********
    strcpy(newuser->USERID,a.USERID);
    //strcpy(newuser->USERPASSWORD,a.USERPASSWORD);
    USER tmp = onlineUserHead->next;
    USER tmp1 = NULL;
    while(tmp!=NULL)
    {
        tmp1 = tmp;
        tmp = tmp->next;
    }
    newuser->USER_socket_udp=a.ADDR;
    newuser->USER_socket=a.remote_socket;
    newuser->next=NULL;
     pthread_mutex_lock(&t);
    if(onlineUserHead->next==tmp)
    {
        onlineUserHead->next=newuser;
    }
    else
    {
        tmp1->next = newuser;
    }
     pthread_mutex_unlock(&t);
    onlineUserHead->OnlineUserNum++;
    ///***********************************
    return 1;
}
