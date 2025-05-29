#include <stdio.h>

int main(){
    int n1, n2, n3, n4, temp;

    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    // 1° valor
    if(n2 < n1){
        temp = n1;
        n1 = n2;
        n2 = temp;
    }
    else if(n3 < n1){
        temp = n1;
        n1 = n3;
        n3 = temp;
    }
    else if(n4 < n1){
        temp = n1;
        n1 = n4;
        n4 = temp;
    }

    // 2° valor
    if(n3 < n2){
        temp = n2;
        n2 = n3;
        n3 = temp;
    }
    else if(n4 < n2){
        temp = n2;
        n2 = n4;
        n4 = temp;
    }

    // 3° valor
    if(n4 < n3){
        temp = n3;
        n3 = n4;
        n4 = temp;
    }

    // Final
    if(n1==n2 && n2==n3 && n3==n4){
        printf("Valores iguais");
    }
    else{
        printf("%d %d %d %d", n1, n2, n3, n4);
    }

    return 0;
}
