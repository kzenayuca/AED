#include <stdlib.h>
#include <assert.h>
#include "rbtree.h"

RBNode* createRBNode(int key){
  RBNode* newNode = malloc(sizeof(RBNode));
  newNode->parent = NULL;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->key = key;
  newNode->color = RED;
  return newNode;
}

RBTree* createRBTree(){
  RBTree* t = malloc(sizeof(RBTree));
  t->root = NULL;
  return t;
}

int isRootBlack(RBTree *t){
  if(!t->root) return 1;
  return t->root->color == BLACK;
}

void leftRotate(RBTree *t, RBNode* x){
  RBNode* y = x->right;
  RBNode* Yparent = y->parent;
  RBNode* Xparent = x->parent;

  if(y->left){
    x->right = y->left;
    y->left->parent = x;
  }
  else
    x->right = NULL;
  

  y->left = x;

  Yparent = Xparent;
  Xparent = y;

}

void rightRotate(RBTree *t, RBNode* y){
  RBNode* x = y->left;
  RBNode* Yparent = y->parent;
  RBNode* Xparent = x->parent;

  if(x->right){
    y->left = x->right;
    x->right->parent = y;
  }
  else
    y->left = NULL;
  

  x->right = y;

  Xparent = Yparent;
  Yparent = x; 

}

void rbInsert(RBTree *t, RBNode* z){
  RBNode* x = t->root;
  RBNode* y = NULL;

  while(x){
    y = x;
    if(z->key < x->key)
      x = x->left;
    else 
      x = x->right;
  }

  z->parent = y;

  if(!y)
    t->root = z;
  else{
    if(z->key < y->key)
      y->left = z;
    else
      y->right = z;
  }
  //rbInsertFixUp(t, z);
}

