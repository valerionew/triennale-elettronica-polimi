//
//  main.c
//  Esercizio 2 febbraio 2019
//
//  Created by Matteo Rigamonti on 20/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 2 (5 punti).
 Si supponga di avere, già presente in memoria, una lista dinamica che memorizza una sequenza di interi. Si scriva una funzione ricorsiva in C che riceve come parametro la testa della lista, modifica la lista sommando a ogni elemento il valore di tutti gli elementi a esso successivi (l’ultimo elemento resta invariato), e restituisca la somma di tutti i valori nella lista.
 Es. : Data la lista 1→2→10→3→6 la funzione la modificherà in 22→21→19→9→ 6 e restituirà il valore 22

 */

#include <stdio.h>

typedef struct _nodo{
    int n;
    struct _nodo *next;
}nodo;

int funzione(nodo *head){
    if (head == NULL) {
        return head -> n;
    }else{
        head -> n += funzione(head -> next);
    }
    return head -> n;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
