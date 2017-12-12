#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "PaqueteDatagrama.cpp"
#include "SocketDatagrama.cpp"
#include <fstream>
using namespace std;

int length( char * cad ){
    int i = 0;
    while( 1 ){
        if( (isalpha(cad[ i ]) || cad[ i ] == ' ' )|| cad[ i ] == '.'){

        }else
            break;
        i++;
    }
    return --i;
}
const char * concat( char * str ){
    int cad_len = length( str );
    char * aux = (char *)malloc( sizeof( char ) * (cad_len + 7));
    char res[] = "../res/";
    int i = 0;
    for( i = 0 ; i < 7 ; i++ ){
        aux[ i ] = res[ i ];
    }
    int k = 0;
    for( ; i < cad_len + 7 ; i++){
        aux[ i ] = str[ k++ ];
    }
    return (const char *)aux;
}
int main(void){


      int puerto = 7201;
      SocketDatagrama s(puerto);
      while(true){
        cout << "Esperando mínimo de búsqueda..." << endl;   
        PaqueteDatagrama p(1);
        s.recibe( p );
        char * data = (char *)p.obtieneDatos();
        int min = data[ 0 ] - 48;
        cout << min << endl;
        cout << "Esperando máximo de búsqueda..." << endl;   
        PaqueteDatagrama p2(1);
        s.recibe( p2 );
        char * data2 = (char *)p2.obtieneDatos();
        int max = data2[ 0 ] - 48;
        cout << max << endl;
        cout << "Esperando caracter de búsqueda..." << endl;   
        PaqueteDatagrama p3(1);
        s.recibe( p3 );
        char * aux = (char *)p3.obtieneDatos();
        cout << "Data: " << aux << endl ;
        cout << aux[ 0 ];


                DIR *d;
                struct dirent *dir;
                d = opendir("../res/");
                int k = 0;
                if (d){
                    int cont = 0;
                    while ((dir = readdir(d)) != NULL){
                        char *aux = dir->d_name;
                        if( aux[ 0 ] != '.'){
                            if( cont >= 0 && cont <= 3) {
                                string sx = "../res/";
                                sx += dir->d_name;
                                //cout << s << endl;
                                //Busqueda en archivo:
                                int c;
                                FILE *file;
                                file = fopen( sx.c_str() , "r");
                                int aux_cont = 0;
                                int total_coinc = 0;
                                if (file) {
                                    while ((c = getc(file)) != EOF){
                                        //putchar(c);
                                        if( c == aux[ 0 ] ){
                                            total_coinc++;
                                            cout << "Coincidencia" << endl;
                                            printf("%c", c);
                                            printf("%c", aux[0]);
                                        }
                                    }
                                    string res = "Se encontraron ";


                                    string k = std::to_string( total_coinc );
                                    res += k;
                                    res += " coincidencias en ";
                                    res += sx;
                                    cout << res << endl;
                                    //Envía el dataggrama con res

                                      char *y = new char[res.length() + 1];
                                      strcpy(y, res.c_str());
                                      string st(p.obtieneDireccion());
                                      PaqueteDatagrama r(y, strlen(y),st, p.obtienePuerto());
                                      s.envia( r );
                                    fclose(file);
                                }




                            }
                            cont++;
                        }
                    }
                    closedir(d);
                }

      }


                
}