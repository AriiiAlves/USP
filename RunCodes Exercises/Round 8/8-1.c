#include <stdio.h>

int main(){
    typedef struct {
        int x;
        int y;
        int z;
    } vetor;

    vetor vec1;
    vetor vec2;
    vetor vec_prod;

    scanf("%d %d %d %d %d %d", &vec1.x, &vec1.y, &vec1.z, &vec2.x, &vec2.y, &vec2.z);

    vec_prod.x = (vec1.y * vec2.z)-(vec1.z * vec2.y);
    vec_prod.y = (vec1.z * vec2.x)-(vec1.x * vec2.z);
    vec_prod.z = (vec1.x * vec2.y)-(vec1.y * vec2.x);

    printf("%d %d %d", vec_prod.x, vec_prod.y, vec_prod.z);
}