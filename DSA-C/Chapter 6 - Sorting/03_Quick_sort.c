#include <stdio.h>

void quick_sort(int arr[], int low, int high);
int hoare_partition(int arr[], int low, int high);
void print_array(int arr[], int size);

int main() {
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = 10;

    printf("Before Sorting:\n");
    print_array(arr, size);

    quick_sort(arr, 0, size - 1);

    printf("After Sorting:\n");
    print_array(arr, size);

    return 0;
}

int hoare_partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (j >= low && arr[j] > pivot)
            j--;

        if (i >= j)
            break;

        // swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Swap pivot with arr[j]
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = hoare_partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf(" %d", arr[i]);
    printf("\n");
}
