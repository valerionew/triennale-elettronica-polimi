//
//  main.c
//  Esercizio 3 luglio 2019
//
//  Created by Matteo Rigamonti on 23/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
Quesito3(5punti). Si supponga di avere,già presente in memoria, una matrice quadrata di interi di dimensione NxN, N costante predefinita. Si scriva una funzione ricorsiva che riceve come parametro la matrice (più altri parametri che si ritenga siano necessari) e verifica se la matrice è simmetrica, cioè se tutti gli elementi in posizioni simmetriche rispetto alla diagonale principale hanno stesso valore.
 */

#include <stdio.h>
#define N 5

int is_simmetric(int mat[N][N]){
    int i,j, flag = 1;
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (mat[i][j] != mat[j][i]) {
                flag = 0;
            }
        }
    }
    return flag;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
