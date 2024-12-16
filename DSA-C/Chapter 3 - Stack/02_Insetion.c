#include <stdio.h>
#include <stdlib.h>

typedef struct STACK {
    int top;
    int size;
    int *arr;
} STACK;


int isEMPTY(STACK *ptr);
int isFULL(STACK *ptr);
void PUSH(STACK *ptr);
void display(STACK *ptr);

int main(int argc, char const *argv[]) {
    
    STACK *stack = (STACK *)malloc(sizeof(STACK));
    stack->top = -1;
    stack->size = 10;
    stack->arr = (int *)malloc(stack->size * sizeof(int));

    for (int i = 0; i < 10; i++)
    {
        PUSH(stack);
    }
    
    display(stack);

    return 0;
}


int isEMPTY(STACK *ptr) {
    return (ptr->top == -1);
}


int isFULL(STACK *ptr) {
    return (ptr->top >= ptr->size - 1);
}


void PUSH(STACK *ptr) {
    if (isFULL(ptr)) {
        perror("Stack Overflow\n");
        return;
    }

    int value;
    printf("Enter a value to be inserted: ");
    scanf("%d", &value);
    ptr->top++;
    ptr->arr[ptr->top] = value;
}

void display(STACK *ptr) {
    if (isEMPTY(ptr)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contents (top to bottom):\n");
    for (int i = ptr->top; i >= 0; i--) {  
        printf("|__%d__|\n", ptr->arr[i]);
    }
}
