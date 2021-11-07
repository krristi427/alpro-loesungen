#pragma once

// Dies ist ein Modul indem Sie Funktionsimplementierungen 
// auslagern.

// Druckt Debuginfos aus, wenn DEBUG definiert ist.
#define DEBUG 1
void debug(char* text);


#define buffer_len 1024
// Die Funktion liest von der Standardeingabe maximal buffer_len -1 viele Zeichen.
// Das Symbol '\n' wird ebenfalls eingeladen.
void lies_eingabe_und_schreib_sie_hier_rein(char* rein);


// Diese Funktion erhält einen String und gibt die Anzahl der Zeichen
// des Strings zurück. Dabei wird vom Beginn an bis zum ersten
// Aufkommen des Zeichen '\0' gezählt. Das Zeichen '\0' wird nicht
// mitgezählt.
// 
// Die Funktion gibt z.B. folgende Werte zurück:
//   "" -> 0
//   "Hi" -> 2
//   "Hallo Alpro" -> 11
//   "Komsich\0was hier so passiert" -> 7
int meine_strlen(char* text);


// Gibt zufällige Ganzzahl zurück.
int zufaellige_zahl();


// Diese Funktion bekommt ein int-Array
// sowie die Länge des Arrays übergeben.
// Die Funktion füllt dieses Array mit zufälligen
// Werten.
void int_array_befuellen(int* array, int laenge);


// Diese Funktion bekommt ein int-Array
// sowie die Länge des Arrays übergeben.
// Die Funktion druckt die Zahlen des Arrays nach folgendem
// Format aus:
// [ %4d, %4d, ..., ]
void int_array_ausrucken(int* array, int laenge);


// Diese Funktion stellt das Sortierverfahren aus der Vorlesung
// zur Verfügung. Es wird ein int-Array übergeben sowie
// die Länge des Arrays.
// Die Funktion soll das Array so wie ind er Vorlesung beschrieben
// sortieren und die Anzahl der verwendeten Vertauschungen
// zurückgeben.
int kisten_sortieren(int* kisten, int anzahl_kisten);

