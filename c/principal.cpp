#include "PaqueteDatagrama.cpp"
#include "SocketDatagrama.cpp"
#include <iostream>
#include <fstream>
using namespace std;  
int main()
{
  int puerto = 7201;
  SocketDatagrama s(puerto);

  char* nombreArchivo;
  //char* extension=".txt";

  char* datos;

  PaqueteDatagrama r(1024);
  //ofstream fs("archivo.txt");

  while(true){
	/*
	s.recibe(r);
    cout << "Datos recibidos: " << r.obtieneDatos() << endl;
    fs << r.obtieneDatos();
    fs.close();*/

    s.recibe(r);
    nombreArchivo=NULL;
    nombreArchivo= (char*)r.obtieneDatos();
    ofstream fs(nombreArchivo);
    //cout << "Nombre del archivo: " << r.obtieneDatos() << endl;
    printf("Nombre del archivo: %s\n", nombreArchivo);
    s.recibe(r);
    datos=NULL;
    datos=(char*)r.obtieneDatos();
    //cout << "Datos recibidos: " << r.obtieneDatos() << endl;
    printf("Datos recibidos: %s\n", datos);
    fs << datos;
    fs.close();

  }
}

