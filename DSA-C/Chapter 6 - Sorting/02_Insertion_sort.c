#include <stdio.h>

static int array[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5}; // Prime Global Array [cant be const]

void Insertion_Sort(int array[], int size);
void swap(int *a, int *b);
void Print_Array(int array[], int size);

int main(int argc, char const *argv[])

{
    int size = sizeof(array) / sizeof(array[0]);
    Print_Array(array, size);
    Insertion_Sort(array, size);
    Print_Array(array, size);

    return 0;
}

void Insertion_Sort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int current = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > current) // This loop runs untill j is 0 and it keeps shifting elements to next
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current; // inserts the element into correct position
    }
}

void Print_Array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}