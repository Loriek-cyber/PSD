#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "item.h"


struct list {
    int size;
    struct node *head;
	struct node *tail; //da fare
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
	if(pos<0 || pos>sizeList(list)){
		return 0;
	}
	
	if(pos==0){
		addHead(list,item);
		return 1;
	}
	
	struct node *p,*newNode;
	int i=0;
    for (p=list->head; p!=NULL && i<pos-1; p=p->next,i++);
	newNode=malloc(sizeof(struct node));
	newNode->value=item;
	newNode->next=p->next;
	p->next=newNode;
	list->size++;
	return 1;
}

int addListTail(List list, Item item){
	return addListPos(list,item,sizeList(list));
		
}

void reverseList(List list){
	struct node *p,*prev=NULL,*temp;
	for (p=list->head; p!=NULL; prev=p, p=temp){
		temp=p->next;
		p->next=prev;
	}
	list->head=prev;
	
}

List cloneList(List list){
	List clone=newList();
	struct node *p;
	for (p=list->head; p!=NULL; p=p->next){
		addListTail(clone,p->value);
	}
	return clone;
}

/*
swapElementPos scambia due elementi di posizione x e y
*/


int swapElementPos(List list, int pos1, int pos2){
	
	if(pos1>sizeList(list) && pos2>sizeList(list)) return 0;
	if(pos1<0 && pos2<0) return 0; // controlli
	
	struct node *p1;
	struct node *p;
	Item temp = malloc(sizeof(Item));


	//si sposta ai nodi interessati
	for (p=list->head; pos1 != 0 ; p=p->next,pos1--);
	for (p1=list->head; pos2 != 0 ; p1=p1->next,pos2--);

	temp = p1->value;
	p1->value = p->value;
	p->value = temp;

	return 1;
}

void sortList(List list){
	if(sizeList(list)<2) return;

	struct node *p;
	struct node *p2;
	
	int c1 = 0, c2 = 1;
	
	for (p=list->head; p!=NULL; p=p->next){
		for(p2 = p->next; p2!=NULL ;p2=p2->next){ //trova il minimo
			if((cmpItem(p->value,p2->value))>0) swapElementPos(list,c1,c2);
			c2++; //si segna i posti
		}
		c1++;
		c2 = c1 +1; //fa il resto alla poszione c1 + 1 cosi da non prendere in considerazione gli elementi prima visto che sarebbe inutile
	}
}
