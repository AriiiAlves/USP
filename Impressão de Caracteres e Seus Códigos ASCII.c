#include <stdio.h>

int main()
{
    char frase[3];
    
    scanf("%s", frase);
    
    // Ao definir a saída como inteiro, porém a variável sendo char, será impresso o código do caractere
    printf("%c %d\n%c %d\n%c %d", frase[0], frase[0], frase[1], frase[1], frase[2], frase[2]);
    
    return 0;
}