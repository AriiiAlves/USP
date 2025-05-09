#include <stdio.h>
#include <string.h> // Necessário para trabalhar com strings

int main(){
    // Strings são listas de char's. Assim como os arrays são listas de números.
    // Porém, toda string deve ter o '\0' no final, cujo código é 0.
    // Assim, se vamos criar uma string para uma palavra de 5 letras, devemos criar uma string de tamanho n+1.

    char frase[6]; //  Receberá palavra de 5 letras

    // ---------------- CUIDADOS AO TRABALHAR COM STRINGS ----------------

    // - Lembre-se de deixar um espaço para um '\0' no final de toda string.
    // - Atente-se ao tamanho da sua string: Ele é fixo ao longo do código.
    // - É recomendável SEMPRE INICIALIZAR as strings com valores.
    //   Se ela receberá seu valor mais adiante, inicialize com '\0' em todos os elementos!:
    // - Tome nota de que uma string na verdade é um ponteiro (endereço de memória) para
    //   o primeiro elemento da string.

    char exemplo[6] = {0}; // Todos elementos com 0, que em ASCII é '\0'
    // ou
    char exemplo2[6] = ""; // Todos elementos com 0, que em ASCII é '\0'

    // ---------------- ACESSANDO ÍNDICES DA STRING ----------------

    // Cada índice da string representa um caractere.

    frase[0] = 't';
    frase[1] = 'e';
    frase[2] = 's';
    frase[3] = 't';
    frase[4] = 'e';

    printf("%c", frase[0]); // Imprimindo caractere
    printf("\n");

    // ---------------- IMPRIMINDO STRING ----------------

    // A string é impressa com %s. Esse é o especificador de formato de strings.

    printf("%s", frase);
    printf("\n");

    // ---------------- TAMANHO DE UMA STRING ----------------

    // O tamanho de uma string pode ser verificado utilizando-se:

    int tamanho = sizeof(frase)/sizeof(frase[0]); // Retorna 6 (tamanho definido)

    printf("%d", tamanho);
    printf("\n");

    // Mas isso pode ser feito com a função strlen.
    // Porém, ela não contabiliza o '\0'. Então sempre retorna um a menos.
    // Porém sempre é muito utilizado, pois geralmente não mexemos no '\0' do fim.

    tamanho = strlen(frase); // Retorna 5 (tamanho definido - 1)

    printf("%d", tamanho);
    printf("\n");

    // ---------------- PREENCHENDO STRINGS COM STRCPY ----------------

    // frase = "Hello"; --> ERRADO!

    // Como strings são arrays de caracteres, e não apenas simples variáveis,
    // teremos de usar a biblioteca string.h. Utilize #include <string.h> no código.

    // Preenchendo strings com texto:
    strcpy(frase, "Hello World");
    // string final: ['H','E','L','L','O','\0']

    // Copiando uma string para outra:
    char frase2[] = "Oi!";
    strcpy(frase, frase2);
    // string final: ['O','i','!','\0','d','\0']

    // ---------------- "LIXO" DA STRING ----------------

    // Observe acima que o 'd' não foi limpo. Isso ocorre porque
    // o strcpy não "Limpa" a string, deixando tudo certinho com '\0'
    // antes de copiar a próxima string. Ele apenas sobrescreve.

    // Mas o interessante é que em funções como printf() ou strlen(), só será lido/impresso
    // até o '\0'. Portanto, o 'd' vai ser ignorado, mas ainda existirá na memória.

    // Um exemplo prático pode ser observado abaixo.

    char exemplo3[6] = "ABCDE";  // ['A', 'B', 'C', 'D', 'E', '\0']
    char exemplo4[2] = "X";      // ['X', '\0']
    strcpy(exemplo3, exemplo4);
    // string final: ['X','\0','C','D','E','\0']
    // em ASCII: [88 ,0,67,68,69,0]

    // Abaixo será impressa a string exemplo3, que recebeu cópia da string exemplo 4.
    // Porém, está sendo impresso em ASCII. Assim, caracteres ocultos serão impressos.
    // Observe que haverá no meio da string um '\0' e depois os ASCII da string antiga.

    tamanho = 6;

    for(int i = 0; i < tamanho; i++){
        printf("%d ", exemplo3[i]);
    }

    // ---------------- LENDO STRINGS ----------------

    char leitura[100] = {0};

    // SCANF()
    // - O scanf() lê toda a string até que encontre um espaço.
    // - O resto será ignorado (inclusive o espaço).
    // - OBS: Para outros tipos de dados, a variável possui um & antes,
    //        o que retorna o ponteiro (endereço de memória da variável).
    //        Porém, as strings já são um ponteiro (endereço de memória).
    //        Então é somente escrever a variável, sem &.
    //
    // - scanf(tipos a serem lidos, var1, var2, ...)

    scanf("%s", leitura);

    for(int i = 0; i < 10; i++){
        printf("%d ", leitura[i]);
    }
    printf("\n");
    printf("%s\n", leitura);

    // Input: "DANIEL SANTOS"
    // String: ['D','A','N','I','E','L','\0','\0',...]

    // FGETS()
    // - O fgets() lê uma linha inteira.
    // - Entende-se computacionalmente por linha todo grupo de caracteres
    //   até que se encontre um '\n'. '\n' é a 'quebra de linha', ou enter.
    // - O resto será ignorado (o '\n' NÃO É IGNORADO).

    // fgets(string, quantidade máxima de caracteres, onde ler)

    fflush(stdin); // Limpa buffer do console(stdin)

    fgets(leitura, 100, stdin); // stdin é o console

    for(int i = 0; i < 20; i++){
        printf("%d ", leitura[i]);
    }
    printf("\n%s", leitura);

    // Input: "DANIEL SANTOS"
    // String: ['D','A','N','I','E','L',' ','S','A','N','T','O','S','\n','\0','\0',...]

    // ---------------- AVISO DO BUFFER ----------------

    // Observe que tivemos que utilizar o fflush anteriormente.

    // Suponha a entrada: "DANIEL SANTOS". E considere buffer como o que escrevemos no terminal.

    // O scanf() lê até que haja um espaço. Portanto, ele coletou "DANIEL" do buffer.
    // E o resto? Foi deixado no buffer, como lixo. Quando o fgets fosse fazer a leitura, não faria uma leitura nova.
    // Mas sim, leria " SANTOS". Pois foi o que foi deixado no buffer, e o fgets lê até um '\n'.
    // O fflush(stdin) limpa a entrada do console, de modo que tira esse lixo da memória.

    fflush(stdin);

    // ---------------- STRING COMO ARGUMENTO DE UMA FUNÇÃO ----------------

    void mostrar_string(char str[]){
        printf("%s", str);
        printf("\n");
    }

    mostrar_string(leitura);

    // ---------------- STRINGS E PONTEIROS ----------------

    // Sabendo que a string é um ponteiro, podemos acessar seus itens por meio disso.

    char nome[] = "TONY STARK";

    printf("%c", *nome); // T
    printf("%c", *(nome+1)); // O
    printf("%c", *(nome+2)); // N

    // ---------------- FUNÇÕES DO STRING.H ----------------

    // strlen() - Calcula tamanho da string (não contabiliza o '\0')

    // strcpy() - Copia uma string para a outra (sobrescreve)

    // strcmp() - Compara duas strings
    //          - strcmp(string1, string2)
    //          - Retorna 0 (CONTINUAR DEPOIS)

    // strcat() - Junta duas strings

    return 0;
}
