#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    char line[100];
    int *a;

    printf("inserisci il vettore: ");
    scanf("%[^\n]",line);
    //legge un intero fino al newline "\n"
    a = input_array_dyn(&n,line);
    bubble_sort(a, n);
    output_array(a, n);

    return 0;
}