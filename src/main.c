#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#include "Leitura.c"
#include "Cifra.c"
#include "BMH.c"

int main(){
    int opcao;
    char* texto = NULL;
    char nomeArquivo[256];
    int op_cifra, chave;

    //Para calcular o tempo de execucao usamos o clock
    clock_t inicio, final;
    double tempo_gasto;


    //char texto[] = "AABCACCACBAC"; 
    char* padrao = (char*)malloc(250 * sizeof(char)); 

    //strcpy(nomeArquivo, "../lib/texto.txt");
    //char *texto = LeituraTexto(nomeArquivo);
    //printf("%s", texto);



    do{
        printf("\n------ MENU -----\n");
        printf("1- Carregar aquivo.\n");
        printf("2- Boyer-Moore-Horspool.\n");
        printf("3- Casamento de padroes 2.\n");
        printf("4- Cifra de deslocamento.\n");
        printf("5- Sair\n");

        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("\nDigite o nome do arquivo a ser lido: ");
                scanf("%s", nomeArquivo);

                texto = LeituraTexto(nomeArquivo);
                break;
            case 2:
                long tamTexto = strlen(texto);
                converteMaiuscula(texto);

                long tamPadrao; 

                printf("\n\n\n\nO que deseja procurar?\n");
                scanf("%s", padrao);
                tamPadrao = strlen(padrao);
                converteMaiuscula(padrao);


                printf("\nCom Boyer-Moore:\n");
                //Inicio da contagem
                inicio = clock();

                bmh(texto, tamTexto, padrao, tamPadrao);
                //Final da contagem
                final = clock();

                //Para achar o tempo gasto em segundos, dividimos o intervalor por clocks por segundos
                tempo_gasto = ((double) (final - inicio)) / CLOCKS_PER_SEC;
                printf("Tempo gasto: %f segundos\n", tempo_gasto);
                
                int seed;
                seed = time(NULL);
                srand(seed);
                break;
            case 3:
                break;
            case 4:
                if(texto != NULL){
                    printf("    ------ CIFRA -----\n");
                    printf("    1- Criptografa.\n");
                    printf("    2- Descriptografa.\n");
                    printf("    3- Chave aleatoria.\n");
                    printf("    4- Sair\n");
                    scanf("%d", &op_cifra);

                    if(op_cifra == 1){
                        printf("Digite a chave:\n");
                        scanf("%d", &chave);
                        criptografa(texto, chave);
                        printf("Arquivo de entrada: %s\n", nomeArquivo);
                        printf("Arquivo de saida: criptografado.txt\n");
                        break;
                    }else if(op_cifra == 2){
                        printf("Digite a chave:\n");
                        scanf("%d", &chave);
                        descriptografa(texto, chave);
                        printf("Arquivo de entrada: %s\n", nomeArquivo);
                        printf("Arquivo de saida: descriptografado.txt\n");
                        break;
                    }else if(op_cifra == 3){
                        chave = rand()%26;
                        criptografa(texto, chave);
                        texto = LeituraTexto("criptografado.txt");
                        chave_aleatoria(texto);
                        printf("Arquivo de entrada para utilizar a chave: %s\n", nomeArquivo);
                        printf("Arquivo utilizado para adivinhar chave: criptografado.txt\n");
                        printf("Chave correta: %d\n", chave);
                        break;
                    }else{
                        break;
                    }
                }else{
                    printf("\n\nArquivo nao carregado!\n");
                    break;
                }
            case 5:
                return 0;
                break;
        }
    }while(1);
}
