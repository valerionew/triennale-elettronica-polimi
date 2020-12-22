//
//  main.c
//  Esercizio 2 luglio 2017
//
//  Created by Matteo Rigamonti on 26/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 2 (5 punti). Scrivere una funzione ricorsiva che verifichi se la somma degli elementi della diagonale principale è uguale a quella della diagonale secondaria.
 */

#include <stdio.h>
#define N 5

int funzione(int mat[N][N], int i){
    int sum_diag = 0, sum_antidiag = 0, index;
    if (i == N - 1) {
        return i;
    }else{
        index = funzione(mat, i + 1);
        sum_diag += mat[i][i] + mat[N - i][N - i] + mat[index][index] + mat[N - index][N - index];
        sum_antidiag += mat[N - i][i] + mat[i][N - i] + mat[N - index][index] + mat[index][N - index];
    }
    if (sum_antidiag == sum_diag) {
        return 1;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
