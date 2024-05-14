#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 100

// Tutte le funzioni sono state scritte nel file list.c

void printBello(List l, Item i){
  int pos;
  printList(l);
    if (searchList(l, i, &pos) != NULL) {
      printf("\nL'elemento e' stato trovato nella posizione %d\n", pos);
    } else
      printf("L'elemeto non e' stato trovato\n");
    printf("L'elemento e' stato trovato %d volte\n", numberListItem(l,i));
    printf("\n");
    delList(l);
}


int main() {

  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);

  List l = newList();
  char Line[Max];
  char *p;

  printf("Inserisci l'elemento da cercare:");
  Item qsearch = inputItem();
  
  while (fgets(Line, sizeof(Line), fp)!=NULL) {
    p = Line;
    while (*p!='\n' && *p) {
      char *temp = malloc(sizeof(char) * Max);
      sscanf(p, "%s", temp);
      addHead(l, temp);
      p += strlen(temp) + 1;
    }
    printBello(l,qsearch);
  }
  fclose(fp);
}
