#include <stdio.h>
#include <stdlib.h>

int main(){

  char arr[] = "hola como estas";
  //un array de 3, tiene 4 casilleros.
  int i = 0;
  int spaces = 0;
  while(arr[i] != 0){
    if(arr[i] == ' ')
      spaces++;
    i++;
  }
  printf("len: %d , spaces: %d\n",i,spaces);


  int new_size = i-spaces + (3 * spaces) +1;
  char nuevo[new_size];
  for(int p = 0; p < new_size; p++){
    nuevo[p] = 'a';
  }
  nuevo[new_size] = '\0';

  int j = 0;
  int k = 0;
  while(nuevo[k] != 0){
    if(arr[j] == ' '){
      nuevo[k++] = '%';
      nuevo[k++] = '2';
      nuevo[k++] = '0';
      j++;
    }else{
      nuevo[k] = arr[j];
      k++;
      j++;
    }
  }
  int h = 0;
  while(nuevo[h] != 0){
    printf("%c",nuevo[h]);
    h++;
  }
  printf("\n");
}
