# include<stdio.h>

int main(){
    int hora1, minuto1, hora2, minuto2, soma_hora, soma_minuto;
    
    scanf("%d:%d %d:%d", &hora1, &minuto1, &hora2, &minuto2);
    
    if(minuto1 >= 60){
        hora1 += minuto1 / 60;
        minuto1 = minuto1 % 60;
    }
    if(hora1 >= 24){
        hora1 = hora1 % 24;
    }
    if(minuto2 >= 60){
        hora2 += minuto2 / 60;
        minuto2 = minuto2 % 60;
    }
    if(hora2 >= 24){
        hora2 = hora2 % 24;
    }
    
    soma_hora = hora1 + hora2;
    soma_minuto = minuto1 + minuto2;
    
    if(soma_minuto >= 60){
        soma_hora += soma_minuto / 60;
        soma_minuto = soma_minuto % 60;
    }
    if(soma_hora >= 24){
        soma_hora = soma_hora % 24;
    }
    
    printf("%02d:%02d", soma_hora, soma_minuto);
    
    return 0;
}