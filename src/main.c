#include"../head/SERVER.h"
pthread_mutex_t t;
int main()
{
    pthread_mutex_init(&t,NULL);
    initServer();
    printf("��������ʼ���ɹ���");
    AcceptClient();
    return 0;
}
