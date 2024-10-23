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
    
    int used, option, element, index,b_a,target;
    printf("Enter the number of elemets: ");
    scanf("%d", &used);
    create_array(&Array_1, used);
    do
    {
        printf("Current Array: \n");
        display(&Array_1);

        printf("ARRAY OPERATIONS: \n");
        printf("1. Input elements in array\n");
        printf("2. Insert elements in array\n");
        printf("3. Delete elements in array\n");
        printf("4. Search elements in array\n");
        printf("5. Add more spaces(rellocate)\n");
        printf("6. Reset array\n");
        printf("7. Exit\n");
        scanf("%d",&option);

        switch (option) // PRIME SWITCH CASE - 1
        {
            case 1:
                input(&Array_1);
                break;
            case 2:
                printf("Choose accordingly: \n");
                printf("\t 1. Insert at Begining\t");
                printf("\t 2. Insert at an index\t");
                printf("\t 3. Insert at end\t");
                printf("\t 4. Insert at specific the element position\n");
                printf("\t");
                scanf("%d", &option);
                switch (option) // INSERT SWITCH CASE - 1.1
                {
                    case 1:
                        printf("\t Enter the element to insert: ");
                        scanf("%d",&element);
                        insert(&Array_1,element,0);
                        break;
                    case 2: 
                        printf("\t Enter the element to insert: ");
                        scanf("%d",&element);
                        printf("\t Enter the index of insertion: ");
                        scanf("%d",&index);
                        insert(&Array_1,element,index);
                        break;
                    case 3:
                        printf("\t Enter the element to insert: ");
                        scanf("%d",&element);
                        insert(&Array_1,element,Array_1.used_size);
                        break;
                    case 4:
                        printf("\t Enter the element to insert: ");
                        scanf("%d",&element);
                        printf("\t Enter the target element: ");
                        scanf("%d",&target);
                        printf("\t Enter before or after the element(B = -1 / A = +1): ");
                        scanf("%d",&b_a);
                        insert(&Array_1,element,linear_search(&Array_1,target)+b_a);
                        break;
                    default:
                        printf("\t INVALID INSERTION CHOICE !!!!\n");
                        break;
                }
                break; // BREAK of 1.1
            case 3: 
                printf("Choose accordingly: \n");
                printf("\t 1. Delete at Begining\t");
                printf("\t 2. Delete at an index\t");
                printf("\t 3. Delete a specific element\t");
                printf("\t 4. Delete at end\n");
                printf("\t");
                scanf("%d", &option);
                switch (option) // DELETE SWITCH CASE - 1.2
                {
                case 1:
                    printf("\t Deleting the 1st element\n");
                    delete(&Array_1,0);
                    break;
                case 2:
                    printf("\t Enter an index: ");
                    scanf("%d",&index);
                    delete(&Array_1,index);
                    break;
                case 3:
                    printf("\t Enter the element to delete: ");
                    scanf("%d",&target);

                    delete(&Array_1,linear_search(&Array_1,target));
                    break;
                case 4: 
                    printf("\tDeleting at end");
                    delete(&Array_1,Array_1.used_size-1);
                    break;

                default:
                    printf("\t INVALID DELETION CHOICE !!!\n");
                    break;
                }
                break; // BREAK of 1.2
            case 4:
                printf("Choose accordingly: \n");
                printf("\t 1. linear search");
                printf("\t 2. Binary search");
                scanf("%d",&option);
                switch (option) // SEARCH SWITCH CASE - 1.3
                {
                case 1:
                    printf("\t Enter the element to search: ");
                    scanf("%d",&element);
                    int search_result = linear_search(&Array_1,element);
                    if (search_result == -1)
                    {
                        printf("Element not found\n");
                        break;
                    }
                    printf("Element (%d) is found at: %d",element,search_result);
                    break;
                case 2:
                    printf("\t WARNING CHECK ARRAY SORTING !!! \n");
                    printf("\t Enter the element to search: ");
                    scanf("%d",&element);
                    int search_result = binary_search(&Array_1,element,0,Array_1.used_size-1);
                    if (search_result == -1)
                    {
                        printf("Element doesnt exsist\n");
                        break;
                    }
                    printf("Element (%d) is found at: %d",element,search_result);
                    break;
                
                default:
                    printf("\t INVALID SEARCHING CHOICE !!!");
                    break;
                }
                break; // BREAK of 1.3
            case 6:
                printf("RESETING ARRAY !!!\n");
                reset_array(&Array_1);
                break;
            case 7:
                reset_array(&Array_1);
                printf("\n");
                printf("Exiting....");
                exit(0);
                break;
            default:
                printf("INVALID CHOICE !!!\n");
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
    a->data = (int *)calloc(1000, sizeof(int));
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

// Step-6. linear search deplyoment
int linear_search(ADT *a, int element)
{
    for (int i = 0; i < a->used_size; i++)
    {
        if (element == a->data[i])
        {
            return i;
        }
        
    }
    return -1;
}

// Step-7. binary search deplyoment
int binary_search(ADT *a, int element, int start, int end) {
    if (start > end) {
        return -1;
    }

    int mid = start + ((end - start) / 2);

    if (a->data[mid] == element) {
        return mid;
    } else if (element > a->data[mid]) {
        return binary_search(a, element, mid + 1, end);
    } else {
        return binary_search(a, element, start, mid - 1);
    }
}

// Step-8. free array
void reset_array(ADT *a) {
    a->used_size = 0;
    printf("Array has been reset.\n");
}
