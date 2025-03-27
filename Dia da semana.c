#include <stdio.h>

void dia_semana(int avanco, int dia){
    int n_dia;
    n_dia = (dia + avanco) % 7;

    switch(n_dia){
    case 1:
        printf("Segunda");
        break;
    case 2:
        printf("Terca");
        break;
    case 3:
        printf("Quarta");
        break;
    case 4:
        printf("Quinta");
        break;
    case 5:
        printf("Sexta");
        break;
    case 6:
        printf("Sabado");
        break;
    case 0:
        printf("Domingo");
        break;
    }
}

int main(){
    int dia, mes;

    scanf("%d %d", &dia, &mes);

    // Segunda
    if(mes == 9 || mes == 12){
        dia_semana(0, dia);
    }
    // Terça
    else if(mes == 4 || mes == 7){
        dia_semana(1, dia);
    }
    // Quarta
    else if(mes == 1 || mes == 10){
        dia_semana(2, dia);
    }
    // Quinta
    else if(mes == 5){
        dia_semana(3, dia);
    }
    // Sexta
    else if(mes == 8){
        dia_semana(4, dia);
    }
    // Sábado
    else if(mes == 2 || mes == 3 || mes == 11){
        dia_semana(5, dia);
    }
    // Domingo
    else if(mes == 6){
        dia_semana(6, dia);
    }

    return 0;
}
