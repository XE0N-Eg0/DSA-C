#include <stdio.h>

static int array[] = {10,1,9,2,8,3,7,4,6,5}; // Prime Global Array [cant be const]


void Bubble_Sort(int array[], int size);
void swap(int * a ,int * b);
void Print_Array(int array[],int size);

int main(int argc, char const *argv[])

{
    int size = sizeof(array)/sizeof(array[0]);
    Print_Array(array,size);
    Bubble_Sort(array,size);
    Print_Array(array,size);
    
    return 0;
}

void Bubble_Sort(int array[], int size){
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            if (array[j]>array[j+1]) // if the element before is larger than next it gets swapped [ascending]
            {
                swap(&array[j],&array[j+1]); // passed by reference ('&')
            }
            
        }
        
    }
    
}

void swap(int * a ,int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Print_Array(int array[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}