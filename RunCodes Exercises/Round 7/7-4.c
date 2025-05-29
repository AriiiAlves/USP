#include <stdio.h>
#include <string.h>
#define DEBUG 1
//#include "avaliador.h"

int main(){
    char line[150], arq_in[50], arq_out[50], word[20];

    FILE *arq;
    FILE *out;

    scanf("%s", arq_in);
    scanf("%s", arq_out);
    scanf("%s", word);

    arq = fopen(arq_in, "rt");
    out = fopen(arq_out, "wt");

    if(arq==NULL){
        printf("\nArquivo não existe!\n");
        return 0;
    }

    while(fgets(line, 150, arq)){

        //if(DEBUG) printf("%s",line);
        //if(DEBUG) fileeye(arq, out);

        if(strstr(line, word)!=NULL){
            // fprintf(out, "%s", line);
            if(DEBUG) filelineeye(arq, out, line);
        }
    }

    fclose(arq);
    fclose(out);

    //arquivo_finalizado("saida.txt");

    return 0;
}
