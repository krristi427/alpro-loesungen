#include <stdio.h>
#include <stdlib.h>

// Schreiben Sie ein Programm welches zwei Ganzzahl x und y einliest
// und den größten gemeinsamen Teiler ggT(x,y) sowie
// das kleinste gemeinsame Vielfache kgV(x,y) berechnet und ausdruckt.
// Implementieren Sie dazu die Funktionen ggT und kgV.
// Schreiben Sie dabei aussagekräftigen Code und kommentieren Sie Ihre Abgabe.

// Beispiele:
//  4 -> 1
//  7 -> 3
// 43 -> 4

/* Hier kommt euer Programmcode hin */

int ggT(int x, int y) {

    // reine Definitionssache...0 zurückzugeben wäre aber schlecht, wenn man das kgV(0,0) berechnen will
    if (x == 0 || y == 0) {
        return 1;
    }

    // bestimmte den Betrag von x und y...man hätte auch abs(x) benutzen können
    if (x < 0) {
        x = -x;
    }
    if (y < 0) {
        y = -y;
    }

    // implementation des euklidischen Algorithmus...just google it
    while (y != 0) {
        int rest = x % y;
        x = y;
        y = rest;
    }

    return x;
}

int kgV(int x, int y) {
    if (x < 0) {
        x = -x;
    }
    if (y < 0) {
        y = -y;
    }
    return x*y / ggT(x,y);
}

int main() {
    // Lies x ein (ein bisschen Magie)
    char buf[0x30];
    int x = atoi(fgets(buf, 0x30, stdin));
    int y = atoi(fgets(buf, 0x30, stdin));

    printf("ggT(x,y) = %d, kgV(x,y) = %d\n", ggT(x,y), kgV(x,y));
    return 0;
}


