#include <stdio.h>

int main(){
    float lado1, lado2, lado3;

    scanf("%f %f %f", &lado1, &lado2, &lado3);

    if(lado1 + lado2 <= lado3){
        printf("Triangulo Invalido");
    }
    else if(lado1 + lado3 <= lado2){
        printf("Triangulo Invalido");
    }
    else if(lado2 + lado3 <= lado1){
        printf("Triangulo Invalido");
    }
    else{
        printf("Triangulo Valido");
    }
}
