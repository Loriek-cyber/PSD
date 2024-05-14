#include <stdio.h>
#include <stdlib.h>
#include "libri.h"

struct libri{
    char *autor;
    char *editor;
    int year;
};

Book InitLibro(char *autor, char *editor, int year){
    Book book = malloc(sizeof(struct libri));
    book->autor=autor;
    book->editor=editor;
    book->year= year;
    return book;
}

char *getAutor(Book book){
    return book->autor;
}

char *getEditor(Book book){
    return book->editor;
}

int getYear(Book book){
    return book->year;
}