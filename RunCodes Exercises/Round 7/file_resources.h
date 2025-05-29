#ifndef FILE_RESOURCES
#define FILE_RESOURCES

#include<stdio.h>
#include<string.h>

void fileeye(FILE *arq, FILE *out){
    char line[150];

    while(fgets(line, 150, arq)){
        for (int i = 0; i < strlen(line); i++)
            {
                fprintf(out, "%03d ", line[i]);
            }
            fprintf(out, "\n");
            for (int i = 0; i < strlen(line); i++)
            {
                if(line[i] < 32){
                    fprintf(out, "/// ");
                }
                else{
                    fprintf(out, "%c   ", line[i]);
                }
            }
            fprintf(out, "\n");
        }
}

void filelineeye(FILE *arq, FILE *out, char *line){

    for (int i = 0; i < strlen(line); i++)
        {
            fprintf(out, "%03d ", line[i]);
        }
        fprintf(out, "\n");
        for (int i = 0; i < strlen(line); i++)
        {
            if(line[i] < 32){
                fprintf(out, "/// ");
            }
            else{
                fprintf(out, "%c   ", line[i]);
            }
        }
        fprintf(out, "\n");
}

void filechareye(FILE *arq, FILE *out){
    char c;

    while(c = fgetc(arq)){
        fprintf(out, "%03d ", c);

        if(c == '\n'){
            fprintf(out, "\n");
        }
    }

    rewind(arq);

    while(c = fgetc(arq)){
        if(c < 32){
            fprintf(out, "/// ");
            if(c == '\n'){
                fprintf(out, "\n");
            }
        }
        else{
            fprintf(out, "%c   ", c);
        }
    }
}

#endif