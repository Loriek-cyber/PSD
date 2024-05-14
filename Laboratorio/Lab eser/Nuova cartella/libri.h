typedef struct libri *Book;

Book InitLibro(char *autor, char *editor, int year);
char *getAutor(Book book);
char *getEditor(Book book);
int getYear(Book book);