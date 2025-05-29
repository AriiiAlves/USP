#include <stdio.h>

void calcula_media(int v1, int v2, float *media){
    *media = (v1 + v2) / 2.0; // <media> is a pointer. <*media> allow to change the value that the pointer points to.

    // The original variable was changed!!!
}

int main(){
    int n1 = 2, n2 = 5;
    float result;

    calcula_media(n1, n2, &result); // *result -> gives the memory addres of the variable, a pointer.

    printf("Media: %f", result);
}