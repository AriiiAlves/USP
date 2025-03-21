#include <stdio.h>

int main()
{
    float salario, imposto, salario_liquido;
    
    scanf("%f", &salario);
    
    if(salario >=0 && salario <= 1500){
        imposto = 0;
        salario_liquido = salario;
    }
    else if(salario > 1500 && salario <= 2500){
        imposto = salario * 0.1;
        salario_liquido = salario - imposto;
    }
    else if(salario > 2500 && salario <= 3500){
        imposto = salario * 0.15;
        salario_liquido = salario - imposto;
    }
    else if(salario > 3500){
        imposto = salario * 0.2;
        salario_liquido = salario - imposto;
    }
    
    printf("Imposto a pagar: %.2f\n", imposto);
    printf("Salario liquido: %.2f\n", salario_liquido);
}