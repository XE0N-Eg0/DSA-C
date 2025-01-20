#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[SIZE] = {NULL};

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int idx = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

int search(int key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];
    while (temp) {
        if (temp->key == key) return 1;
        temp = temp->next;
    }
    return 0;
}

void deleteKey(int key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];
    Node* prev = NULL;
    while (temp && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return;
    if (prev) prev->next = temp->next;
    else hashTable[idx] = temp->next;
    free(temp);
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]:", i);
        Node* temp = hashTable[i];
        while (temp) {
            printf(" %d ->", temp->key);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main() {
    insert(15); insert(25); insert(35); insert(45);
    display();
    printf("Search 25: %s\n", search(25) ? "Found" : "Not Found");
    deleteKey(25);
    display();
    return 0;
}
