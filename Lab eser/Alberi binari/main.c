#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "Btree.h"

int main(){
    
    Btree o = buildBtree(newBtree(),newBtree(),"o");
    Btree q = buildBtree(newBtree(),newBtree(),"q");
    Btree d = buildBtree(NULL,NULL,"q");
    Btree l = buildBtree(o,q,"l");
    
    preOrder(l);
}