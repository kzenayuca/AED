#include <stdio.h>
#include "heap.h"

int main(int argc, char* argv[]){
  int n = 14;
  printf("%d -> %d \n", n, PARENT(n));
}
