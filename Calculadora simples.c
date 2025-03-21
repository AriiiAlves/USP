#include <stdio.h>

int main(){
    int n1, n2;
    float total;
    char operador;

    scanf("%d %d %c", &n1, &n2, &operador);

    if(operador == '+'){
        total = (float)n1+(float)n2;
        printf("%.2f", total);
    }
    else if(operador == '-'){
        total = (float)n1-(float)n2;
        printf("%.2f", total);
    }
    else if(operador == '*'){
        total = (float)n1*(float)n2;
        printf("%.2f", total);
    }
    else if (operador == '/'){
        if(n2==0) {
            printf("Erro: divisao por zero");
        }
        else {
            total = (float)n1/(float)n2;
            printf("%.2f", total);
        }
    }
    else {
        printf("Erro: operacao invalida");
    }
}
