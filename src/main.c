#include"../head/SERVER.h"
pthread_mutex_t t;
int main()
{
    pthread_mutex_init(&t,NULL);
    initServer();
    printf("服务器初始化成功！");
    AcceptClient();
    return 0;
}
