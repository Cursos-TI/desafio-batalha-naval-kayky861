#include <stdio.h>

int main() {
    int tamanhoTabuleiro = 10;  
    int tamanhoNavio = 3;        
    int agua = 0;               
    int parteNavio = 3;          

    int tabuleiro[10][10];


    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3]   = {3, 3, 3};


    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = agua;
        }
    }


    int linhaH = 2, colunaH = 1;
    int linhaV = 5, colunaV = 6; 


    if (colunaH + tamanhoNavio > tamanhoTabuleiro) {
        printf("Erro: navio horizontal fora do tabuleiro.\n");
        return 1;
    }
    if (linhaV + tamanhoNavio > tamanhoTabuleiro) {
        printf("Erro: navio vertical fora do tabuleiro.\n");
        return 1;
    }


    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }


    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }


    printf("\n===== TABULEIRO =====\n\n");

    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
