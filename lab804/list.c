#include <stdlib.h>
#include <stdio.h>
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
	printf("\n");
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
swap scambia le value di due nodi, ho precedentemente usato un'implementazione con gli Item, ma
ogni volta sostituiva solamente i titoli, è ho capito che la item puntava al primo puntatore della struct
cioe il title, questa implementazione ci permette di lavorare su ogni tipologia di item anche le struct
*/


void swap(struct node *item,struct node *item2){
	struct node *temp = malloc(sizeof(struct node));
	temp->value = item2->value;
	item2->value = item->value;
	item->value = temp->value;
}

/*
Trova il minimo in una funzioni partendo da un certo nodo p, cosi da lasciare tutti gli elementi
prima di p.

*/

struct node *minimo(struct node *p){
	struct node *i, *min = p;
	for  (i = p;  i != NULL; i = i->next){
		if((cmpItem(min->value,i->value))>0) min = i;
	}
	return min;
}

/*
Per ogni iterazione del for, cerchiamo un minimo partendo da p fino alla fine.
con lo swap cambiamo le value dei due nodi
*/

void SelectionSort(List list){
	struct node *p,*pos_minimo;
	for (p=list->head; p!=NULL;p=p->next){
		pos_minimo = minimo(p);
		swap(pos_minimo,p);
	}
}
