#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include "queue.h"

#define maxqueue 6


struct queue{
    Item items[maxqueue];
    int tail;
    int head;
};

Queue newQueue(){
    Queue queue = malloc(sizeof(struct queue));
    queue->head = 0;
    queue->tail = 0;
    return queue;
}
int isEmptyQueue(Queue queue){
    return ((queue->tail) - (queue->head))==0;
}
int enqueue(Queue queue, Item item){
    if((queue->tail+1)%maxqueue== queue->head)return 0;
    (queue->tail)++;
    queue->items[queue->tail%maxqueue]=item;
}
Item dequeue(Queue queue){
    if((queue->head+1)%maxqueue== queue->tail)return 0;
    Item temp = malloc(sizeof(Item));
    temp = queue->items[queue->head%maxqueue];
    (queue->head)++;
    return temp;
}

void printQueue(Queue queue){
    for (int i = queue->head; i < maxqueue; i++){
        outputItem(queue->items[i]);
    }
    printf("\n");
}