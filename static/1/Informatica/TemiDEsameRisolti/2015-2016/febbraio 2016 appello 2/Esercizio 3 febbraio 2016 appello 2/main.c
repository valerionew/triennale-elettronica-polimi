//
//  main.c
//  Esercizio 3 febbraio 2016 appello 2
//
//  Created by Matteo Rigamonti on 27/07/2020.
//  Copyright © 2020 Matteo Rigamonti. All rights reserved.
//

/*
 Esercizio 3. Uso di File e Liste Dinamiche (19 punti)
 Un numero n si dice Primo Troncabile a Sinistra (PTS) se n e tutti i numeri ottenuti cancellando ripetutamente le sue cifre più a sinistra sono primi. Per esempio, 313 è un PTS; infatti, 313 è primo, 13 è primo (è stata cancellata la prima cifra a sinistra), 3 è primo (sono state cancellate le prime due cifre a sinistra).
 Si definisca un programma in C in grado di leggere dal file una sequenza di interi e memorizzare in una lista dinamica ordinata i soli elementi che sono PTS. Il file è organizzato in modo da contenere un intero per ogni riga. Il nome del file deve essere letto come argomento della linea di comando con cui si esegue il programma.
 Il programma deve essere realizzato in modo modulare, scomponendolo almeno nelle seguenti funzioni:
 1. La funzione main, con passaggio come argomento della linea di comando del nome del file contenente gli interi (3 punti);
 2. Una funzione per verificare se un intero letto dal file è PTS. Tale funzione può anche far uso di altre funzioni, per esempio quella per verificare che un numero sia primo (8 punti).
 3. Una funzione che legga dal file gli interi e memorizzi i soli PTS in una lista dinamica. L’inserimento deve avvenire in ordine, in modo che nella lista risultante gli interi siano elencati in ordine crescente (8 punti);
 */

#include <stdio.h>
#include <math.h>

int n_cifre(int n){
    int count = 0;
    while (n / 10 > 0) {
        count++;
        n /= 10;
    }
    return count + 1;
}

int is_prime(int n){
    int i, flag = 1;
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            flag = 0;
        }
    }
    return flag;
}

int is_pts2(int n){
    int d;
    //caso base, il numero ha una cifra
    if (n / 10 == 0) {
        printf("return n: %d\n", n);
        return is_prime(n);
    }else{
        
        printf("checking: %d\n",n);
        d = is_pts2(n % (int)pow(10, n_cifre(n) - 1));
        printf("calling: %d\n",n);
        return is_prime(d);
        
    }
}

int main(int argc, const char * argv[]) {
    
    printf("%d", is_pts2(313));
    
    return 0;
}
