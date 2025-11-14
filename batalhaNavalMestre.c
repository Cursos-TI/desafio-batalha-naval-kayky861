#include <stdio.h>

int main() {
    int tab[10][10];
    int tam = 10;
    int navTam = 3;
    int agua = 0, nav = 3, efeito = 5;
    int i, j;

    for (i = 0; i < tam; i++)
        for (j = 0; j < tam; j++)
            tab[i][j] = agua;

    int LH = 2, CH = 1;
    int LV = 5, CV = 6;
    int LDC = 1, CDC = 1;
    int LDD = 0, CDD = 9;

    int h[3] = {3,3,3}, v[3] = {3,3,3}, dc[3] = {3,3,3}, dd[3] = {3,3,3};

    for (i = 0; i < navTam; i++) {
        tab[LH][CH + i] = h[i];
        tab[LV + i][CV] = v[i];
        tab[LDC + i][CDC + i] = dc[i];
        tab[LDD + i][CDD - i] = dd[i];
    }

    int sizeH = 5;
    int center = sizeH / 2;

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    for (i = 0; i < sizeH; i++) {
        for (j = 0; j < sizeH; j++) {
            if ( (j - center < 0 ? center - j : j - center) <= i )
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    for (i = 0; i < sizeH; i++)
        for (j = 0; j < sizeH; j++)
            cruz[i][j] = (i == center || j == center) ? 1 : 0;

    for (i = 0; i < sizeH; i++) {
        for (j = 0; j < sizeH; j++) {
            int dr = i - center;
            int dcj = j - center;
            int dist = (dr < 0 ? -dr : dr) + (dcj < 0 ? -dcj : dcj);
            octaedro[i][j] = (dist <= center) ? 1 : 0;
        }
    }

    int origemConeLinha = 1, origemConeColuna = 4;
    int origemCruzLinha = 6, origemCruzColuna = 2;
    int origemOctaLinha = 7, origemOctaColuna = 7;

    for (i = 0; i < sizeH; i++) {
        for (j = 0; j < sizeH; j++) {
            if (cone[i][j] == 1) {
                int bi = origemConeLinha - center + i;
                int bj = origemConeColuna - center + j;
                if (bi >= 0 && bi < tam && bj >= 0 && bj < tam)
                    tab[bi][bj] = efeito;
            }
        }
    }

    for (i = 0; i < sizeH; i++) {
        for (j = 0; j < sizeH; j++) {
            if (cruz[i][j] == 1) {
                int bi = origemCruzLinha - center + i;
                int bj = origemCruzColuna - center + j;
                if (bi >= 0 && bi < tam && bj >= 0 && bj < tam)
                    tab[bi][bj] = efeito;
            }
        }
    }

    for (i = 0; i < sizeH; i++) {
        for (j = 0; j < sizeH; j++) {
            if (octaedro[i][j] == 1) {
                int bi = origemOctaLinha - center + i;
                int bj = origemOctaColuna - center + j;
                if (bi >= 0 && bi < tam && bj >= 0 && bj < tam)
                    tab[bi][bj] = efeito;
            }
        }
    }

    printf("\nTABULEIRO (0=agua, 3=navio, 5=area de habilidade) - MESTRE\n\n");
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = agua, 3 = navio, 5 = area afetada pela habilidade\n");
    printf("Habilidades aplicadas: Cone (centro em %d,%d), Cruz (centro em %d,%d), Octaedro (centro em %d,%d)\n",
           origemConeLinha, origemConeColuna, origemCruzLinha, origemCruzColuna, origemOctaLinha, origemOctaColuna);

    return 0;
}
