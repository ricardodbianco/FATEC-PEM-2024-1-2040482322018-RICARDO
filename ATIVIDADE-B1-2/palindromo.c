#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool is_art_prep(const char *word) {
    const char *art_prep[] = {"o", "a", "os", "as", "um", "uma", "uns", "umas",
                                           "de", "do", "da", "dos", "das", "em", "no", "na",
                                           "nos", "nas", "por", "pelo", "pela", "pelos", "pelas",
                                           "com", NULL};
    for (int i = 0; art_prep[i] != NULL; i++) {
        if (strcasecmp(word, art_prep[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool is_palindromo(const char *word) {
    int inicio = 0;
    int fim = strlen(word) - 1;

    while (inicio < fim) {
        if (tolower(word[inicio]) != tolower(word[fim])) {
            return false;
        }
        inicio++;
        fim--;
    }
    return true;
}

void conct_words(const char *frase, char *result) {
    char buffer[256];
    strcpy(buffer, frase);
    char *token = strtok(buffer, " ");
    result[0] = '\0';

    while (token != NULL) {
        if (!is_art_prep(token)) {
            strcat(result, token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char frase[256];
    char junta[256];
    char inverte[256];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = 0;

    conct_words(frase, junta);

    int len = strlen(junta);
    for (int i = 0; i < len; i++) {
        inverte[i] = junta[len - 1 - i];
    }
    inverte[len] = '\0'; 

    if (is_palindromo(junta)) {
        printf("A frase inteira sem artigos e preposiçoes é um palíndromo:%s",frase);
    } else {
        printf("A frase sem artigos e preposiçoes não é um palíndromo.\n");

        char *token = strtok(frase, " ");
        while (token != NULL) {
            if (!is_art_prep(token) && is_palindromo(token)) {
                printf("Palíndromo(s) encontrado(s): %s\n", token);
            }
            token = strtok(NULL, " ");
        }
    }

    return 0;
}