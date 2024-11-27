#ifndef RBTREE_H
#define RBTREE_H
typedef enum {RED, BLACK} Color;
typedef struct sRBNode{
  struct sRBNode *parent;
  struct sRBNode *left;
  struct sRBNode *rigth;
  int key;
  Color color;
} RBNode;

RBNode* createRBNode(int key);

#endif

