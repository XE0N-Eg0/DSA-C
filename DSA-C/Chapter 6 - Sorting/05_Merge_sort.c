#include <stdio.h>

void merge(int A[], int left, int mid, int right);
void merge_sort(int *arr, int left, int right);
void print_array(int *arr, int left, int right);

int main(int argc, char const *argv[])
{

  int array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  print_array(array, 0, 10);
  merge_sort(array,0,9);
  print_array(array,0,10);
  return 0;
}

void print_array(int *arr, int left, int right)
{
  for (int i = 0; i < right; i++)
  {
    printf(" %d", arr[i]);
  }
  printf("\n");
}

void merge(int A[], int left, int mid, int right)
{
  int i, j, k;
  int B[100];
  i = left;
  j = mid + 1;
  k = left;

  while (i <= mid && j <= right)
  {
    if (A[i] < A[j])
    {
      B[k] = A[i];
      i++;
      k++;
    }
    else if (A[j] < A[i])
    {
      B[k] = A[j];
      j++;
      k++;
    }
  }
  while (i <= mid)
  {
    B[k] = A[i];
    i++;
    k++;
  }
  while (j <= right)
  {
    B[k] = A[j];
    j++;
    k++;
  }

  for (int i = 0; i <= right; i++)
  {
    A[i] = B[i];
  }
}

void merge_sort(int *arr, int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;

    merge_sort(arr, left, mid);

    merge_sort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}