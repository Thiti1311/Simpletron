#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 5
// Definição dos comandos
//-------------------------------------------------------------------------
#define READ 10
#define WRITE 11
#define ADD 30
#define HALT 43
//-------------------------------------------------------------------------
int main(){
    setlocale(LC_ALL, "Portuguese");

    int i,j, maior = 0;
    int comando[10];
    char sinal[10];
    int operando, operar;

    printf("*** Bem vindo ao Simpletron!                        ***\n");
    printf("*** Favor digitar seu programa, uma instrução       ***\n");
    printf("*** (ou palavra de dados) por vez. Mostrarei        ***\n");
    printf("*** o número do local e uma interrogação (?).       ***\n");
    printf("*** Você, então, deverá digitar a palavra para esse ***\n");
    printf("*** local. Digite a sentinela +4300 para            ***\n");
    printf("*** encerrar a entrada do seu programa.             ***\n");

    for(i = 0; i < TAM; i++){
        fflush(stdin);
        scanf("%c%4d", &sinal[i], &comando[i]);

        operando = comando[i]%100;
        operar = comando[i]/100;

        if (operando > maior){
            maior = operando;
        }
        if (sinal[i] == '+' && comando[i] == 4300){
            break;
        }
    }

    for(j = 0; j < i; j++){
        printf("%02d \? %c%4d\n", j, sinal[j],comando[j]);
    }
    printf("*** Carga do programa concluída    ***\n");
    printf("*** Iniciando execução do programa ***\n");

    system("pause");

    int valores_lidos[maior];
    char sinal_de_valores[10];
    int acumulador = 0;

    for (i = 0; i <= maior; i++){
        valores_lidos[i] = 0;
    }

    for (i = 0; i < TAM; i++){

        operando = comando[i]%100;
        operar = comando[i]/100;

        switch (operar)
        {
        case READ:
            fflush(stdin);
            printf("Digite o número para posição %02d:\t", operando);
            scanf("%d", &valores_lidos[operando]);
            printf("\n");
            break;
        case WRITE:
            printf("O número de posição %02d:\t%+d\n", operando, valores_lidos[operando]);
            break;
        case ADD:
            for (i = 0; i <= maior; i++){
                acumulador += valores_lidos[i];
            }
            printf("Soma de todos os números inseridos:\t%+d\n", acumulador);
            break;
        case HALT:
            break;
        }
        if (comando[i] == HALT){
            printf("*** Execução do Simpletron encerrada ***\n");
            break;
        }
    }
    
    return 0;
}