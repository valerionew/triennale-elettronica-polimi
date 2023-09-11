//
//  main.c
//  Esercizio 3 secondo itinere 2014
//
//  Created by Matteo Rigamonti on 31/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 3 – Funzioni ricorsive (8 punti)
 Sia data una matrice quadrata di dimensione NxN, con N costante dichiarata nella parte dichiarativa globale del programma. Scrivere una funzione ricorsiva in C che restituisca il valore 1 se la matrice possiede almeno due righe consecutive uguali, 0 altrimenti.
 */

#include <stdio.h>
#define N 5

int funzione(int mat[N][N], int i, int j){
    if (i == N && mat[i][j] == mat[i - 1][j]) {
        return 1;
    }else{
        
        if (mat[i][j] == mat[i - 1][j]) {
            if (j > N) {
                return funzione(mat, i + 1, 0);
            }else{
                return funzione(mat, i, j + 1);
            }
        }else{
            return 0;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
