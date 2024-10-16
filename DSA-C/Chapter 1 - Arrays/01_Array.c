#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

/* STEP BY STEP PROCESS:

1. We need a structure to form an overall ADT that defines 
   the properties and operations for a custom array.

2. We'll de-reference the structure in functions by passing its address 
   (call by reference). This ensures that all operations are made on the 
   actual structure and its members, rather than on a copy (which happens 
   with call by value).

3. The approach will be this:
   - we keep two data sizes 
        1. total_size = this will be the larger than the users requirment (INT_MAX if possible)
        2. used_size  = this will be provided to user initially, if more is needed the we will 
                        use from total size
   - we will then keep a pointer for the dyamic array that will be called and refered in functions
   - we will first initialize the space or dynamic array in the create_array fucntion
   - rest will be explained as we procced
*/


// Structure to represent the custom array
struct Custom_Array
{
    int total_size;   // Total size that will be reserved for future use
    int used_size;    // Size that the user wants to actively use
    int *ptr;         // Pointer to the dynamically allocated array
};



// FUNCTIONS:

void create_array(struct Custom_Array *a, int total , int used);
void show_array(struct Custom_Array *a);
void input_array(struct Custom_Array *a);

int main(int argc, char const *argv[])
{
    struct Custom_Array array1; /*we created a Custom_Array data type named array1 like [int arry1]
                                  we will pass this array1 to other functions through ref calls to
                                  access its properties and change them inside array1 */


    int size;
    int total = 100;
    printf("Enter the amount of elements you need: ");
    scanf("%d", &size);
    create_array(&array1, total, size);
    show_array(&array1);
    input_array(&array1);
    show_array(&array1);
    free(array1.ptr);

    return 0;
}


void create_array(struct Custom_Array *a, int total, int used) /*Here we used a Custom_Array datatype which is a struct
                                                                 and accepted a pointer of that data type thus *a */
{

    // (*a).total_size = a -> total_size
    // (*a).used_size = a -> used_size


    a->total_size = total;  // This directly translates to: from the structure array1 set the total size as ...... 
    a->used_size = used;    // similarly this says: set arry1's used_size to ..........
    a->ptr = (int *)malloc(total * sizeof(int));  //This says the ptr form arry1 will be a array of (total) elements each int size


    /* why dynamic ? -----> we could set (*a).ptr = array[10..100..etc]. we take dynamic coz er dont know what will be the size form 
    before hand and we want the memory from heap coz static memory will be lost after a fucntion is completed*/

    // IF MEMORY ALLOCATION FALIS MALLOC RETURNS A NULL POINTER 
    if (a->ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); 
    }
}


void show_array(struct Custom_Array *a)
{
    for (int i = 0; i < a->used_size; i++)  
    {
        printf("Element %d is: %d\n", i, (a->ptr)[i]);  
    }
}

/*  we could also use the show_array(struct Custom_Array, int upto) but as the size is already
    assinged into the structure itself we can directly use from structure just by pointing to it (a->used_size)*/


void input_array(struct Custom_Array *a)
{
    for (int i = 0; i < a->used_size; i++)  
    {
        printf("Enter the value of element %d: ", i); 
        scanf("%d", &(a->ptr)[i]);  // here ptr is pointing to the memory locations thus using & operator
    }
}
