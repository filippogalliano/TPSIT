#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main () {
    int n_alunni ;
    float R ;

    printf ("Inserisci R: ") ;
    scanf ("%f", &R) ;

    printf ("Inserisci il numero di alunni: ") ;
    scanf ("%d", &n_alunni) ;

    int g = 1 ;
    float v [n_alunni] ;

    v[0] = 1 ;

    do {
        v[g] = R * v[g - 1] ;
        g++ ;
    } while (v[g - 1] < n_alunni) ;

    for (int k = 0; k < g; k++) {
        printf ("Giorno %d: %.0f \nContagiati\n", k + 1, vettore[k]) ;
    }
}