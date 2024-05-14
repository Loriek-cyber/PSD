#include <stdio.h>
#include "list.h" 
#include "item.h"
#include "playlist.h"
#include "song.h"

int main(){
	char *nome = "Rock";
	
	Playlist playlist = createPlaylist(nome);
	for (int i = 0; i < 5; i++)
	{
		addSong(playlist,inputItem());
	}
	printPlaylist(playlist);
	
	sortPlaylist(playlist);

	printPlaylist(playlist);
	free(playlist);
}