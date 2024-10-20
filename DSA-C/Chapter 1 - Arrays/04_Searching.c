#include <stdio.h>
#include <stdlib.h>


void Display(int arr[], int size);
void linear_search(int arr[],int size, int target);
void binary_search_iterative(int arr[], int size, int target);
void binary_search_recursive(int arr[], int target, int start, int end);


int main(int argc, char const *argv[])
{
    int array[]= {1,2,4,5,6,7,8,9,10}; // taken a sorted array so that we can use both search methords
    int target, index, option, size ;
    size = sizeof(array)/sizeof(array[0]);
    do
    {
        printf("Current array:\n");
        Display(array,size);
        printf("\nCHOOSE AN OPERTATION: \n");
        printf("1.Linear search\n");
        printf("2.Binary search (Iterative)\n");
        printf("3.Binary search (Recursive)\n");
        printf("4.Exit\n");
        scanf("%d",&option);
        switch (option)
        {
            
            case 1:
                printf("Enter element to search : ");
                scanf("%d",&target);
                linear_search(array,size,target);
                printf("\n");
                break;
            case 2:
                printf("Enter element to search : ");
                scanf("%d",&target);
                binary_search_iterative(array,size,target);
                printf("\n");
                break;
            case 3:
                printf("Enter element to search : ");
                scanf("%d",&target);
                binary_search_recursive(array,target,0,size-1);
                printf("\n");
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Invalid Option!!!\n");
                break;
        }
        
    } while (option != 4);
    


    return 0;
}

void Display(int arr[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void linear_search(int arr[],int size, int target){

    for (int i = 0; i < size; i++)  
    {
        if (target == arr[i])   // checks all the values of index one by one for matching with target
        {
            printf("Element found at %d\n",i); // matches it gets printed
            return;
        }
        
    }

    printf("Element not found !!!\n");  // if not found the loop exits and this get printed
    return;
    
}

void binary_search_iterative(int arr[], int size, int target){

    int start = 0;      // start is assinged to the starting index
    int end = size-1;   // end is assinged to the last index [i.e. size -1]

    while(start<=end){

        int mid = start + ((end-start)/2);  // optimised formula for mid {explained in notes}

        if (target == arr[mid])
        {
            printf("Element found at %d\n", mid); // if target is found then it returns the index [mid]
            return;
        }
        else if (target>arr[mid])
        {
            start = mid+1;      // this narrows the search area, and shifts the search area to frist half
        }
        else if (target<arr[mid])
        {
            end = mid-1;        // this shifts the search area to  last half of array 
        }
    }
    printf("Target Not Found!!!\n");
        return;
}

void binary_search_recursive(int arr[], int target, int start, int end){
    if (start > end) {
        printf("Target Not Found!\n");
        return;
    }

    int mid = start + ((end-start)/2);

    if (target == arr[mid])
        {
            printf("Element found at %d", mid);
            return;
        }
        else if (target>arr[mid])      // recursively calls the 1st half for search
        {
            binary_search_recursive(arr,target, mid+1, end);
        }
        else if (target<arr[mid])      // recursively calls the last half for search
        {
            binary_search_recursive(arr,target, start, mid-1);  
        }
        
}