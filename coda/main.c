#include <stdio.h>
#include "list.h" 
#include "item.h"
#include "playlist.h"
#include "song.h"

int main(){
	char *nome = "Rock";
	Playlist playlist = createPlaylist(nome);
	for (int i = 0; i < 3; i++)
	{
		addSong(playlist,inputItem());
	}
	sortPlaylist(playlist);
	printPlaylist(playlist);
}