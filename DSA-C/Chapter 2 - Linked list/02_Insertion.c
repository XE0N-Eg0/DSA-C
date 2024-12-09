#include <stdio.h>
#include <stdlib.h>

typedef struct Linked_list {
    int data;
    struct Linked_list *next;
} Node;

Node *create_node(int value, Node *temp);
void display(Node *head);
void insert_at_begining(int value, Node **head);
void insert_at_index(int value, int index, Node *head);
void insert_at_end(int value, Node *head);
void insert_after_index(int value, int index, Node * head);

int main(int argc, char const *argv[]) {
    int num, value, choice, index; // Added variables `choice` and `index` for menu
    Node *head = NULL;
    Node *temp = NULL;

    printf("Enter the number of nodes you want: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Enter the value of node %d : ", i + 1);
        scanf("%d", &value);
        Node *fresh_node = create_node(value, temp);

        if (head == NULL) {
            head = fresh_node;
        }
        temp = fresh_node;
    }

    do {
        printf("\n");
        display(head);
        printf("\nMain Menu:\n"); 
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Index\n");
        printf("3. Insert after Index\n");
        printf("4. Insert at End\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insert_at_begining(value, &head);
                break;
            case 2:
                printf("Enter the index to insert at: ");
                scanf("%d", &index);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert_at_index(value, index, head);
                break;
            case 3:
                printf("Enter the index to insert after: ");
                scanf("%d", &index);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert_after_index(value, index, head);
                break;
            case 4:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insert_at_end(value, head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5); // Loop continues until user chooses to exit

    return 0;
}

Node *create_node(int value, Node *temp) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (temp != NULL) {
        temp->next = new_node;
    }

    return new_node;
}

void display(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insert_at_begining(int value, Node **head) { // we are calling head by reference so its automatically changed in the main function 
    Node *insert = (Node *)malloc(sizeof(Node));
    insert->data = value;
    insert->next = *head;
    *head = insert;
}

void insert_at_index(int value, int index, Node *head){
    Node * insert = (Node *)malloc(sizeof(Node));
    Node * ptr = head;
    int j = 0;
    while (j != index-1)
    {
        ptr = ptr->next;
        j++;
    }
    insert->data = value;
    insert->next = ptr->next;
    ptr->next = insert;

}

void insert_at_end(int value, Node * head){
    Node * insert =(Node *)malloc(sizeof(Node));
    Node * ptr = head;
    int j = 0;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;

    }
    insert->data = value;
    ptr->next = insert;
    insert->next = NULL;
    
}

void insert_after_index(int value, int index, Node * head){
    Node * insert = (Node * )malloc(sizeof(Node));
    Node * ptr = head;
    int j = 0;
    while (j != index)
    {
        ptr = ptr->next;
        j++;
    }
    insert->data =value;
    insert->next = ptr->next;
    ptr->next = insert;

}
