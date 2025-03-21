# include<stdio.h>

int main(){
    char cpf[11];
    
    scanf("%s", cpf);
    
    printf("%c%c%c.%c%c%c.%c%c%c-%c%c", cpf[0], cpf[1], cpf[2],
        cpf[3], cpf[4], cpf[5], cpf[6], cpf[7], cpf[8],
        cpf[9], cpf[10]);
    
    return 0;
}