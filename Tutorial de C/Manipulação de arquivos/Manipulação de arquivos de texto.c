#include <stdio.h>

int main(){

    // Vamos trabalhar com arquivos texto. Leitura, escrita, etc.

    // -------- ABRINDO E FECHANDO ARQUIVOS COM FOPEN/FCLOSE --------

    /* Aqui, definimos um PONTEIRO para um tipo de estrutura chamada FILE.
    FILE é um STRUCT definido pelo <stdio.h> que armazena todas as
    informações necessárias para gerenciar um arquivo:

    - Ponteiro para o arquivo
    - Modo de abertura (leitura, escrita. etc)
    - Estado do buffer
    - etc.
        Lembrando que o ponteiro é um endereço de memória.
    */
    FILE *aquivo;

    /* Aqui, usamos fopen("nome do arquivo.ext","modo&tipo").
    O modo é como vamos operar com o arquivo. Existem os modos:

    - r -> Leitura. O arquivo PRECISA existir. Ao ser aberto, o conteúdo permanece.
    - w -> Escrita. O arquivo NÃO PRECISA existir, será criado um novo caso não exista. Ao abrir, o conteúdo é apagado.
    - a -> Acrescentar/Append. O arquivo NÃO PRECISA existir, será criado um novo caso não exista. Ao abrir, novo conteúdo é adicionado ao fim.
    - r+ -> Leitura e escrita. O arquivo PRECISA existir. Ao abrir, o conteúdo permanece.
    - w+ -> Escrita e leitura. O arquivo NÃO PRECISA existir, , será criado um novo caso não exista. Ao abrir, o conteúdo é apagado.
    - a -> Leitura e append. O arquivo NÃO PRECISA existir. Ao abrir, pode ser lido ou adicionado novo conteúdo no fim.

       Ao lodo do modo escolhido, coloca-se o tipo de arquivo.

    - b -> Binário (.exe, etc)
    - t -> Texto (.txt)
    */

    arquivo = fopen("teste.txt","rt"); // Leitura de texto

    /* Se o fopen retornar NULL, quer dizer que não encontrou o
       arquivo. O NULL é equivalente a um 0 ou "false" para o if. */
    if(arquivo){
        printf("Arquivo aberto com sucesso!");

        /* Após abrir com sucesso o arquivo, precisamos FECHÁ-LO, pois:

        - Libera recursos do sistema (memória reservada)
        - Garante que os dados sejam SALVOS no arquivo(quando você escreve no arquivo,
          os dados geralmente vão primeiro para um buffer
          na memória, para melhorar a performance. O fclose garante que esse buffer seja
          efetivado no arquivo.
        - Permite que o arquivo seja reaberto. Se você não fechar o arquivo, pode não
          conseguir abri-lo novamente, aparece "o arquivo está sendo usado por outro programa"
        */
        fclose(arquivo);
    }
    else{
        // Se fopen retornar NULL
        printf("Arquivo não encontrado!");
    }

    fclose(arquivo);

    // ---------------- FUNÇÕES DE ARQUIVOS DE TEXTO ----------------

    FILE *aquivo;
    arquivo = fopen("teste.txt","rt");
    int num; // Será utilizado para testes
    char string[150]; // Será utilizado para testes

    if(arquivo){

        // >>>>>>>>>> FPRINTF <<<<<<<<<<
        // printf para arquivos. Lembre-se de especificar o ponteiro do arquivo no início.
        fprintf(arquivo,"Teste de escrita com fprintf");

        // >>>>>>>>>> FSCANF <<<<<<<<<<
        // scanf para arquivos. Lê até esbarrar em um espaço ou \n.
        // Lembre-se de especificar o ponteiro do arquivo no início.
        fscanf(arquivo,"%d", num);

        // >>>>>>>>>> FGETS <<<<<<<<<<
        // Mesma coisa do fgets para prompt. Ele também consegue ler arquivos.
        // Lembrando que ele lê até encontrar um \n, ou seja, frases inteiras.
        fgets(string, 10, arquivo);

        // >>>>>>>>>> FPUTS <<<<<<<<<<
        // Escreve uma linha de texto no arquivo (texto + \n)
        fputs(string, arquivo);

        // >>>>>>>>>> FEOF <<<<<<<<<<
        // Verifica se chegou ao final do arquivo. Retorna 0 (Falso) se ainda não chegar ao fim.
        // OBS: O FEOF NÃO ANTECIPA  o fim do arquivo. Ele só retorna 1 (True) após uma tentativa falha.
        //      Assim, se usado como abaixo, a última vez repetirá.

        // >>>>>>>>>> USANDO FEOF (INCORRETO) <<<<<<<<<<
        while (!feof(arquivo)) {
            fscanf(arquivo, "%d", &num);
            printf("Número lido: %d\n", num);
        }

        // >>>>>>>>>> EVITANDO FEOF <<<<<<<<<<
        // O FEOF NÃO DEVE SER USADO COMO CONDIÇÃO PRINCIPAL do seu código. Há várias alternativas.

        // USANDO FSCANF PARA END OF FILE

        // Útil pois fscanf retorna 1 se conseguir fazer a leitura esperada.
        // OBS: Se o fscanf ler uma string ao invés do número esperado, retornará 0.

        while(fscanf(arquivo, "%d", &num) == 1){
            printf("Número lido: %d\n", num);
        }

        // USANDO GETC()

        // O getc() é uma função que lê o próximo caractere do arquivo.
        // Ele é ideal pelo fato de int, float, etc, poderem ser representados como strings.
        char ch;

        while((ch=getc(arquivo)) != EOF){
            printf("Número lido: %d\n", num);
        }

        // temos que atribuir o getc a uma variável para ser realizda a leitura
        // desse endereço de memória. Depois, comparamos com EOF, que varia dependendo
        // do sistema operacional ou linguagem. Pode ser -1, por exemplo.

        fclose(arquivo);
    }
}
