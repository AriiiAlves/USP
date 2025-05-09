#include <stdio.h>

int main(){
    int a = 1, b = 2, x = 0;
    // ------------- OPERADORES ARITMÉTICOS -------------

    x = a + b; // Adição
    x = a - b; // Subtração
    x = a * b; // Multiplicação
    x = a / b; // Divisão
    x = a % b; // Divisão inteira (ou módulo)

    x = a++; // incrementa a depois do uso.
    x = ++a; // Incrementa a antes do uso.
    x = a--; // Decrementa a depois do uso.
    x = --a; // Decrementa a antes do uso.

    // Exemplo do incremento:
    x = 0;
    a = 1;

    x = a++; // x = 1, a = 2 (a variável a aumenta 1);
    x = ++a; // x = 2, a = 2 (a variável a aumenta 1);

    // ------------- OPERADORES DE COMPARAÇÃO -------------

    if(a==b){}; // Igual
    if(a!=b){}; // Diferente
    if(a>b){}; // Maior
    if(a<b){}; // Menor
    if(a>=b){}; // Maior ou igual
    if(a<=b){}; // Menor ou igual

    // ------------- OPERADORES LÓGICOS -------------

    if(!(a==b)){} // NOT (inverte - se é verdadeiro, fica falso, e vice-versa)
    if(a==b && b==a){} // AND (se as duas não forem verdadeiras, não é verdadeiro)
    if(a==b || b==a){} // OR (se uma das duas for verdadeira, é verdadeiro)

    // ------------- OPERADORES DE ATRIBUIÇÃO COMPOSTOS -------------

    x += a; // forma reduzida de x = x + a
    x -= a; // forma reduzida de x = x - a
    x *= a; // forma reduzida de x = x * a
    x /= a; // forma reduzida de x = x / a
    x %= a; // forma reduzida de x = x % a

    // ------------- OPERADOR TERNÁRIO -------------

    // <condição> ? <executa se verdadeiro> : <executa se falso>

    a==b ? printf("Igual") : printf("Diferente");
    printf("\n");

    // ------------- OPERADOR SIZEOF -------------

    // Retorna o tamanho da variável/tipo de dado. O tamanho é medido em bytes.

    printf("%d", sizeof(int));

    return 0;
}
