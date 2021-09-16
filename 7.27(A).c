#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 10
//Opera��es de entrada/sa�da:
#define READ 10 //L� uma palavra do terminal para um local espec�fico na mem�ria.
#define WRITE 11 //Escreve uma palavra de um local espec�fico na mem�ria para o terminal.
//SOMA E MEDIA
#define MEDIA 13 //Calcula a m�dia dos 7 elementos inseridos.
#define SOMA 14 //Calcula a soma dos 10 n�meros inseridos
//Opera��es de carregamento/armazenamento:
#define LOAD 20 //Carrega uma palavra de um local espec�fico na mem�ria para o acumulador.
#define STORE 21 //Armazena uma palavra do acumulador para um local espec�fico na mem�ria.
//Opera��es aritm�ticas:
#define ADD 30 //Soma uma palavra de um local espec�fico na mem�ria � palavra no acumulador (deixa o resultado no acumulador).
#define SUBTRACT 31 //Subtrai uma palavra de um local espec�fico na mem�ria da palavra no acumulador (deixa o resultado no acumulador).
#define DIVIDE 32 //Divide uma palavra de um local espec�fico na mem�ria pela palavra no acumulador (deixa o resultado no acumulador).
#define MULTIPLY 33 //Multiplica uma palavra de um local espec�fico na mem�ria pela palavra no acumulador (deixa o resultado no acumulador).
//Opera��es de transfer�ncia de controle:
#define BRANCH 40 //Desvia para um local espec�fico na mem�ria.
#define BRANCHNEG 41 //Desvia para um local espec�fico na mem�ria se o acumulador for negativo.
#define BRANCHZERO 42 //Desvia para um local espec�fico na mem�ria se o acumulador for zero.
#define HALT 43 //Para (halt), ou seja, o programa concluiu sua tarefa.
int main(){
    setlocale(LC_ALL, "Portuguese");
    int i,j, maior = 0;
    int comando[100];
    char sinal[100];
    int operando, operar;
    int sentinela = 0;
    printf("*** Bem vindo ao Simpletron!                        ***\n");
    printf("*** Favor digitar seu programa, uma instru��o       ***\n");
    printf("*** (ou palavra de dados) por vez. Mostrarei        ***\n");
    printf("*** o n�mero do local e uma interroga��o (?).       ***\n");
    printf("*** Voc�, ent�o, dever� digitar a palavra para esse ***\n");
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
        if (j < i){
            printf("%02d \? %c%4d\n", j, sinal[j],comando[j]);
        }else{
            sinal[j] = '+';
            comando[j] = 0000;
            printf("%02d \? %c%04d\n", j, sinal[j],comando[j]);
        }
        
    }
    printf("*** Carga do programa conclu�da    ***\n");
    printf("*** Iniciando execu��o do programa ***\n");
    system("pause");
    int valores_lidos[maior];
    int acumulador = 0;
    int media, soma, cont, num[10];
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
                printf("Informe o valor com endere�o a linha %02d: ", operando);
                scanf("%d", &valores_lidos[operando]);
                break;
            case WRITE:
                printf("Valor na mem�ria da linha %02d: %d\n", operando, valores_lidos[operando]);
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
                printf("Digite sete n�meros para calcular a m�dia: ");
                for(cont = 0; cont < 7; cont++){
                    scanf("%d", &num[cont]);
                    media += num[cont];
                }
                printf("M�dia = %d\n", media/7);
                break;
            case SOMA:
                soma = 0;
                printf("Digite dez n�meros para calcular a soma: ");
                for(cont = 0; cont < 10; cont++){
                    scanf("%d", &num[cont]);
                    soma += num[cont];
                }
                printf("Soma = %d\n", soma);
                break;
            case HALT: 
                break;
        }
        if (comando[j] == HALT){
            printf("*** Execu��o do Simpletron encerrada ***\n");
            break;
        }
    }
    return 0;
}