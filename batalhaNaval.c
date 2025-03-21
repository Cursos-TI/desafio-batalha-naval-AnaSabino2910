#include <stdio.h>

#define TAMANHO 10 // TAMANHO DO TABULEIRO 10X10
#define TAM_HABILIDADE 5 //TAMANHO FIXO DAS HABILIDADES 5X5

// FUNÇÃO PARA INICIALIZAR O TABULEIRO COM0 ÁGUA
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// FUNÇÃO PARA POSICIONAR NAVIOS NA POSIÇÃO
void posicionarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    //NAVIO HORIZONTAL NA LINHA 2, COLUNAS 3 a 5
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    // NAVIO NA VERTICAL COLUNA 6, LINHAS 5 a 7
    tabuleiro[5][6] = 3;
    tabuleiro[6][6] = 3;
    tabuleiro[7][6] = 3;
}

// FUNÇÃO PARA APLICAR UMA HABILIDADE NO TABULEIRO
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemX, int origemY) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
           
            //CALCULANDO POSIÇÃO REAL NO TABULEIRO
            int x = origemX + i - 2;
            int y = origemY + j - 2;

            //GARANTINDO QUE ESTÁ DENTRO DOS LIMITES DO TABULEIRO
            if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO) {
                //SE A MATRIZ DA HABILIDADE INDICAR 1, MARCA NO TABULEIRO COMO 5, 5 (ÁREA AFETADA)
                if (habilidade[i][j] == 1 && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5;
                }
            }
        }
    }
}

// FUNÇÃO PARA EXIBIR TABULEIRO
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro do Batalha Naval:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ "); // Água
            else if (tabuleiro[i][j] == 3)
                printf("N "); // Navio
            else if (tabuleiro[i][j] == 5)
                printf("* "); // Área da habilidade
        }
        printf("\n");
    }
}

// FUNÇÃO PARA PREENCHER MATRIZ DA HABILIDADE EM FORMATO DE CONE
void criarHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // COPIA PARA A MATRIZ DA HABILIDADE
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = cone[i][j];
        }
    }
}

// FUNÇÃO PARA PREENCHER A MATRIZ DA HABILIDADE EM FORMATO DE CRUZ
void criarHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    // COPIA PARA A MATRIZ DE HABILIDADE
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = cruz[i][j];
        }
    }
}

// FUNÇÃO PARA PRENCHER A MATRIZ DA HABILIDADE EM FORMATO DE OCTEADRO (LOSANGO)
void criarHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // COPIA PARA A MATRIZ DE HABILIDADE
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = octaedro[i][j];
        }
    }
}

// FUNÇÃO PRINCIPAL
int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];

    //INICIALIZA O TABULEIRO E POSICIONA OS NAVIOS
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    //CRIAR E APLICAR HABILIDADES CONE NO CENTRO DO TABULEIRO
    criarHabilidadeCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4);
    printf("\nHabilidade: Cone\n");
    exibirTabuleiro(tabuleiro);

    // REINICIAR O TABULEIRO E APLICAR HABILIDADE CRUZ 
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    criarHabilidadeCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 5, 5);
    printf("\nHabilidade: Cruz\n");
    exibirTabuleiro(tabuleiro);

    // REINICIAR O TABULEIRO E APLICAR HABILIDADE OCTEADRO (LOSANGO)
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    criarHabilidadeOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 6, 6);
    printf("\nHabilidade: Octaedro\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}