#include <stdio.h>
#include <string.h>

#include "Leitura.c"

int main() {
    char nomeArquivo[256];
    //printf("Digite o nome do arquivo a ser lido: ");
    //scanf("%s", fileName);

    strcpy(nomeArquivo, "../lib/texto.txt");
    char *texto = LeituraTexto(nomeArquivo);
    printf("%s", texto);
}
