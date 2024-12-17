#include <stdio.h>
#include <stdlib.h>

typedef struct STACK
{
    int size;
    int top;
    int * arr;
}STACK;

int isEMPTY(STACK * ptr);
int isFULL(STACK * ptr);;
void display(STACK * ptr);
void PEAK(STACK * ptr);

int main(int argc, char const *argv[])
{
    STACK * stack = (STACK *)malloc(sizeof(STACK));
    stack->size = 10;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->size*sizeof(int));

    for (int i = 0; i < 6; i++)
    {
        stack->top++;
        stack->arr[stack->top] = i;
    }
    display(stack);
    PEAK(stack);
    
    return 0;
}

int isEMPTY(STACK * ptr){
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
    
}

int isFULL(STACK * ptr){
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void display(STACK * ptr){
    if (isEMPTY(ptr)) {
        printf("Stack is empty\n");
        return;
    }

    for (int i = ptr->top ; i >= 0 ; i--) {
        printf("|__%d__|\n", ptr->arr[i]);
    }
}

void PEAK(STACK * ptr){
    int index;
    printf("Enter the index you want to peep: ");
    scanf("%d",&index);

    printf("The value at %d = %d",index,ptr->arr[index]);
}