#include <stdio.h>

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

int main(){

    int acumulador;
    int comandos[100];
    int i = 0;

    do{
        scanf("%d", comandos[i]);
        i++;
        
    } while (comandos != -99999 || i < 100);

    for (acumulador = 0; acumulador < i; acumulador++){
        printf("%02d \? %+d", acumulador, comandos[acumulador]);
    }
    
/*
   for (i = 0; i <= 99; i++){
       printf("%02d\t", i);
   }
*/
    return 0;
}