#include <stdio.h>
#include <string.h>
#include <time.h>

#include "Leitura.c"
#include "BMH.c"

int main() {
    char nomeArquivo[256];
    //printf("Digite o nome do arquivo a ser lido: ");
    //scanf("%s", fileName);

    strcpy(nomeArquivo, "../lib/texto.txt");
    char *texto = LeituraTexto(nomeArquivo);
    printf("%s", texto);

    //Para calcular o tempo de execucao usamos o clock
    clock_t inicio, final;
    double tempo_gasto;


    //char texto[] = "AABCACCACBAC"; 
    char* padrao = (char*)malloc(250 * sizeof(char)); 

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
    
}
