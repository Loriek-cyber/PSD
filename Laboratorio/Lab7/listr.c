#include "item.h"
#include "list.h"
#include <stdlib.h>

//Versione di Lista con Funzioni Ricorsive

//Uguale alla list.h \\Inizio
struct list {
  int size;
  struct node *head;
};

struct node {
  Item value;
  struct node *next;
};

List newList() {
  List list = malloc(sizeof(struct list));
  list->size = 0;
  list->head = NULL;

  return list;
}

int isEmpty(List l) { return (l->size == 0 ? 1 : 0); }

void addHead(List l, Item a) {
  struct node *n = malloc(sizeof(struct node));
  n->value = a;
  n->next = l->head;
  l->head = n;

  (l->size)++;
}
Item removeHead(List l) {
  Item a;
  if (isEmpty(l))
    return NULL;

  struct node *tmp = l->head;
  l->head = l->head->next;
  a = tmp->value;
  free(tmp);
  (l->size)--;
  return a;
}

Item getHead(List l) {
  if (isEmpty(l))
    return NULL;
  else
    return (l->head->value);
}
int sizeList(List l) { return l->size; }
//fine

// Inzio sezione printList Ricorsiva
void subprint(struct node *p) {
  if (p != NULL) { //condizione base
    outputItem(p->value); 
    subprint(p->next); // Richiamo della funzione con il nodo successivo
  } else
      return; // la funzione ritorna un valore positivo se trova un NUll come
}

void printList(List list) { 
  subprint(list->head); //Per fare in modo che la funzione printList sia identica alla sua controparte non ricorsiva
  //ho creato la funzione subprint che fa il lavoro principale invece printList è solo una chiamata 
}


/*
Search list Item restituisce l'item è la posizione dell'item
anche la sua controparte fa la stessa cosa e quindi ho dovuto usare lo stesso strattagema anche qui

*/

Item subsearch(struct node *p, Item item, int *pos) {
  if (p == NULL) {
    *pos = -1;
    return NULL;
  } // se siamo al NULL cioe all'ultimo p->next allora la funzione ritorna NULL
  
  if (compareItem(p->value, item)) {
    return p->value; // se l'item attuale e l'item passatto dal caller saranno uguali allora la funzione ritornera l'item stesso
  } else {
    (*pos) += 1; //se no per prima cosa aumentiamo il pos e poi facciamo la ricorsione al successivo
    return subsearch(p->next, item, pos);
  }
}

Item searchList(List list, Item item, int *pos) {
  *pos = 0; //assegnamo pos a zero poiche staremmo nella testa
  if(isEmpty(list)){
    pos = -1;
    return NULL;
  } //condizione per velocizzare il codice
  return subsearch(list->head, item, pos); //diamo il primo nodo a subserch
}

//la subnumber conta ogni nodo 1 a 1 fino a quando non si trova alla fine allora ritornerà il valore dell'accumulatore cioe i
int subnumber(struct node *p, Item item, int *i) {
  if (p == NULL)
    return *i;
  if (compareItem(p->value, item))
    (*i)++;
  return subnumber(p->next, item, i);
}

// funzione rieorsiva che conta quante volte compare un elemento nella lista
int numberListItem(List list, Item item) {
  int i = 0;
  if (isEmpty(list))
    return 0;
  return subnumber(list->head, item, &i);
}

// DelList dealloca la memoria della lista;

void delNode(struct node *p) {
  if (p == NULL) {
    return; // quando arriva alla p == Null il resto del programma si ferma
  }
  delNode(p->next); // funzione ricorsiva che si ferma quando p->next == Null
                    // cioe all'ultimo elemento
  free(p->value);   // Dealloca l'item del nodo corrente
  free(p);          // Dealloca il nodo
}
void delList(List list) {
  if (isEmpty(list)) {
    return;
  }
  delNode(list->head); // fa partire la funzione delNode
  list->size = 0;      // Imposta la size a zero
  list->head = NULL;   // Imposta la testa a NULL
}