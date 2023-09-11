//
//  main.c
//  esercizio 2 settembre 2015
//
//  Created by Matteo Rigamonti on 07/08/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 2 – Gestione dei File in C (8 punti)
 Sia dato un file che memorizza dati sulle operazioni effettuate su un conto corrente bancario. Ciascuna operazione è memorizzata su una singola riga del file. I dati memorizzati in ogni riga sono:
 • La data nel formato gg/mm/aa;
 • L’importo dell’operazione(un numero reale positivo);
 • Il simbolo “+” o “–“ per indicare che l’operazione costituisce una entrata o una uscita. Un esempio di file secondo tale formato è il seguente:
 10/01 1500.00 +
 20/01 200.00 -
 05/02 120.10 -
 10/02 3000.00 +
 ......
Si scriva una funzione in C che, ricevuto come parametro il nome di un file, nomefile, e una soglia di credito, s, produca in output dei messaggi con le date in cui il saldo è sceso sotto la soglia s e con il valore del saldo in quelle date. Nel caso in cui, in base ai movimenti memorizzati nel file, il saldo non scenda mai sotto tale valore, la funzione deve mostrare a video semplicemente il saldo.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    char date[6];
    float operation;
    char sign;
    struct _nodo *next;
}nodo;

void funzione(char *nomefile, float s){
    FILE *fp;
    fp = fopen(nomefile, "r");
    nodo *lista = NULL, *cur;
    float sum = 0;
    
    while (feof(fp)) {
        if (lista == NULL) {
            lista = malloc(sizeof(nodo*));
            fscanf(fp, "%s", lista -> date);
            fscanf(fp, "%f", &lista -> operation);
            fscanf(fp, "%c", &lista -> sign);
            cur = lista -> next;
        }else{
            cur = malloc(sizeof(nodo*));
            fscanf(fp, "%s", cur -> date);
            fscanf(fp, "%f", &cur -> operation);
            fscanf(fp, "%c", &cur -> sign);
            cur = cur -> next;
        }
    }
    
    fclose(fp);
    
    for (cur = lista; cur != NULL; cur = cur -> next) {
        if (cur -> sign == '+') {
            sum += cur -> operation;
        }else if(cur -> sign == '-'){
            sum -= cur -> operation;
        }
        if (sum <= s) {
            printf("valore sotto la soglia: %f, in data: %s\n", sum, cur -> date);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
