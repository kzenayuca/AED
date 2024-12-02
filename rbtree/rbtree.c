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
  assert( x != NULL);
  RBNode* y = x->right;
  RBNode* Yparent = y->parent; //no necesario.
  RBNode* Xparent = x->parent;
  RBNode* B = y->left;

  if(y->left){ //no necesario, 
    x->right = y->left;
    y->left->parent = x;
  }
  else
    x->right = NULL;
  //aqui fuera x->right = y->left;
  
  y->left = x;
  
  y->parent  = Xparent;
  x->parent = y;
}

//prueba
void rightRotate(RBTree *t, RBNode* y){
  assert(y != NULL);
  RBNode* x = y->left;
  assert(x != NULL);
  RBNode* Yparent = y->parent;
  RBNode* Xparent = x->parent;


  if(x->right){
    y->left = x->right;
    x->right->parent = y;
  }
  else
    y->left = NULL;
  

  x->right = y;

  x->parent = Yparent;
  y->parent = x; 

}
void rbInsertFixUp(RBTree *t, RBNode *z){
  while( z->parent && z->parent->color == RED){
    RBNode* y;
    if(z->parent == z->parent->parent->right){
      y = z->parent->parent->right;
      if(y->color == RED){
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      }else{
        if(z == z->parent->right){
          z = z->parent;
          leftRotate(t,z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        rightRotate(t,z->parent->parent);
      }
    }else{
      y = z->parent->parent->left;
      if(y->color == RED){
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      }else{
        if(z == z->parent->right){
          z = z->parent;
          rightRotate(t,z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        leftRotate(t,z->parent->parent);
      }

    }
    t->root->color = BLACK;
  }


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
  rbInsertFixUp(t, z);
}

void print(RBTree *t){
  if(t == NULL){
    return 
  }
}
