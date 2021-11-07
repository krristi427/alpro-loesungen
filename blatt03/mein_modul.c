#include "mein_modul.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Gibt Debuginfos aus (bei Bedarf)
void debug(char* text) {
#ifdef DEBUG
    printf("[DEBUG: %s]\n", text);
#endif
}

// Gibt zufällige Ganzzahl zurück...hier im intervall [-500, 499]
int zufaellige_zahl() {
    return (rand() % 1000) - 500;
}

// Die Funktion liest von der Standardeingabe maximal buffer_len -1 viele Zeichen.
// Das Symbol '\n' wird ebenfalls eingeladen.
void lies_eingabe_und_schreib_sie_hier_rein(char* rein) {
    fgets(rein, buffer_len, stdin);
}

int meine_strlen(char* text) {

    // starte counter für die Länge auf 0
    int counter = 0;

    // da strings in C null-terminiert sind, muss man bis zur 0-byte prüfen
    // ACHTUNG: \0 in '' und nicht in "" schreiben. '' ist ein char und "" ist ein string
    while (text[counter] != '\0') {
        counter++;
    }
    return counter;

    // maybe kürzer:
    // for(;text[counter] != '\0'; counter++) {}
    // aber es geht um lesbarkeit ;)
}

void int_array_befuellen(int* array, int laenge) {

    // legit was der methodenname sagt
    for (int i = 0; i < laenge; i++) {
        array[i] = zufaellige_zahl();
    }
}

void int_array_ausrucken(int* array, int laenge) {

    printf("[ ");

    // man bricht 1 früher ab, damit man die muster perfekt hinbekommt
    for (int i = 0; i < laenge - 1; ++i) {
        printf("%4d, ", array[i]);
    }
    printf("%4d]\n", array[laenge - 1]);
}

int kisten_sortieren(int* kisten, int anzahl_kisten) {

    int swap_counter = 0;

    // ich behaupte, es geht um bubble-sort
    // gehe alle kisten durch
    for (int i = 0; i < anzahl_kisten - 1; i++) {

        // gehe alle verbleibenden Kisten durch
        for (int j = 0; j < anzahl_kisten - i - 1; j++) {

            // wenn die eine kiste größer ist als ihr nachbar: swap
            if (kisten[j] > kisten[j + 1]) {
                int tmp = kisten[j];
                kisten[j] = kisten[j + 1];
                kisten[j + 1] = tmp;
                swap_counter++;
            }
        }
    }
    return swap_counter;
}

// Diese Funktion wird zur Ladezeit der Bibliothek,
// also zum Start des Prozess, ausgeführt.
void __attribute__((constructor)) init_random_seed() {
    srand(time(NULL));
    debug("Modul ist initalisiert");
}
