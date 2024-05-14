math: math.o main.o
	gcc math.o main.o -o lez17.exe

int: list.o main.o item_int.o stackList.o queue_array.o
	gcc list.o item_int.o main.o stackList.o queue_array.o -o queue.exe

string: list.o main.o item_string.o stackArray.o queue.o
	gcc list.o item_string.o main.o stackArray.o queue.o -o queue.exe

queue_array.o:
	gcc -c queue_array.c

math.o:
	gcc -c math.c

queue.o:
	gcc -c queue.c

stackList.o:
	gcc -c stackList.c

stackArray.o:
	gcc -c stackArray.c

item_int.o:
	gcc -c item_int.c

item_string.o:
	gcc -c item_string.c
	
main.o:
	gcc -c main.c

list.o: 
	gcc -c list.c

clean:
	rm -f *.o *.exe