#include <stdio.h>
#include <stdlib.h>

// Structure Definitions
typedef struct Singly_Linked_list
{
    int data;
    struct Singly_Linked_list *next;
} S_NODE;
    
typedef struct Doubly_Linked_list
{
    int data;
    struct Doubly_Linked_list *next;
    struct Doubly_Linked_list *prev;
} D_NODE;

// Function Prototypes
// Linked list Creation function
S_NODE *create_singly_node(int value, S_NODE *singly_temp);
D_NODE *create_doubly_node(int value, D_NODE *tail);

// Prime Display function
void display(int linked_list_type, D_NODE *doubly_head, D_NODE *doubly_tail, S_NODE *singly_head, S_NODE *circular_head);

// Singly Operation functions
void insertSinglyAtBeginning(S_NODE **head, int value);
void insertSinglyAtIndex(S_NODE **head, int index, int value);
void insertSinglyAtEnd(S_NODE **head, int value);

void deleteSinglyAtBeginning(S_NODE **head);
void deleteSinglyAtIndex(S_NODE **head, int index);
void deleteSinglyAtEnd(S_NODE **head);

// Circular Operation functions
void insertCircularAtBeginning(S_NODE **head, int value);
void insertCircularAtIndex(S_NODE **head, int index, int value);
void insertCircularAtEnd(S_NODE **head, int value);

void deleteCircularAtBeginning(S_NODE **head);
void deleteCircularAtIndex(S_NODE **head, int index);
void deleteCircularAtEnd(S_NODE **head);

// Doubly Operation functions
void insertDoublyAtBeginning(D_NODE **head, D_NODE **tail, int value);
void insertDoublyAtIndex(D_NODE **head, D_NODE **tail, int index, int value);
void insertDoublyAtEnd(D_NODE **head, D_NODE **tail, int value);

void deleteDoublyAtBeginning(D_NODE **head, D_NODE **tail);
void deleteDoublyAtIndex(D_NODE **head, D_NODE **tail, int index);
void deleteDoublyAtEnd(D_NODE **head, D_NODE **tail);

