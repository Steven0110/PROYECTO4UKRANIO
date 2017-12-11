#include <dirent.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
  DIR *d;
  struct dirent *dir;
  d = opendir("../res");
  int k = 0;
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
}
