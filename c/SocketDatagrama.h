#ifndef SOCKETDATAGRAMA_H_
#define SOCKETDATAGRAMA_H_

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <sys/time.h>
#include <string>
using namespace std;
#include "PaqueteDatagrama.h"

class SocketDatagrama{
  public:
    SocketDatagrama(int);
    ~SocketDatagrama();
    //Recibe un paquete tipo datagrama proveniente de este socket
    int recibe(PaqueteDatagrama & p);
    int recibeTimeout(PaqueteDatagrama & p);
    //Envía un paquete tipo datagrama desde este socket
    int envia(PaqueteDatagrama & p);

    void setTimeout(time_t segundos, suseconds_t microsegundos);
    void unsetTimeout();
  private:
    struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    int s; //ID socket
    int pto;

    struct timeval tiempofuera;
    bool timeout;
};

#endif
