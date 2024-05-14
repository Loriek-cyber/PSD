#include <stdio.h>

int main(){
    int matricola;
    int resto;
    printf("inserisci le ultime 5 cifre matricola:");
    scanf("%d",&matricola);
    resto = matricola%3;
    if(resto == 0)while (1) printf("MUORI");
    printf("Il tuo resto è %d",resto);
}