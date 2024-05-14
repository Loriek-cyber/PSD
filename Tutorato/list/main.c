#include <stdio.h>
#include "list.h" 
#include "item.h"

int main(){

	Item item;
	int pos;
	List list=newList ();
	for (int i=0; i<5; i++){
		Item item = inputItem();
		addHead (list, item);
	}
	printList (list);
	transferList(list,1,2);
	printList(list);
	return 0;
}