#include <stdio.h>   
#include <string.h>

char *morse[] = {  // Array de strings representando o código Morse das letras A-Z
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", 
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",  
    "..-", "...-", ".--", "-..-", "-.--", "--.."                           
};

char Traduzir(char vet[]) {   // Função que recebe um código Morse completo e retorna a letra correspondente
    for (int i = 0; i < 26; i++) { 
        if (strcmp(vet, morse[i]) == 0) {  
            return 'A' + i;  // Retorna a letra correspondente (A=0, B=1, etc.)
        }
    }
    return ' ';  
}

void sugestao(char vet[]) {  // Função que sugere letras possíveis quando há um '*' no código Morse
    printf("["); 
    for (int i = 0; i < 26; i++) {  
        if (strncmp(vet, morse[i], strlen(vet)) == 0) { // Compara apenas o prefixo da string
            printf("%c", 'A' + i); 
        }
    }
    printf("]");  
}

void SepararString(char vet[], int tam) {  // Função que lê o código Morse e traduz
    char codigo[10];   
    int cont = 0;      
    int espacos = 0;  

    for (int i = 0; vet[i] != '\0'; i++) { 
        if (vet[i] == '.' || vet[i] == '-') {  
            codigo[cont++] = vet[i];         
            codigo[cont] = '\0';         
            espacos = 0;                   
        } 
        else if (vet[i] == '*') {  // Se encontrar '*', chamar sugestão
            codigo[cont] = '\0';  
            sugestao(codigo);      
            cont = 0;             
            codigo[0] = '\0';  
        }
        else if (vet[i] == ' ') {  // Se encontrar espaço
            if (cont > 0) {         
                printf("%c", Traduzir(codigo));  // Traduz e imprime letra
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

    if (cont > 0) { //Ultima traducao
        printf("%c", Traduzir(codigo));  
    }
}

int main() {
    char codigo[200];  // Array para armazenar toda a entrada do usuário

    printf("Digite o codigo Morse (1 espaco = letra, 2 espacos = palavra):\n"); 
    fgets(codigo, sizeof(codigo), stdin);
    codigo[strcspn(codigo, "\n")] = '\0';

    SepararString(codigo, 200);  

    printf("\n");  
    return 0;    
}
