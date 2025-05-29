#include <stdio.h>
#include <string.h>
#define DEBUG 0
#include "file_resources.h"
//#include "avaliador.h"

int main(){
    char ch;

    FILE *arq;
    FILE *out;

    arq = fopen("notas.csv", "rt");
    out = fopen("notas_convertido.csv", "wt");

    if(arq==NULL){
        printf("\nArquivo não existe!\n");
        return 0;
    }

    if(DEBUG) filechareye(arq, out);

    while(!feof(arq)){
        ch=fgetc(arq);

        if(ch==',') ch = ';';
        if(ch=='.') ch = ',';

        if(ch >= 32 || ch == '\n') fputc(ch,out);
    }

    fclose(arq);
    fclose(out);

    //arquivo_finalizado("notas_convertido.csv");

    return 0;
}
