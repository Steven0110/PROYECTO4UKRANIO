#include <string.h>
#include <iostream>
#include "PaqueteDatagrama.h"

using namespace std;


PaqueteDatagrama::PaqueteDatagrama(char *p, unsigned int i,string q, int x)
{
  datos = new char[i];
  longitud = i;
  memcpy(datos, p, longitud);
  strncpy(ip, q.c_str(), sizeof(ip));
  puerto = x;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int x){
  datos = new char[x];
}

PaqueteDatagrama::~PaqueteDatagrama()
{

}
char * PaqueteDatagrama::obtieneDireccion()
{
  return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud()
{
  return longitud;
}
int PaqueteDatagrama::obtienePuerto()
{
  return puerto;
}
char *PaqueteDatagrama::obtieneDatos()
{
  return datos;
}
void PaqueteDatagrama::inicializaPuerto(int x)
{
  puerto = x;
}
void PaqueteDatagrama::inicializaIp(string q)
{
  strncpy(ip, q.c_str(), sizeof(ip));
}
void PaqueteDatagrama::inicializaDatos(char *p)
{
  memcpy(datos, p, strlen(p));
}
