#include <stdio.h>

static int array[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5}; // Prime Global Array [cant be const]

void Selection_Sort(int array[], int size);
void swap(int *a, int *b);
void Print_Array(int array[], int size);

int main(int argc, char const *argv[])
{
    int size = sizeof(array) / sizeof(array[0]);
    Print_Array(array, size);
    Selection_Sort(array, size);
    Print_Array(array, size);

    return 0;
}

void Selection_Sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i; // Start with the current index as the minimum
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j; // Update the index of the minimum element
            }
        }
        // Swap the found minimum element with the first element
        swap(&array[i], &array[min_index]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Print_Array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
