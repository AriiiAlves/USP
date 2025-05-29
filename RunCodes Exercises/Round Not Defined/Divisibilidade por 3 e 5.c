#include <stdio.h>

int main(){
    int a;

    scanf("%d", &a);

    if(a%3 == 0 && a%5  == 0){
        printf("Divisivel por 5 e 3");
    }
    else if(a%3 == 0){
        printf("Divisivel por 3");
    }
    else if(a%5 == 0){
        printf("Divisivel por 5");
    }
    else{
        printf("Nao e divisivel por 3 nem por 5");
    }

}
