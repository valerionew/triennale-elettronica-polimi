//
//  main.c
//  Esercizio 3 gennaio 2019
//
//  Created by Matteo Rigamonti on 19/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 3 (8 punti).
 Una matrice quadrata M di nxn interi è un quadrato latino se ogni intero nell'insieme {1, ..., n} compare una e una sola volta in ogni riga e in ogni colonna. Per esempio, la matrice seguente di ordine 4 è un quadrato latino:
 1234
 2143
 4321
 3412
 
 mentre non lo è la matrice
 
 1235
 2143
 4321
 3412
 
 perché la prima riga e l’ultima colonna non includono il valore 4, mentre è presente il valore 5 che è fuori dall’intervallo {1, ..., 4}.
 Si scriva un programma in C, organizzato in opportune funzioni e facente uso di opportune strutture dati, che dopo aver letto da un file i valori della matrice verifichi se questa è un quadrato latino e produca in output un opportuno messaggio.
 Il nome del file deve essere specificato dall’utente come argomento della linea di comando (parametro del main). Il file è organizzato in modo che la prima riga riporti la dimensione effettiva della matrice, n. Questo sarà un valore minore di una costante predefinita N, che invece rappresenta la dimensione massima della matrice. Ogni riga successiva del file memorizza i valori delle righe della matrice separati da uno spazio. Per esempio, il file che memorizza la matrice riportata sopra sarà organizzato nel seguente modo:
 4
 1234
 2143
 4321
 3412
 */

#include <stdio.h>

int is_latin(int dim, int mat[dim][dim]){
    int i,j,flag = 1;
    int occ[dim];
    
    for (i = 0; i < dim; i++) { // controllo le righe
        for (j = 0; j < dim; j++) {
            occ[j]++;
            if (occ[j] > 1 || mat[i][j] > dim) {
                flag = 0;
            }
        }
    }
    
    for (j = 0; j < dim; j++) {
        for (i = 0; i < dim; i++) {
            if (occ[i] > 1 || mat[i][j] > dim) {
                flag = 0;
            }
        }
    }
    
    return flag;
}

int main(int argc, const char * argv[]) {
    
    int N,i,j;
    
    FILE *fp;
    fp = fopen(argv[0], "r");
    
    //leggo
    fscanf(fp, "%d", &N);
    
    int mat[N][N];
    
    //leggo la matrice
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            fscanf(fp, "%d", &mat[i][j]);
        }
    }
    
    return 0;
}
