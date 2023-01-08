#include <iostream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

const uint16_t port = 8080;
#define NUM 1024

int main()
{
    // 1、建立套接字
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0){
        perror("socket err");
    }

    struct sockaddr_in local;
    local.sin_family = AF_INET;
    local.sin_port = htons(port);
    local.sin_addr.s_addr = INADDR_ANY;

    // 2、绑定
    if (bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0){
        perror("bind err");
    }

    // 3、建立服务
    bool quit = false;
    char buffer[NUM];

    while(!quit){
        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);
        recvfrom(sock, buffer, sizeof(buffer)-1, 0, (struct sockaddr*)&peer, &len);

        // 输出
        std::cout << "clent# " << buffer << std::endl;

        std::string echo = "hello";
        sendto(sock, echo.c_str(), echo.size(), 0, (struct sockaddr*)&peer, len);
    }

    return 0;
}
