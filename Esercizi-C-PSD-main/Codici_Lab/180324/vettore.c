#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#define FALSE 0
#define TRUE 1

/*
 * Estrae un array da una stringa. Muove il puntatore pos per indicare la posizione dopo il primo array già scansionato.
 * Se pos è diverso da 0, sposta la posizione di calcolo dell'array dopo il primo già scansionato. Altrimenti, sposta la posizione
 * di pos tutti i caratteri scansionati prima più 3 per saltare il carattere di separazione e gli spazi.
 */
int input_array_str(int *arr, char *line, int *pos) {
    int i = 0, n = 0;
    if (*pos != 0)
        line += *pos + 3;
    while ((sscanf(line, "%d%n", &arr[i], &n)) == 1) {
        line += n;
        *pos += n;
        i++;
    }
    return i;
}

/*
 * Estrae un singolo dato intero da una stringa. Utilizzato per ottenere il valore dall'oracolo.
 */
int getresult(char *line) {
    int n;
    sscanf(line, "%d", &n);
    return n;
}

/*
 * Restituisce la somma di tutti i valori di un array.
 */
int sommaArray(int *arr, int imax) {
    int n = 0;
    for (int i = 0; i < imax; i++)
        n += arr[i];
    return n;
}

/*
 * Somma gli elementi di due array, salvando il risultato nel primo.
 * Se la dimensione del primo array è minore della dimensione del secondo, imax1 viene aggiornato a imax2.
 * Non c'è pericolo di overflow in quanto gli array sono inizializzati a 0.
 */
void somma2Array(int *arr1, int *arr2, int *imax1, int *imax2) {
    if (*imax1 < *imax2)
        *imax1 = *imax2;
    for (int i = 0; (i < *imax1); i++)
        arr1[i] = arr1[i] + arr2[i];
}

/*
 * Controlla se due array sono uguali.
 */
int controlloOracleArray(int *arr, int *oracle, int imax) {
    for (int i = 0; i < imax; i++)
        if (arr[i] != oracle[i])
            return 0;
    return 1;
}

/*
 * Calcola la somma dei prodotti tra gli elementi di due array.
 */
int sumProd(int *arr1, int *arr2, int imax) {
    int n = 0;
    for (int i = 0; i < imax; i++)
        n += (arr1[i] * arr2[i]);
    return n;
}

/*
 * Stampa tutti gli elementi di un array.
 */
void outputArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/*
 * Conta il numero di elementi in una stringa di interi.
 */
int conta_numeri(char *line) {
    int size = 0;
    int controllo = TRUE;
    while (*line == ' ')
        line++;
    for (; *line; line++) {
        if (*line == ' ' && controllo) {
            size++;
            controllo = FALSE;
        } else if (*line != ' ')
            controllo = TRUE;
    }
    return (size + 1);
}

/*
 * Estrae un array dinamico da una stringa di interi.
 */
int *input_array_dyn(int *size, char *line) {
    *size = conta_numeri(line);
    int i = 0, n = 0;
    int *arr = (int *)calloc(*size, sizeof(int));
    while ((sscanf(line, "%d%n", &arr[i], &n)) == 1) {
        line += n;
        i++;
    }
    return arr;
}

/*
 * Ordina un array utilizzando l'Adaptive Bubble Sort.
 */
void adaptiveBubbleSort(int *a, int n) {
    int ordinato = FALSE;
    for (int i = 1; i < n && !ordinato; i++) {
        ordinato = TRUE;
        for (int j = 0; j < (n - i); j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
                ordinato = FALSE;
            }
        }
    }
}

/*
 * Concatena due array in un terzo array.
 */
int *concatena_vet(int *a, int *b, int n1, int n2, int *n3) {
    int *c = (int *)calloc((n1 + n2), sizeof(int));
    int i;
    for (i = 0; i < n1; i++)
        c[i] = a[i];
    for (int i2 = 0; i2 < n2; i2++, i++)
        c[i] = b[i2];
    *n3 = n1 + n2;
    return c;
}
