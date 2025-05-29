#include <stdio.h>

int main()
{
    int numero;
    
    scanf("%d", &numero);
    
    if(numero > 1000){
        // o \a emite o beep!
        printf("ALERTA!\a"); 
    }
    else{
        printf("OK");
    }
    

    return 0;
}