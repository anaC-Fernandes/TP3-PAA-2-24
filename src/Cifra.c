#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool caractere_especial(char c){
    if(c == '.' || c == ',' || c == ' ' || c == ';' || c == '/' || c == ':' \
    || c == '-' || c == '!' || c == '?' || c == '(' || c == ')'){
        return true;
    }else{
        return false;
    }
}

int alfabeto(char c){
    int temp;
    switch (c){
        case 'a':
        case 'A':
            temp = 1;
            break;
        case 'b':
        case 'B':
            temp = 2;
            break;
        case 'c':
        case 'C':
            temp = 3;
            break;
        case 'd':
        case 'D':
            temp = 4;
            break;
        case 'e':
        case 'E':
            temp = 5;
            break;
        case 'f':
        case 'F':
            temp = 6;
            break;
        case 'g':
        case 'G':
            temp = 7;
            break;
        case 'h':
        case 'H':
            temp = 8;
            break;
        case 'i':
        case 'I':
            temp = 9;
            break;
        case 'j':
        case 'J':
            temp = 10;
            break;
        case 'k':
        case 'K':
            temp = 11;
            break;
        case 'l':
        case 'L':
            temp = 12;
            break;
        case 'm':
        case 'M':
            temp = 13;
            break;
        case 'n':
        case 'N':
            temp = 14;
            break;
        case 'o':
        case 'O':
            temp = 15;
            break;
        case 'p':
        case 'P':
            temp = 16;
            break;
        case 'q':
        case 'Q':
            temp = 17;
            break;
        case 'r':
        case 'R':
            temp = 18;
            break;
        case 's':
        case 'S':
            temp = 19;
            break;
        case 't':
        case 'T':
            temp = 20;
            break;
        case 'u':
        case 'U':
            temp = 21;
            break;
        case 'v':
        case 'V':
            temp = 22;
            break;
        case 'w':
        case 'W':
            temp = 23;
            break;
        case 'x':
        case 'X':
            temp = 24;
            break;
        case 'y':
        case 'Y':
            temp = 25;
            break;
        case 'z':
        case 'Z':
            temp = 26;
            break;
        
        default:
            break;
    }
    return temp;
}

int criptografa(char* texto, int x){
    int tam = strlen(texto);
    FILE* saida = fopen("criptografado.txt", "w");

    for(int i=0; i<tam; i++){
        if(caractere_especial(texto[i])){
            putc(texto[i], saida);
        }else{
            if(alfabeto(texto[i]) + x > 26){
                if(((alfabeto(texto[i]) + x) % 26) == 0){
                    putc(texto[i] - alfabeto(texto[i]) + 26, saida); //Caso caractere seja z
                }else{
                    putc(texto[i] - alfabeto(texto[i]) + ((alfabeto(texto[i]) + x) % 26), saida);
                }
            }else{
                putc(texto[i] + x, saida);
            }
        }
    }

    fclose(saida);
    return 0;
}

int descriptografa(char* texto, int x){
    int tam = strlen(texto);
    FILE* saida = fopen("descriptografado.txt", "w");

    for(int i=0; i<tam; i++){
        if(texto[i] == '.' || texto[i] == ',' || texto[i] == '/' || texto[i] == ' '){
            putc(texto[i], saida);
        }else{
            if(alfabeto(texto[i]) - x < 1){
                putc(texto[i] - alfabeto(texto[i]) + 26 - abs((alfabeto(texto[i]) - x) % 26), saida);
                //printf("\nC: %c A: %d %d",texto[i], alfabeto(texto[i]) - x, abs((alfabeto(texto[i]) - x)%26));
            }else{
                putc(texto[i] - x, saida);
            }
        }
    }

    fclose(saida);
    return 0;
}

int chave_aleatoria(char* texto) {
    int caracteres = 0;
    float rec[26] = {0};
    int chave = 0;
    float melhor_correspondencia = 1000; // Inicializa com um valor grande
    float soma_diferenca;
    int indice;

    float tabela[26] = {
        0.1463, 0.0104, 0.0388, 0.0499, 0.1257, 0.0102, 0.0130, 0.0128, 0.0618, 0.0040,
        0.0002, 0.0278, 0.0474, 0.0505, 0.1073, 0.0252, 0.0120, 0.0653, 0.0781, 0.0434,
        0.0463, 0.0167, 0.0001, 0.0021, 0.0001, 0.0047
    };

    for (int i = 0; i < strlen(texto); i++) { // Conta as ocorrências de cada letra no texto
        if (!caractere_especial(texto[i])) {
            rec[alfabeto(texto[i]) - 1] += 1;
            caracteres++;
        }
    }

    for (int i = 0; i < 26; i++) { // Converte as ocorrências para proporções
        rec[i] /= caracteres;
    }
    
    printf("TABELA FREQUENCIAS:\n");
    for (int i = 0; i < 13; i++){
        printf("Letra: %c Frequencia: %.2f | Letra: %c Frequencia: %.2f\n", i+65, rec[i]*100, i+78, rec[i+13]*100);
    }

    for (int deslocamento = 0; deslocamento < 26; deslocamento++) { //Testa os valores para todos deslocamentos possíveis
        soma_diferenca = 0;

        for (int i = 0; i < 26; i++) { //Realiza as somas das diferenças entres os indices bases
            indice = (i + deslocamento) % 26;
            soma_diferenca += fabs(rec[indice] - tabela[i]);
        }

        if (soma_diferenca < melhor_correspondencia) { //Se diferenca for menor, escolher como chave
            melhor_correspondencia = soma_diferenca;
            chave = deslocamento;
        }
    }

    printf("\nChave de Cesar encontrada: %d\n", chave);
    return chave;
}
