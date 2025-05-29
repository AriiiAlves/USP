#include <stdio.h>
#include <stdlib.h>

int main(){
    // -------------------------- POINTER AS A VARIABLE --------------------------
    int valor = 10;
    int *ptr_valor;

    // If we have a pointer, we can allocate memory for this pointer. Example: A memory with int size allocated, can store a int number.

    ptr_valor = (int*)calloc(1, sizeof(int)); // Allocating memory for int
    *ptr_valor = 123; // The '*' before a pointer (already declared) takes not the memory address, but the value that the memory address is pointing for.

    printf("Value inserted in the pointer after allocation: %d", *ptr_valor);

    // -------------------------- POINTER OF A VARIABLE --------------------------

    // The pointer can take memory addresses of variables, and we can work with this addresses.

    ptr_valor = &valor; // The '&' character takes the memory address of the variable, and now the pointer has the memory address stored.
    *ptr_valor = 123;

    printf("\nValue inserted in the variable through a pointer: %d", valor);

    // If the pointer has a variable address, we can change your value in any place.

    // -------------------------- POINTER OPERATIONS --------------------------

    int vector[10];
    int data;
    int *ptr;

    ptr = &data; // Takes variable MEMORY ADDRESS
    *ptr = 130; // Stores 130 inside the memory address

    ptr = vector; // Takes the memory address of the FIRST array item -> vector[0]
    *ptr = 130; // Stores 130 inside the vector[0]

    ptr++; // Points the NEXT ITEM of the memory. In this case, the SECOND array item -> vector[1]
    *ptr = 131; // Stores 131 inside the vector[1]

    *vector = 1; // Stores 1 inside the vector[0], because <vector> is a pointer for the vector[0].
    *(vector+5) = 2; // Stores 2 inside the vector[5]

    free(ptr); // Turns a memory block free! (it turns it avaliable again)
}