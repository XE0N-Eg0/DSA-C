#include <stdio.h>
#include <stdlib.h>

void Display(int arr[], int size);
void Delete_at_Index(int array[],int *size, int index);


int main(int argc, char const *argv[])
{
    int index,option;
    int array[] = {1,2,3,4,5};
    int size = sizeof(array)/sizeof(array[0]);
    
    do
    {
        printf("\nCurrent Array: \n");
        Display(array,size);

        printf("\nCHOOSE AN OPERTATION: \n");
        printf("1.Delete at an index\n");
        printf("2.Delete at an begining\n");
        printf("3.Delete at end\n");
        printf("4.Exit\n");
        scanf("%d",&option);

        switch (option)
        {
            case 1:
                printf("Enter a valid index: ");
                scanf("%d",&index);
                Delete_at_Index(array,&size,index); 
                printf("\n");

                break;
            case 2:
                printf("\nDeleting the 1st element!!!\n");
                Delete_at_Index(array,&size,0); // as the begining index of any array is always zero; index = 0
                printf("\n");

                break;
            case 3:
                printf("\nDeleting the last element!!!\n");
                Delete_at_Index(array,&size,size-1); // last index of the arrry = size -1
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            
            default:
                printf("INVALID OPTION\n");
                
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

void Delete_at_Index(int array[],int *size, int index){

    if (index < 0 || index > *size) { // check if the postition is valid
        printf("Invalid position!\n");
        exit(-1); // exits the code with -1
    }
    
    for (int i = index; i < *size - 1; i++)
    {
        array[i] = array[i+1]; // this  shifts the  elements to left
    }
    (*size)--; // size -= 1 coz we deleted an element reducing thus reducing size
}
