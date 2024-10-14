
  

# Arrays in C

  

## 1. What are Arrays?

  

An **array** is a data structure that allows you to store multiple elements of the same type in a contiguous block of memory. Each element is accessed using an index, and the index of the first element starts from 0.

  

In C, arrays are defined with a specific size, which determines the number of elements that can be stored. Once declared, the size of an array cannot be changed.

### Initializating arrays

```c

int  array[10];

int myNumbers[] = {25, 50, 75, 100};

```

## 2. Advantages of an array

  

1.  **Constant-Time Access**: Arrays allow for constant-time (O(1)) access to any element using its index, making them very fast for retrieving or modifying elements.

  

2.  **Simple and Efficient**: Arrays are straightforward to use and efficient in terms of memory and access time, especially when the size is known in advance.

  

3.  **Contiguous Memory**: Arrays use contiguous memory locations, which is cache-friendly and can lead to faster execution on modern processors.

  
  

## 3. Disadvantages of Array :

  

1.  **Fixed Size**: Static arrays have a fixed size, so if the size of the data changes, resizing the array can be costly (involving creating a new array and copying elements).

  

2.  **Costly Insertion/Deletion**: Inserting or deleting elements at arbitrary positions in an array can be inefficient (O(n)), as it often requires shifting elements.

  

3.  **Inefficient Memory Use**: If an array is declared larger than needed, it wastes memory; if it is smaller than needed, it may need to be resized.# Arrays in C

---
# Array ADT STRUCTURE
```c
struct  Custom_Array
{						
int  max_size;  // max capacity of array
int  used_size; // capacity allocated
int  *data;		// pointer for the array
};
```
