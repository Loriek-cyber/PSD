#include "item.h"

typedef struct list *List;

List newList();
int isEmpty(List);
void addHead(List, Item);
Item removeHead(List);
Item getHead(List);
int sizeList(List);
void printList(List);

Item searchList(List, Item, int *);
int numberListItem(List list, Item item);
void delList(List list);


