#include <stdio.h>
#include<stdlib.h>


// structure for singly linked list 
typedef struct Singly_Linked_list
{
    int data;
    struct Singly_Linked_list * next
}S_NODE;


// structure for doubly linked list 
typedef struct Doubly_Linked_list
{
    int data;
    struct Doubly_Linked_list * next;
    struct Doubly_Linked_list * prev;
}D_NODE;


// Function Prototypes 
S_NODE * create_singly_node();
D_NODE * create_doubly_node();
void insert_at_begining();
void insert_at_end();
void insert_at_index();
void delete_at_beginig();
void delete_at_end();
void delete_at_index();
void delete_node();
void display();




int main(int argc, char const *argv[])
{
    int LL_option,num_nodes;

    printf("Choose the linked list you want: \n");
    printf("1. Singly \n");
    printf("2. Circular \n");
    printf("3. Double \n");


    switch (LL_option)
    {
    case 1:
        printf("Enter the number of nodes: ");
        scanf("%d",&num_nodes);
        S_NODE * head = (S_NODE *)malloc(sizeof(S_NODE));
        for (int i = 0; i < num_nodes; i++)
        {
            create_singly_node();
        }
              
        break;
    
    default:
        break;
    }

    return 0;
}

S_NODE * create_singly_node(){

}