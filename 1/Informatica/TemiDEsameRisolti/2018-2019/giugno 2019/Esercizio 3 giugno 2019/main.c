//
//  main.c
//  Esercizio 3 giugno 2019
//
//  Created by Matteo Rigamonti on 20/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito3(5punti).
 Si supponga di avere ,già presente in memoria, una matrice quadrata di interi di dimensione NxN, N costante predefinita. Si scriva una funzione ricorsiva che riceve come parametro la matrice e verifica se la matrice è identica, cioè se tutti gli elementi della diagonale principale hanno valore 1, mentre i restanti elementi hanno valore 0. La funzione restituisce valore 1 se la matrice è identica, 0 altrimenti.
 */

#include <stdio.h>
#define N 4

int funzione(int mat[N][N]){
    int i,j;
    for (i = 0; i < N; i++) {
        if (mat[i][i] != 1) {
            return 0;
        }
        for (j = 0; j < N && j != i; j++) {
            if (mat[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

int funzione_ric(int mat[N][N], int i, int j){
    if (i == N) {
        return mat[i][j];
    }else{
        
        if (mat[i][j] != 0 || mat[i][i] != 1) {
            return 0;
        }else if (j == N) {
            return funzione_ric(mat, i + 1, 0);
        }else{
            return funzione_ric(mat, i, j + 1);
        }
        
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
