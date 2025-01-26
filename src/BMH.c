#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void bmh(char texto[], long tamTexto, char padrao[], long tamPadrao) { 
    
    int quantPadrao = 0;
    if (tamPadrao > tamTexto) {
        printf("O padrão é maior que o texto. Não há casamento possível.\n");
        return;
    }


    //Tabela de deslocamento
    int tabelaDeslocamento[256]; 
    for (int j = 0; j < 256; j++) { 
        //Inicializa todas as posicoes como tamanho do padrao
        tabelaDeslocamento[j] = tamPadrao; 
    } 
    for (int j = 0; j < tamPadrao - 1; j++) { 
        //Para os primeiro tamPadrao - 1 sao definidos os valores da tabela
        //A tabela de deslocamento salva a última ocorrência da letra
        //Da direita para a esquerda
        tabelaDeslocamento[(int)padrao[j]] = tamPadrao - j - 1; 
    } 

    //Comparacoes
    int i = tamPadrao - 1; 
    while (i < tamTexto) { 
        int k = i; 
        int j = tamPadrao - 1; 
        while ((j >= 0) && (texto[k] == padrao[j])) { 
            //Diminui j e k enquanto forem casando
            j--; 
            k--; 
        } 
        if (j < 0) { 
            //Caso tenha percorrido todo o padrao e tenha casado todas
            //Entao j sera menor que 0
            quantPadrao++;
            printf("Casamento na posicao :  %d\n", k + 1);
        }
        //Caso tenha encontrado uma colisao
        //Procura pela tabela o deslocamento da letra que causou a colisao
        //Soma com a posicao atual e efetua o deslocamento
        //Reiniciando as comparacoes 
        i = i + tabelaDeslocamento[(int)texto[i]]; 
    }
    printf("\nO padrao foi encontrado %d vezes\n", quantPadrao);
}

void converteMaiuscula(char* texto){
    for(int i = 0; texto[i] != '\0'; i++){
        if((int)texto[i] >= 65 && (int)texto[i] <= 90){
            texto[i] = (char)((int)texto[i] + 32);
        }
    }
}
