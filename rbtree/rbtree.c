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
  RBTree* newTree = (RBTree*)malloc(sizeof(RBTree));
  if(newTree == NULL){
    fprintf(stderr,"Error: No se pudo asignar memeoria para el arbol.\n");
    exit(EXIT_FAILURE);
  }
  newTree->root = NULL;
  return newTree;
}

int isRootBlack(RBTree *t){
  assert(t != NULL);
  if(!t->root) 
    return 1;
  return t->root->color == BLACK;
}

void leftRotate(RBTree *t, RBNode* x){
  assert(t != NULL);
  assert(x != NULL);

  RBNode* y = x->right;
  x->right = y->left; //asignacion de B

  if(y->left != NULL){
    y->left->parent = x;
  }

  y->parent = x->parent;
  
  if(x->parent ==  NULL){
    t->root = y;
  }else{
    if(x == x->parent->left;)
      x->parent->left = y;
    else
      x->parent->right = y;
    
  }
  y->left = x;
  x->parent = y;
}

//prueba
void rightRotate(RBTree *t, RBNode* y){
  assert(t != NULL);
  assert(y != NULL);
  //asignamos un nombre al hijo izq de y;
  RBNode* x = y->left;
  //cambio: el hijo izq de y apunta al hijo der de x
  y->left = x->right;
  //si el hijo der de x no es NULL hacemos que su puntero parent  apunte a y
  if(x->right != NULL)
    x->right->parent = y;
  //el padre de x ahora apunta al padre de y 
  x->parent = y->parent;
  //si y era raiz, ahora x va ser raiz
  if(y->parent == NULL)
    t->root = x;
  else{ //si no es el caso entonces
    //ubicamos x como hijo izq o der
    if(y == y->parent->left)
      y->parent->left = x;
    else
      y->parent->right = x;
  }

  x->left = y;
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
  assert(t != NULL);

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

  z->color = RED;
  rbInsertFixUp(t, z);
}

void print(RBTree *t){
  if(t == NULL){
    return 
  }
}
