#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "item.h"
#include "stack.h"

Item newItem(char *word) {  //Funzione di creazione item, partendo da una stringa
	char *a=malloc(sizeof(word));
	strcpy(a,word);
	return a;
}

void reverseStack(Stack *stackOrigin, Item param) { //Funzione che restituisce, sul puntatore dello Stack originale, lo Stack invertito e confrontato col parametro
	Stack stackNew=newStack(); //Creo un nuovo stack
	Item item;
	while(!(isEmptyStack(*stackOrigin))) { //Ciclo finché lo stack originale è vuoto, così prendo sicuramente tutti gli elementi dello stack
		item=top(*stackOrigin);
		if(compareItem(item,param)>0) push(stackNew,item); //Nel caso in cui rispetta la condizione col parametro, allora viene inserito nel nuovo stack
		pop(*stackOrigin); //Altrimenti non viene considerato e viene rimosso
	}
	*stackOrigin=stackNew; //Lo stack originale ora punta al nuovo stack calcolato
}


int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga
	FILE *fp=fopen("input.txt","r");
	Stack stack;
	char line[100], word[20];
	Item param, wordReal;
	char *linep, *linef;
	while(fgets(line,sizeof(line),fp)) {
		stack=newStack();
		linep=line;
		for(linef=line;*linef;linef++); //Mi calcolo il punto finale della stringa
		sscanf(linep,"%s",word); //Mi prendo la prima parola, che corrisponde al parametro
		if(word[0]=='!') param=randomItem(); //Nel caso in cui è un punto esclamativo, allora viene inserito in parametro una parola casuale
		else param=newItem(word); //Altrimenti viene inserita la parola data in input
		linep+=strlen(word)+1; //Salto sulla stringa fino alla nuova parola (+1 perché così saltiamo lo spazio)
		while(linep<linef) { //Andiamo avanti finché non finiamo la riga
			sscanf(linep,"%s ",word); //Prendo ogni parola
			linep+=strlen(word)+1; //Porto avanti il puntatore della riga
			if (strlen(word)>0) { //Nel caso in cui c'è una parola
				if(word[0]=='!') wordReal=randomItem(); //Se è un punto esclamativo, allora anche qui viene inserita una parola casuale
				else wordReal=newItem(word); //Altrimenti viene creato l'item con la parola trovata
				push(stack,wordReal); //E viene aggiunta allo Stack
			}
		}
		printf("Elemento parametro: %s\nStack originale: ",param); //Stampe finali
		printStack(stack);
		printf("\nStack invertito: ");
		reverseStack(&stack,param);
		printStack(stack);
		printf("\n\n");
		free(stack); //Libero lo stack
	}
}
