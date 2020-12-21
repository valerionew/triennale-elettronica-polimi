//
//  main.c
//  Esercizio 4 febbraio 2018
//
//  Created by Matteo Rigamonti on 24/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 4 (6 punti).
Si codifichi una funzione ... replace( ... ) che riceve come parametri due stringhe str e sost ed un carattere ch, e alloca dinamicamente e restituisce una nuova stringa derivata da str sostituendo tutte le occorrenze di ch con la stringa sost. La nuova stringa dovrà occupare la minima quantità di memoria sufficiente allo scopo.
Esempi:
str : “CULLA” ch : ‘U’ sost : “ARTE”  “CARTELLA”
str : “PIPE” ch : ‘P’ sost : “CAR”  “CARICARE”
str : “STRESS” ch : ‘S’ sost : “”  “TRE”
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *replace(char str[6], char sost[5], char ch){
    
    char final[strlen(str) + strlen(sost) - 2];
    int i,j, k = 0;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ch) {
            for (j = i; j < strlen(sost) + 1; j++) {
                final[k] = sost[j - i];
                k++;
            }
        }else{
            final[k] = str[i];
            k++;
        }
    }
    
    for (i = 0; i < strlen(final) - 2; i++) {
        printf("%c", final[i]);
    }
    printf("\n");
    
    return final;
}

int main(int argc, const char * argv[]) {
    
    replace("CULLA", "ARTE", 'U');
    
    return 0;
}
