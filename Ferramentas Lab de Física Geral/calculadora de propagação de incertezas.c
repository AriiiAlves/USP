#include <stdio.h>
#include <math.h> // Caso seja necessario usar pow(), pi, etc.

// Cria uma estrutura que tera x como numero e var como incerteza
typedef struct {
  double x;
  double var;
} number;

// Operacao de adicao
number add(number op1, number op2){
    number result = {0,0};
    
    result.x = op1.x + op2.x;
    result.var = op1.var + op2.var;
    
    return result;
}

// Operacao de subtracao
number sub(number op1, number op2){
    number result = {0,0};
    
    result.x = op1.x - op2.x;
    result.var = op1.var + op2.var;
    
    return result;
}

// Operacao de multiplicacao
number mult(number op1, number op2){
    number result = {0,0};
    
    result.x = op1.x * op2.x;
    result.var = op1.x * op2.var + op2.x * op1.var;
    
    double part1 = op1.x * op2.var;
    double part2 = op2.x * op1.var;
    
    return result;
}

// Operacao de potencia
number pot(number op1, int n){
    number result = {0,0};
    
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
number mult_by_const(number op1, double constant){
    number result = {0,0};
    
    result.x = op1.x * constant;
    result.var = op1.var * constant;

    return result;
}

// Operacao de divisao
number divi(number op1, number op2){
    number result = {0,0};
    
    result.x = op1.x / op2.x;
    result.var = (op1.x * op2.var + op2.x * op1.var)/pow(op2.x,2);

    return result;
}

// Operação de seno
number seno(number op){
    number result = {0,0};

    result.x = sin(op.x);
    result.var = cos(op.x) * op.var;

    return result;
}

// Operação de cosseno
number cosseno(number op){
    number result = {0,0};

    result.x = cos(op.x);
    result.var = sin(op.x) * op.var;

    return result;
}

// Operação de tangente
number tangente(number op){
    number result = {0,0};

    result = divi(seno(op),cosseno(op));

    return result;
}

// Operação de cotangente
number cotangente(number op){
    number result = {0,0};

    result = divi(cosseno(op),seno(op));

    return result;
}

// Mostra a estrutura na forma (x +- var) (modifique para notação científica ou as casas decimais se necessário)
void show(number result){
    printf("result: (%.3lf +- %.3lf)\n",result.x, result.var);
}

// Funcao principal
int main() {
    // Exemplo: coeficiente angular da reta Forca x Deflexao
    number n1 = {3201.9, 0.7};
    number n2 = {1057.6, 0.2};
    number n3 = {49, 2};
    number n4 = {15, 2};

    // Diferenca de forcas
    number deltaF = sub(n1, n2);
    show(deltaF);

    // Diferenca de deflexoes
    number deltaX = sub(n3, n4);
    show(deltaX);

    // Coeficiente angular da reta (k = deltaF / deltaX)
    number k = divi(deltaF, deltaX);
    show(k);

    return 0;
}
