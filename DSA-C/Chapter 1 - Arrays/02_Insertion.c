#include <stdio.h>
#include<stdlib.h>

void Insert(int arr[], int *size, int element, int index);
void Display(int arr[], int size);
void Insert_at_Begining(int arr[], int *size, int element);
void Insert_at_End(int arr[], int *size, int element);

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element, index, option;

    do {
        // Display original array
        printf("\nCurrent array: ");
        Display(arr, size);

        // Present the user with options for insertion
        printf("\nCHOOSE AN OPERATION:\n");
        printf("1. Insert at a specific index\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        // Process the user's option using switch-case
        switch (option) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the index: ");
                scanf("%d", &index);
                Insert(arr, &size, element, index);
                printf("Array after inserting at index %d: ", index);
                printf("\n");
                break;

            case 2:
                printf("Enter the element to insert at the beginning: ");
                scanf("%d", &element);
                Insert_at_Begining(arr, &size, element);
                printf("Array after inserting at the beginning: ");
                printf("\n");
                break;

            case 3:
                printf("Enter the element to insert at the end: ");
                scanf("%d", &element);
                Insert_at_End(arr, &size, element);
                printf("Array after inserting at the end: ");
                printf("\n");
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option! Please choose again.\n"); /*we could have made the switch case less cluttered by adding
                                                                     a fx to take values and index but that will introduce more complexity */ 
        }

    } while (option != 4);  // Continue until the user chooses to exit

    return 0;
}

void Insert(int arr[], int *size, int element, int index) {
    
    if (index < 0 || index > *size) { // check if the postition is valid
        printf("Invalid index!\n");
        exit(-1); // exits the code with -1
    }
    
    for (int i = (*size) - 1; i >= index; i--) { //it shifts the elements from backwards(end of array), coz form forward(i++) it isnt 
                                                    // or probably we need a temp var to store an element or swap it
        arr[i + 1] = arr[i];
    }
    arr[index] = element;    
    (*size)++; // size += 1 coz we added one element
}

void Display(int arr[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Insert_at_Begining(int arr[], int *size, int element) {
    Insert(arr, size, element, 0);  // Insert at index 0
}

void Insert_at_End(int arr[], int *size, int element) {
    Insert(arr, size, element, *size);  // Insert at the end of the array or at the size
}