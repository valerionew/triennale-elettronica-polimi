//
//  main.c
//  Esercizio 1 Luglio 2014
//
//  Created by Matteo Rigamonti on 23/08/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
Esercizio 1 – Stringhe (8 punti).
Si scriva una funzione che, date due stringhe s1 e s2 (ognuna lunga max 20 caratteri), verifichi se s2 è contenuta almeno una volta in s1. La funzione restituisce la posizione in s1 in cui ha inizio la stringa s2 (se contenuta in s1), oppure -1 se s2 non è contenuta in s1.
N.B.: Per la soluzione dell’esercizio, non deve essere utilizzata la funzione di libreria strstr.
 */

#include <stdio.h>
#include <string.h>
#define N 20

int funzione(char s1[N], char s2[N]){
    int i,j, flag = 1;
    for (i = 0; i < strlen(s1); i++) {
        if (s1[i] == s2[i]) {
            for (j = i; j < strlen(s2); j++) {
                if (s1[j] != s2[j]) {
                    flag = 0;
                }
            }
            if (flag != 0) {
                return i;
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
