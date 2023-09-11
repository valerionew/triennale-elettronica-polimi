//
//  main.c
//  Esercizio 3 febbraio 2019
//
//  Created by Matteo Rigamonti on 20/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 3 (6 punti).
 Un punto nel piano cartesiano è definito dalla coppia delle sue coordinate x e y.
 Data una matrice quadrata di NxN punti (N costante predefinita), le sequenze di punti della diagonale, quelli di ogni riga e quelli di ogni colonna definiscono linee spezzate (ciascuna di N-1 lati). Si definisce regolare una matrice di punti in cui la lunghezza della spezzata definita dalla diagonale è maggiore della lunghezza di tutte le spezzate definite dalle righe e dalle colonne della matrice.
 Si definisca il tipo di dato point_t.
 Si scriva una funzione in C che, ricevuta come parametro una matrice di punti, restituisca 1 se la matrice è regolare, 0 se non lo è. Si supponga di avere a disposizione una funzione per il calcolo della distanza euclidea tra due punti nel piano. Tale funzione non dovrà essere codificata ma sarà necessario definirne il prototipo.
 */

#include <stdio.h>
#include <math.h>
#define N 4

typedef struct point{
    int x;
    int y;
}point_t;

int distanza(point_t A, point_t B){
    int dx,dy;
    dx = A.x - B.x;
    dy = A.y - B.y;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

int funzione(point_t mat[N][N]){
    int diag = 0,row = 0,col = 0, flag = 1;
    int i,j;
    
    for (i = 0; i < N - 1; i++) {
        diag += distanza(mat[i][i], mat[i + 1][i + 1]);
    }
    
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - 1; j++) {
            row += distanza(mat[i][j], mat[i][j + 1]);
        }
        if (row > diag) {
            flag = 0;
        }
        row = 0;
    }
    
    for (j = 0; j < N - 1; j++) {
        for (i = 0; i < N - 1; i++) {
            col += distanza(mat[i][j], mat[i + 1][j]);
        }
        if (col > diag) {
            flag = 0;
        }
        col = 0;
    }
    return flag;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
