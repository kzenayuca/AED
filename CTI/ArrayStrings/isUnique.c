#include <stdio.h>
#include <stdlib.h>

int main(){
  char arr[] = "hola";

  int i;
  while(arr[i] != 0){
    i++;
  }

  printf("%d\n",i);

 // char *temp = "hola";
  //temp += 'a';
  //printf("%s \n",temp);

  return 0;
}
