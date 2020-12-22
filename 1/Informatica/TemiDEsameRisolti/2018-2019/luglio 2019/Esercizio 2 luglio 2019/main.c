//
//  main.c
//  Esercizio 2 luglio 2019
//
//  Created by Matteo Rigamonti on 23/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 2 (4 punti).
 Si vuole definire una funzione che, ricevuto come parametro (almeno) un array di 100 valori interi, restituisce all’ambiente chiamante il minimo, il massimo e il valore medio dei valori nell’array.
 Si definisca la funzione evidenziando almeno due diverse modalità in cui la funzione può comunicare con l’ambiente chiamante per restituire i valori calcolati.
 */

#include <stdio.h>
#define N 100

struct data{
    int max;
    int min;
    int avg;
};

struct data funzione(int array[N]){
    int i, min = 10000, max = 0, sum = 0;
    struct data arr;
    
    for (i = 0; i < N; i++) {
        if (array[i] > max) {
            max = array[i];
        }else if (array[i] < min){
            min = array[i];
        }
        sum += array[i];
    }
    arr.max = max;
    arr.min = min;
    arr.avg = (int)sum / N;
    
    return arr;
}

void funzione_2(int array[N]){
    int i, min = 10000, max = 0, sum = 0;
    
    for (i = 0; i < N; i++) {
        if (array[i] > max) {
            max = array[i];
        }else if (array[i] < min){
            min = array[i];
        }
        sum += array[i];
    }
    
    printf("max: %d\nmin: %d\navg: %d", max, min, sum / N);
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
