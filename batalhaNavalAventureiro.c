#include <stdio.h>

int main() {
    int tab[10][10];
    int tam = 10;
    int navTam = 3;
    int agua = 0, nav = 3;

    int h[3] = {3,3,3};
    int v[3] = {3,3,3};
    int dc[3] = {3,3,3};
    int dd[3] = {3,3,3};

    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            tab[i][j] = agua;

    int LH = 2, CH = 1;
    int LV = 5, CV = 6;
    int LDC = 1, CDC = 1;
    int LDD = 0, CDD = 9;

    if (CH + navTam > tam) {
        printf("Erro: navio horizontal fora do tabuleiro.\n");
        return 1;
    }
    if (LV + navTam > tam) {
        printf("Erro: navio vertical fora do tabuleiro.\n");
        return 1;
    }
    if (LDC + navTam > tam || CDC + navTam > tam) {
        printf("Erro: navio diagonal crescente fora do tabuleiro.\n");
        return 1;
    }
    if (LDD + navTam > tam || CDD - (navTam - 1) < 0) {
        printf("Erro: navio diagonal decrescente fora do tabuleiro.\n");
        return 1;
    }

    for (int i = 0; i < navTam; i++) {
        if (tab[LH][CH + i] == nav) { printf("Erro: sobreposição H.\n"); return 1; }
    }
    for (int i = 0; i < navTam; i++) {
        if (tab[LV + i][CV] == nav) { printf("Erro: sobreposição V.\n"); return 1; }
    }
    for (int i = 0; i < navTam; i++) {
        if (tab[LDC + i][CDC + i] == nav) { printf("Erro: sobreposição DC.\n"); return 1; }
    }
    for (int i = 0; i < navTam; i++) {
        if (tab[LDD + i][CDD - i] == nav) { printf("Erro: sobreposição DD.\n"); return 1; }
    }

    for (int i = 0; i < navTam; i++) {
        tab[LH][CH + i] = h[i];
        tab[LV + i][CV] = v[i];
        tab[LDC + i][CDC + i] = dc[i];
        tab[LDD + i][CDD - i] = dd[i];
    }

    printf("\nTABULEIRO (0=agua, 3=navio) - AVENTUREIRO\n\n");
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++)
            printf("%d ", tab[i][j]);
        printf("\n");
    }

    return 0;
}
