#include <stdlib.h>
#include "list.h"
#include "item.h"
#include "queue.h"


struct queue{
    List list;
};

Queue newQueue(){
    Queue queue = malloc(sizeof(struct queue));
    queue->list=newList();
}

int isEmptyQueue(Queue queue){
    return isEmpty(queue->list);
}

endqueue(Queue queue,Item item){
    addListTail(queue->list,item);
}

