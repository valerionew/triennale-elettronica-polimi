//
//  main.c
//  Esercizio 2 febbraio 2018
//
//  Created by Matteo Rigamonti on 24/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
Quesito 2 (6 punti).
1. Scrivere una funzione ricorsiva che, data una matrice di dimensione NxM, stampi la somma delle righe pari e quella delle righe dispari (6 punti).
2. Come cambierebbe la funzione se invece di stampare le due somme dovesse restituire le somme all’ambiente chiamante? Come cambia l’header della funzione e come cambiano le chiamate ricorsive? (3 punto)
 */

#include <stdio.h>
#define N 5
#define M 6

struct data{
    int sum_even;
    int sum_odd;
};

struct data funzione_ric(int mat[N][N], int i, int j, struct data result){
    if (i == N) {
        
    }else{
        if (i % 2 == 0) {
            result.sum_even += mat[i][j];
        }else{
            result.sum_odd += mat[i][j];
        }
        
        if (j == N) {
            return funzione_ric(mat, i + 1, 0, result);
        }else{
            return funzione_ric(mat, i, j + 1, result);
        }
    }
    return result;
}

void funzione_ric2(int mat[N][N], int i, int j, struct data result){
    if (i == N) {
        
    }else{
        if (i % 2 == 0) {
            result.sum_even += mat[i][j];
        }else{
            result.sum_odd += mat[i][j];
        }
        
        if (j == N) {
            funzione_ric(mat, i + 1, 0, result);
        }else{
            funzione_ric(mat, i, j + 1, result);
        }
    }
    printf("somma pari: %d\nsomma dispari:%d\n", result.sum_even, result.sum_odd);
}

struct data funzione(int mat[N][M]){
    int i,j;
    struct data result;
    result.sum_even = 0;
    result.sum_odd = 0;
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i % 2 == 0) {
                result.sum_even += mat[i][j];
            }else{
                result.sum_odd += mat[i][j];
            }
        }
    }
    
    return result;
}

void funzione_2(int mat[N][M]){
    int i,j;
    int sum_even = 0;
    int sum_odd = 0;
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i % 2 == 0) {
                sum_even += mat[i][j];
            }else{
                sum_odd += mat[i][j];
            }
        }
    }
    
    printf("somma pari: %d", sum_even);
    printf("somma dispari: %d", sum_odd);
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
