// ALUNOS: THIAGO FELIPE VIANA DINIZ - JO�O VICTOR MARINHO SOUZA

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define VAL 00
//Opera��es de entrada/sa�da:
#define READ 10 //L� uma palavra do terminal para um local espec�fico na mem�ria.
#define WRITE 11 //Escreve uma palavra de um local espec�fico na mem�ria para o terminal.
//Opera��es de carregamento/armazenamento:
#define LOAD 20 //Carrega uma palavra de um local espec�fico na mem�ria para o accumulator.
#define STORE 21 //Armazena uma palavra do accumulator para um local espec�fico na mem�ria.
//Opera��es aritm�ticas:
#define ADD 30 //Soma uma palavra de um local espec�fico na mem�ria � palavra no accumulator (deixa o resultado no accumulator).
#define SUBTRACT 31 //Subtrai uma palavra de um local espec�fico na mem�ria da palavra no accumulator (deixa o resultado no accumulator).
#define DIVIDE 32 //Divide uma palavra de um local espec�fico na mem�ria pela palavra no accumulator (deixa o resultado no accumulator).
#define MULTIPLY 33 //Multiplica uma palavra de um local espec�fico na mem�ria pela palavra no accumulator (deixa o resultado no accumulator).
//Opera��es de transfer�ncia de controle:
#define BRANCH 40 //Desvia para um local espec�fico na mem�ria.
#define BRANCHNEG 41 //Desvia para um local espec�fico na mem�ria se o accumulator for negativo.
#define BRANCHZERO 42 //Desvia para um local espec�fico na mem�ria se o accumulator for zero.
#define HALT 43 //Para (halt), ou seinstructionCountera, o programa concluiu sua tarefa.
int main(){
    setlocale(LC_ALL, "Portuguese");

    int instructionCounter;
    int memory[100]; 
    char sinal[100];
    int operand, operationCode;
    int instructionRegister;
    int accumulator = 0;
    int i, verificar;

    for (instructionCounter = 0; instructionCounter < 100; instructionCounter++){
            memory[instructionCounter] = 0;
    }

    instructionCounter = 0;

    printf("*** Bem vindo ao Simpletron!                        ***\n");
    printf("*** Favor digitar seu programa, uma instru��o       ***\n");
    printf("*** (ou palavra de dados) por vez. Mostrarei        ***\n");
    printf("*** o n�mero do local e uma interroga��o (?).       ***\n");
    printf("*** Voc�, ent�o, dever� digitar a palavra para esse ***\n");
    printf("*** local. Digite a sentinela -9999 para            ***\n");
    printf("*** encerrar a entrada do seu programa.             ***\n");
    
    while (instructionCounter < 100){
        fflush(stdin);
        
        printf("%02d \? ", instructionCounter);
        scanf("%c%4d", &sinal[instructionCounter], &memory[instructionCounter]);

        operationCode = memory[instructionCounter] / 100;

        if (sinal[instructionCounter] == '-' && memory[instructionCounter] == 9999){
            break;
        }else if (sinal[instructionCounter] == '-' && memory[instructionCounter] != 9999){
            printf("*** N�mero inv�lido, digite novamente ***\n");
            instructionCounter--;
        }else{
            verificar = 0;
            verificar = validar_operador(operationCode);
            if (verificar != 0){
                printf("*** Opera��o inv�lida, digite novamente ***\n");
                instructionCounter--;
            }
        }
        instructionCounter++;
    }

    printf("*** Carga do programa concluída    ***\n");
    printf("*** Iniciando execução do programa ***\n");
    system("pause");

    instructionCounter = 0;

    while(operationCode != HALT){
        
        instructionRegister = memory[instructionCounter];
        instructionCounter++;
        operationCode = instructionRegister / 100;
        operand = instructionRegister  % 100;
        
        switch (operationCode){
            case VAL:
                memory[instructionCounter -1] = operand;
                break;
            case READ:
                printf("\? ");
                scanf("%d", &memory[operand]);
                break;
            case WRITE:
                printf("\nValor na memoria da linha %02d: %d\n", operand, memory[operand]);
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
                    printf("*** Tentativa de divis�o por zero ***\n*** Execu��o do Simpletron encerrada de forma anormal. ***\n");
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
                }
                break;
            case BRANCHZERO:
                if (accumulator == 0){
                    instructionCounter = operand;
                    continue;
                }
                break;
            case HALT: case 99:
                printf("REGISTERS:\naccumulator %+05d\ninstructionCounter %02d\ninstructionRegister %+04d\noperationCode %02d\noperand %02d\n", accumulator, instructionCounter, instructionRegister, operationCode, operand);
                printf("\nMemory:\n");
                for(i = 0; i < 10; i++){
                    if (i == 0 ){
                        printf("\t");
                    }
                    if (i == 9){
                        printf("%d", i);
                    }else{
                        printf("%d\t", i);
                    }
                }
                printf("\n");
                for(i = 0; i < 100; i++){
                    if (i == 0){
                        printf("%d\t", i);
                    }
                    printf("%+05d\t",memory[i]);
                    if (i == 99){
                        //printf
                    }
                    else if( (i + 1) %10 == 0){
                        printf("\n");
                        printf("%d\t", i+1);
                    }
                }
                printf("\n*** Execu��o do Simpletron encerrada ***\n");
                break;
        }
    }
    return 0;
}
int validar_operador(int num){
    switch (num){
            case VAL:
                return 0;
                break;
            case READ:
                return 0;
                break;
                break;
            case WRITE:
                return 0;
                break;
            case LOAD:
                return 0;
                break;
            case STORE:
                return 0;
                break;
            case ADD:
                return 0;
                break;
            case SUBTRACT:
                return 0;
                break;
            case DIVIDE:
                return 0;
                break;
            case MULTIPLY:
                return 0;
                break;
            case BRANCH:
                return 0;
                break;
            case BRANCHNEG:
                return 0;
                break;
            case BRANCHZERO:
                return 0;
                break;
            case HALT:
                return 0;
                break;
            default:
            return 1;
    }
}       