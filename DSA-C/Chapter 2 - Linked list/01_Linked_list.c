#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};


int main(int argc, char const *argv[])
{
    struct node * head;
    struct node * first;
    struct node * second;
    struct node * third;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head -> data   = 10 ;
    first -> data  = 20 ;
    second -> data = 30 ;
    third -> data  = 40 ;

    head -> next   = first ;
    first -> next  = second ;
    second -> next = third ;
    third -> next  = NULL ;


    return 0;
}
