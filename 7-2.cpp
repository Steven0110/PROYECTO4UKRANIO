#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

int main() {
  srand (time(NULL));
	int x,posicion, cont=0;
	char cadena[4];
	char *cadenota = NULL;
  //x = 1+rand () % 100000000;
  //cin >> x;
  x = 1757600;
  for(int i=0; i<x; i++){
				cadenota = (char *) realloc(cadenota, sizeof(char) * 4 * i+1);
				cadenota[i * 4] = ((char) abs(rand() % 26)) + 'A';
				cadenota[i * 4 + 1] = ((char) abs(rand() % 26)) + 'A';
				cadenota[i * 4 + 2] = ((char) abs(rand() % 26)) + 'A';
				cadenota[i * 4 + 3] = ' ';
        /*cadenota[i * 4] = 'I';
        cadenota[i * 4 + 1] = 'P';
        cadenota[i * 4 + 2] = 'N';
        cadenota[i * 4 + 3] = ' ';*/
  }
  //cout << cadenota << endl;
  //std::cout << x << '\n';
	cadenota[x * 4] = '\0';
	int l = 0;
	while("IPN"[++l]);
		for(int i = 0; i < x * 4; i+=4){
			for(int j = 0; j < l && cadenota[i+j] == "IPN"[j]; j++){
				if(j == l-1) cont++;
			}
		}
	cout << "Ocurrencias de IPN:" << cont << endl;
  return 0;
}
