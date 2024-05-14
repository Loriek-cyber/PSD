int: main.o vettore.o item_int.o
	gcc main.o vettore.o item_int.o -o int.exe

string: main.o vettore.o item_string.o
	gcc main.o vettore.o item_string.o -o string.exe

main.o:
	gcc -c main.c

vettore.o:
	gcc -c vettore.c

item_string.o:
	gcc -c item_string.c

item_int.o:
	gcc -c item_int.c

clean:
	rm -f *.o *.exe
	cls