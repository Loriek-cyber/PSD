#include <stdlib.h>
#include "stack.h"
#define START_DIM 10
#define ADD_DIM 5

struct stack{
    Item *elements;
    int top;
    int dim;
};

Stack newStack(){
    Stack s=malloc(sizeof(struct stack));
    if(s==NULL)
        return NULL;
    s->top=0;
    s->elements=malloc(sizeof(Item)*START_DIM);
    if(s->elements == NULL)
        return NULL;
    s->dim = START_DIM;
    return s;
} 

int isEmptyStack(Stack stack){
    if(stack->top==0)
        return 1;
    else
        return 0;
}

int push(Stack stack, Item item){
    Item *temp;
    if(stack->top==stack->dim){
        temp = realloc(stack->elements,sizeof(Item)*(stack->dim+ADD_DIM));
        if(temp == NULL) return 0;
        else{
            stack-> elements = temp;
            stack-> dim += ADD_DIM;
        }
    }
    
    stack->elements[stack->top]=item;
    stack->top++;
    
    return 1;
}

int pop(Stack stack){
    if(isEmptyStack(stack))
        return 0;

    stack->top--;    
    return 1;
}

Item top(Stack stack){
    if(isEmptyStack(stack))
        return NULL;
    else
        return stack->elements[stack->top-1];
}

void printStack(Stack stack){
    for(int i=stack->top-1; i>=0; i--){
        outputItem(stack->elements[i]);
    }
    
}
