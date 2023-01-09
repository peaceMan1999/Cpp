#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cerrno>

void Usage(std::string msg)
{
  std::cout << "Usage: \n\t" << msg << " server_ip server_port " << std::endl;
}

int main(int argc, char *argv[])
{
  if (argc != 3){
    Usage(argv[0]);
    return 1;
  }

  // 1、创建套接字
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){
    std::cerr << "sock err" << std::endl;
    return 2;
  } 

  // 2、发起连接
  struct sockaddr_in server;
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[2]));
  server.sin_addr.s_addr = inet_addr(argv[1]);
  if (connect(sock,(struct sockaddr*)&server, sizeof(server)) < 0){
    std::cerr << "connect err" << std::endl;
  }

  std::cout << "connect success" << std::endl;

  // 3、发起服务
  while(1){
    std::cout << "Please enter# ";
    char buffer[1024];
    //memset(buffer, 0, sizeof(buffer));
    //getline(buffer, std::cin);
    fgets(buffer, sizeof(buffer)-1, stdin);

    write(sock, buffer, strlen(buffer));
    ssize_t s = read(sock, buffer, sizeof(buffer)-1);
    if (s > 0){
      buffer[s] = 0;
      std::cout << "server echo# " << buffer << std::endl;
    }
  } 


  return 0;
}
