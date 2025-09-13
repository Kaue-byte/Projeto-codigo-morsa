#include <stdio.h>
#include <string.h>

char *morse[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", // A-J
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",   // K-T
    "..-", "...-", ".--", "-..-", "-.--", "--.."                            // U-Z
};

char Traduzir(char vet[]) {
    for (int i = 0; i < 26; i++) {
        if (strcmp(vet, morse[i]) == 0) {
            return 'A' + i;
        }
    }
    return ' ';
}

void SepararString(char vet[], int tam) {
    char codigo[10];
    int cont = 0;
    int espacos = 0;

    for (int i = 0; vet[i] != '\0'; i++) {

        if (vet[i] == '.' || vet[i] == '-') {
            codigo[cont++] = vet[i];
            codigo[cont] = '\0';
            espacos = 0; 
        } 
        else if (vet[i] == ' ') {
            if (cont > 0) {
                printf("%c", Traduzir(codigo));
                cont = 0;
                codigo[0] = '\0';
            }
            espacos++;
            if (espacos == 2) { 
                printf(" ");
                espacos = 0;
            }
        }
    }

    if (cont > 0) {
        printf("%c", Traduzir(codigo));
    }
}

int main() {
    char codigo[100];

    printf("Digite o codigo Morse (1 espaco = letra, 2 espacos = palavra):\n");
    
    scanf(" %[^\n]", codigo);  

    //fgets(codigo, sizeof(codigo), stdin);
    //codigo[strcspn(codigo, "\n")] = '\0';

    SepararString(codigo, 100);

    printf("\n");
    return 0;
}
