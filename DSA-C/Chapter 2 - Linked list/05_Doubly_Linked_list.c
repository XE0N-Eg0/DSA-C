#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedList {
    int data;
    struct DoublyLinkedList *next;
    struct DoublyLinkedList *prev;
} NODE;

NODE* create_node(int value, NODE *prev_node) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if (new_node == NULL) {
        perror("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = prev_node; // this is the connection factor links the nodes backwards

    if (prev_node != NULL) {
        prev_node->next = new_node; // this is the connection factor that links forward
    }

    return new_node;
}

void displayDoublyLinkedList(NODE *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    NODE *temp = head;
    printf("Doubly Linked List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayDoublyLinkedListReverse(NODE *tail) {
    if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }

    NODE *temp = tail;
    printf("Doubly Linked List (reverse): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes. Please enter a positive integer.\n");
        return 1;
    }

    NODE *head = NULL;
    NODE *tail = NULL;

    for (int i = 1; i <= n; i++) {
        int value;
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        if (head == NULL) {
            head = create_node(value, NULL);
            tail = head;
        } else {
            tail = create_node(value, tail);
        }
    }

    displayDoublyLinkedList(head);
    displayDoublyLinkedListReverse(tail);

    return 0;
}
