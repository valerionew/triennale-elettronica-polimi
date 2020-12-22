//
//  main.c
//  Esercizio 3 settembre 2015
//
//  Created by Matteo Rigamonti on 07/08/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 3 – Funzioni ricorsive (8 punti)
 Dato un array A di n interi, si scriva una funzione che ricorsivamente calcoli il minimo tra le differenza di ogni elemento con il precedente. Nel calcolo delle differenze si esclude il primo elemento (che non ha elementi precedenti). Se l’array ha un solo elemento, la funzione restituisce il valore di quell’ elemento. A ed n devono essere i due soli parametri della funzione.
 */

#include <stdio.h>

int funzione(int n, int a[n]){
    int d;
    if (n == 0) {
        //caso del primo elemento
        return a[n - 1];
    }else{
        //sostituisco ogni elemento con la differenza con il successivo
        a[n - 1] -= a[n - 2];
        //apro la chiamata ricorsiva
        d = funzione(n - 1, a);
        //ritorno il nuovo valore
        return a[n - 1];
    }
}

int main(int argc, const char * argv[]) {
    
    int array[5] = {1,2,3,4,5};
    printf("%d", funzione(5, array));
    printf("\n\n");
    int i;
    for (i = 0; i < 5; i++) {
        printf("%d", array[i]);
    }
    
    return 0;
}
