#include <stdio.h>
#include "btree.h"

int height(BTree bt) {
	return 0;
	// da scrivere
}

int* sumByLevel(BTree bt){
	return NULL;
	// da scrivere
}

void printHeightAndSumByLevel(BTree bt) {
	printf("Albero:\n");
	printTree(bt);
	int h = height(bt);
	printf("Altezza albero: %d\n", h);
	printf("Somma nodi per ogni livello: ");
	int* sums = sumByLevel(bt);

	for(int i = 0; i <= h; i++) {
		printf("%d ", sums[i]);
	}
	printf("\n\n");
}

int main(){
	// printHeightAndSumByLevel(aTree);
	// da scrivere
}

