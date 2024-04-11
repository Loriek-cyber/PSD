#include "song.h"
#include "item.h"
typedef struct playlist *Playlist;

Playlist createPlaylist(char *);
void addSong(Playlist, Item);
void removeSong(Playlist, Item);
void sortPlaylist(Playlist);
void printPlaylist(Playlist);

