#include <stdio.h>
#include "rbtree.h"

int main(){
  RBTree* t = createRBTree();
  arbolEjemplo(t);
  RBNode* x = createRBNode(1);
  RBNode* y = createRBNode(2);
  RBNode* z = createRBNode(4);
  RBNode* w = createRBNode(5);
  RBNode* q = createRBNode(7);

  //rbInsert(t,x);
  //rbInsert(t,y);
  //rbInsert(t,z);
  //rbInsert(t,w);
  //rbInsert(t,q);
  //rbInsert(t,createRBNode(8));
  //rbInsert(t,createRBNode(11));
  //rbInsert(t,createRBNode(14));
  //rbInsert(t,createRBNode(15));

  int bh = blackHeight(t->root);
  printf("Altura negra: %d \n",bh);
}
