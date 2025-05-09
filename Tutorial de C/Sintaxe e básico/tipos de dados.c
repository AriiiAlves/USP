#include <stdio.h>

int main(){
    // ---------- NÚMEROS INTEIROS ----------
    // int - Números inteiros.
    //       Valores de -2,147,483,648 até 2,147,483,647. (normalmente)
    //       Ocupa 4 bytes na memória.
    //       Valores de -32,768 até 32,767 (em alguns casos)
    //       Ocupa 2 bytes na memória.
    int n1 = 1;

    // long int - Números inteiros .
    //            Valores de -2,147,483,648 até 2,147,483,647.
    //            Ocupa 4 bytes na memória.
    long int n2 = 1;

    // long long int - Números inteiros .
    //                 Valores de -9,223,372,036,854,775,808 até 9,223,372,036,854,775,807.
    //                 Ocupa 8 bytes na memória.
    long long int n3 = 1;

    // unsigned int - Números inteiros não negativos.
    //                Valores de 0 a 65,535.
    //                Ocupa 2 bytes na memória.
    unsigned int n4 = 1;

    // ---------- NÚMEROS COM CASAS DECIMAIS (PONTO FLUTUANTE) ----------
    // float - Números com ponto flutuante.
    //         Valores de 1.2E-38 até 3.4E+38.
    //         Precisão de 6 casas decimais.
    //         Ocupa 4 bytes na memória.
    float n5 = 1.0;

    // double - Números com ponto flutuante.
    //          Valores de 2.3E-308 até 1.7E+308.
    //          Precisão de 15 casas decimais.
    //          Ocupa 8 bytes na memória.
    double n6 = 1.0;

    // long double - Números com ponto flutuante.
    //               Valores de 3.4E-4932 até 1.1E+4932.
    //               Precisão de 19 casas decimais.
    //               Ocupa 16 bytes na memória.
    long double n7 = 1.0;

    // ---------- ARRAYS ----------
    // int variavel[] - Array ("lista") de números.
    //                  Pode ser int,float,double, etc.
    //                  Cada elemento da string ocupará o tamanho relativo ao tipo de dado.
    //                  Se for um array de tamanho 4 do tipo int, o array ocupa 2 bytes na memória. (4 vezes 2 bytes)
    int numeros[] = {25, 50, 75, 100}; // 1° Forma

    int numeros2[4]; // Define tamanho do array (4 números) para atribuir variáveis depois // 2° Forma

    numeros2[0] = 25; // Muda índice 0
    numeros2[1] = 50; // Muda índice 1
    numeros2[2] = 75; // Muda índice 2
    numeros2[3] = 100; // Muda índice 3

    // ---------- CARACTERES ----------
    // char - Número inteiro de 0 a 255 ou -128 a 127.
    //        O número representa um código na tabela ASCII.
    //        Ocupa 1 byte na memória.
    char caractere = 'c';

    // ---------- STRINGS ----------
    // char variavel[] - Array ("lista") de char's. Define uma palavra, frase, etc.
    //                   A quantidade de caracteres que uma string possui define seu tamanho.
    //                    Cada char da string ocupa 1 byte. Uma string de tamanho 5 ocupa 6 bytes.
    char palavra1[] = {'H','E','L','L','O'}; // (1° Forma)
    char palavra2[] = "Hello"; // (2° Forma)

    char palavra3[6]; // Define tamanho da string (6 caracteres) para atribuir caracteres depois // (3° Forma)

    palavra3[0] = 'H';
    palavra3[1] = 'E';
    palavra3[2] = 'L';
    palavra3[3] = 'L';
    palavra3[4] = 'O';

    // OBSERVAÇÃO: Toda string deverá ter um caractere a mais, diferente dos arrays.
    //             Isto pois o último caractere será '\0', que indica que a string chegou ao fim na memória.
    //             Caso não tenha esse 1 caractere a mais, ao realizar a leitura da memória, não encontrará fim e terá comportamento indesejado.

    // ---------- CONSTANTES ----------
    // Constantes são variáveis que não podem ser alteradas.
    // As constantes normalmente são declaradas com letra maiúscula.

    const int VAR1 = 37; // (1° Forma)
    #define VAR2 = 37 // (2° Forma)

    return 0; // Termina o código
}
