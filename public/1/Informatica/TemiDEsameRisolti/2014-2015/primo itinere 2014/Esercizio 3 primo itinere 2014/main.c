//
//  main.c
//  Esercizio 3 primo itinere 2014
//
//  Created by Matteo Rigamonti on 31/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 3 – Matrici (10 punti).
 Si scriva un programma in C, completo di opportune dichiarazioni, che:
 1. Acquisisca in input i valori di una matrice quadrata di interi, m1, di dimensione NxN (N costante predefinita).
 2. Costruisca una nuova matrice della stessa dimensione, m2, in cui ogni elemento m2[i][j] è dato dalla media degli 2N-1 valori disposti sulla i-esima riga e j-esima colonna di m1.
     m2
 Ʃ
 3. Stampi la nuova matrice, m2, per righe.
 Suggerimento: attenzione a non includere due volte il valore m1[i][j] nel calcolo del valore di m2[i][j].
 */

#include <stdio.h>
#define N 5

int main(int argc, const char * argv[]) {
    
    int m1[N][N], m2[N][N] = {0};
    int i,j,k;
    int n = 2*N - 1;
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m2[i][j] -= m1[i][j];
            for (k = 0; k < N; k++) {
                m2[i][j] += m2[k][j];
                m2[i][j] += m2[j][k];
            }
            m2[i][j] /= n;
        }
    }
    
    return 0;
}
