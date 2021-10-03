 #include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

#define VAL 00
//Operaes de entrada/sada:
#define READ 10 //L uma palavra do terminal para um local especfico na memria.
#define WRITE 11 //Escreve uma palavra de um local especfico na memria para o terminal.
//Operaes de carregamento/armazenamento:
#define LOAD 20 //Carrega uma palavra de um local especfico na memria para o accumulator.
#define STORE 21 //Armazena uma palavra do accumulator para um local especfico na memria.
//Operaes aritmticas:
#define ADD 30 //Soma uma palavra de um local especfico na memria  palavra no accumulator (deixa o resultado no accumulator).
#define SUBTRACT 31 //Subtrai uma palavra de um local especfico na memria da palavra no accumulator (deixa o resultado no accumulator).
#define DIVIDE 32 //Divide uma palavra de um local especfico na memria pela palavra no accumulator (deixa o resultado no accumulator).
#define MULTIPLY 33 //Multiplica uma palavra de um local especfico na memria pela palavra no accumulator (deixa o resultado no accumulator).
//Operaes de transferncia de controle:
#define BRANCH 40 //Desvia para um local especfico na memria.
#define BRANCHNEG 41 //Desvia para um local especfico na memria se o accumulator for negativo.
#define BRANCHZERO 42 //Desvia para um local especfico na memria se o accumulator for zero.
#define HALT 43 //Para (halt), ou seinstructionCountera, o programa concluiu sua tarefa.

int menu_mostrar();
void sml_menu();
int validar_operador(int num); 
void flush_in();

int main(){
    //setlocale(LC_ALL, "Portuguese");

    char sinal[100], inter[100];
    int memory[100], instructionCounter;
    int operand, operationCode, instructionRegister;
    int accumulator = 0;
    int i, verificar;
    int num, car_exe, teste, tamanho;
    int num_Arquivo = 1;
    char arquivo_d[15], aux[4], c, date_c[100], date_e[100], objt[100];

    int existe;

    struct tm *data_hora_atual;     
    time_t segundos;
    time(&segundos);   
    data_hora_atual = localtime(&segundos); 

    FILE *arquivo;

    while(num!=4){
    char nome[15];
    num = menu_mostrar();
    switch (num)
    {
        case 1:
            for (instructionCounter = 0; instructionCounter < 100; instructionCounter++){
                    memory[instructionCounter] = 0;
            }
            existe = 0;
            num_Arquivo = 1;
            while (existe == 0)
            {
                strcpy(nome, "PROG");
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
                arquivo = fopen(nome, "r");
                if (arquivo == NULL){
                    //printf("O arquivo %s nao existe!\n", nome);
                    existe == 1;
                    break;
                }
                else
                {
                    //printf("O arquivo %s ja existe!\n", nome);
                }
                fclose(arquivo);
                num_Arquivo++;
            }

            printf("\nNome do arquivo criado: %s\n", nome);
            arquivo = fopen(nome, "w");
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
                printf("\n Informe a finalidade do programa: \n");
                flush_in();
                scanf("%[^\n]",objt);
                
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
                fprintf(arquivo, "%s %02d:%02d %s %02d/%02d/%4d\n", "Criado as:", data_hora_atual->tm_hour,data_hora_atual->tm_min,"em",data_hora_atual->tm_mday, data_hora_atual->tm_mon+1,data_hora_atual->tm_year+1900);

                fprintf(arquivo, "%30s\n", objt);

                while(i < instructionCounter){
                    fprintf(arquivo, "%c%.4d\n", sinal[i], memory[i]);
                    i++;
                }
                printf("\n* Carga do programa concluida    *\n");
                rewind( arquivo );
                fclose(arquivo);
                system("pause");
            break;
        case 2:  
            printf("Arquivos existentes: \n");

            existe = 0;
            num_Arquivo = 1;
            while (existe == 0)
            {
                strcpy(nome, "PROG");
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
                arquivo = fopen(nome, "r");
                if (arquivo == NULL){
                    existe == 1;
                    break;
                }
                else
                {
                    printf("%s\n", nome);
                }
                fclose(arquivo);
                num_Arquivo++;
            }

            printf("* Para executar o programa, infrome o nome do arquivo : (Ex.PROG002)\n");
            scanf("%s", arquivo_d);
            strcat(arquivo_d, ".txt");

            arquivo = fopen(arquivo_d, "r+");
            if (arquivo == NULL){
                printf("ERRO! O arquivo nao foi encontrado\n");
            }
            else
            {
                printf("O arquivo foi encontrado!\n");

                for (instructionCounter = 0; instructionCounter < 100; instructionCounter++){
                    memory[instructionCounter] = 0;
                }
                instructionCounter = 0;

                fgets(date_c,32,arquivo);
                printf("%s", date_c);

                fgets(objt,31,arquivo);
                printf("%s\n", objt);


                while ((fscanf(arquivo, "%c%d\n", &sinal[instructionCounter], &memory[instructionCounter])) != EOF)
                {
                    //printf("%02d %c%04d\n",i, sinal[instructionCounter],memory[instructionCounter]);
        
                    instructionCounter++;
                }

                rewind( arquivo );
                fclose(arquivo);
                
                printf("\n* Carga do programa concluida    *\n");
                printf("* Iniciando execução do programa   *\n");
                system("pause");

                instructionCounter = 0;
                operationCode = 0;

                while(operationCode != HALT){

                    instructionRegister = memory[instructionCounter];
                    instructionCounter++;    
                    operationCode = instructionRegister / 100;
                    operand = instructionRegister  % 100;
                        
                    switch (operationCode){
                        case VAL:
                            memory[instructionCounter - 1] = operand;
                            break;
                        case READ:
                            printf("\? ");
                            scanf("%d", &memory[operand]);
                            break;
                        case WRITE:
                            printf("Valor na memoria da linha %02d: %d\n",   operand, memory[operand]);
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
                                        
                                }
                                else if( (i + 1) %10 == 0){
                                    printf("\n");
                                    printf("%d\t", i+1);
                                }
                            }
                            printf("\n*** Execução do Simpletron encerrada ***\n");
                            break;
                    }
                }
            }
            system("pause");
            break;
        case 3:

            printf("Arquivos existentes: \n");

            existe = 0;
            num_Arquivo = 1;
            while (existe == 0)
            {
                strcpy(nome, "PROG");
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
                arquivo = fopen(nome, "r");
                if (arquivo == NULL){
                    //printf("O arquivo %s nao existe!\n", nome);
                    existe == 1;
                    break;
                }
                else
                {
                    printf("%s\n", nome);
                }
                fclose(arquivo);
                num_Arquivo++;
            }

            printf("\nInforme o nome do arquivo para leitura: (Ex.PROG002)\n");
            scanf("%s", arquivo_d);
            strcat(arquivo_d, ".txt");

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
    int teste = 0;
    
    while (teste == 0)
    {
        printf("\n");
        printf("* Escolha uma das opções informadas abaixo   *\n");
        printf("* 1 - Digitar um novo codigo                 *\n");
        printf("* 2 - Executar/carregar um codigo da memoria *\n");
        printf("* 3 - Pesquisar um codigo existente          *\n");
        printf("* 4 - Encerrar o programa                    *\n");
        scanf("%d", &escolha);
        if (escolha == 1 || escolha == 2 ||escolha == 3 || escolha == 4)
        {
            teste = 1;
        }
        else
        {
            printf("Escolha inválida, tente novamente.\n");
        }
    }
    
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
void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}