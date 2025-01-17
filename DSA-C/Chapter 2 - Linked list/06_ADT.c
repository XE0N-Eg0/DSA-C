#include <stdio.h>
#include <stdlib.h>

// structure for singly linked list 
typedef struct Singly_Linked_list
{
    int data;
    struct Singly_Linked_list * next;
} S_NODE;

// structure for doubly linked list 
typedef struct Doubly_Linked_list
{
    int data;
    struct Doubly_Linked_list * next;
    struct Doubly_Linked_list * prev;
} D_NODE;

// Function Prototypes 
S_NODE * create_singly_node(int value, S_NODE * singly_temp);
D_NODE * create_doubly_node(int value, D_NODE * tail);
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
    int LL_option, num_nodes;

    do {
        printf("Choose the linked list you want: \n");
        printf("1. Singly \n");
        printf("2. Circular \n");
        printf("3. Double \n");
        printf("Enter an option: ");
        scanf("%d", &LL_option);

        if (LL_option < 1 || LL_option > 3) {
            printf("Wrong option! Please enter a valid option.\n");
            continue; // Prompt for input again if invalid option is entered
        }

        printf("Enter the number of nodes: ");
        scanf("%d", &num_nodes);

        switch (LL_option)
        {
        case 1: {
            S_NODE *singly_head = NULL;
            S_NODE *singly_temp = NULL;

            for (int i = 0; i < num_nodes; i++) {
                int value;
                printf("Enter value for node %d: ", i + 1);
                scanf("%d", &value);
                S_NODE *fresh_node = create_singly_node(value, singly_temp);
                if (singly_head == NULL) {
                    singly_head = fresh_node;
                }
                singly_temp = fresh_node;
            }

            break;
        }
        case 2: {
            S_NODE *circular_head = NULL;
            S_NODE *circular_temp = NULL;

            for (int i = 0; i < num_nodes; i++) {
                int value;
                printf("Enter value for node %d: ", i + 1);
                scanf("%d", &value);
                S_NODE *fresh_node = create_singly_node(value, circular_temp);
                if (circular_head == NULL) {
                    circular_head = fresh_node;
                    circular_temp = circular_head;
                } else {
                    circular_temp->next = fresh_node;
                    circular_temp = fresh_node;
                }
            }
            if (circular_temp != NULL) {
                circular_temp->next = circular_head;
            }
            break;
        }
        case 3: {
            D_NODE *doubly_head = NULL;
            D_NODE *doubly_tail = NULL;

            for (int i = 0; i < num_nodes; i++) {
                int value;
                printf("Enter value for node %d: ", i + 1);
                scanf("%d", &value);
                if (doubly_head == NULL) {
                    doubly_head = create_doubly_node(value, doubly_tail);
                    doubly_tail = doubly_head;
                } else {
                    doubly_tail = create_doubly_node(value, doubly_tail);
                }
            }
            break;
        }
        default:
            break;
        }

        // Ask the user if they want to perform another operation
        printf("\nDo you want to perform another operation? (1 for Yes, 0 for No): ");
        scanf("%d", &LL_option);

    } while (LL_option != 0);  // Exit loop if the user chooses 0

    return 0;
}

S_NODE * create_singly_node(int value, S_NODE * singly_temp) {
    S_NODE * new_node = (S_NODE *)malloc(sizeof(S_NODE));
    if (new_node == NULL) {
        perror("Memory allocation failed!!!\n");
        exit(-1);
    }

    new_node->data = value;
    new_node->next = NULL;

    if (singly_temp != NULL) {
        singly_temp->next = new_node;
    }

    return new_node;
}

D_NODE * create_doubly_node(int value, D_NODE * tail) {
    D_NODE *new_node = (D_NODE *)malloc(sizeof(D_NODE));
    if (new_node == NULL) {
        perror("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = tail;

    if (tail != NULL) {
        tail->next = new_node;
    }

    return new_node;
}
