//
//  main.c
//  Esercizio 5 febbraio 2018
//
//  Created by Matteo Rigamonti on 24/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*Quesito 5 (6 punti).
Un quadrato magico è una matrice quadrata tale che il contenuto della prima riga si trovi anche sulla prima colonna nonché, in ordine inverso, sull'ultima riga e sull'ultima colonna, e così via considerando cornici concentriche fino a che le sottomatrici considerate siano significative. Per esempio, date le due matrici di caratteri di seguito riportate:
sator
arepo
tenet
opera
rotas
 
sator
arepo
tenXt
opera
rotas
 
la prima matrice a sinistra è un quadrato magico, poiché la sequenza sator è nella prima riga e nella prima colonna e, in ordine inverso, nell’ultima riga e nell’ultima colonna. Lo stesso vale per la sequenza rep, nella sottomatrice più interna.
La seconda matrice, invece, non è magica vista la presenza dell’elemento X in posizione (2,3).
Si definisca una funzione che verifichi se una matrice quadrata ricevuta come parametro è magica. La funzione restituisce 0 in caso positivo, mentre in caso negativo visualizza le posizioni degli elementi che violano la regola e restituisce all’ambiente chiamante il numero di violazioni.*/

#include <stdio.h>

int funzione(int dim, int mat[dim][dim]){
    int i,j, flag = 0;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            if (mat[i][j] != mat[j][i]
                || mat[i][j] != mat[dim - i][dim - j]
                || mat[dim - i][dim - j] != mat[dim - j][dim - i]
                || mat[j][i] != mat[dim - j][dim - i]) {

                printf("posizione violazione: %d,%d", i,j);
                flag++;
                
            }
        }
    }
    return flag;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