int main()
{
    int linked_list_type = 0, num_nodes = 0;
    S_NODE *singly_head = NULL, *circular_head = NULL;
    D_NODE *doubly_head = NULL, *doubly_tail = NULL;

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
            continue;
        }

        printf("Enter the number of nodes: ");
        scanf("%d", &num_nodes);

        switch (linked_list_type)
        {
        case 1:
        {
            S_NODE *singly_temp = NULL;
            for (int i = 0; i < num_nodes; i++)
            {
                int value;
                printf("Enter value for node %d: ", i + 1);
                scanf("%d", &value);
                S_NODE *fresh_node = create_singly_node(value, singly_temp);
                if (singly_head == NULL)
                    singly_head = fresh_node;
                singly_temp = fresh_node;
            }
            break;
        }
        case 2:
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
                circular_temp->next = circular_head;
            break;
        }
        case 3:
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
            break;
    }

    while (1)
    {
        int operation_choice;
        printf("\n============================\n");
        printf("Current linked list:\n");
        display(linked_list_type, doubly_head, doubly_tail, singly_head, circular_head);
        printf("\nOPERATIONS:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &operation_choice);

        if (operation_choice == 3)
            exit(0);

        switch (operation_choice)
        {
        case 1:
        {
            while (1)
            {
                int insertion_options, value, index;
                display(linked_list_type, doubly_head, doubly_tail, singly_head, circular_head);
                printf("\n--- Insertion Options ---\n");
                printf("1. Insert at beginning\t");
                printf("2. Insert at index\t");
                printf("3. Insert at end\t");
                printf("4. Go Back\t");
                printf("\nEnter your choice: ");
                scanf("%d", &insertion_options);

                if (insertion_options == 4)
                    break;

                switch (insertion_options)
                {
                case 1:
                    printf("Enter value: ");
                    scanf("%d", &value);
                    if (linked_list_type == 1)
                        insertSinglyAtBeginning(&singly_head, value);
                    else if (linked_list_type == 2)
                        insertCircularAtBeginning(&circular_head, value);
                    else if (linked_list_type == 3)
                        insertDoublyAtBeginning(&doubly_head, &doubly_tail, value);
                    break;
                case 2:
                    printf("Enter index: ");
                    scanf("%d", &index);
                    printf("Enter value: ");
                    scanf("%d", &value);
                    if (linked_list_type == 1)
                        insertSinglyAtIndex(&singly_head, index, value);
                    else if (linked_list_type == 2)
                        insertCircularAtIndex(&circular_head, index, value);
                    else if (linked_list_type == 3)
                        insertDoublyAtIndex(&doubly_head, &doubly_tail, index, value);
                    break;
                case 3:
                    printf("Enter value: ");
                    scanf("%d", &value);
                    if (linked_list_type == 1)
                        insertSinglyAtEnd(&singly_head, value);
                    else if (linked_list_type == 2)
                        insertCircularAtEnd(&circular_head, value);
                    else if (linked_list_type == 3)
                        insertDoublyAtEnd(&doubly_head, &doubly_tail, value);
                    break;
                default:
                    printf("Invalid option! Try again.\n");
                }
            }
            break;
        }
        case 2:
        {
            while (1)
            {
                int deletion_options, index;
                display(linked_list_type, doubly_head, doubly_tail, singly_head, circular_head);
                printf("\n--- Deletion Options ---\n");
                printf("1. Delete at beginning\t");
                printf("2. Delete at index\t");
                printf("3. Delete at end\t");
                printf("4. Go Back\t");
                printf("\nEnter your choice: ");
                scanf("%d", &deletion_options);

                if (deletion_options == 4)
                    break;

                switch (deletion_options)
                {
                case 1:
                    if (linked_list_type == 1)
                        deleteSinglyAtBeginning(&singly_head);
                    else if (linked_list_type == 2)
                        deleteCircularAtBeginning(&circular_head);
                    else if (linked_list_type == 3)
                        deleteDoublyAtBeginning(&doubly_head, &doubly_tail);
                    break;
                case 2:
                    printf("Enter index: ");
                    scanf("%d", &index);
                    if (linked_list_type == 1)
                        deleteSinglyAtIndex(&singly_head, index);
                    else if (linked_list_type == 2)
                        deleteCircularAtIndex(&circular_head, index);
                    else if (linked_list_type == 3)
                        deleteDoublyAtIndex(&doubly_head, &doubly_tail, index);
                    break;
                case 3:
                    if (linked_list_type == 1)
                        deleteSinglyAtEnd(&singly_head);
                    else if (linked_list_type == 2)
                        deleteCircularAtEnd(&circular_head);
                    else if (linked_list_type == 3)
                        deleteDoublyAtEnd(&doubly_head, &doubly_tail);
                    break;
                default:
                    printf("Invalid option! Try again.\n");
                }
            }
            break;
        }
        default:
            printf("Invalid option! Try again.\n");
        }
    }

    return 0;
}

