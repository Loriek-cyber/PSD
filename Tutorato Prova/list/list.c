#include <stdlib.h>
#include "list.h"
#include "item.h"


struct list {
    int size;
    struct node *head;
};

struct node {
    Item value;
    struct node *next;
};


List newList(){
    List list=malloc(sizeof(struct list));
    list->size = 0;
    list->head = NULL;
    
    return list;
}

int isEmpty(List list){
    return list->size==0;
}

void addHead(List list, Item item){
    struct node *newNode= malloc(sizeof(struct node));
    newNode->value = item;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

Item removeHead(List list){
    if (isEmpty (list)) return NULL;
    struct node *temp= list->head;
    list->head = temp->next;
    Item item = temp->value;
    free (temp);
    list->size--;
    return item;
}

Item getHead(List list){
    if (isEmpty (list)) return NULL;
    return list->head->value;
}

int sizeList(List list){
    return list->size;
}

void printList(List list){
    struct node *p;
    for (p=list->head; p!=NULL; p=p->next)
        outputItem(p->value);
}

Item searchListItem(List list, Item item, int *pos){
	struct node *p;
	*pos=0;
    for (p=list->head; p!=NULL; p=p->next){
       if (cmpItem(item,p->value)==0){
		   return p->value;
	   }
	   (*pos)++;
	}
	*pos=-1;
	return NULL;
}
Item removeListItem(List list, Item item){
	Item temp;
	if (isEmpty(list))
		return NULL;
	struct node *p,*prev;
    for (p=list->head; p!=NULL; prev=p, p=p->next){
       if (cmpItem(item,p->value)==0){
			if(p==list->head)
				return removeHead(list);
			prev->next = p->next;
			temp = p->value;
			free (p);
			list->size--;
			return temp;
	   }
	
	}
	return NULL;
}

Item removeListPos(List list, int pos){
	Item temp;
	int cont=0;
	if (isEmpty(list) || pos<0 || pos>=sizeList(list))
		return NULL;
	struct node *p,*prev;
    for (p=list->head; p!=NULL; prev=p, p=p->next){
		if (pos==cont){
			if(p==list->head)
				return removeHead(list);
			prev->next = p->next;
			temp = p->value;
			free (p);
			list->size--;
			return temp;
			
		}
		cont++;
	}
	return NULL;
	
}

int addListPos(List list, Item item, int pos){
	if(pos>sizeList(list) || pos<0) 
		return 0;
	if(pos==0){
		addHead(list,item);
		return 1;}
	struct node *newnode = malloc(sizeof(struct node));
	struct node *now;
	int pos2 = 0;
	for (now = list->head ;  now != NULL  && pos2 != pos-1; now = now->next,pos2++);
	
	newnode ->value = item;
	newnode ->next = now->next;
	now -> next = newnode;
	list->size++;
	return 1;
}


int addListTail(List list, Item item){
	struct node *now;
	struct node *tail = malloc(sizeof(struct node));
	int size = 0;
	for (now = list->head ;  size == sizeList(list) ; size++,now = now->next);
	now->next = tail;
	tail->next = NULL;
	tail->value = item;
	return 1;
}

int transferList(List list, int p1, int p2){

	if(p1== p2) return -1;
	if(p1>sizeList(list) || p2>sizeList(list) || p1<0 || p2 < 0) return -1;

	struct node *pos1,*pos2,*temp;
	int cont1 = 0;
	int cont2 = 0;
	for (pos1 = list->head ;  pos1 != NULL  && cont1 != p1-1; pos1 = pos1->next,cont1++);
	for (pos2 = list->head ;  pos2 != NULL  && cont2 != p1-1; pos2 = pos2->next,cont2++);

	temp->next = pos1->next;
	pos1->next = pos2->next;
	pos2->next = temp->next;

	temp = temp->next;
	pos1 = pos1->next;
	pos2 = pos2->next;

	temp->next = pos1->next;
	pos1->next = pos2->next;
	pos2->next = temp->next;

	return 1;
}

void reverseList(List list);

List cloneList(List list){

}
List cloneListItem(List list);