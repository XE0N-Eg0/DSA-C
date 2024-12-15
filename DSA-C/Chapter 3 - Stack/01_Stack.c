#include <stdio.h>
#include <stdlib.h>

typedef struct STACK 
{
    int top;
    int size;
    int * arr;

}STACK;

int isEMPTY(STACK * ptr);
int isFULL(STACK * ptr);
void display(STACK * ptr);
int main(int argc, char const *argv[])
{
    // STACK s;
    // s.top = -1;
    // s.size = 10;
    // s.arr = (int*)malloc(s.size*sizeof(int));

    STACK * stack;
    stack->top = -1;
    stack->size = 10;
    stack->arr = (int)malloc(stack->size*sizeof(int));



    return 0;
}

int isEMPTY(STACK * ptr){
    if (ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFULL(STACK * ptr){
    if (ptr->top >= ptr->size-1){
        return 1;
    }
    return 0;
}

void display(STACK * ptr){
    for (int i = 0; i < ptr->size; i++)
    {
        printf("|__%d__|\n",ptr->arr[i]);
    }
}