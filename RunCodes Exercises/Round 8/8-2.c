#include <stdio.h>
#include <math.h>

int main(){
    typedef struct {
        float x;
        float y;
        float z;
    } vetor;

    vetor vec;
    vetor unit;
    float module;

    scanf("%f %f %f", &vec.x, &vec.y, &vec.z);

    //printf("%.0f %.0f %.0f", vec.x, vec.y, vec.z);

    if(vec.x == 0 && vec.y == 0 && vec.z == 0){
        printf("Vetor nulo.");
        return 0;
    }

    module = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));

    unit.x = vec.x / module;
    unit.y = vec.y / module;
    unit.z = vec.z / module;

    printf("%.6f %.6f %.6f", unit.x, unit.y, unit.z);
}