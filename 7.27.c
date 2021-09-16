#include <stdio.h>

#define TAM 5
// Definição dos comandos
// ----------------------------------------------------------------------------
#define READ 10
#define WRITE 11
// ----------------------------------------------------------------------------
#define LOAD 20
#define STORE 21
// ----------------------------------------------------------------------------
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
// ----------------------------------------------------------------------------
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43
// ----------------------------------------------------------------------------
int verificar_comando(char str, int num);
int main(){
    char sinal[TAM];
    int acumulador = 0000;
    int comandos[TAM];
    int i,j;
    int verifica;
    int operar, operando;
    int resultados[TAM];
    int A,B,k = 0;

    for(i = 0; i < 100; i++){
        fflush(stdin);
        scanf("%c%5d", &sinal[i], &comandos[i]);

        verifica = verificar_comando(sinal[i], comandos[i]);

        if(verifica == 1){
            printf("acabaram os comandos\n");
            break;
        }
        else if(verifica == 0){
            operando = comandos[i]%100;
            operar = comandos[i]/100;
            printf("entrou aqui\n");
            switch (operar){
                case READ:
                    if (k == 0){
                        printf("Digite A:\t");
                        scanf("%d", &A);
                        resultados[operando] = A;
                    }else{
                        printf("Digite B:\t");
                        scanf("%d", &B);
                        resultados[operando] = B;
                    }
                    k++;
                    break;
                case WRITE:
                    resultados[operando] = acumulador;
                    break;
                case LOAD:
                    acumulador += resultados[operando];
                    break;
                case STORE:
                    resultados[operando] = acumulador;
                    break;
                case ADD:
                    acumulador += resultados[operando];
                    break;
                case SUBTRACT:
                    acumulador -= resultados[operando];
                    break;
                case DIVIDE:
                    acumulador /= resultados[operando];
                    break;
                case MULTIPLY:
                    acumulador *= resultados[operando];
                    break;
                case BRANCH:
                    //Desviar para um local especifico da memoria. Como?
                    break;
                case BRANCHNEG:
                    if (acumulador < 0){
                        resultados[operando] = acumulador;
                    }
                    break;
                case BRANCHZERO:
                    if (acumulador == 0){
                        resultados[operando] = acumulador;
                    }
                    break;
                case HALT:
                    break;
            }
            if (operar == HALT){
                break;
            }
        }
        else{
            printf("não entra\n");
        }
    }
    for (j = 0; j < i; j++){
        printf("%02d \? %+d\n", j, comandos[j]);
    }
    return 0;
}
int verificar_comando(char str, int num){
    
    fflush(stdin);

    if (str == '+'){
        return 0;
    }else if (str == '-'){
        if (num == 99999){
            return 1+5
            +;
        }
        
    }
}