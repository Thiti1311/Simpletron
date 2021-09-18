#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10
#define VAL 00
//Operações de entrada/saída:
#define READ 10 //Lê uma palavra do terminal para um local específico na memória.
#define WRITE 11 //Escreve uma palavra de um local específico na memória para o terminal.
//SOMA E MEDIA
#define MEDIA 13 //Calcula a média dos 7 elementos inseridos.
#define SOMA 14 //Calcula a soma dos 10 números inseridos
//Operações de carregamento/armazenamento:
#define LOAD 20 //Carrega uma palavra de um local específico na memória para o accumulator.
#define STORE 21 //Armazena uma palavra do accumulator para um local específico na memória.
//Operações aritméticas:
#define ADD 30 //Soma uma palavra de um local específico na memória à palavra no accumulator (deixa o resultado no accumulator).
#define SUBTRACT 31 //Subtrai uma palavra de um local específico na memória da palavra no accumulator (deixa o resultado no accumulator).
#define DIVIDE 32 //Divide uma palavra de um local específico na memória pela palavra no accumulator (deixa o resultado no accumulator).
#define MULTIPLY 33 //Multiplica uma palavra de um local específico na memória pela palavra no accumulator (deixa o resultado no accumulator).
//Operações de transferência de controle:
#define BRANCH 40 //Desvia para um local específico na memória.
#define BRANCHNEG 41 //Desvia para um local específico na memória se o accumulator for negativo.
#define BRANCHZERO 42 //Desvia para um local específico na memória se o accumulator for zero.
#define HALT 43 //Para (halt), ou seinstructionCountera, o programa concluiu sua tarefa.
int main(){
    setlocale(LC_ALL, "Portuguese");

    int instructionCounter;
    int memory[100]; 
    char sinal[100];
    int operand, operationCode;
    int instructionRegister;
    int accumulator = 0;
    int linha, coluna, k = 0, l = 0;

    for (instructionCounter = 0; instructionCounter < 100; instructionCounter++){
            memory[instructionCounter] = 0;
    }

    instructionCounter = 0;

    printf("*** Bem vindo ao Simpletron!                        ***\n");
    printf("*** Favor digitar seu programa, uma instrução       ***\n");
    printf("*** (ou palavra de dados) por vez. Mostrarei        ***\n");
    printf("*** o número do local e uma interrogação (?).       ***\n");
    printf("*** Você, então, deverá digitar a palavra para esse ***\n");
    printf("*** local. Digite a sentinela -9999 para            ***\n");
    printf("*** encerrar a entrada do seu programa.             ***\n");
    
    while (instructionCounter < 100){
        fflush(stdin);
        
        printf("%02d \? ", instructionCounter);
        scanf("%c%4d", &sinal[instructionCounter], &memory[instructionCounter]);

        if (sinal[instructionCounter] == '-' && memory[instructionCounter] == 9999){
            break;
        }else if (sinal[instructionCounter] == '-' && memory[instructionCounter] != 9999){
            memory[instructionCounter] *= -1;
        }
        instructionCounter++;
        k++;
    }

    printf("*** Carga do programa concluída    ***\n");
    printf("*** Iniciando execução do programa ***\n");
    system("pause");

    instructionCounter = 0;

    while(operationCode != HALT){

        instructionRegister = memory[instructionCounter];

        operationCode = instructionRegister / 100;
        operand = instructionRegister  % 100;
        
        switch (operationCode){
            case VAL:
                memory[instructionCounter] = operand;
                break;
            case READ:
                printf("\? ");
                scanf("%d", &memory[operand]);
                break;
            case WRITE:
                printf("Valor na memória da linha %02d: %d\n", operand, memory[operand]);
                break;
            case LOAD:
                accumulator = memory[operand];
                break;
            case STORE:
                memory[operand] = accumulator;
                break;
            case ADD:
                accumulator += memory[operand];
                break;
            case SUBTRACT:
                accumulator -= memory[operand];
                break;
            case DIVIDE:
                if (memory[operand] == 0 || accumulator == 0){
                    printf("*** Tentativa de divisão por zero ***\n*** Execução do Simpletron encerrada de forma anormal. ***\n");
                    operationCode = HALT;
                    continue;
                }else{
                    accumulator /= memory[operand];
                }
                break;
            case MULTIPLY:
                accumulator *= memory[operand];
                break;
            case BRANCH:
                instructionCounter = operand;
                break;
            case BRANCHNEG:
                if (accumulator < 0){
                    instructionCounter = operand;
                    continue;
                }else{
                    break;
                }
            case BRANCHZERO:
                if (accumulator == 0){
                    instructionCounter = operand;
                    continue;
                }else{
                    break;
                }
            case HALT: 
                printf("REGISTERS:\naccumulator %+04d\ninstructionCounter %02d\ninstructionRegister %+04d\noperationCode %02d\noperand %02d\n", accumulator, instructionCounter, instructionRegister, operationCode, operand);
                printf("\nMemory:\n");
                for (linha = 0; linha <= k; linha++){
                    printf("%+4d\t", memory[linha]);
                    /*for (coluna = 0; coluna <= 9; coluna++){
                        if (linha == 0 && coluna == 0){
                            printf("\t");
                        }else if (linha == 0){
                            printf("%d\t", k);
                            k++;
                        }else if (coluna == 0){
                            printf("%d\t", l);
                            l += 10;
                        }else {
                            printf("%+05d\t", memory[linha][coluna]);
                        }
            
                    }
                    printf("\n");*/
                }
                printf("*** Execução do Simpletron encerrada ***\n");
                break;
        }
        instructionCounter++;
    }
    return 0;
}