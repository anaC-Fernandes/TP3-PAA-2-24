#include <stdio.h>
#include <string.h>

#include "Leitura.h"

int main() {
    char nomeArquivo[256];
    //printf("Digite o nome do arquivo a ser lido: ");
    //scanf("%s", fileName);

    strcpy(nomeArquivo, "C:\\Users\\gabri\\OneDrive\\Documentos\\GitHub\\TP3-PAA-2-24\\lib\\texto.txt");
    char *texto = LeituraTexto(nomeArquivo);
    printf("%s", texto);
}
