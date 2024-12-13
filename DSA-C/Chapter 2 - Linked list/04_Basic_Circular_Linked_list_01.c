#include <stdio.h>
#include<stdlib.h>


typedef struct Circular_Linked_List
{
    int data;
    struct Circular_Linked_List * next;
} NODE;

void display(NODE * head){
    NODE * ptr = head->next;
    do
    {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    
    printf("HEAD");
    
}

int main(int argc, char const *argv[])
{
    NODE * head = (NODE *)malloc(sizeof(NODE));
    NODE * First= (NODE *)malloc(sizeof(NODE));
    NODE * Second = (NODE *)malloc(sizeof(NODE));
    NODE * Third = (NODE *)malloc(sizeof(NODE));
    NODE * Fourth = (NODE *)malloc(sizeof(NODE));

    First->data = 10;
    Second->data = 20;
    Third->data = 30;
    Fourth->data = 40;

    head->next = First;
    First->next = Second;
    Second->next = Third;
    Third->next = Fourth;
    Fourth->next = head;

    display(head);
    return 0;
}
