//
//  main.c
//  Esercizio 4 giugno 2019
//
//  Created by Matteo Rigamonti on 20/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 4 (6 punti). Si definisca una funzione che riceve due stringhe come parametri, s1 e s2, e a partire da s1 costruisce dinamicamente una nuova stringa, s3, ottenuta sostituendo ogni occorrenza di s2 in s1 (se esiste) con una sequenza di caratteri ‘+’, oppure ricopiando s1 nel caso in cui non vi siano occorrenze di s2. Quindi la funzione restituisce s3 all’ambiente chiamante.
 Per esempio:
 1. Per s2 = “menti”:
 - se s1 = “fondamenti”, la funzione crea e restituisce al chiamante la stringa “fonda+++++”. - se s1 = “fondamentalmente”, la funzione restituisce al chiamante “fondamentalmente”. 2. Per s2 = “ment”
 - se s1 = “fondamenti”, la funzione crea e restituisce al chiamante la stringa “fonda++++i”. - se s1 = “fondamentalmente”, la funzione restituisce al chiamante “fonda++++al++++e”.
 */

#include <stdio.h>
#include <string.h>

char *funzione(char *s1, char *s2){
    int i,j,k = 0, flag = 1;
    char *s3 = NULL;
    
    for (i = 0; i < strlen(s1); i++) {
        
        if (s2[0] == s1[i]) {
            for (j = i; j < strlen(s2); j++) {
                if (s2[j - i] != s1[j]) {
                    flag = 0;
                }
            }
            if (flag == 1) {
                for (j = i; j < strlen(s2); j++) {
                    s3[k] = '+';
                    k++;
                }
            }
        }
        s3[k] = s1[i];
    }
    return s3;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
