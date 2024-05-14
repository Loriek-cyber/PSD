#include <stdlib.h>
#include "item.h"
#include "Btree.h"

struct node{
    Item value;
    struct node *left;
    struct node *right;
};

Btree newBtree(){
    return NULL;
}

int isEmpty(Btree b){
    if(b==NULL)
        return 1;
    else 
        return 0;
}

Btree buildBtree(Btree a,Btree b, Item h){
    Btree r = malloc(sizeof(struct node));
    r->left = a;
    r->right = b;
    r->value = h;
    return r; 
}

Item getBtreeRoot(Btree b){
    return b->value;
}

Btree getLeft(Btree b){
    return b->left;
}

Btree getRight(Btree b){
    return b->right;
}

void preOrder(Btree b){
    if(!isEmpty(b)){       
    outputItem(b->value);
    preOrder(b->left);
    preOrder(b->right);
    }
}

void postOrder(Btree b){
    if(!isEmpty(b)){       
    postOrder(b->left);
    postOrder(b->right);
    outputItem(b->value);
    }
}

void inOrder(Btree b){
    if(!isEmpty(b)){       
    inOrder(b->left);
    inOrder(b->right);
    outputItem(b->value);
    }
}
