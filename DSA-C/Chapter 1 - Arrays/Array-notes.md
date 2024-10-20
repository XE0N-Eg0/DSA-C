
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
struct Custom_Array
{
int max_size; // max capacity of array
int used_size; // capacity allocated
int *data; // pointer for the array
};
```
**`max_size`** : We allocate a larger space that will be the actual total size of the array  that will be preserved for the future use and thus we can perform insertion or other operations smoothly.

**`used_size`** : This will be a part of the array that will be allocated to the user. They can use to store data and perform the oprations like insertion, deletion and traversal.

**`int *data`**: This is a pointer that will be used for the array, this will help to assign data to indices and for traversal within the array 

---
# OPERATIONS:

## 1. Insertion
```c
void  Insert(int arr[], int size, int element, int index) {

	for (int i =(*size) -1; i >= index; i--){ 
	
		arr[i + 1] =  arr[i]; // shifts the element 
	}
	arr[index] = element; // inserts the element
	size++; 			  // increases the size of array by 1
}
```
### Steps For Insertion -

 1. From last [size-1] we start shifting the elements one  index back  upto our desired index where we want to insert the new element. This is done by a for loop that starts from `size -1` and goes to the index  replacing the elements to a their next index by `arr[i +  1]  = arr[i]`
 2. The after all shifting, we insert the new element at the freshly created index `arr[index]  = element`
 3. we increase the size of the array allocated to user by the number of elements added (here 1) `size += 1 `.  NOTE : In code, size is passed by reference thus `(*size)++` 

---
## 2. Deletion
```c
void  Delete_at_Index(int  array[],int size, int index){
	for (int i = index; i  <  size - 1; i++)
	{
		array[i] = array[i+1]; // this shifts the elements 
	}
	size--; // decreses the size of array
}
```
### Steps For Deletion-

 - From the index of deletion  [index] we start shifting the elements one  index forward upto our desired index where last element was deleted. This is done by a for loop that starts from `index` and goes to the end of array replacing the elements to a their next index by `arr[i]  = arr[i+1]`
 - We actually dont have to delete an individual element the shifting already overwrites the data thus deleting it 
 - we decrease the size of the array allocated to user by the number of elements added (here 1) `size -= 1 `.  NOTE : In code, size is passed by reference thus `(*size)--` 
---
## 3. Searching
### 1. Linear search
```c
void  linear_search(int  arr[],int  size, int  target){
		for (int i =  0; i < size; i++)
		{
				if (target ==  arr[i])	// checks all the values of index one by one for matching with target
				{
					printf("Element found at %d\n",i); // matches it gets printed
					return;
				}
		}
		printf("Element not found !!!\n"); // if not found the loop exits and this get printed
		return;
}
```
 - Tme Complexity : **O(n)**

