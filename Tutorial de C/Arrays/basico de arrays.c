#include <stdio.h>

int main(){
    // Arrays são "listas" de números.
    // Arrays pode conter qualquer tipo numérico (int, float, double, etc)
    // NOTA: Diferente de strings, arrays não terminam com '\0'. O tamanho do array é a quantidade de itens mesmo.

    // ------------- DECLARANDO ARRAYS -------------

    // 1° Forma
    int array[] = {25, 50, 75, 100};

    // 2° Forma
    int array2[4]; // Define tamanho do array (4 números) para atribuir variáveis depois

    array2[0] = 25; // Muda índice 0
    array2[1] = 50; // Muda índice 1
    array2[2] = 75; // Muda índice 2
    array2[3] = 100; // Muda índice 3

    // ------------- ACESSANDO ÍNDICES DO ARRAY -------------

    // Se foi criado um array de tamanho [4], haverão os índices 0,1,2,3. (vai de 0 a n-1).

    // [50, 51, 52, 53]
    //  0   1    2   3

    // Assim, podemos usar um índice numeros[n] como se fosse uma variável única, normal.

    printf("%d", array[0]); // Imprimindo
    printf("\n");

    array[0] = array[1] + 1; // Somando

    printf("%d", array[0]);
    printf("\n");
    // E todas as propriedades de variáveis, operações, etc...

    // ------------- TAMANHO DO ARRAY -------------

    // Se quisermos a QUANTIDADE DE ITENS em um array, podemos utilizar o método abaixo.

    int tamanho = 0;
    tamanho = sizeof(array)/sizeof(array[0]);

    printf("%d", tamanho);
    printf("\n");

    // sizeof(array) -> Retorna o tamanho do array em bytes.
    // sizeof(array[0]) -> Retorna o tamanho de um elemento do array em bytes.

    // Um array de 4 elementos int terá 16 bytes, pois são 4 elementos de 4 bytes.
    // O método acima utiliza o raciocínio inverso.

    // ------------- ITERANDO SOBRE UM ARRAY -------------

    // Em arrays muito grandes, é condenável acessar elemento por elemento.
    // Por isso, frequentemente arrays são acessados via loops.

    int array3[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    tamanho = sizeof(array3)/sizeof(array3[0]);

    for(int i = 0; i < tamanho; i++){
        printf("%d ", array3[i]);
    }
    printf("\n");

    // 1) i = 0, pois o primeiro índice sempre é zero.
    // 2) i < tamanho, pois o tamanho é 20, mas os índices vão de 0-19.

    // ------------- ARRAY BIDIMENSIONAL -------------

    // É um array de duas dimensões.
    // Pode ser pensado como array[linha][coluna].

    // 1° Forma
    int array2D[][3] = {{1,2,3},{1,2,3},{1,2,3}};

    // [1,2,3]
    // [1,2,3] --> Array criado
    // [1,2,3]

    // 2° Forma (cria array e adiciona elementos depois)
    int array2_2D[3][3];

    array2_2D[0][0] = 1;
    array2_2D[0][1] = 2;
    array2_2D[0][2] = 3;
    array2_2D[1][0] = 1;
    array2_2D[1][1] = 2;
    array2_2D[1][2] = 3;
    array2_2D[2][0] = 1;
    array2_2D[2][1] = 2;
    array2_2D[2][2] = 3;

    // Nota: em arrays de 2+ dimensões, o tamanho a partir da 2° dimensão tem que ser especificado.
    //       array[]
    //       array[][3]
    //       array[][3][3]

    // ------------- ACESSANDO ÍNDICES DO ARRAY BIDIMENSIONAL -------------

    // Pensa-se como array[linha][coluna], lembrando que os índices começam em 0.

    array2D[1][0] = 1;
    array2D[1][0] = array2D[1][1] + 1;

    // [1,2,3]
    // [1,2,3] --> Acessando 1: array_2d[1][0]
    // [1,2,3]

    // ------------- ITERANDO SOBRE UM ARRAY BIDIMENSIONAL -------------

    // Linhas: Tamanho do array / Tamanho de uma linha
    int linhas = sizeof(array2D)/sizeof(array2D[0]);
    // Colunas: Tamanho de uma linha / Tamanho de um item
    int colunas = sizeof(array2D[0])/sizeof(array2D[0][0]);

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d ", array2D[i][j]);
        }
        printf("\n");
    }

    // O código acima entra na linha i=0, e imprime os elementos j=1, j=2, j=3
    // Depois entra na linha i=1, e imprime os elementos j=1, j=2, j=3
    // ...

    return 0;
}
