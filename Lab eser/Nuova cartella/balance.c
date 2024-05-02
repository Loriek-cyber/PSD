#include "item.h"
#include "stack.h"
#define true 1
#define false 0


int isClose(char c) {
  if (c == ')' || c == ']' || c == '}')
    return true;
  else
    return false;
} // se una char è una parentesi aperta ritorna una true se no un false

int isOpen(char c) {
  if (c == '(' || c == '[' || c == '{')
    return true;
  else
    return false;
}  // se una char è una parentesi aperta ritorna una true se no un false

int Compare(char c, char d) {
  if (c == '(' && d == ')')
    return true;
  if (c == '[' && d == ']')
    return true;
  if (c == '{' && d == '}')
    return true;

  return false;
} // se il primo carrattere cioe c e il secondo carrattere d sono rispettivamente parentesi di apertura e chiusura dello 
// stesso tipo allora la funzione ritornerà true se no false

int is_balanced(char *str) {
  Stack stack = newStack();
  //creamo uno stack per inserire tutte le parentesi aperte
  for (; *str; str++) {
    if (isOpen(*str)) 
      push(stack, str);
      /*Controlliamo se la parentesi è aperta e la inseriamo nello stack precedentemente creato*/
    else if (isClose(*str)) {
      //adesso controlliamo se il carattere che *str sta puntando sia una parentesi di chiusura
      if (isEmptyStack(stack))
        return false; // se lo stack è vuoto è abbiamo trovato una parentesi di chiusura allora sicuramente non sarà bilanciato
      char *hop = top(stack); //creamo un puntatore di supporto per il primo elemento di top
      if (Compare(*hop, *str)) /*
      confrontiamo l'elemento corrente e il top della stack, se il risultato è positivo facciamo il pop
      se no allora ritorniamo un false
      */
        pop(stack);
      else
        return false;
    }
  }
  //se fino a questo punto lo stack è ancora pieno allora non è sicuramente bilanciato
  if (isEmptyStack(stack))
    return true;
  else
    return false;
}