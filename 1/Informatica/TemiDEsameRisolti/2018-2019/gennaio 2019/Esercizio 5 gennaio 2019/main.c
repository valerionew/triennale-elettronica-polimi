//
//  main.c
//  Esercizio 5 gennaio 2019
//
//  Created by Matteo Rigamonti on 19/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Quesito 5 (5 punti). Una azienda vuole pubblicare sul suo sito Web gli indirizzi email dei propri dipendenti, ma solo dopo averli trasformati affinché non siano intercettabili da “email scraper” automatici. Si supponga che gli indirizzi email aziendali rispettino il formato: nome.cognome@azienda.com
 Allora, questi dovranno essere trasformati in: nome_DOT_cognome_AT_azienda_DOT_com
 In generale, ogni punto dovrà essere sostituito dalla stringa “_DOT_” e il carattere ‘@’ con la stringa “_AT_”.
 Si codifichi una funzione in C in grado di effettuare la trasformazione. La funzione riceve come parametro una stringa, email, che rappresenta un indirizzo email valido (non è necessario effettuare controlli sulla correttezza del formato) e restituisce una nuova stringa, trasf, ottenuta trasformando email nel modo sopra illustrato. La nuova stringa dovrà occupare la minima quantità di memoria necessaria a memorizzare i suoi caratteri, quindi dovrà essere allocata dinamicamente.
 */

#include <stdio.h>
#include <string.h>

void funzione(int dim, char *email){
    int i,j,k = 0;
    int dot_size = 6, at_size = 5;
    char trasf[dim + dot_size + at_size];
    char dot[dot_size], at[at_size];
    
    strcpy(dot, "_DOT_");
    
    for (i = 0; i < dim; i++) {
        
        if (email[i] == '.') { //se trovo il punto sostituisco la stringa dot
            for (j = i; j < dot_size; j++) {
                trasf[k] = dot[j - i];
                k++;
            }
        }else if(email[i] == '@'){ //se trovo la chiocciola sostituisco la stringa at
            for (j = i; j < at_size; j++) {
                trasf[k] = at[j - i];
                k++;
            }
        }else{ //altrimenti mi limito a copiare gli elementi
            trasf[k] = email[i];
            k++;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
