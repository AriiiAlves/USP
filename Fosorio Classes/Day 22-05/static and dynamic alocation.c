#include <stdio.h>
#include <stdlib.h>

#define N_ITEMS 10

int main(){
    /*--------------- DYNAMIC ALOCATION ---------------*/

    int *array; // Creates a pointer

    array = (int*)calloc(N_ITEMS, sizeof(int)); // Dynamic alocation. Alocates space for 10 items in the array, and returns the pointer for the first items of the array.

    for (int i = 0; i < N_ITEMS; i++) // Fill up the array and show it
    {
        array[i]= i*2;

        printf("\narray[%d]: %d", i, array[i]);
    }
    printf("\n\n");

    /*--------------- STATIC ALOCATION ---------------*/

    int array2[N_ITEMS]; // Creates a static array

    for (int i = 0; i < N_ITEMS; i++) // Fill up the array and show it
    {
        array2[i]= i*2;

        printf("\narray2[%d] index: %d", i, array2[i]);
    }

    /*
    
    OPS: Difference between malloc and calloc?

    The calloc put zeros in the memory before allocate it. So, it 'cleans' the memory first. It's more slow than malloc, but more secure.
    The malloc just allocate memory withouth clean it. So, it's more fast, but it's less secure.

    */
}