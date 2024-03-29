#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED
#include <stdio.h>
#include <WinSock2.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <direct.h>
#include <time.h>
#define BUFSIZ 512
///**************在线用户节点****************
struct user
{
    SOCKET USER_socket;
    SOCKADDR_IN USER_socket_udp;
    //SOCKADDR_IN USER_ADDR;
    char USERID[12];
    char USERPASSWORD[33];
    //char DATE[513];
    char info[100];
    struct user *next;
};
typedef struct user * USER;
 struct contact
{
    char checkcode[18];
    char USERID[12];
    char USERPASSWORD[33];
    char TalktoID[12];
    char info[10];
}contact ;
typedef struct contact * Contact;
 struct message
{
    char checkcode[18];
    char USERID[12];
    char USERPASSWORD[33];
    char TalktoID[12];
    char data[513];
} ;
typedef struct message * Message;
struct OnlineUserHead
{
    char DATE[100];
    char TIME[18];
    char info[100];
    int OnlineUserNum;
    USER  next;
};
///*******************************************
struct OnlineUserHead * onlineUserHead;
struct OnlineUserHead * RegistedUserHead;
///*****************接口**********************
typedef struct
{
    char checkcode[18];
    char USERID[12];
    char USERPASSWORD[33];
    char TalktoID[12];
    char REUSERPASSWORD[33];
    char DATA[513];
    char save[100];
} sendbag;
///********函数接口*************
typedef struct
{
    SOCKET remote_socket;
    SOCKADDR_IN ADDR;
    char USERID[12];
    char USERPASSWORD[33];
    char checkcode[18];
    char DATE[100];
    char TalktoID[12];
    char REUSERPASSWORD[33];
    char data[513];
    char info[100];//[0]是否注销登录,N_Y;
} cln;
typedef struct
{
    cln a;
    char filename[32];
    char file_lx[8];
    char file_path[32];
} tcp_send_interface;

///*****************************
///*******函数声明**************
int StartThread(cln* );
int AcceptClient();
int initServer();
int newOnlineUser(cln);
int delete_out_user(cln);
DWORD WINAPI SendMsg2AllServer(LPVOID b);
///*****************************
///***************各类标志码**********************
char CHECK[3];///应用进入时登陆检测是否已经注册
char SIGN_IN[3];///登陆码
char REGISTER[3];///注册码
char MESSAGE[3];///信息发送码
char TALK_TO[3];///通信目标地址码
char SIGN_OUT[3];///注销
char CONTACT[3];///联系人码
char REPWD[3];
///************************************************
///**********全局变量****************
SOCKET server_sockfd;//TCP服务器端套接字
SOCKET server_sockfd_udp;//UDP服务器端套接字
HANDLE cln_thread[200];
int cln_num;
int warnfile;
int logflag;
FILE* REGISTERlocal;
FILE* loginfo;
char app_version[4];
///**********************************
#endif // SERVER_H_INCLUDED
