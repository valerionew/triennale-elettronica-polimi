//
//  main.c
//  Esercizio 3 luglio 2015
//
//  Created by Matteo Rigamonti on 06/08/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 3 – Funzioni ricorsive (8 punti)
 1. (4 punti). Scrivere una funzione ricorsiva in C che, ricevuto come parametro un valore intero n, calcoli i
 numeri interi T(n) definiti dalle seguenti relazioni:
 T(0) = 0, T(1) = 1
 T(n) = 2T(n − 2) + 5 per n ≥ 2
 2. (4 punti). Scrivere una funzione ricorsiva in C che, ricevendo come parametri un array a di interi positivi, la sua dimensione n, e un valore val, restituisca 1 se tutti gli elementi dell’array sono maggiori di val, 0 altrimenti.
 */

#include <stdio.h>

int funzione(int n){
    if (n == 0) {
        return n;
    }else if(n == 1){
        return 1;
    }else{
        return 2 * funzione(n - 2) + 5;
    }
}

int funzione2(int n, int a[n], int val){
    if (n == 0) {
        if (a[n] > val) {
            return 1;
        }
        return 0;
    }else{
        if (a[n] > val) {
            return funzione2(n - 1, a, val);
        }
        return 0;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
