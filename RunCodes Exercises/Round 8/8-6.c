#include <stdio.h>
#include "vector_resources.h"

int main(){
    Tcoord initPoint, dirVec, interPoint;
    Tplan plan;
    float under, over, lambda;

    initPoint = vecScan();
    dirVec = vecScan();
    plan = vecPlanScan();

    under = plan.a*dirVec.x + plan.b*dirVec.y + plan.c*dirVec.z;
    over = -(plan.a*initPoint.x + plan.b*initPoint.y + plan.c*initPoint.z + plan.d);

    if(under != 0){
        lambda =  over / under;
        interPoint = vecSum(initPoint, vecScalarMult(dirVec, lambda));
        printf("Intersecao: x=%f, y=%f, z=%f", interPoint.x, interPoint.y, interPoint.z);
    }
    else{
        if(over == 0){
            printf("A reta esta contida no plano");
        }
        else{
            printf("A reta e paralela ao plano");
        }
    }
}