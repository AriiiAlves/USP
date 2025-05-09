#include <stdio.h>
#include <string.h>

// Verifica se não é um caractere invisível
int charvalid(char c){
    if(c >= 32){return 1;} else{return 0;}
}

// deixa caracteres invisíveis visíveis
const char* chardiscover(char c){
    int code = c; // Converte char para int
    static char ascii[5] = {0}; // Stores the simplified name

    switch(code) {
        case 0:   strcpy(ascii, "\\0"); break;       // Null
        case 7:   strcpy(ascii, "\\a"); break;       // Bell (Alert)
        case 8:   strcpy(ascii, "\\b"); break;       // Backspace
        case 9:   strcpy(ascii, "\\t"); break;       // Horizontal Tab
        case 10:  strcpy(ascii, "\\n"); break;       // New Line
        case 11:  strcpy(ascii, "\\v"); break;       // Vertical Tab
        case 12:  strcpy(ascii, "\\f"); break;       // Form Feed
        case 13:  strcpy(ascii, "\\r"); break;       // Carriage Return
        case 27:  strcpy(ascii, "\\e"); break;       // Escape (not in standard C, but common)
        case 26:  strcpy(ascii, "^Z"); break;        // Ctrl+Z (EOF in Windows)
        case 3:   strcpy(ascii, "^C"); break;        // Ctrl+C (Interrupt)
        case 4:   strcpy(ascii, "^D"); break;        // Ctrl+D (EOF in Unix)
        case 1:   strcpy(ascii, "^A"); break;        // Ctrl+A
        case 2:   strcpy(ascii, "^B"); break;        // Ctrl+B
        // ... (more Ctrl+key mappings if needed)
        default:  sprintf(ascii, "%d", code); break; // Fallback: show raw number
    }
    
    return ascii;
}

// Programa para mostrar todos os caracteres de uma string
void stropen(char str[]){
        int size = strlen(str) + 1;
        
        printf("-------------------------");
        printf("\nString digitada: \"%s\"", str);
        
        printf("\nNa memória: [");
        for(int i = 0; i < size; i++){
            if(i!=size-1){
                printf("\'%c\',", str[i]);
            }
            else{
                printf("\'%c\'", str[i]);
            }
        }
        printf("]");
        
        printf("\nCaracteres invisíveis: [");
        for(int i = 0; i < size; i++){
            if(i!=size-1){
                if(charvalid(str[i])){
                    printf("\'%c\',", str[i]);
                }
                else{
                    printf("\'%s\',", chardiscover(str[i]));
                }
            }
            else{
                if(charvalid(str[i])){
                    printf("\'%c\'", str[i]);
                }
                else{
                    printf("\'%s\'", chardiscover(str[i]));
                }
            }
        }
        printf("]");
        
        printf("\nCódigos ASCII: [");
        for(int i = 0; i < size; i++){
            if(i!=size-1){
                printf("%d,", str[i]);
            }
            else{
                printf("%d", str[i]);
            }
        }
        printf("]");
        printf("\n-------------------------");
    }

int main()
{
    char string[] = "Hello\a\nMy Brother";
    stropen(string);
    
    return 0;
}