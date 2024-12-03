#include <stdio.h>
#include "rbtree.h"

int main(){
  RBTree* t = createRBTree();
  //arbolEjemplo(t);
  //arbolPruebaExitosa(t);
  
  RBNode* x = createRBNode(1);
  RBNode* y = createRBNode(2);
  RBNode* z = createRBNode(4);
  RBNode* w = createRBNode(5);
  RBNode* q = createRBNode(7);
  
  RBNode* a = createRBNode(8);
  RBNode* b = createRBNode(11);
  RBNode* c = createRBNode(14);
  RBNode* d = createRBNode(15);
  rbInsert(t,x);
  rbInsert(t,y);
  rbInsert(t,z);
  rbInsert(t,w);
  rbInsert(t,q);
  rbInsert(t,a);
  rbInsert(t,b);
  rbInsert(t,c);
  rbInsert(t,d);
  
  int bh = blackHeight(t->root);
  printf("Altura negra: %d \n",bh);
}
