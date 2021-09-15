#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
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
*/
int main(){

    int acumulador;
    char comandos[100][5];
    int i = 0, j = 0;
    int verificar;
    char sinal;
    int numero;

    while (i < 5){
        fflush(stdin);
        verificar = 0;

        //scanf("%d", &comandos[i]);
        //scanf("%[^\n]", &comandos[i][i]);
        scanf("%c%5d", &sinal, &numero);
        
        verificar = verificar_comando(sinal, numero);

        if (verificar == 2){
            printf("entrou aqui\n");
            break;
        }
        i++;
    }
/*
    if (verificar != 2){
        for (acumulador = 0; acumulador < i; acumulador++){
            printf("%02d \? %+d", acumulador, comandos[acumulador]);
        }
    }else{
        for (acumulador = 0; acumulador < i; acumulador++){
            printf("%02d \? %+d", acumulador, comandos[acumulador]);
        }
        printf("Erro Encontrado no Comando %02d: %s", acumulador, erros_comando);
    }
    */
    for (acumulador = 0; acumulador < i; acumulador++){
        printf("%02d \? %+d\n", acumulador, comandos[acumulador]);
    }
    return 0;
}
int verificar_comando(char str, int num){
    
    if (str == '+'){
        return 0;
    }else if (str == '-'){
        if ( num == 99999){
            return 1;
        }else{
            return 2;
        }
    }else{
        return 2;
    }
}