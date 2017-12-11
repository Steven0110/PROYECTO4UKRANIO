#include "PaqueteDatagrama.cpp"
#include "SocketDatagrama.cpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <stdio.h>
using namespace std;
int main()
{
  int puerto = 7203;
  int k = 0;
  SocketDatagrama s(puerto);
  while(true){
    //Recibe una solicitud de status
    cout << "Esperando solicitud de Numero de Archivos..." << endl;
    PaqueteDatagrama p(8);
    s.recibe( p );
    char * code = (char *)p.obtieneDatos();
    if( code[ 0 ] == '3'){
      //Responde que está activa
      DIR *d;
      struct dirent *dir;
      d = opendir("../res");
      if (d){
        while ((dir = readdir(d)) != NULL){
          char *aux = dir->d_name;
          if( aux[ 0 ] != '.'){
          printf("%s\n", dir->d_name);
          k++;
          }
        }
        closedir(d);
      }
      printf("%d\n", k);
    //char msg[0] = k;
    string st(p.obtieneDireccion());
    PaqueteDatagrama r((char*)&k, 8,st, p.obtienePuerto());
    s.envia( r );
    k=0;
    }else continue;
  }
}
