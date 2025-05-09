#include <stdio.h>

int main(){
    int a = 1;

    // ----------------- IF -----------------

    if(a==1){
        // Se a condição for verdadeira, realiza uma ação
    }

    // ----------------- IF/ELSE -----------------

    if(a==1){
        // Se a condição for verdadeira, realiza uma ação
    }
    else{
        // Se a condição for falsa, realiza uma ação
    }

    // ----------------- IF/ELSE IF/ELSE -----------------

    if(a==1){
        // Se a condição for verdadeira, realiza uma ação
    }
    else if(a==2){
        // Se a segunda condição for verdadeira, realiza uma ação
    }
    else{
        // Se a condição for falsa, realiza uma ação
    }

    // ----------------- SWITCH -----------------

    switch(a){
    case 1:
        // Se a==0, realiza uma ação
        break; // Tem que ter o break!!
    case 2:
        // Se a ==2, realiza uma ação
        break;
    default:
        break;
        // Para qualquer outro caso (opcional)
    }

    // ----------------- FOR -----------------

    // for(valor inicial; condição (enquanto for verdadeira, o loop continua); o que fazer a cada fim de loop)

    // Abaixo - 1) O valor inicial é zero.
    //          2) O loop acontece enquanto i for menor ou igual a 10.
    //          3) A cada fim de loop, i aumenta 1.

    for(int i = 0; i<= 10; i++){
        // A ação aqui se repetirá até que a condição seja falsa.
    }

    //
    // Nota: O for verifica a condição sempre antes de iniciar o loop.
    //       Quando a condição for falsa, o loop termina e o código não é executado.

    // ----------------- WHILE -----------------

    // while(condição) --> Enquanto a condição é verdadeira, o loop continua

    while(a==1){
        a++;
    }

    // ----------------- BREAK/CONTINUE (para laços) -----------------

    // break - sai do for/while atual (termina forçadamente).

    while(a==1){
        break;
    }
    for(int i = 0; i<= 10; i++){
        break;
    }

    // continue - pula a iteração atual, ignorando o código abaixo (recomeça do início do comando)

    for(int i = 0; i<= 10; i++){
        if(i==5){
            continue;
        }
        a++; // Quando i==5, a não será incrementado
    }

    return 0;
}
