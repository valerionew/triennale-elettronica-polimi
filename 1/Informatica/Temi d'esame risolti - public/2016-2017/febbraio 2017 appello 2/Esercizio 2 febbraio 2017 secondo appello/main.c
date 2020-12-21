//
//  main.c
//  Esercizio 2 febbraio 2017 secondo appello
//
//  Created by Matteo Rigamonti on 26/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 2 (5 punti). Scrivere una funzione ricorsiva che, ricevuto come parametro un numero intero, restituisce la cifra più alta della sua rappresentazione decimale. Per esempio, se il valore ricevuto in ingresso è 1232 il sottoprogramma restituisce 3.
 */

#include <stdio.h>

int funzione(int n){
    if (n / 10 == 0) {
        return n;
    }else{
        //ritorna il massimo tra n/10 e n % 10
        //return max(n % 10, funzione(n / 10))
        if (n % 10 > funzione(n / 10)) {
            return n % 10;
        }else{
            return funzione(n / 10);
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    printf("%d", funzione(12352));
    
    return 0;
}
