#include <stdio.h>
#include<stdlib.h>

typedef struct Linked_list
{
    int data;
    struct Linked_list * next;
}NODE ;

NODE * create_node(int value, NODE * prev);
void display(NODE * head);
void delete_begining(NODE * head);
void delete_index(NODE * head, int index);
void delete_end(NODE * head);



int main(int argc, char const *argv[])
{
    NODE * head;
    NODE * prev;
    int num, choice, value;
    
    head = NULL;
    prev = NULL;

    printf("Enter number of nodes you want:  ");
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++)
    {
        printf("Enter a value of element %d : ", i+1);
        scanf("%d",&value);
        NODE * fresh_node = create_node(value, prev);
        if (head == NULL)
        {
            head = fresh_node; 
        }
        prev = fresh_node;
    }
    display(head);

    return 0;
}

NODE * create_node(int value, NODE * prev){
    NODE * new_node = (NODE * )malloc(sizeof(NODE));
    new_node->data = value;
    new_node->next = NULL;

    if (prev != NULL)
    {
        prev->next = new_node;
    }
    return new_node;
}

void display(NODE * head){
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
    
}