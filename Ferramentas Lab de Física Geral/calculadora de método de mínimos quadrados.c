#include <stdio.h>
#include <math.h>

int main() {
    double a=0, b=0, dy=0, da=0, db=0, x_med=0, y_med=0, temp1=0, temp2=0;
    // ALTERAR SOMENTE AQUI, X E Y
    double x[] = {0.448,0.811,1.362,1.648,2.034,2.266};
    double y[] = {1.698,3.172,5.318,6.49,8.08,8.67};
    // -----------------------------------------------
    int size = sizeof(x)/sizeof(x[0]);
    
    for(int i = 0; i < size; i++){
        x_med += x[i];
        y_med += y[i];
    }
    
    x_med = x_med / size;
    y_med = y_med / size;
    
    printf("x médio: %.10lf\ny médio: %.10f\n", x_med, y_med);
    
    // angular
    for(int i = 0; i < size; i++){
        temp1 += (x[i]-x_med)*y[i];
        temp2 += pow((x[i]-x_med),2);
    }
    
    printf("somatória (numerador) a: %.10lf\n", temp1);
    printf("somatória (denominador) a: %.10lf\n", temp2);
    
    a = temp1 / temp2;
    temp1 = 0;
    temp2 = 0;
    
    // linear
    b = y_med - a*x_med;
    
    // delta y (OK)
    for(int i = 0; i < size; i++){
        temp1 += pow((a*x[i]+b-y[i]),2);
    }
    
    printf("somatória delta y: %.10lf\n", temp1);
    
    dy = sqrt(temp1/(size-2));
    temp1 = 0;
    
    // delta a
    for(int i = 0; i < size; i++){
        temp1 += pow((x[i]-x_med),2);
    }
    
    printf("somatória delta a: %.10lf\n", temp1);
    
    da = dy / temp1;
    temp1 = 0;
    
    // delta b
    for(int i = 0; i < size; i++){
        temp1 += pow(x[i],2);
        temp2 += pow((x[i]-x_med),2);
    }
    
    printf("somatória (numerador) delta b: %.10lf\n", temp1);
    printf("somatória (denominador) delta b: %.10lf\n", temp2);
    
    db = sqrt(temp1/(temp2*size))*dy;
    
    printf("\na: %.10lf\nb: %.10lf\ndy: %.10lf\nda: %.10lf\ndb: %.10lf", a, b, dy, da, db);
    
    return 0;
}