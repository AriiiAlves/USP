#include <stdio.h>

int main()
{
    float a,b,c, delta;
    
    scanf("%f %f %f", &a, &b, &c);
    
    delta = b*b - 4*a*c;
    
    if(delta > 0){
        printf("Duas raizes reais");
    }
    else if(delta == 0){
        printf("Uma raiz real");
    }
    else{
        printf("Nenhuma raiz real");
    }
}