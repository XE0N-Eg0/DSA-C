#include <stdio.h>
#include<stdlib.h>

typedef struct STACK
{
    int top;
    int size;
    int * arr;
} STACK;

int isEMPTY(STACK * ptr);
int isFULL(STACK * ptr);
void display(STACK * ptr);
void POP(STACK * ptr);

int main(int argc, char const *argv[])
{
    // Allocate memory for the stack itself
    STACK * stack = (STACK*)malloc(sizeof(STACK));
    
    // Initialize stack properties
    stack->top = -1;
    stack->size = 10;
    stack->arr = (int*)malloc(stack->size * sizeof(int));

    // Push values onto the stack
    for (int i = 0; i < 10; i++)
    {
        stack->top++;
        stack->arr[stack->top] = i;
    }

    // Display the stack and pop an element
    display(stack);
    POP(stack);
    display(stack);

    // Free memory for the stack
    free(stack->arr);
    free(stack);
    
    return 0;
}

int isEMPTY(STACK * ptr){
    if (ptr->top == -1){
        return 1; // Stack is empty
    }
    return 0;
}

int isFULL(STACK * ptr){
    if (ptr->top >= ptr->size - 1){
        return 1; // Stack is full
    }
    return 0;
}

void display(STACK * ptr){
    if (isEMPTY(ptr)) {
        printf("Stack is empty\n");
        return;
    }

    // Display only the valid elements
    for (int i = 0; i <= ptr->top; i++) {
        printf("|__%d__|\n", ptr->arr[i]);
    }
}

void POP(STACK * ptr){
    if (isEMPTY(ptr)) {
        perror("Underflow!\n");
        return;
    }

    int value = ptr->arr[ptr->top];
    ptr->top--;
    printf("%d popped successfully\n", value);
}
