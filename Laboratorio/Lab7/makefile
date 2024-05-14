link: main.o listr.o item.o
	gcc main.o listr.o item.o -o main.exe

main.o:
	gcc -c main.c
listr.o:
	gcc -c listr.c

item.o:
	gcc -c item.c
clean:
	rm -f *.o *.exe *.out