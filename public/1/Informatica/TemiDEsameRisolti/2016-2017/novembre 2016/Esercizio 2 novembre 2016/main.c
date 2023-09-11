//
//  main.c
//  Esercizio 2 novembre 2016
//
//  Created by Matteo Rigamonti on 25/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 2 (8 punti). Il Politecnico vuole calcolare delle statistiche sulle modalità con cui gli studenti sostengono gli esami. In particolare vuole calcolare quanti esami sono ripetuti dagli studenti sia nella sessione invernale, sia in quella estiva.
 Si supponga che, dato uno studente, le sue iscrizioni agli appelli invernali e a quelli estivi siano memorizzate in
   due array distinti, appelliInvernali di seguito definito:
 #define N ... typedef struct {
 e appelliEstivi.
 Tali array sono entrambi del tipo sessione
      char codiceEsame [5];
      char nomeEsame [51];
      char dataIscrizione[11];
 }iscrizione;
 typedef iscrizione sessione[N];
 sessione appelliInvernali, appelliEstivi;
 Si scriva una funzione in C che, dati i due array appelliInvernali e appelliEstivi
 studente, restituisca il numero degli esami che sono contenuti in entrambi gli array, facendo attenzione a non contare le ripetizioni. Per esempio, se:
 
 appelliInvernali =
 {{ “085A“, “Analisi Matematica”, “31/01/2016”}, {“084B“, “Fondamenti di Informatica”, “04/02/2016”}, {“085A“, “Analisi Matematica”, “15/02/2016”}, {“072N”,“Geometria e Algebra Lineare”, “16/02/2016”}, {“072N”,“ “Geometria e Algebra Lineare”, ”24/02/2016”}}
 
 appelliEstivi =
 {{“084B“, “Fondamenti di Informatica”, 30/06/2016}, {“012B“,“Fisica”,”04/07/2016”},
 {“065Z“, “Elettrotecnica”, ”05/07/2016” },
 {“065Z“, “Elettrotecnica”, “15/07/2016”},
 {“085A“ ,“Analisi Matematica”, “18/07/2016”}}
 
 allora la funzione restituisce il valore 2, in quanto gli esami comuni ai due array, a meno di ripetizioni in ogni singolo array, sono “Fondamenti di Informatica” e “Analisi Matematica”.
 N.B.: Gli esami in un array possono essere ripetuti nell’eventualità in cui lo studente si sia iscritto per uno stesso esame a più appelli nella stessa sessione.
 */

#include <stdio.h>
#include <string.h>
#define N 5

typedef struct {
    char codiceEsame [5];
    char nomeEsame [51];
    char dataIscrizione[11];
}iscrizione;

typedef iscrizione sessione[N];

int funzione(sessione appelli_inv, sessione appelli_est){
    int i,j, count[N], result = 0;
    
    for (i = 0; i < 5; i++) {
        
        for (j = 0; j < 5; j++) {
            
            if (strcmp(appelli_inv[i].codiceEsame, appelli_est[j].codiceEsame)
                && (j != i)
                ) {
                count[j]++;
            }
        }
    }
    for (i = 0; i < 5; i++) {
        if (count[i] > 0) {
            result++;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
