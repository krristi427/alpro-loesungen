#include <stdio.h>
#include "mein_modul.h"

// Compile with:
// clang -std=c17 -Wall -Wextra -Wpedantic -g -o loesung aufgaben.c mein_modul.c


// Aufgabe:
// Implementieren und testen Sie die Funktionen
// die in mein_modul.h beschrieben werden.
// Die dort beschrieben Funktionen sollen in
// mein_modul.c implementiert werden.

int main() {
    char *mystring = "kristi";
    printf("mystring hat die länge: %d\n", meine_strlen(mystring));

    int *myarray = malloc(7 * sizeof(int));
    int_array_befuellen(myarray, 7);
    int_array_ausrucken(myarray, 7);

    int vergleiche = kisten_sortieren(myarray, 7);
    printf("Für das Sortieren der längsten Liste der Welt wurden: %d Vergleiche gemacht\n", vergleiche);
    printf("Die liste sieht nun so aus\n");
    int_array_ausrucken(myarray, 7);

    // every malloc needs a free
    free(myarray);
    return 0;
}
