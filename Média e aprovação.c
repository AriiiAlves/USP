#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){
    float nota1, nota2, media;

    scanf("%f %f", &nota1, &nota2);

    media = (nota1 + nota2)/2.0;

    if(media >= 8){
        printf("Aprovado");
    }
    else{
        printf("Reprovado");
    }
}
