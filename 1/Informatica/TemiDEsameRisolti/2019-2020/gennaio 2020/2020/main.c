//
//  main.c
//  2020
//
//  Created by Matteo Rigamonti on 09/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//


/*
 Quesito 2 (5 punti). Si scriva una funzione ricorsiva che, ricevuti come parametri un array di interi, a, un intero positivo, val, e altri parametri eventualmente ritenuti necessari, restituisce 1 se il numero di valori negativi in a è maggiore di val, 0 altrimenti.
 */

#include <stdio.h>

int funzione_ricorsiva(int index, int dim, int a[dim], int val){
    if (index == dim) {
        if (val <= 0) { //alla fine, se il numero di negativi supera val, val e minore di zero
            return 1;
        }else{
            return 0;
        }
    }else{//vado avanti con index
        if (a[index] < 0) { // se l'elemento è minore di zero decremento val
            funzione_ricorsiva(index + 1, dim, a, val - 1);
        }else{
            funzione_ricorsiva(index + 1, dim, a, val);
        }
    }
    return -1; //messo nel debug per controllare se ci arriva la funzione, omettere nel etma d'esame oppure sostituire con return 0
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
