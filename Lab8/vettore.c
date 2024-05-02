#include <stdlib.h>
#include <stdio.h>
#include "item.h"

Item *NewVettore(int n){
    Item *vettore = malloc(sizeof(Item)*n);
    for (int i = 0; i < n; i++)
        vettore[i] = inputItem();
    return vettore;
}

void printVettore(Item *vettore, int n){
    if(n == 0) 
        return;
    outputItem(*vettore);
    printVettore(vettore+1,n-1);
}


/*

La funzione minimo è ricorsiva e viene chiamatan volte all'interno della funzione SelectionSort. 
Ogni chiamata minimo scorre attraverso un sottoinsieme dell'array, riducendo la dimensione di tale 
sottoinsieme ad ogni chiamata. Quindi, la complessità totale della funzione minimo è

O(n+(n−1)+(n−2)+...+1)\=O(n2)

*/


Item minimo(Item *vet,int n,Item m){
    if(n == 0) 
        return m;
    if(compareItem(*vet,m)<0)
        m = *vet;
    return minimo(vet+1,n-1,m);
}


void swap(Item *a, Item *b){
    Item *t = malloc(sizeof(a)); 
    *t = *a;
    *a = *b;
    *b = *t;
    free(t);
}

/*

La funzione SelectionSort è anch'essa ricorsiva e viene chiamata nnn volte. 
Ogni chiamata SelectionSort esegue un numero costante di operazioni 
(in particolare, una chiamata a `minimo` e una a swap). 
Pertanto, la complessità totale di SelectionSort è O(n^2)

*/

void SelectionSort(Item *vet,int n){
    if(n == 0)
        return ;
    swap(*vet,minimo(vet,n,*vet));
    SelectionSort(vet+1,n-1);
}