# Sorting Algorithms Notes

## 1. Bubble Sort
### Description:
Bubble Sort is a simple comparison-based sorting algorithm. It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the list is sorted.

### Characteristics:
- **Time Complexity:**
  - Best Case: O(n)
  - Worst Case: O(n²)
  - Average Case: O(n²)
- **Space Complexity:** O(1) (In-place)
- **Stability:** Yes

### Algorithm:
1. Start with the first element of the list.
2. Compare it with the next element in the list.
3. If the first element is greater than the second, swap them to arrange in order.
4. Continue comparing each adjacent pair of elements, moving the largest unsorted element to its correct position by the end of the list.
5. Repeat this process for all elements, gradually reducing the range of unsorted elements.

### Pseudo Code:
```
for i from 0 to n-1:
    for j from 0 to n-i-2:
        if array[j] > array[j+1]:
            swap(array[j], array[j+1])
```

---

## 2. Insertion Sort
### Description:
Insertion Sort is a simple sorting algorithm that builds the final sorted array one element at a time by repeatedly inserting elements into their correct position.

### Characteristics:
- **Time Complexity:**
  - Best Case: O(n)
  - Worst Case: O(n²)
  - Average Case: O(n²)
- **Space Complexity:** O(1) (In-place)
- **Stability:** Yes

### Algorithm:
1. Start with the second element in the array as the key.
2. Compare the key with the elements before it in the sorted portion of the array.
3. Shift all elements greater than the key one position to the right.
4. Insert the key into its correct position in the sorted portion.
5. Move to the next element and repeat until the entire array is sorted.

### Pseudo Code:
```
for i from 1 to n-1:
    key = array[i]
    j = i-1
    while j >= 0 and array[j] > key:
        array[j+1] = array[j]
        j = j-1
    array[j+1] = key
```

---

## 3. Quick Sort
### Description:
Quick Sort is a divide-and-conquer algorithm that selects a pivot element and partitions the array around the pivot. Elements smaller than the pivot are moved to its left, and elements larger to its right.

### Characteristics:
- **Time Complexity:**
  - Best Case: O(n log n)
  - Worst Case: O(n²) (occurs when the pivot is the smallest or largest element)
  - Average Case: O(n log n)
- **Space Complexity:** O(log n) (In-place but requires recursion stack)
- **Stability:** No

### Algorithm:
1. Choose a pivot element, often the last element in the array.
2. Partition the array into two subarrays: one with elements smaller than the pivot and one with elements larger.
3. Place the pivot in its correct position between the two subarrays.
4. Recursively apply Quick Sort to the subarrays until they are sorted.

### Pseudo Code:
```
function quickSort(array, low, high):
    if low < high:
        pivotIndex = partition(array, low, high)
        quickSort(array, low, pivotIndex-1)
        quickSort(array, pivotIndex+1, high)

function partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j from low to high-1:
        if array[j] <= pivot:
            i = i + 1
            swap(array[i], array[j])
    swap(array[i+1], array[high])
    return i+1
```

---

## 4. Selection Sort
### Description:
Selection Sort repeatedly selects the smallest (or largest) element from the unsorted portion of the list and moves it to the sorted portion.

### Characteristics:
- **Time Complexity:**
  - Best Case: O(n²)
  - Worst Case: O(n²)
  - Average Case: O(n²)
- **Space Complexity:** O(1) (In-place)
- **Stability:** No

### Algorithm:
1. Divide the array into sorted and unsorted portions.
2. Find the smallest element in the unsorted portion.
3. Swap the smallest element with the first element of the unsorted portion.
4. Expand the sorted portion by one element and repeat until the entire array is sorted.

### Pseudo Code:
```
for i from 0 to n-1:
    minIndex = i
    for j from i+1 to n-1:
        if array[j] < array[minIndex]:
            minIndex = j
    swap(array[i], array[minIndex])
```

---

## 5. Merge Sort
### Description:
Merge Sort is a divide-and-conquer algorithm that divides the array into halves, sorts each half, and merges them back together.

### Characteristics:
- **Time Complexity:**
  - Best Case: O(n log n)
  - Worst Case: O(n log n)
  - Average Case: O(n log n)
- **Space Complexity:** O(n) (requires additional memory for merging)
- **Stability:** Yes

### Algorithm:
1. Divide the array into two halves.
2. Recursively apply Merge Sort to each half until the subarrays have one element each.
3. Merge the two sorted subarrays back into a single sorted array.

### Pseudo Code:
```
function mergeSort(array):
    if length(array) > 1:
        mid = length(array) / 2
        left = array[0:mid]
        right = array[mid:]

        mergeSort(left)
        mergeSort(right)

        i = j = k = 0

        while i < length(left) and j < length(right):
            if left[i] < right[j]:
                array[k] = left[i]
                i = i + 1
            else:
                array[k] = right[j]
                j = j + 1
            k = k + 1

        while i < length(left):
            array[k] = left[i]
            i = i + 1
            k = k + 1

        while j < length(right):
            array[k] = right[j]
            j = j + 1
            k = k + 1
```

---

## 6. Heap Sort
### Description:
Heap Sort uses a binary heap data structure to sort elements. It first builds a max heap, then repeatedly extracts the maximum element and rebuilds the heap.

### Characteristics:
- **Time Complexity:**
  - Best Case: O(n log n)
  - Worst Case: O(n log n)
  - Average Case: O(n log n)
- **Space Complexity:** O(1) (In-place)
- **Stability:** No

### Algorithm:
1. Build a max heap from the array.
2. Swap the root of the heap (largest element) with the last element in the array.
3. Reduce the size of the heap and heapify the root element to restore the max heap property.
4. Repeat the process until the heap size is reduced to 1.

### Pseudo Code:
```
function heapSort(array):
    buildMaxHeap(array)
    for i from length(array)-1 to 1:
        swap(array[0], array[i])
        heapify(array, 0, i)

function buildMaxHeap(array):
    for i from length(array)//2-1 to 0:
        heapify(array, i, length(array))

function heapify(array, i, heapSize):
    largest = i
    left = 2*i + 1
    right = 2*i + 2

    if left < heapSize and array[left] > array[largest]:
        largest = left
    if right < heapSize and array[right] > array[largest]:
        largest = right
    if largest != i:
        swap(array[i], array[largest])
        heapify(array, largest, heapSize)
```

---

## Comparison of Sorting Algorithms

| Algorithm       | Time Complexity (Best) | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity | Stability |
|-----------------|-------------------------|---------------------------|--------------------------|------------------|-----------|
| Bubble Sort     | O(n)                   | O(n²)                    | O(n²)                   | O(1)             | Yes       |
| Insertion Sort  | O(n)                   | O(n²)                    | O(n²)                   | O(1)             | Yes       |
| Quick Sort      | O(n log n)             | O(n log n)               | O(n²)                   | O(log n)         | No        |
| Selection Sort  | O(n²)                  | O(n²)                    | O(n²)                   | O(1)             | No        |
| Merge Sort      | O(n log n)             | O(n log n)               | O(n log n)              | O(n)             | Yes       |
| Heap Sort       | O(n log n)             | O(n log n)               | O(n log n)              | O(1)             | No        |
