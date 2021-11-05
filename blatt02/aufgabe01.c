#include <stdio.h>
#include <stdlib.h>

// Die Standardbibliothek stdio.h stellt grundlegende Funktionen zur
// Ein- und Ausgabe von Text zur Verfügung

// Aufgabe:
// Schreiben Sie die Funktionen zur Sinus- und Kosinusberechnung.
// Schreiben Sie dabei aussagekräftigen Code und kommentieren Sie Ihre Abgabe.

// In der Main soll eine Gleitkommazahl x eingelesen werden.
// Im Anschluss soll die zwei Gleitkommazahlen sin(x) und cos(x) in einer Zeile ausgegeben werden.
// Erklären Sie im Detail wie der Formatstring aufgebaut ist.
// Sie können dazu die "Manpage" nutzen oder in ihrer Lieblingssuchmaschine nach Formatstrings suchen.

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

    // trigonometrisches Identität
    return sin(3.14159265358979323846 / 2.0 - x);
}

int main() {
    // Lies x ein (ein bisschen Magie)
    char buf[0x30];

    // atof = ascii to float
    // fgets: reads 0x30 characters from stdin and writes it in buf.
    //        it returns a pointer to buf, or NULL if reading was unsuccessful
    //        which is why one should probably use the returned ptr instead of buf
    double x = atof(fgets(buf, 0x30, stdin));

    // % tells the compiler to look out for whatever comes next
    // 0. just prints the 0.
    // 4 means it will print 4 decimal places
    // f is for a float
    // \n ist a new-line character
    printf("sin(x) = %0.4f, cos(x) = %0.4f\n", sin(x), cos(x));
    return 0;
}
