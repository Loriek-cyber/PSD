#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "stack.h"


#define MAX 256

Stack reversestack(Stack stack,char *parametro){
	char *temp;
	Stack tempstack = newStack();
	while(top(stack)){
		temp = top(stack);
		pop(stack);
		if(strcmp(temp,parametro)>0)
			push(tempstack,temp);
	}
	free(stack);
	return tempstack;
}



int main() { // non modificare/spostare questa riga
	srand(time(NULL)); // non modificare/spostare questa riga

	FILE *fp = fopen("input.txt","r");
	if(fp == NULL) return -1;

	char Line[MAX];
	char *parametro = malloc(sizeof(char)*MAX);
	char *stritem = malloc(sizeof(char)*MAX);
	char *p;
	Item temp;

	while(fgets(Line,sizeof(Line),fp)){
		Stack stack = newStack();	
		p = Line;
		sscanf(p,"%s",parametro);
		if(*parametro == '!') parametro = randomItem();
		p = p+strlen(parametro)+1;
		printf("Parametro;  (%s) :\t",parametro);
		while((sscanf(p,"%s", stritem)) == 1){
			char *temp2 = malloc(sizeof(char)*strlen(stritem));
			if(*stritem != '!') {
				strcpy(temp2,stritem);
				temp = temp2;}
			else temp = randomItem();
			if(temp == NULL) break;
			push(stack,temp);
			p = p+strlen(stritem)+1;
		}
		printStack(stack);

		stack = reversestack(stack,parametro);
		printf("\nReverse stack:\t");
		printStack(stack);

		printf("\n");
		free(stack);
	}
	fclose(fp);
}
