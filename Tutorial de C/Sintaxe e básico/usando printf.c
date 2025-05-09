#include <stdio.h>

int main(){
    // ---------- A FUNÇÃO PRINTF() ----------
    // printf() - Função que imprime variáveis/texto no console.
    //            Uso: printf("<dados a imprimir>", var1, var2, ...);

    printf("Hello World"); // Imprime texto
    printf("\n"); // Quebra de linha

    int num= 2; // Variável de exemplo

    printf("%d", num); // Imprime variável
    printf("\n");
    printf("Numero: %d", num); // Imprime texto e variável
    printf("\n\n");

    // Cada tipo de dado tem seu especificador de formato diferente.
    // Como visto acima, o do inteiro é %d.
    // Isso indica que deverá ser impressa a variável em formato de inteiro.

    // OBS: Para usar printf(), deve-se incluir a biblioteca stdio.h
    //      Use #include <stdio.h> no começo do código.

    // OBS2: '\n' representa uma quebra de linha (enter).

    // ---------- NÚMEROS INTEIROS ----------

    // OBS2: Abaixo, foram colocados os valores máximos possíveis.
    //       Ao passar disso, volta do começo (desde o negativo, ou zero se for unsigned).

    int n1 = 2147483647; // %d
    long int n2 = 2147483647; // %ld
    long long int n3 = 9223372036854775807; // %lld
    unsigned int n4 = 4294967295; // %u

    // ---------- NÚMEROS COM CASAS DECIMAIS (PONTO FLUTUANTE) ----------

    // OBS2: Abaixo, foram colocados os valores máximos possíveis.
    //       Ao passar disso, começa a arredondar ou volta do começo.

    float n5 = 1.123456; // %f
    double n6 = 1.123456789012345; // %lf
    long double n7 = 1.1234567890123456789; // %Lf (não funcionando)

    // ---------- CARACTERES ----------
    char caractere = 'c'; // %c

    // ---------- CONSTANTES ----------
    const int VAR1 = 37; // %d (mesmo tipo especificado da constante)

    // EXEMPLOS
    printf("%d", n1); // int
    printf("\n");
    printf("%ld", n2); // long int
    printf("\n");
    printf("%lld", n3); // long long int
    printf("\n");
    printf("%u", n4); // short int
    printf("\n");
    printf("%f", n5); // float
    printf("\n");
    printf("%.15lf", n6); // double (temos que colocar .15 para mostrar as 15 casas decimais)
    printf("\n");
    printf("%.15Lf", n7); // long double (não funcionando)
    printf("\n");
    printf("%c", caractere); // char
    printf("\n");
    printf("%d", VAR1); // const int
    printf("\n");

    return 0; // Termina o código
}
