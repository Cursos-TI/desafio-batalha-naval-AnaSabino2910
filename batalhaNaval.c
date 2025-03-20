#include <stdio.h>

int main() {
    //CRIANDO O TABULEIRO 10 X 10PREENCHIDO COM 0 (ÁGUA)
    int tabuleiro[10][10];

    //INICIALIZANDO O TABULEIRO COM ÁGUA
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
      
    }
    //POSICIONANDO O NAVIO HORIZONTAL (TAMANHO 3) NA LINHA 2, A PARTIR DA COLUNA 3
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    //POSICIONANDO O NAVIO VERTICAL (TAMANHO3) NA COLUNA 6, A PARTIR DA LINHA 5
    tabuleiro[5][6] = 3;
    tabuleiro[6][6] = 3;
    tabuleiro[7][6] = 3;

    //EXIBINDO O TABULEIRO
    printf("\nTabuleiro de Batalha Naval:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}
