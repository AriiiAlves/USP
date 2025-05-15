#include <stdio.h>

int main(){

    // ----------------- USANDO STRTOK -----------------

    /* O strtok() quebra uma string em múltiplas partes/tokens usando delimitadores.
       A primeira chamada do strtok() deve ter um ponteiro à string que será quebrada.
       Já as próximas chamadas para pegar a 2°, 3°, ... partes da string, deve ter o argumento NULL.
       Pois cada vez que a função é chamada, um ponteiro para uma parte/token é retornado até que não
       hajam mais tokens.

       Fique atento, pois essa função modifica a string original, substituindo os
       delimitadores por caracteres '\0', assim cada token pode ter seu próprio caractere
       de término.

       Para usar strtok(), utilize a biblioteca <string.h>

       SINTAXE: strtok(variavel da string (apenas no 1° uso), delimitador (espaço, vírgula, etc);*/

    // ----------------- LENDO UM CSV -----------------

    // Fazer a leitura de um CSV é abrir um simples arquivo-texto.
    // CSV são arquivos onde em cada linha há strings/números separados por
    // vírgula (EN) ou ponto e vírgula (BR)

    FILE *arq;
    arq = fopen("dados.csv","rt");

    char line[100]; // Irá receber uma linha do CSV
    char v1[10],v2[10],v3[10]; // Valores de cada linha do CSV. v1, v2, v3: coluna 1,2,3.
    char *sp; // Ponteiro que armazenará endereço de memória da string cortada temporariamente
    int count;

    if(!arq){
        printf("Erro: não foi possível abrir o arquivo");
    }

    // Observe que não será usado FEOF (incorreto usar ele), e sim verificamos se o FGETS
    // consegue fazer a leitura (retorna diferente de NULL sempre que lê algo)
    while(fgets(line, 100, arq)!= NULL){

        // Abaixo, temos uma observação. Por que usamos um ponteiro *sp
        // e não atribuímos direto o strtok a uma variável?

        // v1 = strtok(line, ",");     // ERRO: você não pode atribuir a um vetor assim

        // Mas, se usarmos ponteiro, não estamnos guardando a string para guardá-la
        // na variável de string depois. E sim, estamos pegando o endereço da string
        // para aí sim fazermos um strcpy()!

        sp = strtok(line, ",");     // Separador: Vírgula ','
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

    // Apenas utilize as funções básicas de escrita em arquivos, tendo em mente
    // que serão valores separados por vírgula ou ponto e vírgula, e o \n designa
    // o fim de cada linha da planilha.

    int Data[] = {1,2,3,4,5,6,7,8,9,10,11,12};

    FILE *arq;
    arq = fopen("dados.csv","wt");

    if(!arq){
        printf("Erro: não foi possível abrir o arquivo");
    }

    for (i=1; i <= 12; i++)
    {
        fprintf(arq,"%d, ",Data[i-1]);
        if ((i % 3) == 0) fprintf(arq,"\n");
    }
}
