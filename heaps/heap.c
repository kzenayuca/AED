#include "heap.h"
void initHeap(struct Heap* heap){
  heap->heapSize = 0;
}
int isEmpty(struct Heap* heap){
  return heap->heapSize == 0;
}
