#include <stdio.h>
#include <math.h> // Caso seja necessario usar pow(), pi, etc.

// Cria uma estrutura que tera x como numero e var como incerteza
struct number {
  double x;
  double var;
};

// Operacao de adicao
struct number add(struct number op1, struct number op2){
    struct number result = {0,0};
    
    result.x = op1.x + op2.x;
    result.var = op1.var + op2.var;
    
    return result;
}

// Operacao de subtracao
struct number sub(struct number op1, struct number op2){
    struct number result = {0,0};
    
    result.x = op1.x - op2.x;
    result.var = op1.var + op2.var;
    
    return result;
}

// Operacao de multiplicacao
struct number mult(struct number op1, struct number op2){
    struct number result = {0,0};
    
    result.x = op1.x * op2.x;
    result.var = op1.x * op2.var + op2.x * op1.var;
    
    double part1 = op1.x * op2.var;
    double part2 = op2.x * op1.var;
    
    return result;
}

// Operacao de potencia
struct number pot(struct number op1, int n){
    struct number result = {0,0};
    
    if(n > 1){
    
        for(int i = 1; i < n; i++){
            if(i == 1){
                result = mult(op1, op1);
            }
            else{
                result = mult(result, op1);
            }
        }
        
        return result;   
    }
    else if(n == 1){
        
        return op1;
    }
    else if(n == 0){
        result.x = 1;
        result.var = 1;
        
        return result;
    }
}

// Operacao de multiplicacao por constante
struct number mult_by_const(struct number op1, double constant){
    struct number result = {0,0};
    
    result.x = op1.x * constant;
    result.var = op1.var * constant;

    return result;
}

// Operacao de divisao
struct number divi(struct number op1, struct number op2){
    struct number result = {0,0};
    
    result.x = op1.x / op2.x;
    result.var = (op1.x * op2.var + op2.x * op1.var)/pow(op2.x,2);

    return result;
}

// Mostra a estrutura na forma (x +- var) em notacao cientifica
// com 14 casas apos a virgula
void show(struct number result){
    printf("\nresult: (%.14e +- %.14e)",result.x, result.var);
}

// Funcao principal
int main() {
    // Exemplo: coeficiente angular da reta Forca x Deflexao
    struct number n1 = {3201.9, 0.7};
    struct number n2 = {1057.6, 0.2};
    struct number n3 = {49, 2};
    struct number n4 = {15, 2};

    // Diferenca de forcas
    struct number deltaF = sub(n1, n2);
    show(deltaF);

    // Diferenca de deflexoes
    struct number deltaX = sub(n3, n4);
    show(deltaX);

    // Coeficiente angular da reta (k = deltaF / deltaX)
    struct number k = divi(deltaF, deltaX);
    show(k);

    return 0;
}