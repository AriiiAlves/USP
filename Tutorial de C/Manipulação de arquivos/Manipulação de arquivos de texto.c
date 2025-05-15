#include <stdio.h>

int main(){

    // Vamos trabalhar com arquivos texto. Leitura, escrita, etc.

    // -------- ABRINDO E FECHANDO ARQUIVOS COM FOPEN/FCLOSE --------

    /* Aqui, definimos um PONTEIRO para um tipo de estrutura chamada FILE.
    FILE � um STRUCT definido pelo <stdio.h> que armazena todas as
    informa��es necess�rias para gerenciar um arquivo:

    - Ponteiro para o arquivo
    - Modo de abertura (leitura, escrita. etc)
    - Estado do buffer
    - etc.
        Lembrando que o ponteiro � um endere�o de mem�ria.
    */
    FILE *aquivo;

    /* Aqui, usamos fopen("nome do arquivo.ext","modo&tipo").
    O modo � como vamos operar com o arquivo. Existem os modos:

    - r -> Leitura. O arquivo PRECISA existir. Ao ser aberto, o conte�do permanece.
    - w -> Escrita. O arquivo N�O PRECISA existir, ser� criado um novo caso n�o exista. Ao abrir, o conte�do � apagado.
    - a -> Acrescentar/Append. O arquivo N�O PRECISA existir, ser� criado um novo caso n�o exista. Ao abrir, novo conte�do � adicionado ao fim.
    - r+ -> Leitura e escrita. O arquivo PRECISA existir. Ao abrir, o conte�do permanece.
    - w+ -> Escrita e leitura. O arquivo N�O PRECISA existir, , ser� criado um novo caso n�o exista. Ao abrir, o conte�do � apagado.
    - a -> Leitura e append. O arquivo N�O PRECISA existir. Ao abrir, pode ser lido ou adicionado novo conte�do no fim.

       Ao lodo do modo escolhido, coloca-se o tipo de arquivo.

    - b -> Bin�rio (.exe, etc)
    - t -> Texto (.txt)
    */

    arquivo = fopen("teste.txt","rt"); // Leitura de texto

    /* Se o fopen retornar NULL, quer dizer que n�o encontrou o
       arquivo. O NULL � equivalente a um 0 ou "false" para o if. */
    if(arquivo){
        printf("Arquivo aberto com sucesso!");

        /* Ap�s abrir com sucesso o arquivo, precisamos FECH�-LO, pois:

        - Libera recursos do sistema (mem�ria reservada)
        - Garante que os dados sejam SALVOS no arquivo(quando voc� escreve no arquivo,
          os dados geralmente v�o primeiro para um buffer
          na mem�ria, para melhorar a performance. O fclose garante que esse buffer seja
          efetivado no arquivo.
        - Permite que o arquivo seja reaberto. Se voc� n�o fechar o arquivo, pode n�o
          conseguir abri-lo novamente, aparece "o arquivo est� sendo usado por outro programa"
        */
        fclose(arquivo);
    }
    else{
        // Se fopen retornar NULL
        printf("Arquivo n�o encontrado!");
    }

    fclose(arquivo);

    // ---------------- FUN��ES DE ARQUIVOS DE TEXTO ----------------

    FILE *aquivo;
    arquivo = fopen("teste.txt","rt");
    int num; // Ser� utilizado para testes
    char string[150]; // Ser� utilizado para testes

    if(arquivo){

        // >>>>>>>>>> FPRINTF <<<<<<<<<<
        // printf para arquivos. Lembre-se de especificar o ponteiro do arquivo no in�cio.
        fprintf(arquivo,"Teste de escrita com fprintf");

        // >>>>>>>>>> FSCANF <<<<<<<<<<
        // scanf para arquivos. L� at� esbarrar em um espa�o ou \n.
        // Lembre-se de especificar o ponteiro do arquivo no in�cio.
        fscanf(arquivo,"%d", num);

        // >>>>>>>>>> FGETS <<<<<<<<<<
        // Mesma coisa do fgets para prompt. Ele tamb�m consegue ler arquivos.
        // Lembrando que ele l� at� encontrar um \n, ou seja, frases inteiras.
        fgets(string, 10, arquivo);

        // >>>>>>>>>> FPUTS <<<<<<<<<<
        // Escreve uma linha de texto no arquivo (texto + \n)
        fputs(string, arquivo);

        // >>>>>>>>>> FEOF <<<<<<<<<<
        // Verifica se chegou ao final do arquivo. Retorna 0 (Falso) se ainda n�o chegar ao fim.
        // OBS: O FEOF N�O ANTECIPA  o fim do arquivo. Ele s� retorna 1 (True) ap�s uma tentativa falha.
        //      Assim, se usado como abaixo, a �ltima vez repetir�.

        // >>>>>>>>>> USANDO FEOF (INCORRETO) <<<<<<<<<<
        while (!feof(arquivo)) {
            fscanf(arquivo, "%d", &num);
            printf("N�mero lido: %d\n", num);
        }

        // >>>>>>>>>> EVITANDO FEOF <<<<<<<<<<
        // O FEOF N�O DEVE SER USADO COMO CONDI��O PRINCIPAL do seu c�digo. H� v�rias alternativas.

        // USANDO FSCANF PARA END OF FILE

        // �til pois fscanf retorna 1 se conseguir fazer a leitura esperada.
        // OBS: Se o fscanf ler uma string ao inv�s do n�mero esperado, retornar� 0.

        while(fscanf(arquivo, "%d", &num) == 1){
            printf("N�mero lido: %d\n", num);
        }

        // USANDO GETC()

        // O getc() � uma fun��o que l� o pr�ximo caractere do arquivo.
        // Ele � ideal pelo fato de int, float, etc, poderem ser representados como strings.
        char ch;

        while((ch=getc(arquivo)) != EOF){
            printf("N�mero lido: %d\n", num);
        }

        // temos que atribuir o getc a uma vari�vel para ser realizda a leitura
        // desse endere�o de mem�ria. Depois, comparamos com EOF, que varia dependendo
        // do sistema operacional ou linguagem. Pode ser -1, por exemplo.

        fclose(arquivo);
    }
}
