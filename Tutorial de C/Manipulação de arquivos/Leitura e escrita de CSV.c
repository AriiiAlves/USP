#include <stdio.h>

int main(){

    // ----------------- USANDO STRTOK -----------------

    /* O strtok() quebra uma string em m�ltiplas partes/tokens usando delimitadores.
       A primeira chamada do strtok() deve ter um ponteiro � string que ser� quebrada.
       J� as pr�ximas chamadas para pegar a 2�, 3�, ... partes da string, deve ter o argumento NULL.
       Pois cada vez que a fun��o � chamada, um ponteiro para uma parte/token � retornado at� que n�o
       hajam mais tokens.

       Fique atento, pois essa fun��o modifica a string original, substituindo os
       delimitadores por caracteres '\0', assim cada token pode ter seu pr�prio caractere
       de t�rmino.

       Para usar strtok(), utilize a biblioteca <string.h>

       SINTAXE: strtok(variavel da string (apenas no 1� uso), delimitador (espa�o, v�rgula, etc);*/

    // ----------------- LENDO UM CSV -----------------

    // Fazer a leitura de um CSV � abrir um simples arquivo-texto.
    // CSV s�o arquivos onde em cada linha h� strings/n�meros separados por
    // v�rgula (EN) ou ponto e v�rgula (BR)

    FILE *arq;
    arq = fopen("dados.csv","rt");

    char line[100]; // Ir� receber uma linha do CSV
    char v1[10],v2[10],v3[10]; // Valores de cada linha do CSV. v1, v2, v3: coluna 1,2,3.
    char *sp; // Ponteiro que armazenar� endere�o de mem�ria da string cortada temporariamente
    int count;

    if(!arq){
        printf("Erro: n�o foi poss�vel abrir o arquivo");
    }

    // Observe que n�o ser� usado FEOF (incorreto usar ele), e sim verificamos se o FGETS
    // consegue fazer a leitura (retorna diferente de NULL sempre que l� algo)
    while(fgets(line, 100, arq)!= NULL){

        // Abaixo, temos uma observa��o. Por que usamos um ponteiro *sp
        // e n�o atribu�mos direto o strtok a uma vari�vel?

        // v1 = strtok(line, ",");     // ERRO: voc� n�o pode atribuir a um vetor assim

        // Mas, se usarmos ponteiro, n�o estamnos guardando a string para guard�-la
        // na vari�vel de string depois. E sim, estamos pegando o endere�o da string
        // para a� sim fazermos um strcpy()!

        sp = strtok(line, ",");     // Separador: V�rgula ','
        strcpy(v1,sp);

        sp = strtok(NULL, ",");
        strcpy(v2,sp);

        sp = strtok(NULL, ",");
        strcpy(v3,sp);

        count++; // Cont +1 linha

        printf("Line %d: %s  -  %s  -  %s \n", count, v1, v2, v3);
    }

    fclose(arq);

    // ----------------- ESCREVENDO NUM CSV -----------------

    // Apenas utilize as fun��es b�sicas de escrita em arquivos, tendo em mente
    // que ser�o valores separados por v�rgula ou ponto e v�rgula, e o \n designa
    // o fim de cada linha da planilha.

    int Data[] = {1,2,3,4,5,6,7,8,9,10,11,12};

    FILE *arq;
    arq = fopen("dados.csv","wt");

    if(!arq){
        printf("Erro: n�o foi poss�vel abrir o arquivo");
    }

    for (i=1; i <= 12; i++)
    {
        fprintf(arq,"%d, ",Data[i-1]);
        if ((i % 3) == 0) fprintf(arq,"\n");
    }
}
