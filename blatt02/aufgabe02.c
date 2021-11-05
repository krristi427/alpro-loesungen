#include <stdio.h>
#include <stdlib.h>

// Schreiben Sie ein Programm welches eine Gleitkommazahl einliest
// und den Tangens dieser Zahl in einer Zeile (inkl. dem "neue Zeile Symbol")
// ausgibt.
// Schreiben Sie dabei aussagekräftigen Code und kommentieren Sie Ihre Abgabe.

// Für die ganz Cleveren: Sie dürfen die math.h nicht benutzen.

/* Hier kommt euer Programmcode hin */


double sin(double x) {
    double sinus = 0;          // Berechnet den Sinus als Taylorentwicklung
    double summand = x;        // Aktueller Summand der Taylorentwicklung
    double zaehler_helfer = 1; // Hilft beim Berechnen des Nenners
    double klein = 1e-8;       // Eine kleine Zahl

    // Solange |summand| > klein
    while (summand > klein || -summand > klein) {
        sinus += summand;
        summand = -(summand*x*x) / ((zaehler_helfer+1) * (zaehler_helfer+2));
        zaehler_helfer += 2;
    }
    return sinus;
}

double cos(double x) {
    return sin(3.14159265358979323846 / 2.0 - x);
}

double tan(double x) {

    // again, trigonometrie
    return sin(x) / cos(x);
}

int main() {
    // Lies x ein (ein bisschen Magie)
    char buf[0x30];
    double x = atof(fgets(buf, 0x30, stdin));

    printf("tan(x) = %0.4f\n", tan(x));
}


