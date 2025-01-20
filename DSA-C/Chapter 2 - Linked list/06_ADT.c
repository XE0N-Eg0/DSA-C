#include <stdio.h>
#include <stdlib.h>

// structure for singly linked list
typedef struct Singly_Linked_list
{
    int data;
    struct Singly_Linked_list *next;
} S_NODE;

// structure for doubly linked list
typedef struct Doubly_Linked_list
{
    int data;
    struct Doubly_Linked_list *next;
    struct Doubly_Linked_list *prev;
} D_NODE;

// Function Prototypes
S_NODE *create_singly_node(int value, S_NODE *singly_temp);
D_NODE *create_doubly_node(int value, D_NODE *tail);
void display(int linked_list_type, D_NODE *doubly_head, D_NODE *doubly_tail, S_NODE *singly_head, S_NODE *circular_head);

int main()
{
    int linked_list_type = 0, num_nodes = 0;
    S_NODE *singly_head = NULL;
    S_NODE *circular_head = NULL;
    D_NODE *doubly_head = NULL;
    D_NODE *doubly_tail = NULL;

    while (1)
    {
        printf("Choose the linked list you want:\n");
        printf("1. Singly Linked List\n");
        printf("2. Circular Linked List\n");
        printf("3. Doubly Linked List\n");
        printf("Enter an option: ");
        scanf("%d", &linked_list_type);

        if (linked_list_type < 1 || linked_list_type > 3)
        {
            printf("Invalid option! Please enter a valid option.\n");
            continue; // passes the itteration for this and goes back to start of loop
        }

        printf("Enter the number of nodes: ");
        scanf("%d", &num_nodes);

        switch (linked_list_type)
        {
        case 1: // Singly Linked List
        {
            S_NODE *singly_temp = NULL;
            for (int i = 0; i < num_nodes; i++)
            {
                int value;
                printf("Enter value for node %d: ", i + 1);
                scanf("%d", &value);
                S_NODE *fresh_node = create_singly_node(value, singly_temp);
                if (singly_head == NULL)
                {
                    singly_head = fresh_node;
                }
                singly_temp = fresh_node;
            }
            break;
        }
        case 2: // Circular Linked List
        {
            S_NODE *circular_temp = NULL;
            for (int i = 0; i < num_nodes; i++)
            {
                int value;
                printf("Enter value for node %d: ", i + 1);
                scanf("%d", &value);
                S_NODE *fresh_node = create_singly_node(value, circular_temp);
                if (circular_head == NULL)
                {
                    circular_head = fresh_node;
                    circular_temp = circular_head;
                }
                else
                {
                    circular_temp->next = fresh_node;
                    circular_temp = fresh_node;
                }
            }
            if (circular_temp != NULL)
            {
                circular_temp->next = circular_head;
            }
            break;
        }
        case 3: // Doubly Linked List
        {
            for (int i = 0; i < num_nodes; i++)
            {
                int value;
                printf("Enter value for node %d: ", i + 1);
                scanf("%d", &value);
                if (doubly_head == NULL)
                {
                    doubly_head = create_doubly_node(value, doubly_tail);
                    doubly_tail = doubly_head;
                }
                else
                {
                    doubly_tail = create_doubly_node(value, doubly_tail);
                }
            }
            break;
        }
        }

        int confirm;
        printf("\nDo you confirm the linked list? (1 for Yes, 0 for No): ");
        scanf("%d", &confirm);

        if (confirm == 1)
        {
            break; // Exit the loop if the user confirms
        }
    }

    // Display the linked list
    display(linked_list_type, doubly_head, doubly_tail, singly_head, circular_head);

    return 0;
}

// FOR CREATING SINGLE LL
S_NODE *create_singly_node(int value, S_NODE *singly_temp)
{
    S_NODE *new_node = (S_NODE *)malloc(sizeof(S_NODE));
    if (new_node == NULL)
    {
        perror("Memory allocation failed!!!\n");
        exit(-1);
    }

    new_node->data = value;
    new_node->next = NULL;

    if (singly_temp != NULL)
    {
        singly_temp->next = new_node;
    }

    return new_node;
}

// FOR CREATING DOUBLE LL
D_NODE *create_doubly_node(int value, D_NODE *tail)
{
    D_NODE *new_node = (D_NODE *)malloc(sizeof(D_NODE));
    if (new_node == NULL)
    {
        perror("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = tail;

    if (tail != NULL)
    {
        tail->next = new_node;
    }

    return new_node;
}

// FOR DISPLAY
void display(int linked_list_type, D_NODE *doubly_head, D_NODE *doubly_tail, S_NODE *singly_head, S_NODE *circular_head)
{

    if (linked_list_type == 1) // Singly Linked List
    { 
        S_NODE *ptr = singly_head;
        if (ptr == NULL)
        {
            printf("The linked list is empty!\n");
            return;
        }
        while (ptr != NULL)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }


    else if (linked_list_type == 2) // Circular Linked List
    { 
        S_NODE *ptr = circular_head;
        if (ptr == NULL)
        {
            printf("The linked list is empty!\n");
            return;
        }
        do
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        } while (ptr != circular_head);
        printf("(Back to Head)\n");
    }


    else if (linked_list_type == 3) // Doubly Linked List
    { 
        if (doubly_head == NULL)
        {
            printf("The linked list is empty!\n");
            return;
        }
        printf("\n Doubly Linked List (Forward): "); 
        D_NODE *ptr = doubly_head;
        while (ptr != NULL)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");

        printf("Doubly Linked List (Backward): ");
        D_NODE * qtr = doubly_tail;
        printf("NULL");
        while (qtr != NULL)
        {
            printf(" <- %d", qtr->data);
            qtr = qtr->prev;
        }
        

    }
}
