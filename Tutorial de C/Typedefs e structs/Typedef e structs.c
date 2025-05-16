#include <stdio.h>
int main()
{
    // ------------- TYPEDEF -------------
    
    /* Typedef permite "criar novos tipos de dados". Na verdade, ele
       permite que você não precise repetir a mesma declaração longa
       mais vezes.
       
       Isso é interessante para códigos longos. Usar typdef permite que
       você altere o tipo de TODAS AS VARIÁVEIS que usam aquele Typedef
       em apenas uma linha.
    */
    
    typedef float tip_nota; // Se alterado para int, todos serão alterados para int
    
    tip_nota n1;
    tip_nota n2;
    tip_nota n3;
    
    // ------------- STRUCTS ------------- 
    
    /* Structs são tipos de dados que são grandes armários que contém
       outros tipos de dados armazenados dentro.
       
       Eles são úteis para separar as variáveis criadas em categorias,
       para evitar repetição de criação de variáveis, além de facilitar
       a organização e simplificar o código.
    */
    
    // ------------- DECLARANDO STRUCTS ------------- 
    
    // 1° Forma 
    struct ponto {
      int x;
      int y;
    };
    
    struct ponto p3, p4;
    
    /*Acima, criamos uma struct ponto. O nome ponto pode ser utilizadp
      para criarmos mais structs a partir desse. O que criamos é apenas
      um modelo.*/

    // 2° Forma

    struct ponto p5 = {10,5};
    
    // 3° Forma
    struct{
      int x;
      int y;
    } p1, p2;
    
    /* Acima, após especificar os tipos de dados que o struct receberá,
       criamos dois structs p1 e p2. p1 e p2 contém, ambos x e y. Porém
       eles são duas estruturas (structs) totalmente diferentes!
       
       E também, esse struct some depois. Não dá para criar um p3 mais adiante
       a partir dele, como na 1° Forma.
    */
    
    // ------------- ACESSANDO STRUCTS ------------- 
    
    p1.x = 5;
    p1.y = 10;

    p2.x = 10;
    p2.y = 5;
    
    if(p1.x == 5) printf("p1.x é 5!\n");
    if(p1.y == 10) printf("p1.y é 10!\n");
    if(p2.x == 10) printf("p2.x é 10!\n");
    if(p2.y == 5) printf("p2.y é 5!\n");
    
    // ------------- STRUCTS COM TYPEDEF ------------- 
    
    /* Struct pode ser declarado com typedef para, após criar um
       "modelo" de struct, evitar ficar repetindo <struct modelo variavel>
       a todo momento.
    */
    
    // Forma sem typedef
    struct data{
      int dia;
      int mes;
      int ano;
    };
    
    struct data aniversario = {13,04,2006};
    
    printf("%d/%d/%d\n", aniversario.dia, aniversario.mes, aniversario.ano);
    
    // Forma com typedef
    
    typedef struct{
      int dia;
      int mes;
      int ano;
    } data2; // O nome do "novo tipo" fica no final
    
    data2 aniversario2 = {15,04,2006};
    
    printf("%d/%d/%d", aniversario2.dia, aniversario2.mes, aniversario2.ano);
}
