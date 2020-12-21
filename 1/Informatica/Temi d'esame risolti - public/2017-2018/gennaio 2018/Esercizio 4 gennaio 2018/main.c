//
//  main.c
//  Esercizio 4 gennaio 2018
//
//  Created by Matteo Rigamonti on 24/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 4. (5 punti) Si supponga di avere, già presente in memoria, una lista dinamica che memorizza una sequenza di caratteri. La lista può contenere delle sotto-sequenze delimitate da parentesi tonde. Le sotto sequenze possono anche essere vuote (parentesi aperta e poi chiusa senza altri caratteri intermedi).
Si scriva una funzione in C che modifichi la lista sostituendo alle sotto-sequenze delimitate da parentesi un solo elemento contenente il carattere “#”.
La funzione riceve come parametro in ingresso il puntatore alla testa della lista. Si può supporre che la sequenza di caratteri memorizzata nella lista sia ben formata e cioè che: i) per ogni parentesi che apre una sotto-sequenza ce ne sia una successiva che la chiude; ii) non ci siano intersezioni tra coppie di parentesi. Esempio: data la sequenza iniziale
ab(efc)hi()a(xy)f
la lista, dopo la modifica, memorizzerà la sequenza ab(#)hi(#)a(#)f
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    char c;
    struct _nodo *next;
}nodo;

nodo *funzione(nodo *head){
    nodo *cur, *cur2;
    
    for (cur = head; cur != NULL; cur = cur -> next) {
        if (cur -> c == '(') {
            for (cur2 = cur; cur2 != NULL || cur2 -> c == ')'; cur2 = cur2 -> next){
                if (cur2 -> next -> c == ')') {
                    if (cur2 != cur) {
                        cur2 -> c = '#';
                    }else{
                        cur -> next = malloc(sizeof(nodo));
                        cur -> next -> c = '#';
                        cur -> next -> next = cur2 -> next;
                    }
                }else{
                    free(cur2);
                }
            }
        }
    }
    
    return head;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
