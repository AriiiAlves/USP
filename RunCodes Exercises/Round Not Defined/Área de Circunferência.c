#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){
    float raio, area;

    scanf("%f", &raio);

    //area = raio * raio * M_PI;
    area = pow(raio, 2) * M_PI;

    printf("%.4e", area);
}
