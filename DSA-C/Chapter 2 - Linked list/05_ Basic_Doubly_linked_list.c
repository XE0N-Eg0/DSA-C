#include <stdio.h>
#include <stdlib.h>

typedef struct Doubly_linked_list
{
    int data;
    struct Doubly_linked_list * prev;
    struct Doubly_linked_list * next;
}NODE;

void display_list(NODE * head){
    printf("Moving forward: \n");
    NODE * ptr = head;
    NODE * last = NULL;
    while (ptr != NULL)
    {
        printf(" %d ->",ptr->data);
        last = ptr;
        ptr = ptr->next;
    }
    printf("NULL");
    printf("\nMoving Backwards: \n");
    
    ptr = last;
    while (ptr != NULL)
    {
        printf(" %d <-",ptr->data);
        ptr = ptr->prev;
    }
    printf("NULL\n");
}
int main(int argc, char const *argv[])
{

    NODE * First  = (NODE*)malloc(sizeof(NODE));
    NODE * Second =  (NODE*)malloc(sizeof(NODE));
    NODE * Third = (NODE*)malloc(sizeof(NODE));
    NODE * Fourth = (NODE*)malloc(sizeof(NODE));
    NODE * Head;
    // Alloting data 
    Head = First;
    First->data = 10;
    Second->data = 20;
    Third->data = 30;
    Fourth->data = 40;

    //LINKING PART
    // linking the next ptrs: 
    First->next = Second;
    Second->next = Third;
    Third->next = Fourth;
    Fourth->next = NULL;
    
    // linking the prev ptrs:
    First->prev = NULL;
    Second->prev = First;
    Third->prev = Second;
    Fourth->prev = Third;

    display_list(Head);
    
    return 0;
}
