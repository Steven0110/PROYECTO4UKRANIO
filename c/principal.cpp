#include "PaqueteDatagrama.cpp"
#include "SocketDatagrama.cpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;  
int main()
{
  int puerto = 7201;
  SocketDatagrama s(puerto);

  //char* extension=".txt";


  PaqueteDatagrama r(1024);
  //ofstream fs("archivo.txt");

  while(true){
  /*
  s.recibe(r);
    cout << "Datos recibidos: " << r.obtieneDatos() << endl;
    fs << r.obtieneDatos();
    fs.close();*/

    char* datos;
    char* nombreArchivo;
    s.recibe(r);
    nombreArchivo = (char *)malloc(1024);
    nombreArchivo= (char*)r.obtieneDatos();
    ofstream fs(nombreArchivo);
    //cout << "Nombre del archivo: " << r.obtieneDatos() << endl;
    printf("Nombre del archivo: %s\n", nombreArchivo);
    s.recibe(r);
    datos = (char *)malloc(1024);
    datos=(char*)r.obtieneDatos();
    //cout << "Datos recibidos: " << r.obtieneDatos() << endl;
    printf("Datos recibidos: %s\n", datos);
    fs << datos;
    fs.close();

  }
}

