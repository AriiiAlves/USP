#include <stdio.h>

int main(){
    float peso, altura, imc;

    scanf("%f %f %f", &peso, &altura);

    imc = peso/(altura*altura);

    if(imc < 18.5){
        printf("Abaixo do peso");
    }
    else if(imc >= 18.5 && imc < 25){
        printf("Peso normal");
    }
    else if(imc >= 25 && imc < 30){
        printf("Sobrepeso");
    }
    else if(imc >= 30){
        printf("Obesidade");
    }
}
