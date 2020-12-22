//
//  main.c
//  Esercizio 3 febbraio 2017 appello 2
//
//  Created by Matteo Rigamonti on 26/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*

 Quesito 3. (17 punti). Si vuole definire un programma in C, completo di dichiarazioni e opportunamente strutturato in funzioni che, dato un testo memorizzato in un file, riconosca se questo contiene parole “non valide” di un linguaggio L che è definito secondo le seguenti regole:
 - Gli unici caratteri che possono essere usati per comporre le parole di L sono {a, b, c}. Quindi, la sequenza dbbcac non è una parola del linguaggio perché contiene il carattere d;
 - La lettera b deve sempre comparire in (sotto-)sequenze formate da un numero pari di b in successione. Per esempio, le sequenze bbcac e abbbb sono parole valide del linguaggio. Le sequenze cabc e baba non lo sono.
 - La lettera c deve comparire al massimo due volte in ogni parola, non importa in quale posizione.
 Il programma deve stampare su un file di output le parole che non sono valide. Quindi, se il contenuto del file è:
 dcabb cbbc cbb abbbb
 il programma memorizzerà nel file di output la sequenza dcabb.
 Il programma deve essere realizzato in modo modulare secondo i seguenti requisiti:
                      
 1. La funzione main deve ricevere come argomenti della linea di comando il nome dei due file utilizzati dal programma, quello da cui leggere le sequenze di caratteri e quello di output (3 punti).
 2. Una funzione dovrà essere dedicata a leggere dal file le singole parole; ogni parola, per poter essere analizzata, dovrà essere memorizzata in una opportuna struttura dati. (5 punti).
 3. Una funzione dovrà essere dedicata ad analizzare ogni singola parola per verificarne la sua validità rispetto alle regole del linguaggio (9 punti).
 È ovviamente possibile far uso di ulteriori funzioni oltre a quelle sopra descritte. Il main deve essere specificato in modo completo. È necessario specificare completamente anche la parte dichiarativa globale.
 */

/*
 Nota dell'autore:
 sotto è riportata la versione intelligente del programma, che non si appoggia su una struttura dati intermedia per la memorizzazione delle stringhe lette dal file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_s(char *s, FILE *fp){
    int i, occ_b = 0, occ_c = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] != 'a' || s[i] != 'b' || s[i] != 'c') {
            fprintf(fp, "%s", s);
            return 0;
        }
        if (s[i] == 'b') {
            occ_b++;
        }
        if (s[i] == 'c') {
            occ_c++;
        }
    }
    
    if (occ_c != 2 || occ_b % 2 != 0) {
        fprintf(fp, "%s", s);
        return 0;
    }
    
    return 1;
}

void leggi_f(FILE *fp1, FILE *fp2){
    char *s = NULL;
    int controllo;
    while (feof(fp1)) {
        fscanf(fp1, "%s", s);
        controllo = check_s(s, fp2);
    }
}

int main(int argc, const char * argv[]) {
    
    FILE *fp1, *fp2;
    
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");
    
    leggi_f(fp1, fp2);
    
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
