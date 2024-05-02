#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NCHAR 100 + 1

Item inputItem() {
  char *pString = malloc(NCHAR * sizeof(char));
  scanf("%s", pString);
  return pString;
}

void outputItem(Item item) {
  char *pString =
      item; // puntiamo all'inizio della stringa e non la stiamo copiando
  printf("%s\t", pString);
}

int compareItem(Item item1, Item item2) {
  char *pString1 = item1, *pString2 = item2;
  return strcmp(pString1, pString2) == 0;
}
