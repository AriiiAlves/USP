#include <stdio.h>
#include <math.h>

int main()
{
    int dia, mes, ano;
    
    scanf("%d/%d/%d", &dia, &mes, &ano);
    
    // Verifica se é um mês válido
    if(mes >= 1 && mes <= 12){
        // Verifica se é mês ímpar (31 dias)
        if(mes % 2 != 0){
            if(mes < 9){
                // Verifica se possui 31 dias
                if(dia >= 1 && dia <= 31){
                    printf("Data valida");
                }
                else {
                    printf("Data invalida");
                }
            }
            else{
                // Verifica se possui 30 dias
                if(dia >= 1 && dia <= 30){
                    printf("Data valida");
                }
                else {
                    printf("Data invalida");
                }
            }
        }
        // Se não é ímpar, é mês par
        else{
            // Meses diferentes de fevereiro
            if(mes != 2){
                if(mes < 8){
                    // Verifica se possui 30 dias
                    if(dia >= 1 && dia <= 30){
                        printf("Data valida");
                    }
                    else {
                        printf("Data invalida");
                    } 
                }
                else{
                    // Verifica se possui 31 dias
                    if(dia >= 1 && dia <= 31){
                        printf("Data valida");
                    }
                    else {
                        printf("Data invalida");
                    } 
                }
            }
            // Mês de fevereiro
            else{
                // Verifica se é ano bissexto
                if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
                    if(dia >= 1 && dia <= 29){
                        printf("Data valida");
                    }
                    else{
                        printf("Data invalida");
                    }
                }
                else{
                    if(dia >= 1 && dia <= 28){
                        printf("Data valida");
                    }
                    else{
                        printf("Data invalida");
                    }
                }
            }
        }
    }
    else{
        printf("Data invalida");
    }

    return 0;
}