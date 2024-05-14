#include <stdlib.h>
#include "list.h"
#include "item.h"
#include "song.h"

struct song{
    char *title;
    char *artist;
    int duration;
};

/*
Creamo una sezione di memoria con la malloc per poter creare una struct song con il
modello che abbiamo scritto sopra, e iniziallizziamo tutti i dati con i parametri che 
la funzione ci da, è restituiamo song
*/

Song InnitSong(char *title, char *artist,int duration){
    Song song = malloc(sizeof(struct song));
    song->title = title;
    song->artist = artist;
    song->duration = duration;
    return song;
}

/*
Visto che non potremmo lavorare con le canzioni negli altri file creamo questi funzioni, 
per fare in modo di avere ogni dato a notra disposizione
*/

char *getTitle(Song song){
    return song->title;
}
char *getArtist(Song song){
    return song->artist;
}
int getDuration(Song song){
    return song->duration;
}

