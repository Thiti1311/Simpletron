  
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

#define VAL 00
//Operaùùes de entrada/saùda:
#define READ 10 //Lù uma palavra do terminal para um local especùfico na memùria.
#define WRITE 11 //Escreve uma palavra de um local especùfico na memùria para o terminal.
//Operaùùes de carregamento/armazenamento:
#define LOAD 20 //Carrega uma palavra de um local especùfico na memùria para o accumulator.
#define STORE 21 //Armazena uma palavra do accumulator para um local especùfico na memùria.
//Operaùùes aritmùticas:
#define ADD 30 //Soma uma palavra de um local especùfico na memùria ù palavra no accumulator (deixa o resultado no accumulator).
#define SUBTRACT 31 //Subtrai uma palavra de um local especùfico na memùria da palavra no accumulator (deixa o resultado no accumulator).
#define DIVIDE 32 //Divide uma palavra de um local especùfico na memùria pela palavra no accumulator (deixa o resultado no accumulator).
#define MULTIPLY 33 //Multiplica uma palavra de um local especùfico na memùria pela palavra no accumulator (deixa o resultado no accumulator).
//Operaùùes de transferùncia de controle:
#define BRANCH 40 //Desvia para um local especùfico na memùria.
#define BRANCHNEG 41 //Desvia para um local especùfico na memùria se o accumulator for negativo.
#define BRANCHZERO 42 //Desvia para um local especùfico na memùria se o accumulator for zero.
#define HALT 43 //Para (halt), ou seinstructionCountera, o programa concluiu sua tarefa.
int menu_mostrar();
void sml_menu();
int validar_operador(int num); 
int verificar_existencia(int valor, char string);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num;
    int instructionCounter;
    int memory[100];
    int num_Arquivo;
    int i=0;
    char sinal[100];
    int operacao[100];
    int operationCode;
    int verificar;
    char nome[10] = "PROG", arquivo_d[15];
    char aux[4], tamanho;
    char c;

    struct tm *data_hora_atual;     
    time_t segundos;
    time(&segundos);   
    data_hora_atual = localtime(&segundos); 

    FILE *arquivo;

    while(num!=4){
        num = menu_mostrar();
        switch (num)
        {
        case 1:
            for (instructionCounter = 0; instructionCounter < 100; instructionCounter++){
                    memory[instructionCounter] = 0;
            }
            num_Arquivo++;
            itoa(num_Arquivo, aux, 10);
            tamanho = strlen(aux);
            switch (tamanho)
            {
            case 1:
                strcat(nome, "00");
                strcat(nome, aux);
                strcat(nome, ".txt");
                break;
            case 2:
                strcat(nome, "0");
                strcat(nome, aux);
                strcat(nome, ".txt");
                break;
            case 3:
                strcat(nome, aux);
                strcat(nome, ".txt");
                break;
            }
            printf("\nNome do arquivo criado: %s\n", nome);
            arquivo = fopen(nome, "a");
                if (arquivo == NULL){
                    printf("ERRO! O arquivo nao foi aberto!\n");
                }
                else
                {
                    printf("O arquivo foi aberto com sucesso!\n");
                }
                instructionCounter = 0;
                printf("\n");
                sml_menu();
                while (instructionCounter < 100){
                    fflush(stdin);
                    printf("%.2d \? ", instructionCounter);
                    scanf("%c%4d", &sinal[instructionCounter], &memory[instructionCounter]);
                    operationCode = memory[instructionCounter] / 100;
                    if (sinal[instructionCounter] == '-' && memory[instructionCounter] == 9999){
                        break;
                    }else if (sinal[instructionCounter] == '-' && memory[instructionCounter] != 9999){
                        printf("* Numero invalido, digite novamente *\n");
                        instructionCounter--;
                    }
                    else{
                        verificar = validar_operador(operationCode);
                        if (verificar != 0){
                            printf("* Operacao invalida, digite novamente *\n");
                            instructionCounter--;
                        }
                        verificar = 0;
                    }
                    instructionCounter++;
                }
                i = 0;
                fprintf(arquivo, "%02d:%02d %02d/%02d/%4d\n", data_hora_atual->tm_hour,data_hora_atual->tm_min, data_hora_atual->tm_mday, data_hora_atual->tm_mon+1,data_hora_atual->tm_year+1900);
                while(i < instructionCounter){
                    //printf("%.2d \? ", i);
                    //printf("%c%4d\n", sinal[i], memory[i]);
                    fprintf(arquivo, "%.2d \? %c%.4d\n", i, sinal[i], memory[i]);
                    i++;
                }
                printf("\n* Carga do programa concluida    *\n");
                rewind( arquivo );
                fclose(arquivo);
                system("pause");
            break;
        case 2:
            
            break;
        case 3:
            printf("Informe o nome do arquivo para pesquisa/leitura: ");
            scanf("%s", arquivo_d);
            
            arquivo = fopen(arquivo_d, "r");
            if (arquivo == NULL){
                    printf("ERRO! O arquivo nao foi encontrado\n");
            }
            else
            {
                printf("O arquivo foi encontrado!\n");
            
            c = fgetc(arquivo);
            while (c != EOF)
                {
                    printf ("%c", c);
                    c = fgetc(arquivo);
                }
                printf("\n");
            
                fclose(arquivo);
            
            }
            rewind( arquivo );
            fclose(arquivo);
            system("pause");
            break;
        case 4:
            printf("\n* Fim do programa *\n");
            break;
        }
    }   
    return 0;
}

int menu_mostrar(){
    int escolha;
    
    printf("* 1 - Digitar um novo codigo                 *\n");
    printf("* 2 - Executar/carregar um codigo da memoria *\n");
    printf("* 3 - Pesquisar um codigo existente          *\n");
    printf("* 4 - Encerrar o programa                    *\n");
    scanf("%d", &escolha);

    return escolha;
}
void sml_menu(){

    printf("* Bem vindo ao Simpletron!                        *\n");
    printf("* Favor digitar seu programa, uma instrucao       *\n");
    printf("* (ou palavra de dados) por vez. Mostrarei        *\n");
    printf("* o numero do local e uma interrogacao (?).       *\n");
    printf("* Voce, entao, devera digitar a palavra para esse *\n");
    printf("* local. Digite a sentinela -9999 para            *\n");
    printf("* encerrar a entrada do seu programa.             *\n");
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
int verificar_existencia(int valor, char string){
    int tam;
    char aux;
    FILE *arquivo;
        itoa(valor, aux, 10);
            tam = strlen(aux);
            switch (tam)
            {
            case 1:
                strcat(string, "00");
                strcat(string, aux);
                strcat(string, ".txt");
                break;
            case 2:
                strcat(string, "0");
                strcat(string, aux);
                strcat(string, ".txt");
                break;
            case 3:
                strcat(string, aux);
                strcat(string, ".txt");
                break;
            }
    arquivo = fopen(string, "r");
    while ((arquivo = fopen(string, "r"))!= NULL){
        valor++;
    }
    return valor;
}