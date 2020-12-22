//
//  main.c
//  Esercizio 3 novembre 2016
//
//  Created by Matteo Rigamonti on 25/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 3 (10 punti). Sia data una matrice quadrata A di ordine N contenente valori interi 0 e 1. Sia data una seconda matrice quadrata, B, di ordine 3.
 Si scriva un programma in C che, letti in input gli elementi delle matrici A e B, verifichi se in A esiste una sottomatrice identica a B (è sufficiente individuarne una – la prima). In caso affermativo, il programma deve stampare le coordinate di riga e colonna in A nelle quali si trova l’elemento B[0][0].
 Esempio: Consideriamo le due seguenti matrice:
 A =            B =
    1101110...      101
    1000001         000
    1100101         100
    1101110
 In questo caso il programma stamperà un messaggio per indicare che la matrice B può essere collocata nella matrice A a partire dalla riga di indice 0 e la colonna di indice 1.
 */

#include <stdio.h>
#define N 10
#define M 3

void funzione(int A[N][N], int B[M][M]){
    int i,j,k,l, flag = 0;
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < M; k++) {
                for (l = 0; l < M; l++) {
                    if (A[i][j] == B[k][l]) {
                        flag = 1;
                    }else{
                        flag = 0;
                    }
                }
            }
            if (flag == 1) {
                printf("trovata sottomatrice B alle coordinate: %d,%d", i,j);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
