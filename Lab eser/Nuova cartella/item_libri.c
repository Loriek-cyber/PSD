#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "libri.h"
#define Max 100

Item inputItem(){
    
    char *autor = malloc(sizeof(char)*Max);
    char *editor = malloc(sizeof(char)*Max);
    int *year = malloc(sizeof(int));

    scanf("%[\n]",autor);
    getchar();
    scanf("%[\n]",editor);
    getchar();
    scanf("%d",year);
    getchar();
    Book book = InitLibro(autor,editor,year);
    return book;
}

Item CreateItem(char *autor1,char *editor1, int year1){
    char *autor = malloc(sizeof(char)*Max);
    char *editor = malloc(sizeof(char)*Max);
    int *year = malloc(sizeof(int));
    
    

    Book book = InitLibro(autor,editor,year);
    return book;
}

void outputItem(Item item){
    Book book = item;
    printf("Autor:%s \nEditor:%s\nYear:%d",getAutor(book),getEditor(book),getYear(book));
}
int cmpItem(Item, Item);