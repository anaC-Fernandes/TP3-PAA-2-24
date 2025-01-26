#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "Leitura.c"
#include "Cifra.c"

int main(){
    int opcao;
    char* texto = NULL;
    char nomeArquivo[256];
    int op_cifra, chave;

    int seed;
    seed = time(NULL);
    srand(seed);

    do{
        printf("\n------ MENU -----\n");
        printf("1- Carregar aquivo.\n");
        printf("2- Casamento de padroes 1.\n");
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
