//
//  main.c
//  Esercizio 2 Gennaio 2019
//
//  Created by Matteo Rigamonti on 19/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 2 (5 punti).
 Scrivere una funzione ricorsiva che riceve come parametro un intero positivo e lo stampa a video con tutte le cifre incolonnate (a partire da quella più significativa). Per esempio, per n=123, la funzione stampa:
 1
 2
 3
 */

#include <stdio.h>

void funzione(int n){
    if (n % 10 == 0) {
        printf("");
    }else{
        funzione(n / 10);
        printf("%d\n", n % 10);
    }
}

int main(int argc, const char * argv[]) {
    
    funzione(123);
    
    return 0;
}
