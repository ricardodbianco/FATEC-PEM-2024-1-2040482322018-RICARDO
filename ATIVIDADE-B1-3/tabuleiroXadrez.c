#include <stdio.h>

#define LINHA 8 
#define COLUNA 8 
#define CARACTERE 4 

void printTabuleiro(char tabuleiro[LINHA][COLUNA][CARACTERE]) {

    printf("\n   a   b   c   d   e   f   g   h\n");
    printf("  -------------------------------\n");

    for (int i = 7; i >= 0; i--) {
        printf("%d|", i+1);
        for (int j = 0; j < 8; j++) {
            printf("%s ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[LINHA][COLUNA][CARACTERE] = {
        {"TB1", "CB1", "BB1", "DB1", "RB1", "BB2", "CB2", "TB2"},
        {"PB1", "PB2", "PB3", "PB4", "PB5", "PB6", "PB7", "PB8"},
        {" x ", " x ", " x ", " x ", " x ", " x ", " x ", " x "},
        {" x ", " x ", " x ", " x ", " x ", " x ", " x ", " x "},
        {" x ", " x ", " x ", " x ", " x ", " x ", " x ", " x "},
        {" x ", " x ", " x ", " x ", " x ", " x ", " x ", " x "},
        {"PP1", "PP2", "PP3", "PP4", "PP5", "PP6", "PP7", "PP8"},
        {"TP1", "CP1", "BP1", "DP1", "RP1", "BP2", "CP2", "TP2"},
    };

    printTabuleiro(tabuleiro);

    return 0;
}