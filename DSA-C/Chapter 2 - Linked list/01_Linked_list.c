#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};


void display(struct node * head);   // displays the LL
struct node * create_node_1(int value); // creates the nodes with an input value but doesnt links them
struct node * create_node_2(int value, struct node * prev); // creates nodes with a value and links all nodes





int main(int argc, char const *argv[])
{

    // This would be the manual way of making nodes and linking them
    struct node * head;
    struct node * first;
    struct node * second;
    struct node * third;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    // Data is alloacted to each node
    head -> data   = 10 ;
    first -> data  = 20 ;
    second -> data = 30 ;
    third -> data  = 40 ;

    // Nodes are linked together 
    head -> next   = first ;
    first -> next  = second ;
    second -> next = third ;
    third -> next  = NULL ;



    // this was cerated by create_node_1 fx
    struct node * head_1  = create_node_1(10);
    struct node * first_1  = create_node_1(10);
    struct node * second_1 = create_node_1(10);
    struct node * third_1  = create_node_1(10);

    // linking part of fx_1
    head_1 ->next = first_1;
    first_1 ->next = second_1;
    second_1 ->next = third_1;


    return 0;
}

void display(struct node * head){
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head -> next;
    }
    
}

struct node * create_node_1(int value){
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = value;
    new_node -> next = NULL;
    return new_node;
}