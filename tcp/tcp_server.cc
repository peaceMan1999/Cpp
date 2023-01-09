#include <iostream>
#include <signal.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cerrno>
#include <unistd.h>


void Usage(std::string msg)
{
  std::cout << "Usage: \n\t" << msg << " port "<< std::endl;
}

void Server(int sock)
{
  while(1)
  {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    ssize_t s = read(sock, buffer, sizeof(buffer)-1);
    if (s > 0){
      buffer[s] = 0;
      std::cout << "client# " << buffer << std::endl;

      std::string echo = "server# ";
      echo += buffer;
      write(sock, echo.c_str(), echo.size());
    }else if (s == 0){
      std::cout << "client quit......" << std::endl;
      break;
    }else{
      // err
    }
  }
}


int main(int argc, char *argv[])
{
  if (argc != 2){
    Usage(argv[0]);
    return 1;
  }

  // 1、建立套接字
  int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_sock < 0){
    std::cerr << "sock err" << errno << std::endl;
    return 2;
  }

  struct sockaddr_in local;
  memset(&local, 0, sizeof(local));
  local.sin_family = AF_INET;
  local.sin_port = htons(atoi(argv[1]));
  local.sin_addr.s_addr = INADDR_ANY;

  // 2、绑定
  if (bind(listen_sock, (struct sockaddr*)&local, sizeof(local)) < 0){
    std::cerr << "bind err" << errno << std::endl;
    return 3;
  }

  // 3、监听
  int backlog = 5;
  if (listen(listen_sock, backlog) < 0){
    std::cerr << "listen err" << errno << std::endl;
    return 4;
  }
  
  // 忽略信号
  signal(SIGCHLD, SIG_IGN);
  // 4、建立服务
  for (;;){
    struct sockaddr_in peer;
    memset(&peer, 0, sizeof(peer));
    socklen_t len = sizeof(peer);
    int new_sock = accept(listen_sock, (struct sockaddr*)&peer, &len);
    if (new_sock < 0){
      continue;
    }
    std::cout << "listen success" << std::endl;
    
    pid_t id = fork();
    if (id == 0){
      Server(new_sock);
    }else if (id < 0){
      continue;
    }else{
      //father
    }

  }



  return 0;
}
