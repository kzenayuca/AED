#include <stdio.h>
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
    return 0;
  return t->root->color == BLACK;
}

int blackHeight(RBNode *rbnode){
  if(rbnode == NULL){
    return (1);
  }else{
    int leftBH = blackHeight(rbnode->left);
    int rightBH = blackHeight(rbnode->right);
    
    if(leftBH - rightBH == 0){
      if(rbnode->color == BLACK)
        return (leftBH+1);
      else
        return leftBH;
    }else
      return (-1);
  }
}



void arbolPruebaExitosa(RBTree *t){
  RBNode* x = createRBNode(20);
  RBNode* y = createRBNode(18);
  RBNode* z = createRBNode(25);
  RBNode* w = createRBNode(23);
  RBNode* q = createRBNode(28);

  rbInsert(t,x);
  rbInsert(t,y);
  rbInsert(t,z);
  rbInsert(t,w);
  rbInsert(t,q);
}

void arbolEjemplo(RBTree *t){
  t->root = createRBNode(7);
  t->root->color = BLACK;

  RBNode *raiz = t->root;

  raiz->left = createRBNode(2);
  raiz->right = createRBNode(11);

  RBNode *left = raiz->left;
  RBNode *right = raiz->right;

  left->left = createRBNode(1);
  left->left->color = BLACK;
  left->right = createRBNode(5);
  left->right->color = BLACK;

  right->left = createRBNode(8);
  right->left->color = BLACK;
  right->right = createRBNode(14);
  right->right->color = BLACK;

  RBNode *cinco = left->right;
  cinco->left = createRBNode(4);
 // cinco->left->color = BLACK; //se rompe la propiedad

  RBNode *catorce = right->right;
  catorce->right = createRBNode(15);
}
int blackChildren(RBNode *rbnode){
  assert(rbnode != NULL);
  assert(!rbnode->color == BLACK);
  if(!rbnode->left && !rbnode->right){ //si ambos son NULL
    return 1;
  }
  //posibilidad a revisar : uno solo es NULL y el otro no
  if(rbnode->left->color == BLACK && rbnode->right->color == BLACK)
    return 1;
  else
    return 0;
}


//verificar que todos los nodos rojos tengan hijos negros.
int validateBlackChildren(RBNode *rbnode){
  if(rbnode == NULL){
    return 1;
  }else{
    if(rbnode->color == RED){
      if(!blackChildren(rbnode))
        return 0;
    }
    return validateBlackChildren(rbnode->left) &&
           validateBlackChildren(rbnode->right);
  }
}

int verifyRBTreeBalance(RBTree *rbtree){
  
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
    if(x == x->parent->left)
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

  x->right = y;
  y->parent = x;
}
void rbInsertFixUp(RBTree *t, RBNode *z){
  assert(t != NULL);
  assert(z != NULL);
  //assert(isRootBlack(t));
  //assert(z->parent != NULL);
  while( z->parent && z->parent->color == RED){
    RBNode* y;
    if(z->parent == z->parent->parent->left){
     // assert(z->parent->parent->right != NULL);
      y = z->parent->parent->right;
      if(y && y->color == RED){
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
      y = z->parent->parent->left; //que pasa si tu tio es NULL
      //assert(z->parent->parent->left != NULL);
      if(y && y->color == RED){
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      }else{
        if(z == z->parent->left){
          z = z->parent;
          rightRotate(t,z);
        }
        assert(z->parent != NULL);
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        leftRotate(t,z->parent->parent);
      }

    }
  }
  t->root->color = BLACK;

}
void rbInsert(RBTree *t, RBNode* z){
  assert(t != NULL);
  assert(z != NULL);
  //raiz
  RBNode* x = t->root;
  //padre a identificar
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

void deleteRBNode(RBTree *rbtree, int value){

}
/*
void print(RBTree *t){
  if(t == NULL){
    return 
  }
}
*/
