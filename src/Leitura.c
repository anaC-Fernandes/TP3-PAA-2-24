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

    // Mover o cursor para o final do arquivo para determinar o tamanho do arquivo
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file); // Tamanho do arquivo
    rewind(file); // Volta para o início do arquivo

    // Alocar memória para o buffer com tamanho suficiente
    char *buffer = (char *)malloc((fileSize + 1) * sizeof(char)); // +1 para o '\0'
    if (buffer == NULL) {
        perror("Erro ao alocar memória");
        fclose(file);
        return NULL;
    }

    // Ler o conteúdo do arquivo para o buffer
    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead < fileSize) {
        perror("Erro ao ler o arquivo");
        free(buffer);
        fclose(file);
        return NULL;
    }

    buffer[fileSize] = '\0'; // Garantir que o buffer seja uma string válida
    fclose(file);

    return buffer;
}