S_NODE *create_singly_node(int value, S_NODE *singly_temp)
{
    S_NODE *new_node = (S_NODE *)malloc(sizeof(S_NODE));
    if (!new_node)
    {
        perror("Memory allocation failed");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    if (singly_temp != NULL)
        singly_temp->next = new_node;
    return new_node;
}

D_NODE *create_doubly_node(int value, D_NODE *tail)
{
    D_NODE *new_node = (D_NODE *)malloc(sizeof(D_NODE));
    if (!new_node)
    {
        perror("Memory allocation failed");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = tail;
    if (tail != NULL)
        tail->next = new_node;
    return new_node;
}

void display(int linked_list_type, D_NODE *doubly_head, D_NODE *doubly_tail, S_NODE *singly_head, S_NODE *circular_head)
{
    if (linked_list_type == 1)
    {
        S_NODE *ptr = singly_head;
        if (ptr == NULL)
        {
            printf("List is empty!\n");
            return;
        }
        while (ptr)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
    else if (linked_list_type == 2)
    {
        S_NODE *ptr = circular_head;
        if (ptr == NULL)
        {
            printf("List is empty!\n");
            return;
        }
        do
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        } while (ptr != circular_head);
        printf("(Back to Head)\n");
    }
    else if (linked_list_type == 3)
    {
        if (doubly_head == NULL)
        {
            printf("List is empty!\n");
            return;
        }
        printf("Forward: ");
        D_NODE *ptr = doubly_head;
        while (ptr)
        {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\nBackward: ");
        D_NODE *qtr = doubly_tail;
        while (qtr)
        {
            printf("%d <- ", qtr->data);
            qtr = qtr->prev;
        }
        printf("NULL\n");
    }
}

void insertSinglyAtBeginning(S_NODE **head, int value)
{
    S_NODE *new_node = (S_NODE *)malloc(sizeof(S_NODE));
    if (!new_node)
    {
        perror("Memory allocation failed");
        exit(1);
    }
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void insertSinglyAtIndex(S_NODE **head, int index, int value)
{
    if (index == 0)
    {
        insertSinglyAtBeginning(head, value);
        return;
    }
    S_NODE *temp = *head;
    int i = 0;
    while (temp && i < index - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("Index out of bounds!\n");
        return;
    }
    S_NODE *new_node = (S_NODE *)malloc(sizeof(S_NODE));
    if (!new_node)
    {
        perror("Memory allocation failed");
        exit(1);
    }
    new_node->data = value;
    new_node->next = temp->next;
    temp->next = new_node;
}

void insertSinglyAtEnd(S_NODE **head, int value)
{
    S_NODE *new_node = (S_NODE *)malloc(sizeof(S_NODE));
    if (!new_node)
    {
        perror("Memory allocation failed");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    S_NODE *temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
}

void insertCircularAtBeginning(S_NODE **head, int value)
{
    S_NODE *new_node = (S_NODE *)malloc(sizeof(S_NODE));
    if (!new_node)
    {
        perror("Memory allocation failed");
        exit(1);
    }
    new_node->data = value;
    if (*head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
    }
    else
    {
        S_NODE *tail = *head;
        while (tail->next != *head)
            tail = tail->next;
        new_node->next = *head;
        *head = new_node;
        tail->next = *head;
    }
}

void insertCircularAtIndex(S_NODE **head, int index, int value)
{
    if (index == 0)
    {
        insertCircularAtBeginning(head, value);
        return;
    }
    if (*head == NULL)
    {
        printf("List is empty, cannot insert at index %d\n", index);
        return;
    }
    S_NODE *temp = *head;
    int i = 0;
    do
    {
        if (i == index - 1)
            break;
        temp = temp->next;
        i++;
    } while (temp != *head);
    if (i != index - 1)
    {
        printf("Index out of bounds!\n");
        return;
    }
    S_NODE *new_node = (S_NODE *)malloc(sizeof(S_NODE));
    if (!new_node)
    {
        perror("Memory allocation failed");
        exit(1);
    }
    new_node->data = value;
    new_node->next = temp->next;
    temp->next = new_node;
}

void insertCircularAtEnd(S_NODE **head, int value)
{
    if (*head == NULL)
    {
        insertCircularAtBeginning(head, value);
        return;
    }
    S_NODE *new_node = (S_NODE *)malloc(sizeof(S_NODE));
    if (!new_node)
    {
        perror("Memory allocation failed");
        exit(1);
    }
    new_node->data = value;
    S_NODE *temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    new_node->next = *head;
    temp->next = new_node;
}

void insertDoublyAtBeginning(D_NODE **head, D_NODE **tail, int value)
{
    D_NODE *new_node = (D_NODE *)malloc(sizeof(D_NODE));
    if (!new_node)
    {
        perror("Memory allocation failed");
        exit(1);
    }
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = *head;
    if (*head)
        (*head)->prev = new_node;
    *head = new_node;
    if (*tail == NULL)
        *tail = new_node;
}

void insertDoublyAtIndex(D_NODE **head, D_NODE **tail, int index, int value)
{
    if (index == 0)
    {
        insertDoublyAtBeginning(head, tail, value);
        return;
    }
    D_NODE *temp = *head;
    int i = 0;
    while (temp && i < index - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("Index out of bounds!\n");
        return;
    }
    D_NODE *new_node = (D_NODE *)malloc(sizeof(D_NODE));
    if (!new_node)
    {
        perror("Memory allocation failed");
        exit(1);
    }
    new_node->data = value;
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next)
        temp->next->prev = new_node;
    temp->next = new_node;
    if (new_node->next == NULL)
        *tail = new_node;
}

void insertDoublyAtEnd(D_NODE **head, D_NODE **tail, int value)
{
    if (*tail == NULL)
    {
        insertDoublyAtBeginning(head, tail, value);
        return;
    }
    D_NODE *new_node = (D_NODE *)malloc(sizeof(D_NODE));
    if (!new_node)
    {
        perror("Memory allocation failed");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = *tail;
    (*tail)->next = new_node;
    *tail = new_node;
}

void deleteSinglyAtBeginning(S_NODE **head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    S_NODE *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteSinglyAtIndex(S_NODE **head, int index)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if (index == 0)
    {
        deleteSinglyAtBeginning(head);
        return;
    }
    S_NODE *temp = *head;
    int i = 0;
    while (temp && i < index - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Index out of bounds!\n");
        return;
    }
    S_NODE *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}

void deleteSinglyAtEnd(S_NODE **head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    S_NODE *temp = *head;
    while (temp->next->next)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteCircularAtBeginning(S_NODE **head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }
    S_NODE *tail = *head;
    while (tail->next != *head)
        tail = tail->next;
    S_NODE *temp = *head;
    *head = (*head)->next;
    tail->next = *head;
    free(temp);
}

void deleteCircularAtIndex(S_NODE **head, int index)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if (index == 0)
    {
        deleteCircularAtBeginning(head);
        return;
    }
    S_NODE *temp = *head;
    int i = 0;
    do
    {
        if (i == index - 1)
            break;
        temp = temp->next;
        i++;
    } while (temp != *head);
    if (temp->next == *head)
    {
        printf("Index out of bounds!\n");
        return;
    }
    S_NODE *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}

void deleteCircularAtEnd(S_NODE **head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }
    S_NODE *temp = *head;
    while (temp->next->next != *head)
        temp = temp->next;
    free(temp->next);
    temp->next = *head;
}

void deleteDoublyAtBeginning(D_NODE **head, D_NODE **tail)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    D_NODE *temp = *head;
    *head = (*head)->next;
    if (*head)
        (*head)->prev = NULL;
    else
        *tail = NULL;
    free(temp);
}

void deleteDoublyAtIndex(D_NODE **head, D_NODE **tail, int index)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    if (index == 0)
    {
        deleteDoublyAtBeginning(head, tail);
        return;
    }
    D_NODE *temp = *head;
    int i = 0;
    while (temp && i < index)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("Index out of bounds!\n");
        return;
    }
    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    if (temp == *tail)
        *tail = temp->prev;
    free(temp);
}

void deleteDoublyAtEnd(D_NODE **head, D_NODE **tail)
{
    if (*tail == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    D_NODE *temp = *tail;
    *tail = (*tail)->prev;
    if (*tail)
        (*tail)->next = NULL;
    else
        *head = NULL;
    free(temp);
}
