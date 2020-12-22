//
//  main.c
//  Esercizio 4
//
//  Created by Matteo Rigamonti on 09/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 4 (7 punti).
 Data una matrice di interi mat, di dimensione NxM (N e M costanti), si scriva una funzione per individuare se Mat contiene almeno una sottomatrice, di dimensioni r e c, i cui elementi abbiano somma uguale a 0. La funzione riceve come parametro la matrice mat, le dimensioni r e c della sottomatrice e ogni altro parametro ritenuto necessario. Quindi, restituisce all’ambiente chiamante gli indici dell’angolo superiore sinistro della prima sottomatrice individuata. Se mat non contiene una sottomatrice di somma 0, la funzione restituisce indici di valore -1, -1.
 Per esempio, se la matrice mat ha i seguenti valori:
                 
 15 4 -21 8
 -7 7 -4 -34
 -3 9 -2 18
 -15 -5 3 29
 
 e se r = 2 e c = 3, la funzione individuerà la sottomatrice:
 
 -7 7 -4
 -3 9 -2

 e restituirà quindi i valori 1,0.
 */

#include <stdio.h>
#define M 5
#define N 4

struct pos{
    int x;
    int y;
};

struct pos funzione(int mat[N][M], int r, int c){
    int i,j,k,l;
    int sum = 0, flag = 1;
    struct pos position;
    position.x = -1;
    position.y = -1;
    
    for (i = 0; i < N - r; i++) {
        for (j = 0; j < M - c; j++) {
            sum = 0;
            for (k = i; k < r; k++) {
                for (l = j; l < c; l++) {
                    sum += mat[k][l];
                }
            }
            if (sum == 0) {
                position.x = i;
                position.y = j;
                flag = 0;
            }
        }
    }
    return position;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
