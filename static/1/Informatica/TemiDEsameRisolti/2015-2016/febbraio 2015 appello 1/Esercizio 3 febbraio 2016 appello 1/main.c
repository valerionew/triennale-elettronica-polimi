//
//  main.c
//  Esercizio 3 febbraio 2016 appello 1
//
//  Created by Matteo Rigamonti on 27/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 3. Funzioni ricorsive (8 punti)
 Sia dato un array di valori interi, tutti maggiori di zero. Definire una funzione ricorsiva che conta le “vette”, cioè gli elementi dell’array che sono maggiori di tutti gli elementi a essi successivi.
 Per esempio, l’array {10, 3, 4, 5, 1, 2} contiene due vette, 10 e 5, quindi la funzione per questo array restituirebbe il valore 2. Se l’array è vuoto o contiene un solo elemento, allora la funzione restituisce il valore 0.

 */

#include <stdio.h>

int funzione(int dim, int array[dim], int count){
    
    if (dim < 0) {
        
        return count;
        
    }else{
        
        if (array[dim] > array[dim + 1]) {
            printf("vetta in posizione: %d, valore: %d\n", dim, array[dim]);
            return funzione(dim - 1, array, count + 1);
        }else{
            return funzione(dim - 1, array, count);
        }
        
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    const int dim = 6;
    int array[dim] = {10,3,4,5,1,2};
    printf("%d\n", funzione(dim - 1, array,0));
    
    return 0;
}
