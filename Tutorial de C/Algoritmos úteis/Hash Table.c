#include <stdio.h>

int main() {
    #define MAX 1000

    /*Lucas e Sofia colecionam figurinhas numeradas de 1 at� 1000.
      Lucas possui algumas repetidas e Sofia est� precisando completar
      sua cole��o. Escreva um programa que determine quantas figurinhas
      diferentes Lucas pode fornecer a Sofia.*/

    /* Exemplo de entrada:

    5 4 -> N�mero m�ximo de figurinha para Lucas e Sofia
    1 3 5 7 9 -> Figurinhas Lucas
    2 3 4 9 -> Figurinha Sofia */

    // FAZENDO POR HASH TABLE

    /* Na hash table, o �ndice do array representa o pr�prio valor. E se
       aquele valor est� presente ou n�o, ser� representado por um booleano
       (0 ou 1).

       Exemplo: Lucas tem as figurinha 3 e 5.

       [0,0,0,1,0,1] -> Array repreentando as figurinhas lucas

    */
    int maxLucas=0, maxSofia=0, figLucas=0, figSofia=0, count=0;

    scanf("%d %d", &maxLucas, &maxSofia);

    int Lucas[MAX] = {0};
    int Sofia[MAX] = {0};

    for(int i = 0; i < maxLucas; i++){
        scanf("%d", &figLucas);
        Lucas[figLucas]++;
    }

    for(int i = 0; i < maxSofia; i++){
        scanf("%d", &figSofia);
        Lucas[figSofia]++;
    }

    for(int i = 0; i < maxLucas; i++){
        if(Lucas[i]==1&&Sofia[i]==0){
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
