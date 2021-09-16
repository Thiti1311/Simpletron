#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10
//Operações de entrada/saída:
#define READ 10 //Lê uma palavra do terminal para um local específico na memória.
#define WRITE 11 //Escreve uma palavra de um local específico na memória para o terminal.
//SOMA E MEDIA
#define MEDIA 13 //Calcula a média dos 7 elementos inseridos.
#define SOMA 14 //Calcula a soma dos 10 números inseridos
//Quqantidade de numeros a serem lidos
#define QUANT 15 //Lê a quatidade de numeros que serão lidos
//Operações de carregamento/armazenamento:
#define LOAD 20 //Carrega uma palavra de um local específico na memória para o acumulador.
#define STORE 21 //Armazena uma palavra do acumulador para um local específico na memória.
//Operações aritméticas:
#define ADD 30 //Soma uma palavra de um local específico na memória à palavra no acumulador (deixa o resultado no acumulador).
#define SUBTRACT 31 //Subtrai uma palavra de um local específico na memória da palavra no acumulador (deixa o resultado no acumulador).
#define DIVIDE 32 //Divide uma palavra de um local específico na memória pela palavra no acumulador (deixa o resultado no acumulador).
#define MULTIPLY 33 //Multiplica uma palavra de um local específico na memória pela palavra no acumulador (deixa o resultado no acumulador).
//Operações de transferência de controle:
#define BRANCH 40 //Desvia para um local específico na memória.
#define BRANCHNEG 41 //Desvia para um local específico na memória se o acumulador for negativo.
#define BRANCHZERO 42 //Desvia para um local específico na memória se o acumulador for zero.
#define HALT 43 //Para (halt), ou seja, o programa concluiu sua tarefa.
int main(){
    setlocale(LC_ALL, "Portuguese");
    int i,j, maior = 0;
    int comando[100];
    char sinal[100];
    int operando, operar;
    int sentinela = 0;
    printf("*** Bem vindo ao Simpletron!                        ***\n");
    printf("*** Favor digitar seu programa, uma instrução       ***\n");
    printf("*** (ou palavra de dados) por vez. Mostrarei        ***\n");
    printf("*** o número do local e uma interrogação (?).       ***\n");
    printf("*** Você, então, deverá digitar a palavra para esse ***\n");
    printf("*** local. Digite a sentinela +4300 para            ***\n");
    printf("*** encerrar a entrada do seu programa.             ***\n");
    for(i = 0; i <= TAM; i++){
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
    sentinela = maior;
    for(j = 0; j <= sentinela; j++){
        if (j <= i){
            printf("%02d \? %c%4d\n", j, sinal[j],comando[j]);
        }else{
            sinal[j] = '+';
            comando[j] = 0000;
            printf("%02d \? %c%04d\n", j, sinal[j],comando[j]);
        }
        
    }
    printf("*** Carga do programa concluída    ***\n");
    printf("*** Iniciando execução do programa ***\n");
    system("pause");
    int valores_lidos[maior];
    int acumulador = 0;
    int media, soma, cont, num[10];
    int maior_num, quantidade, num_lidos[quantidade];
    for (j = 0; j <= maior; j++){
        valores_lidos[j] = 0;
    }
    for (j = 0; j < sentinela; j++){

        operar = 0;
        operando = 0;
        
        operando = comando[j]%100;
        operar = comando[j]/100;
        switch (operar){
            case READ:
                printf("Informe o valor com endereço a linha %02d:\n", operando);
                scanf("%d", &valores_lidos[operando]);
                break;
            case WRITE:
                printf("Valor na memória da linha %02d: %d\n", operando, valores_lidos[operando]);
                break;
            case LOAD:
                acumulador = valores_lidos[operando];
                break;
            case STORE:
                valores_lidos[operando] = acumulador;
                break;
            case ADD:
                acumulador += valores_lidos[operando];
                break;
            case SUBTRACT:
                acumulador -= valores_lidos[operando];
                break;
            case DIVIDE:
                acumulador /= valores_lidos[operando];
                break;
            case MULTIPLY:
                acumulador *= valores_lidos[operando];
                break;
            case BRANCH:
                j = operando;
                continue;
                break;
            case BRANCHNEG:
                if (acumulador < 0){
                    j = operando;
                    continue;
                }
                break;
            case BRANCHZERO:
                if (acumulador == 0){
                    j = operando;
                    continue;
                } 
                break;
            case MEDIA:
                media = 0;
                printf("Digite sete números para calcular a média:\n");
                for(cont = 0; cont < 7; cont++){
                    scanf("%d", &num[cont]);
                    media += num[cont];
                }
                printf("Média = %+d\n", media/7);
                break;
            case SOMA:
                soma = 0;
                printf("Digite dez números para calcular a soma:\n");
                for(cont = 0; cont < 10; cont++){
                    scanf("%d", &num[cont]);
                    soma += num[cont];
                }
                printf("Soma = %+d\n", soma);
                break;
            case QUANT:
                quantidade = 0;
                printf("Informe a quantidade de números a serem inseridos:\n");
                scanf("%d", &quantidade);
                for (cont = 0; cont < quantidade; cont++){
                    scanf("%d", num_lidos[cont]);
                    if (num_lidos[cont] > maior_num){
                        maior_num = num_lidos[cont];
                    }
                }
                printf("Maior número = %+d\n", maior_num);
                break;
            case HALT: 
                break;
        }
        if (comando[j] == HALT){
            printf("*** Execução do Simpletron encerrada ***\n");
            break;
        }
    }
    return 0;
}