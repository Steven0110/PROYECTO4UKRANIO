#include "PaqueteDatagrama.cpp"
#include "SocketDatagrama.cpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;  
int main()
{
  int puerto = 7202;
  SocketDatagrama s(puerto);
  while(true){
    //Recibe una solicitud de status
    cout << "Esperando solicitud de status..." << endl;
    PaqueteDatagrama p(8);
    s.recibe( p );
    char * code = (char *)p.obtieneDatos();
    if( code[ 0 ] == '2'){
      //Responde que está activa
    char msg[] = "asdas";
    string st(p.obtieneDireccion());
    PaqueteDatagrama r(msg, strlen(msg),st, p.obtienePuerto());
    s.envia( r );
    }else continue;
  }
}

