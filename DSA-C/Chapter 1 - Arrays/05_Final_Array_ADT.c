#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct ARRAY_ADT
{
    int total_size;
    int used_size;
    int *data;
} ADT;

void create_array(ADT *a, int used);
void input(ADT *a, int starting);
void display(ADT *a);
void insert(ADT *a, int element, int index);
void delete(ADT *a, int index);
int linear_search(ADT *a, int element);
int binary_search(ADT *a, int element, int start, int end);
void reset_array(ADT *a);
void rellocate_spaces(ADT *a, int extra_spaces);

int main(int argc, char const *argv[])
{
    ADT Array_1; // declared the array 
    
    int used, option, element, index,b_a,target, search_result,extra_spaces; // the varrs we will need 
    int insert_option, delete_option, search_option;        // varr for sub switch cases 

    printf("Enter the number of elemets: ");
    scanf("%d", &used);
    create_array(&Array_1, used);           // allocated  the array 
    do
    {
        printf("\n");
        printf("Current Array: \n");
        display(&Array_1);

        printf("ARRAY OPERATIONS: \n");             // MAIN MENU
        printf("1. Input elements in array\n");
        printf("2. Insert elements in array\n");
        printf("3. Delete elements in array\n");
        printf("4. Search elements in array\n");
        printf("5. Add more spaces(rellocate)\n");
        printf("6. Reset array\n");
        printf("7. Exit\n");
        scanf("%d",&option);

        switch (option)                             // PRIME SWITCH - 1 (main menu)
        {
            case 1:                                 // PRIME INPUT CASE
                input(&Array_1,0);
                break;
            case 2:                                 // PRIME INSERT CASE
                do
                {
                    printf("\n");
                    printf("Current Array: \n");
                    display(&Array_1);
                    printf("Choose accordingly: \n");
                    printf("\t 1. Insert at Begining\t");
                    printf("\t 2. Insert at an index\t");
                    printf("\t 3. Insert at end\t");
                    printf("\t 4. Insert at specific the element position\n");
                    printf("\t 5. Exit to main menu\n");
                    printf("\t ");
                    scanf("%d", &insert_option);
                    switch (insert_option)              // Insert Sub switch case - 1.1
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
                            search_result = linear_search(&Array_1, target);
                            if (search_result == -1)
                            {
                                printf("\t %d do not exsist !!!\n", target);
                                break;
                            }
                            printf("\t Enter before or after the element(B = 0/ A = 1): ");
                            scanf("%d",&b_a);
                            insert(&Array_1,element,search_result+b_a);
                            break;
                        case 5:
                            printf("\t Exiting to main menu......\n");
                            break;
                        default:
                            printf("\t INVALID INSERTION CHOICE !!!!\n");
                            break;
                    }
                } while (insert_option != 5 );
                break;                                  // Break of 1.1 (Insertion case)
                
                
            case 3:                                     // PRIME DELETION CASE
                do
                {
                    printf("\n");
                    printf("Current Array: \n");
                    display(&Array_1);
                    printf("Choose accordingly: \n");
                    printf("\t 1. Delete at Begining\t");
                    printf("\t 2. Delete at an index\t");
                    printf("\t 3. Delete at end\t");
                    printf("\t 4. Delete a specific element\n");
                    printf("\t 5. Exit to main menu\n");
                    printf("\t ");
                    scanf("%d", &delete_option);
                    switch (delete_option)               // Delete sub switch case - 1.2
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
                            printf("\tDeleting at end");
                            delete(&Array_1,Array_1.used_size-1);
                            break;
                        case 4:
                            printf("\t Enter the element to delete: ");
                            scanf("%d",&target);
                            search_result = linear_search(&Array_1, target);
                            if (search_result == -1)
                            {
                                printf("\t %d do not exsist !!!\n",target);
                                break;
                            }
                            delete(&Array_1,search_result);
                            break;
                        case 5:
                            printf("Exiting to main menu.....!! ");
                            break;
                        default:
                            printf("\t INVALID DELETION CHOICE !!!\n");
                            break;
                    }
                } while (delete_option != 5);
                break;                                   // break of 1.2 (Delete case)
                
            case 4:                                      // PRIME SEARCH CASE 
                do
                {
                    printf("Choose accordingly: \n");
                    printf("\t 1. linear search");
                    printf("\t 2. Binary search");
                    printf("\t 3. Exit to main menu\n");
                    scanf("%d",&search_option);
                    switch (search_option)                  // Search sub switch case  - 1.3
                    {
                        case 1:
                            printf("\t Enter the element to search: ");
                            printf("\t");
                            scanf("%d",&element);
                            search_result = linear_search(&Array_1,element);
                            if (search_result == -1)
                            {
                                printf("\t Element not found\n");
                                break;
                            }
                            printf("\t Element (%d) is found at: %d\n",element,search_result);
                            break;
                        case 2:
                            printf("\t WARNING CHECK ARRAY SORTING !!! \n");
                            printf("\t Enter the element to search: ");
                            scanf("%d",&element);
                            search_result = binary_search(&Array_1,element,0,Array_1.used_size-1);
                            if (search_result == -1)
                            {
                                printf("\t Element doesnt exsist\n");
                                break;
                            }
                            printf("\t Element (%d) is found at: %d\n",element,search_result);
                            break;
                        case 3:
                            printf("\t Exiting to main menu.....!!\n");
                        
                        default:
                            printf("\t INVALID SEARCHING CHOICE !!!");
                            break;
                    }
                } while (search_option != 3 );
                break;                                      // Break of 1.3 (search case)

            case 5:                                         // PRIME RELLOCATE CASE
                printf("Enter the amount of extra spaces you want: ");
                scanf("%d",&extra_spaces);
                rellocate_spaces(&Array_1,extra_spaces);
                printf("Enter the values of extra %d spaces: \n",extra_spaces);
                input(&Array_1,Array_1.used_size-extra_spaces);
                
                break;
            case 6:                                         // PRIME RESET CASE
                printf("RESETING ARRAY !!!\n");
                reset_array(&Array_1);
                break;
            case 7:                                         // PRIME EXIT CASE
                free(Array_1.data);
                printf("Exiting....!!!\n");
                exit(0);
                break;
            default:                                        // PRIME DEFAULT 
                printf("INVALID CHOICE !!!\n");
                break;
        }
    } while (option != 7);

    return 0;
}

// Step-1. created the arrays as per user inputs
void create_array(ADT *a, int used)
{

    a->total_size = MAX;
    a->used_size = used;
    a->data = (int *)calloc(MAX, sizeof(int));
}

// Step-2. asked for inputs
void input(ADT *a, int starting)
{
    for (int i = starting; i < a->used_size; i++)
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

    for (int i = 0; i < a->used_size; i++)
    {
        a->data[i] = 0;
    }
    printf("Array has been reset.\n");
    
}

// Step.9. relloacate more spaces
void rellocate_spaces(ADT *a,int extra_spaces){
    
    if (extra_spaces > MAX)
    {
        printf("Maxnimum limit reached !!!\n ");
        return;

    }

    a->used_size  +=  extra_spaces;

    for (int i = a->used_size - extra_spaces ; i < (a->used_size + extra_spaces); i++) //just for the reasons it should not show garbage values
    {
        a->data[i] = 0; // assings the new spaces with 0
    } 
}