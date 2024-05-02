#include "balance.h" // header che si occupa della funzione is_balance
#include <stdio.h>

int main() {
  char temp[100];
  scanf(" %[^\n]", temp);

  if (is_balanced(temp) == 1) {
    printf("Parentesi bilanciate\n");
  } else {
    printf("Parentesi non bilanciate\n");
  }
}
