# include<stdio.h>

int main(){
    int numero;
    
    scanf("%d", &numero);
    
    printf("Decimal: %d\nOctal: %o\nHexadecimal: %X", numero, numero, numero);
    
    return 0;
}