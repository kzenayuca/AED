#ifndef RBTREE_H
#define RBTREE_H
typedef enum {RED, BLACK} Color;
typedef struct sRBNode{
  struct sRBNode *parent;
  struct sRBNode *left;
  struct sRBNode *right;
  int key;
  Color color;
} RBNode;

RBNode* createRBNode(int key);

typedef struct {RBNode *root;} RBTree;

RBTree* createRBTree();

int isRootBlack(RBTree *t);

void rbInsert(RBTree *t, RBNode* z);

void leftRotate(RBTree *t, RBNode* x);
void rightRotate(RBTree *t, RBNode* y);

int blackHeight(RBNode *rbnode);
#endif

