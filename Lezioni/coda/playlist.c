#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "item.h"
#include "playlist.h"

struct playlist{
    char *name;
    List songs;
};

/*
Playlist createPlaylist ritorna una playlist composta da
- Lista di Item (di solito song, ma anche per esempio int è uguale)
- Nome della lista che viene passato per parametro della funzione

La funzione ritorna la playlist creata

*/

Playlist createPlaylist(char *name){
    Playlist playlist = malloc(sizeof(struct playlist));
    playlist->name = name;
    playlist->songs=newList();
    return playlist;
}

/* 
Per la add song, basta semplicemente usare la addhead precedentemente creata per aggiungere un item 
(dal caller) al dato Lista della playlist
*/

void addSong(Playlist playlist, Item song){
    addHead(playlist->songs,song);
}

/*
Qui ho modificato il progetto iniziale, poiche era molto più semplice usare la removeListItem, 
pero passando Un item come secondo elemento invece della stringa
*/

void removeSong(Playlist playlist, Item qsong){
    removeListItem(playlist->songs,qsong);
}

//abbiamo creato la funzione all'sortList usando il compareItem, che nel mio caso fa il confronto tra i titoli con strcmp
void sortPlaylist(Playlist playlist){
    sortList(playlist->songs);
}

void printPlaylist(Playlist playlist){
    printf("\n%s\n",playlist->name);
    printList(playlist->songs);
}