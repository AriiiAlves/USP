#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

int main(){
    typedef struct{
        char producer[20];
        char model[20];
        int year;
        char color[20];
        float price;
    } car;

    car *cars;
    int size, cheapIndex = 0;

    scanf("%d", &size);

    cars = (car*) calloc(size, sizeof(car));

    for (int i = 0; i < size; i++)
    {
        scanf("%s %s %d %s %f", cars[i].producer, cars[i].model, &cars[i].year, cars[i].color, &cars[i].price);
    }
    
    if(DEBUG){
        if(cars[77].price < cars[78].price){
            printf("78 menor do que 79.\n");
        }
    }

    if(size > 1){
        for (int i = 0; i < size; i++){
            if(DEBUG) printf("%s %f\n", cars[i].producer, cars[i].price);

            if(cars[i].price < cars[cheapIndex].price){
                cheapIndex = i;
            }
        }
    }
    else{
        cheapIndex = 0;
    }

    printf("%s", cars[cheapIndex].model);
}