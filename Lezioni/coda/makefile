int: list.o main.o item_int.o
	gcc -Wall list.o item_int.o main.o -o list.out

string: list.o main.o item_string.o
	gcc list.o item_string.o main.o -o list.out

song: list.o main.o item_song.o song.o
	gcc list.o main.o item_song.o song.o -o list.exe
playlist: list.o main.o item_song.o song.o playlist.o
	gcc list.o main.o item_song.o song.o playlist.o -o list.exe

playlist.o:
	gcc -c playlist.c

song.o:
	gcc -c song.c

item_int.o:
	gcc -c item_int.c

item_string.o:
	gcc -c item_string.c
item_song.o:
	gcc -c item_song.c
	
main.o:
	gcc -c main.c

list.o: 
	gcc -c list.c

clean:
	rm -f *.o *.exe