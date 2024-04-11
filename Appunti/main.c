#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc != 2) return 1;
    FILE *fp_input = fopen("input.txt","r");
    FILE *fp_oracle = fopen("oracle.txt","r");

    if(fp_input == NULL)return 0;
    if(fp_oracle == NULL)return 0;

    
}