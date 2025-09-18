#include <stdio.h>   // Biblioteca padrão de entrada e saída (printf, scanf)
#include <string.h>  // Biblioteca para manipulação de strings (strcmp, strncmp, strlen)

char *morse[] = {  // Array de strings representando o código Morse das letras A-Z
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", // A-J
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",   // K-T
    "..-", "...-", ".--", "-..-", "-.--", "--.."                            // U-Z
};

char Traduzir(char vet[]) {   // Função que recebe um código Morse completo e retorna a letra correspondente
    for (int i = 0; i < 26; i++) {  // Percorre todas as letras A-Z
        if (strcmp(vet, morse[i]) == 0) {  // Compara a string vet com morse[i]
            return 'A' + i;  // Retorna a letra correspondente (A=0, B=1, etc.)
        }
    }
    return ' ';  // Se não encontrar, retorna espaço
}

void sugestao(char vet[]) {  // Função que sugere letras possíveis quando há um '*' no código Morse
    printf("[");  // Abre colchete para mostrar as sugestões
    for (int i = 0; i < 26; i++) {  // Percorre todas as letras A-Z
        if (strncmp(vet, morse[i], strlen(vet)) == 0) { // Compara apenas o prefixo da string
            printf("%c", 'A' + i);  // Se o prefixo bate, imprime a letra como sugestão
        }
    }
    printf("]");  // Fecha colchete das sugestões
}

void SepararString(char vet[], int tam) {  // Função que lê o código Morse e traduz
    char codigo[10];   // Array temporário para armazenar o código de uma letra
    int cont = 0;      // Contador de posições no array codigo
    int espacos = 0;   // Contador de espaços consecutivos

    for (int i = 0; vet[i] != '\0'; i++) {  // Percorre toda a string de entrada
        if (vet[i] == '.' || vet[i] == '-') {  // Se for ponto ou traço
            codigo[cont++] = vet[i];          // Adiciona ao array codigo
            codigo[cont] = '\0';              // Finaliza string
            espacos = 0;                       // Reseta contador de espaços
        } 
        else if (vet[i] == '*') {  // Se encontrar '*', chamar sugestão
            codigo[cont] = '\0';   // Finaliza string temporária
            sugestao(codigo);      // Mostra letras possíveis
            cont = 0;              // Reseta contador
            codigo[0] = '\0';      // Limpa array codigo
        }
        else if (vet[i] == ' ') {  // Se encontrar espaço
            if (cont > 0) {         // Se tiver código acumulado
                printf("%c", Traduzir(codigo));  // Traduz e imprime letra
                cont = 0;           // Reseta contador
                codigo[0] = '\0';   // Limpa array codigo
            }
            espacos++;              // Conta espaço consecutivo
            if (espacos == 2) {     // Dois espaços consecutivos = nova palavra
                printf(" ");        // Imprime espaço entre palavras
                espacos = 0;        // Reseta contador de espaços
            }
        }
    }

    if (cont > 0) {  // Se sobrar código no final da string
        printf("%c", Traduzir(codigo));  // Traduz e imprime última letra
    }
}

int main() {
    char codigo[200];  // Array para armazenar toda a entrada do usuário

    printf("Digite o codigo Morse (1 espaco = letra, 2 espacos = palavra):\n");  // Mensagem
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    SepararString(codigo, 200);  // Chama função que processa e traduz o código Morse

    printf("\n");  // Pula linha no final
    return 0;      // Encerra o programa
}
