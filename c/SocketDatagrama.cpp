#include <string.h>
#include <iostream>
#include <errno.h>
#include "SocketDatagrama.h"
using namespace std;


SocketDatagrama::SocketDatagrama(int puerto)
{
  pto = puerto;
  s = socket(AF_INET, SOCK_DGRAM, 0);
  bzero((char *)&direccionLocal, sizeof(direccionLocal));
  direccionLocal.sin_family = AF_INET;
  direccionLocal.sin_port = htons(puerto);
  bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
  timeout = false;
}

SocketDatagrama::~SocketDatagrama()
{
  close(s);
}
//Recibe un paquete tipo datagrama proveniente de este socket
int SocketDatagrama::recibe(PaqueteDatagrama & p)
{
  cout << "Esperando mensaje...\n";
  socklen_t clilen = sizeof(direccionForanea);

  char *data = p.obtieneDatos();
  recvfrom(s, (char *)data, 500,
              0, (struct sockaddr *)&direccionForanea, &clilen);
  
  char str[INET_ADDRSTRLEN];
  inet_ntop(AF_INET, &(direccionForanea.sin_addr), str, INET_ADDRSTRLEN);
  string dir(str);

  p.inicializaIp(str);
  p.inicializaPuerto(ntohs(direccionForanea.sin_port));

}

int SocketDatagrama::recibeTimeout(PaqueteDatagrama & p)
{
  //cout << "Esperando mensaje con timeout...\n";
  setTimeout(0, 50000);

  struct timeval tiempo1;
  struct timeval tiempo2;
  struct timeval res;

  socklen_t clilen = sizeof(direccionForanea);

  gettimeofday(&tiempo1, NULL);
  int n;
  n = recvfrom(s, (char *)p.obtieneDatos(), 500,
              0, (struct sockaddr *)&direccionForanea, &clilen);

  if(n < 0){
      /*if(errno == EWOULDBLOCK)
        fprintf(stderr, "Tiempo de recepción transcurrido\n");
      else
        fprintf(stderr, "Error en recvfrom\n");*/

  }else{
    gettimeofday(&tiempo2, NULL);
    //cout << "El mensaje es: " << p.obtieneDatos() << "\n";
    //printf("%s\n", p.obtieneDatos());
    unsigned char direc[4];
    memcpy(direc, &direccionForanea.sin_addr.s_addr, 4);
    printf("Mensaje recibido por %d.%d.%d.%d ", direc[0],direc[1],direc[2],direc[3]);
    cout << "en el puerto " << ntohs(direccionForanea.sin_port) << "\n";
    res.tv_sec = tiempo2.tv_sec - tiempo1.tv_sec;
    res.tv_usec = tiempo2.tv_usec - tiempo1.tv_usec;
    cout << "Tiempo en recibir el mensaje:" << endl;
    printf("Segundos: %ld\n", res.tv_sec);
    printf("Microsegundos: %ld\n", res.tv_usec);
  }

}
//Envía un paquete tipo datagrama desde este socket
int SocketDatagrama::envia(PaqueteDatagrama & p)
{

    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());

    socklen_t clilen = sizeof(direccionForanea);

    //cout << "Enviado al " << p.obtieneDireccion() << endl;
    //cout << "por el puerto " << p.obtienePuerto() << endl;

    sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr*)&direccionForanea, clilen);
}

void SocketDatagrama::setTimeout(time_t segundos, suseconds_t microsegundos)
{
    tiempofuera.tv_sec = segundos;
    tiempofuera.tv_usec = microsegundos;
    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&tiempofuera, sizeof(tiempofuera));
    timeout = true;
    return;
}
void SocketDatagrama::unsetTimeout()
{
    tiempofuera.tv_sec = 0;
    tiempofuera.tv_usec = 0;
    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&tiempofuera, sizeof(tiempofuera));
    timeout = false;
    return;
}
