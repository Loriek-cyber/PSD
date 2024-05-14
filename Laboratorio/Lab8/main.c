#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "vettore.h"

int main(void){
    Item *vettore = NewVettore(5);
    printVettore(vettore,5);
    SelectionSort(vettore,5);
    printf("\n");
    printVettore(vettore,5);
    free(vettore);
}