#include <stdio.h>

int main()
{
    int a,b;

    scanf("%d %d", &a, &b);

    if(a > b)
        {
        printf("%d", a);
    }
    else if(a == b){
        printf("igual");
    }
    else{
        printf("%d", b);
    }

    return 0;
}
