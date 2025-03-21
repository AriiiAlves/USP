#include <stdio.h>

int main()
{
    int a;

    scanf("%d", &a);

    if(a>0){
        printf("positivo");
    }
    else if(a<0){
        printf("negativo");
    }
    else{
        printf("zero");
    }

    return 0;
}
