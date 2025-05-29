#include <stdio.h>
#include "vector_resources.h"

// PROGRAM

#define DEBUG 0

int main(){
    Tcoord P, vecRP, vecProd;
    Tline line;
    float module1, module2, distance;

    P = vecScan();
    line.initPoint = vecScan();
    line.dirVec = vecScan();

    if(DEBUG){
        printf("P: ");
        vecPrint(P);
        printf("Po: ");
        vecPrint(line.initPoint);
        printf("v: ");
        vecPrint(line.dirVec);
    }

    vecRP = vecSub(line.initPoint, P);

    if(DEBUG) vecPrint(vecRP);

    vecProd = vecProduct(line.dirVec, vecRP);
    
    module1 = vecModule(vecProd);
    module2 = vecModule(line.dirVec);

    distance = module1 / module2;

    printf("%f", distance);
}