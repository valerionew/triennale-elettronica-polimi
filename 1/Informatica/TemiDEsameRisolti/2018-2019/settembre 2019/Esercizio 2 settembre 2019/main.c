//
//  main.c
//  Esercizio 2 settembre 2019
//
//  Created by Matteo Rigamonti on 24/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
Quesito 2 (4 punti).
Si vuole definire una funzione che, ricevuta come parametro una matrice di NxN valori interi (e altri parametri eventualmente ritenuti necessari), restituisce all’ambiente chiamante la somma e il prodotto dei valori della matrice.
Si definisca la funzione evidenziando modalità alternative in cui la funzione può comunicare con l’ambiente chiamante per restituire i valori calcolati.
*/

#include <stdio.h>
#define N 5

struct datas{
    int sum;
    int prod;
};

struct datas funzione(int mat[N][N]){
    int i,j, sum = 0, prod = 1;
    struct datas risultato;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            sum += mat[i][j];
            prod *= mat[i][j];
        }
    }
    risultato.sum = sum;
    risultato.prod = prod;
    
    return risultato;
}

void funzione_2(int mat[N][N]){
    int i,j, sum = 0, prod = 1;
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            sum += mat[i][j];
            prod *= mat[i][j];
        }
    }
    
    printf("Somma: %d", sum);
    printf("Prodotto: %d", prod);
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
