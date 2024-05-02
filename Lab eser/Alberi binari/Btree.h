#include "item.h"
typedef struct node *Btree;
Btree newBtree();
int isEmpty(Btree b);
Btree buildBtree(Btree a,Btree b, Item h);
Item getBtreeRoot(Btree b);
Btree getLeft(Btree b);
Btree getRight(Btree b);
void preOrder(Btree b);
void postOrder(Btree b);
