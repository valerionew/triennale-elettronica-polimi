//
//  main.c
//  Esercizio 2 luglio 2016
//
//  Created by Matteo Rigamonti on 28/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 2. Funzioni ricorsive (8 punti)
 Si consideri un array a di caratteri lungo n, che contiene alcune parole separate da un trattino. Si definisca una funzione ricorsiva che restituisce 1 se la prima parola nell’array è formata in ordine dai caratteri iniziali delle restanti parole, 0 altrimenti.
 Esempio: Sia n = 22;
 Se il contenuto di a è “PERA-PANE-EGO-ROSA-ALA”, la funzione produrrà il valore 1;
 Se il contenuto di a è “PANE-PERA-ECO-NOIA-EGO”, il risultato sarà 0 poiché la terza parola non comincia per A.
 N.B.: è eventualmente possibile definire una versione iterativa della funzione. Tale soluzione sarà tuttavia valutata con un massimo di 3 punti.
 */

//boh

//analisi del problema
//scorro la stringa, appena trovo '-' cerco se il carattere dopo si trova nella stringa

#include <stdio.h>
#define n 22

int funzione_iterativa(char array[n]){
    int i,j, flag = 1;
    for (i = 0; i < n; i++) {
        if (array[i] == '-') {
            for (j = 1; j < 5; j++) {
                if (array[j] == array[i]) {
                    flag = 0;
                }
            }
        }
    }
    if (flag == 0) {
        return 1;
    }else{
        return 0;
    }
    return -1;
}


//funzione scritta male, poco efficiente e molto poco elegante
int funzione_ricorsiva(char array[n], int index){
    if (index == n) {
        return 1;
    }else{
        if (array[index] == '-') {
            //se quella dopo non c'è return 0
            //altrimenti index++
            if (/*array[index + 1] not in first 4*/
                array[index + 1] != array[0]
                || array[index] != array[1]
                || array[index] != array[2]
                || array[index] != array[3]) {
                return 0;
            }else{
                return funzione_ricorsiva(array, index + 1);
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
