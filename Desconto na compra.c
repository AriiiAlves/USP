#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){
    float total;

    scanf("%f", &total);

    if(total > 100.0){
        total = total - (total*0.1);
    }

    printf("%.2f", total);
}
