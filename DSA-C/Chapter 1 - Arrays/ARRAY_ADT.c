#include <stdio.h>
#include <stdlib.h>

typedef struct ARRAY_ADT
{
    int total_size;
    int used_size;
    int *data;
} ADT;

void create_array(ADT *a, int used);
void input(ADT *a);
void display(ADT *a);
void insert(ADT *a, int element, int index);
void delete(ADT *a, int index);
int linear_search(ADT *a, int element);
int binary_search(ADT *a, int element, int start, int end);
void reset_array(ADT *a);

int main(int argc, char const *argv[])
{
    ADT Array_1;
    
    int used, option, element, index;
    printf("Enter the number of elemets: ");
    scanf("%d", &used);
    create_array(&Array_1, used);
    do
    {
        printf("Current Array: \n");
        display(&Array_1);

        printf("ARRAY OPERATIONS: ");
        printf("1. Input elements in array");
        printf("2. Insert elements in array");
        printf("3. Delete elements in array");
        printf("4. Search elements in array");
        printf("5. Reset array");
        printf("6. Exit");
        scanf("%d",&option);

        switch (option)
        {
            case 1:
                input(&Array_1);
                break;
            case 2:
                printf("\tChoose accordingly");
                printf("\t1. Insert at Begining");
                printf("\t2. Insert at an index");
                printf("\t3. Insert at end");
                scanf("%d", &option);
                switch (option)
                {
                    case 1:
                        printf("Enter the element to insert: ");
                        scanf("%d",&element);
                        insert(&Array_1,element,0);
                        break;
                    case 2: 
                        printf("Enter the element to insert: ");
                        scanf("%d",&element);
                        printf("Enter the index of insertion");
                        scanf("%d",&index);
                        insert(&Array_1,element,index);
                        break;
                    case 3:
                        printf("Enter the element to insert: ");
                        scanf("%d",&element);
                        insert(&Array_1,element,Array_1.used_size);
                    case 4:
                        int target,b_a;
                        printf("Enter the element to insert: ");
                        scanf("%d",&element);
                        printf("Enter the target element: ");
                        scanf("%d",&target);
                        printf("Enter before or after the element(B = -1 / A = +1)");
                        scanf("%d",&b_a);
                        insert(&Array_1,element,linear_search(&Array_1,target)+b_a);
                    default:
                        printf("INVALID INSERTION CHOICE !!!!");
                        break;
                }
            case 3: 
                printf("\tChoose accordingly");
                printf("\t1. Delete at Begining");
                printf("\t2. Delete at an index");
                printf("\t3. Delete a specific element");
                printf("\t4. Delete at end");
                scanf("%d", &option);
                switch (option)
                {
                case 1:
                    printf("Deleting the 1st element");
                    delete(&Array_1,0);
                    break;
                case 2:
                default:
                    break;
                }

            default:
                break;
        }
    } while (option != 6);

    return 0;
}

// Step-1. created the arrays as per user inputs
void create_array(ADT *a, int used)
{

    a->total_size = 1000;
    a->used_size = used;
    a->data = (int *)malloc(1000 * sizeof(int));
}

// Step-2. asked for inputs
void input(ADT *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the %d element : ", i);
        scanf("%d", &(a->data)[i]);
    }
    printf("Input finished\n");
}

// Step-3. displaying the latest array
void display(ADT *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d ", a->data[i]);
    }
    printf("\n");
}

// Step-4. insertions in array
void insert(ADT *a, int element, int index)
{
    if (a->used_size >= a->total_size) {
        printf("Array is full, cannot insert more elements.\n");
        return;
    }

    for (int i = a->used_size; i >= index; i--)
    {
        a->data[i + 1] = a->data[i];
    }
    a->data[index] = element;
    a->used_size += 1;
}

// Step-5. deletion in array
void delete(ADT *a, int index)
{
    if (a->used_size == 0) {
        printf("Array is empty, nothing to delete.\n");
        return;
    }

    for (int i = index; i < a->used_size - 1; i++)
    {
        a->data[i] = a->data[i + 1];
    }
    a->used_size -= 1;
}

int linear_search(ADT *a, int element)
{
    for (int i = 0; i < a->used_size; i++)
    {
        if (element == a->data[i])
        {
            printf("element found at %d \n", i);
            return i;
        }
        
    }
    printf("element not found \n");
    return -1;
}

int binary_search(ADT *a, int element, int start, int end) {
    if (start > end) {
        printf("Element not found\n");
        return -1;
    }

    int mid = start + ((end - start) / 2);

    if (a->data[mid] == element) {
        printf("Element found at %d\n", mid);
        return mid;
    } else if (element > a->data[mid]) {
        return binary_search(a, element, mid + 1, end);
    } else {
        return binary_search(a, element, start, mid - 1);
    }
}

void reset_array(ADT *a) {
    a->used_size = 0;
    printf("Array has been reset.\n");
}
