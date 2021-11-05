#include <stdio.h>
#include <stdlib.h>

// Schreiben Sie ein Programm welches eine Ganzzahl x einliest
// und die Anzahl der Einsen in der Bitdarstellung der positiven Ganzzahl |x|
// ausdruckt (inkl. dem "neue Zeile Symbol").
// Schreiben Sie dabei aussagekräftigen Code und kommentieren Sie Ihre Abgabe.

// Beispiele:
//  4 -> 1
//  7 -> 3
// 43 -> 4

/* Hier kommt euer Programmcode hin */

int anzahl_einsen(int x) {

    // man betrachtet den Betrag.
    if (x < 0) {
        x = -x;
    }

    int anzahl = 0;

    // Idee: halbiere x solange, bis es 0 ist.
    // da wo es nicht genau halbieren lässt: anzahl der einsen hochzählen
    while (x > 0) {
        if (x % 2 == 1){
            anzahl = anzahl + 1;
        }

        // Nach den Inhalten der Vorlesung geht auch das hier:
        // anzahl += (x % 2 == 1);

        x = x/2;
    }

    return anzahl;
}

int main() {
    // Lies x ein (ein bisschen Magie)
    char buf[0x30];
    int x = atoi(fgets(buf, 0x30, stdin));

    printf("%d\n", anzahl_einsen(x));
    return 0;
}
