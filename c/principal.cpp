#include "PaqueteDatagrama.cpp"
#include "SocketDatagrama.cpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

int main(){
  int puerto = 7201;
  SocketDatagrama s(puerto);
  fstream listaArchivos;
  string frase;

  
  while(true){
  	//listaArchivos.open("Lista de archivos.txt", ios::in);
    char* datos;
    char* nombreArchivo;
    PaqueteDatagrama r(1024);

    //Recibiendo nombre de archivo
    s.recibe(r);
    nombreArchivo = (char *)malloc(1024);
    nombreArchivo= (char*)r.obtieneDatos();
    ofstream fs(nombreArchivo);
 	printf("Nombre del archivo: %s\n", nombreArchivo);
    
 	listaArchivos.open("Lista de archivos.txt", ios::app);
 	if(listaArchivos.is_open()){ //Si lista de archivos esta abierto
 		//while (! listaArchivos.eof() ) { //Mientras no se llegue al fin del archivo
          //  getline (listaArchivos,frase);
           // cout << "Leido: " << frase << endl;
        //}
 		listaArchivos<< nombreArchivo<< '\n';
 		listaArchivos.close();
        //listaArchivos << nombreArchivo;
        //listaArchivos.close();
 	}
 	else{
 		cout << "Fichero inexistente o faltan permisos para abrirlo" << endl; 
 	}
    //Recibiendo contenido del archivo
    s.recibe(r);
    datos = (char *)malloc(1024);
    datos=(char*)r.obtieneDatos();

    printf("Datos recibidos: %s\n", datos);
    fs << datos;
    fs.close();

    //listaArchivos.close();
  }

}

