//
//  main.c
//  Esercizio 3 Settembre 2019
//
//  Created by Matteo Rigamonti on 24/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito3(5punti). Si supponga di avere, già presente in memoria, una matrice quadrata di interi di dimensione NxN, N costante predefinita. Si scriva una funzione ricorsiva che restituisca la somma di tutti gli elementi della matrice.
 */

#include <stdio.h>
#define N 5

int funzione(int mat[N][N], int i, int j){
    if (i == N && j == N) {
        return mat[i][j];
    }else{
        if (j > N) {
            return mat[i][j] + funzione(mat, i + 1, 0);
        }else{
            return mat[i][j] + funzione(mat, i, j + 1);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int mat[N][N];
    int x;
    x = funzione(mat,0,0);
    
    return 0;
}
