#include "stock.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

struct stock{
    int value;
    int *data;
};

Stock InitStock(int value, int giorno, int mese, int anno, int ora, int minuto, int secondi){
    Stock stock = malloc(sizeof(struct stock));
    stock->value = value;
    int *data = malloc(sizeof(int)*6);
    data[0] = secondi;
    data[1] = minuto;
    data[2] = ora;
    data[3] = giorno;
    data[4] = mese;
    data[5] = anno;
    stock->data = data;
    return stock;
}

int gValue(Stock s){
    return s->value;
}

int *gData(Stock s){
    return s->data;
}