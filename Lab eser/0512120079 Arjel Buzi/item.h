// 1) creare un item.h
// con tutti i suoi prototipi

#include <stdio.h>
#include <stdlib.h>

typedef void *Item;

Item inputItem();
void outputItem(Item);
int cmpItem(Item, Item);