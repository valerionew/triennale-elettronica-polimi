//
//  main.c
//  Esercizio 2 gennaio 2018
//
//  Created by Matteo Rigamonti on 24/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 2 (7 punti). Si vuole definire una funzione che legga in input da tastiera una sequenza di caratteri terminata dal “.” e la stampi in maniera invertita. La lunghezza della sequenza è indefinita.
 1. Si scriva una versione iterativa.
 2. Si scriva una versione ricorsiva.
 3. Si spieghino i vantaggi/svantaggi dell’una e dell’altra versione (bonus: 3 punti).
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void funzione_iterativa(void){
    int flag = 1, dim = 0, i = 0;
    char *s,c;
    s = malloc(sizeof(char));
    
    while (flag == 1) {
        
        scanf("%c", &c);
        if (c == '.') {
            flag = 0;
        }
        dim++;
        i = dim - 1;
        realloc(s, dim * sizeof(char));
        s[i] = c;
        
    }
    
    for (i = dim; i > 0; i--) {
        printf("%c", s[i]);
    }
}

void funzione_ricorsiva(char *s, int i){
    if (s[i] == '.') {
        printf("");
    }else{
        funzione_ricorsiva(s, i + 1);
        printf("%c", s[i]);
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
