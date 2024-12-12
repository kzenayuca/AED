#ifndef HEAP_H
#define HEAP_H
#define N 30

#define PARENT(i) (i >> 1)

struct Heap{
  int arr[N];
  int heapSize;
};

void initHeap(struct Heap* heap);
int isEmpty(struct Heap* heap);
#endif

