#include <stdio.h>
#include <math.h>

int main(){
    typedef struct {
        float x;
        float y;
        float z;
    } vetor;

    vetor v;
    vetor u;
    vetor projv;
    float scalar;

    scanf("%f %f %f %f %f %f", &v.x, &v.y, &v.z, &u.x, &u.y, &u.z);

    scalar = (v.x * u.x + v.y * u.y + v.z * u.z) / pow(sqrt(pow(u.x,2) + pow(u.y,2) + pow(u.z,2)),2);
    projv.x = u.x * scalar;
    projv.y = u.y * scalar;
    projv.z = u.z * scalar;

    printf("%.2f %.2f %.2f", projv.x, projv.y, projv.z);
}