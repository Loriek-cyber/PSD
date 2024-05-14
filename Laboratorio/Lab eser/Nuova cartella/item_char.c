#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Item inputItem() {
  char *pChar = malloc(sizeof(char));
  if (scanf("%c", pChar) > 0)
    return NULL;
  return pChar;
}

void outputItem(Item item) {
  char *pChar =
      item; // puntiamo all'inizio della stringa e non la stiamo copiando
  printf("%c ", *pChar);
}

int cmpItem(Item item1, Item item2) {
  char *pChar1 = item1, *pChar2 = item2;
  return strcmp(pChar1, pChar2);
}