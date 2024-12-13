#include <stdio.h>
#include <stdlib.h>

typedef struct CircularLinkedList {
    int data;
    struct CircularLinkedList *next;
} NODE;

NODE* create_node(int value, NODE *temp) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    if (new_node == NULL) {
        perror("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;

    if (temp != NULL) {
        temp->next = new_node;
    }

    return new_node;
}

void displayCircularLinkedList(NODE *head, int n) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    NODE *temp = head;
    printf("Circular Linked List: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", temp->data);
        temp = temp->next;
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
    NODE *temp = NULL;

    for (int i = 1; i <= n; i++) { // this makes regular single linked list
        int value;
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        if (head == NULL) {
            head = create_node(value, temp);
            temp = head;
        } else {
            temp = create_node(value, temp);
        }
    }

    if (temp != NULL) {
        temp->next = head; // makes it circular
    }

    displayCircularLinkedList(head, n);

    return 0;
}
