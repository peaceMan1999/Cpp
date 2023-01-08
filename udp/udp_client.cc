#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <arpa/inet.h>
#include <netinet/in.h>
#define NUM 1024

void Usage(std::string msg)
{
    std::cout << "Usage: \n\t" << msg << " server_ip server_port " << std::endl;
}

int main(int argc, char *argv[])
{
    // 文档
    if (argc != 3){
        Usage(argv[0]);
        return 0;
    }
    // 1、建立套接字
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0){
        perror("sock err");
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    // 2、使用服务
    while (1)
    {
        std::string msg;
        std::cout << "请输入：";
        std::cin >> msg;
        sendto(sock, msg.c_str(), msg.size(), 0, (struct sockaddr*)&server, sizeof(server));

        struct sockaddr_in tmp;
        socklen_t len = sizeof(tmp);
        char buffer[NUM];
        recvfrom(sock, buffer, sizeof(buffer)-1, 0, (struct sockaddr*)&tmp, &len);
        std::cout << "server echo# " << buffer << std::endl;
    }
    return 0;
}
