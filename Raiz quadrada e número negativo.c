#include <stdio.h>
#include <math.h>

int main()
{
    float numero, total;
    
    scanf("%f", &numero);
    
    if(numero >= 0){
        total = sqrt(numero);
        printf("%.2f", total);
    }
    else{
        printf("Numero negativo, nao e possivel calcular a raiz quadrada");
    }

    return 0;
}