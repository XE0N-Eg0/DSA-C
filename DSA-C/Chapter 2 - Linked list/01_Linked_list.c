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
    third_1 ->next = NULL;

    // creation and linking of fx_2

    struct node *head_2 = NULL;
    struct node *prev_2 = NULL;
    int num, value;

    printf("Enter the amount of nodes you want: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Enter the value of element %d: ", i + 1);
        scanf("%d", &value);
        struct node *newnode = create_node_2(value, prev_2);
        if (head_2 == NULL) {
            head_2 = newnode;
        }
        prev_2 = newnode;
    }
    
    // display
    int choice;
    printf("choose the option to display\n");
    printf("1. LL - 1 (manual)\n");
    printf("2. LL - 2 (semi-manual)\n");
    printf("3. LL - 2 (automatic)\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        display(head);
        break;
    case 2:
        display(head_1);
        break;
    case 3:
        display(head_2);
    default:
        break;
    }

    



    return 0;
}

void display(struct node * head){
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head -> next;
    }
    printf("NULL\n");
    
}

struct node * create_node_1(int value){
    struct node * new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = value;
    new_node -> next = NULL;
    return new_node;
}

struct node * create_node_2(int value, struct node * prev_2){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if (prev_2 != NULL) {
        prev_2->next = new_node;
    }
    return new_node;
}