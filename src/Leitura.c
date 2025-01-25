//
// Created by gabri on 25/01/2025.
//

#include "Leitura.h"



char *LeituraTexto(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    // Mover o cursor para o final do arquivo para determinar o tamanho
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    if (fileSize < 0) {
        perror("Erro ao determinar o tamanho do arquivo");
        fclose(file);
        return NULL;
    }

    rewind(file);

    // Alocar memória
    char *buffer = (char *)malloc((fileSize + 1) * sizeof(char));
    if (buffer == NULL) {
        perror("Erro ao alocar memória");
        fclose(file);
        return NULL;
    }

    // Ler o conteúdo do arquivo
    size_t bytesRead = fread(buffer, 1, fileSize, file);
    buffer[bytesRead] = '\0'; // Garante que o buffer seja uma string válida

    fclose(file);

    return buffer;
}


