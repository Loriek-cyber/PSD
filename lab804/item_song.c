#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "item.h"
#include "song.h"

#define N 100

Item inputItem(){
    char *title = malloc(sizeof(char)*N);
    char *artist = malloc(sizeof(char)*N);
    int duration;
    Song song;
    
    printf("Title:");
    scanf("%[^\n]",title);
    
    getchar();
    printf("Artist:");
    scanf("%[^\n]",artist);
    printf("Duration:");
    
    scanf("%d",&duration);
    fflush(stdin); 
    // Questo libera il buffer che se riempiamo una Playlist sicuramente ci sarà una \n che saltera la prima scanf
    
    song = InnitSong(title,artist,duration);
    return song;
}
void outputItem(Item item){
    printf("Title:%s\nArtist:%s\nDuration:%d\n",getTitle(item),getArtist(item),getDuration(item));
}
int cmpItem(Item item1, Item item2){
    return strcmp(getTitle(item1),getTitle(item2));
}