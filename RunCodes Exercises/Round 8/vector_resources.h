/* ----------------------- COMO USAR -----------------------
Essa é uma biblioteca para mexer com vetores ou pontos.

Tanto pontos como vetores são representados pelas mesmas coordenadas
Portanto, o tipo "Tcoord" cria um struct com variáveis x,y,z (coordenadas)
As funções disponíveis são:

- vecScan() -> Lê 3 coordenadas e retorna o tipo "Tcoord", que é o vetor preenchido.
- vecPrint() -> Mostra as coordenadas do ponto/vetor.
- vecSub() -> Subtrai dois pontos/vetores. Sempre se subtrai o segundo do primeiro. Retorna o tipo "Tcoord", que é o vetore resultante.
- vecScalar() -> Faz o produto escalar de dois vetores de retorna um escalar.
- vecProduct() -> Faz o produto vetorial de dois vetores e retorna o tipo "Tcoord", que é o vetor resultante.
- vecModule() -> Retorna a norma/módulo de um vetor.

-------------------------------------------
Para operar com vecScan(), vecSum(), vecSub(), vecProduct(), atribua a saída da função a uma variável "Tcoord":acos

Tcoord vec1, vec2, sub, product;

vec1 = vecScan();
vec2 = vecScan();
sub = vecSub(vec1, vec2);
product = vecProduct(vec1, vec2);
-------------------------------------------
Para operar com vecScalar(), vecModule(), atribua a saída da função a uma variável

float scalar, module;

scalar = vecScalar(vec1, vec2);
module = vecModoule(vec1);
-------------------------------------------
*/

#ifndef VECTOR_RESOURCES
#define VECTOR_RESOURCES

#include <stdio.h>
#include <math.h>

// Elements

typedef struct {
    float x;
    float y;
    float z;
} Tcoord;

typedef struct{
    float a;
    float b;
    float c;
    float d;
} Tplan;

typedef struct{
    Tcoord initPoint;
    Tcoord dirVec;
} Tline;

// Points/Vectors operations

Tcoord vecScan(){
    Tcoord vec;

    scanf("%f %f %f", &vec.x, &vec.y, &vec.z);

    return vec;
}

void vecPrint(Tcoord u){
    printf("Coordinates: (%.2f, %.2f, %.2f)\n", u.x, u.y, u.z);
}

Tcoord vecSum(Tcoord u, Tcoord v){
    Tcoord vec;

    vec.x = u.x + v.x;
    vec.y = u.y + v.y;
    vec.z = u.z + v.z;

    return vec;
}

Tcoord vecSub(Tcoord u, Tcoord v){
    Tcoord vec;

    vec.x = u.x - v.x;
    vec.y = u.y - v.y;
    vec.z = u.z - v.z;

    return vec;
}

Tcoord vecScalarMult(Tcoord u, float b){
    Tcoord vec;

    vec.x = u.x * b;
    vec.y = u.y * b;
    vec.z = u.z * b;

    return vec;
}

int vecScalar(Tcoord u, Tcoord v){
    int calc;

    calc = (v.x * u.x + v.y * u.y + v.z * u.z);
    return calc;
}

Tcoord vecProduct(Tcoord u, Tcoord v){
    Tcoord vec;

    vec.x = (u.y * v.z)-(u.z * v.y);
    vec.y = (u.z * v.x)-(u.x * v.z);
    vec.z = (u.x * v.y)-(u.y * v.x);

    return vec;
}

float vecModule(Tcoord u){
    float calc;
    calc = sqrt(pow(u.x,2) + pow(u.y,2) + pow(u.z,2));

    return calc;
}

// New

Tplan vecPlanScan(){
    Tplan plan;

    scanf("%f %f %f %f", &plan.a, &plan.b, &plan.c, &plan.d);

    return plan;
}

#endif

/*
---------------------- TESTE ----------------------
#define DEBUG 0

int main(){
    // Testing functions
    Tcoord vec1, vec2, sub, vecProd;
    float scalar, module1, module2;

    vec1.x = -2;
    vec1.y = 0;
    vec1.z = 1;

    vec2.x = 4;
    vec2.y = 2;
    vec2.z = 5;

    scalar = vecScalar(vec1, vec2);
    module1 = vecModule(vec1);
    module2 = vecModule(vec2);

    sub = vecSub(vec1, vec2);
    vecProd = vecProduct(vec1, vec2);

    printf("Vec1 . Vec2: %f\n", scalar);
    printf("Vec1 module: %f\n", module1);
    printf("Vec2 module: %f\n", module2);
    printf("Vec1 - Vec2: (%f, %f, %f)\n", sub.x, sub.y, sub.z);
    printf("Vec1 x Vec2: (%f, %f, %f)\n", vecProd.x, vecProd.y, vecProd.z);
}
    */