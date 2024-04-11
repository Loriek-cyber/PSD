#include <stdlib.h>
#include "list.h"
#include "item.h"
#include "queue.h"


struct queue{
    Item array[100];
    int head;
    int tail;
};

Queue newQueue(){
    Queue queue= malloc(sizeof(struct queue));
    queue->head=0;
    queue->tail=0;
}

int isEmptyQueue(Queue queue){
    if(queue->tail==queue->head) return 1;
    else return 0;
}

endqueue(Queue queue,Item item){
    
}