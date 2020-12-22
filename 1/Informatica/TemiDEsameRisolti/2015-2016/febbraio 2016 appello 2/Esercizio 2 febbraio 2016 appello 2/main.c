//
//  main.c
//  Esercizio 4 febbraio 2016 appello 2
//
//  Created by Matteo Rigamonti on 27/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 2. Funzioni ricorsive (8 punti)
 Si definisca una funzione ricorsiva in C che, dato un intero n passato come parametro, costruisce per l’ambiente chiamante una stringa che rappresenta la codifica binaria di n (con i bit significativi allineati a sinistra). Si assuma che l’intero che la funzione riceve come parametro sia rappresentabile su un numero N (costante) di bit definito a priori.
 */

#include <stdio.h>

void funzione(int n){
    if (n / 2 == 0) {
        printf("%d", n % 2);
    }else{
        funzione(n / 2);
        printf("%d", n % 2);
    }
}

int main(int argc, const char * argv[]) {
    
    funzione(17);
    printf("\n");
    
    return 0;
}
