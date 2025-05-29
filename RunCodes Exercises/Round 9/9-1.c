#include <stdio.h>
#include <string.h>

#define MAX 8
#define DEBUG 0

int main(){
    char filename[100];
    unsigned char read[MAX];
    FILE *file;

    char BMP[]={0x42,0x4D};
    char PNG[]={0x89,0x50,0x4E,0x47,0x0D,0x0A,0x1A,0x0A};
    char GIF[]={0x47,0x49,0x46,0x38};
    char JPEG[]={0xFF,0xD8,0XFF};
    char PDF[]={0x25,0x50,0x44,0x46};
    char ZIP[]={0x50,0x4B,0x03,0x04};
    char ELF[]={0x7F,0x45,0x4C,0x46};
    char WAV[]={0x52,0x49,0x46,0x46};
    char MP3_1[]={0xFF,0xFB};
    char MP3_2[]={0x49,0x44,0x33};

    scanf("%s", filename);
    file = fopen(filename,"rb");

    if(!file) return 0;

    fread(read, 1, MAX, file);

    if(DEBUG){
        for (int i = 0; i < MAX; i++)
        {
            printf("%02X ", read[i]);
        }
        printf("\n");
        for (int i = 0; i < MAX; i++)
        {
            printf("%02X ", PNG[i]);
        }
        printf("\n");

        printf("Retorno: %d\n", memcmp(PNG, read, sizeof(PNG)));
    }

    if(!memcmp(BMP, read, sizeof(BMP))){
        printf("Arquivo BMP");
    }
    else if(!memcmp(PNG, read, sizeof(PNG))){
        printf("Arquivo PNG");
    }
    else if(!memcmp(GIF, read, sizeof(GIF))){
        printf("Arquivo GIF");
    }
    else if(!memcmp(JPEG, read, sizeof(JPEG))){
        printf("Arquivo JPEG");
    }
    else if(!memcmp(PDF, read, sizeof(PDF))){
        printf("Arquivo PDF");
    }
    else if(!memcmp(ZIP, read, sizeof(ZIP))){
        printf("Arquivo ZIP");
    }
    else if(!memcmp(ELF, read, sizeof(ELF))){
        printf("Arquivo ELF");
    }
    else if(!memcmp(WAV, read, sizeof(WAV))){
        printf("Arquivo WAV");
    }
    else if(!memcmp(MP3_1, read, sizeof(MP3_1))){
        printf("Arquivo MP3");
    }
    else if(!memcmp(MP3_2, read, sizeof(MP3_2))){
        printf("Arquivo MP3");
    }
    else{
        printf("Tipo de arquivo desconhecido");
    }
    
    fclose(file);
}