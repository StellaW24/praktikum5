#ifndef HEADER_H
#define HEADER_H

#include <iostream>

using namespace::std;

//Daten müssen zuerst kommen, danach die Funktionen

//struktur für die einzelne Figur mit spieler, name und erstbewegung
struct Figur{
    int player;
    int type;
    bool firstmove;
};

//aufzähltyp enum für den Spieler mit den farben weis und schwarz
enum Player{
    undef,
    weis,
    schwarz,
};
//dieses enum ist für die konstanten namen der einzelnen Schachfiguren verantwortlich, das enum startet mit 1 statt 0
enum Type{
  Bauer = 1,
  Laeufer,
  Springer,
  Turm,
  Dame,
  Koenig,
};

//Dieses enum beinhaltet die namen für die zweite position um verwechslungen zu vermeiden
enum Pos2{
    a,
    b,
    c,
    d,
    e,
    f,
    g,
    h,
    i,
};
//struktur für die genaue position
struct Pos{
    int  pos1;
    Pos2 pos2;
};

//Funktion um die Figuren auszugeben
void ausgabeFiguren(Figur chess[8][8],Pos zielort);
//Funktion um das eigentliche spielfeld auszugeben
void ausgabeSpielbrett(Figur board[8][8]);


//Funktion um könig im schach zu erkennen
bool schach(Figur board[8][8], bool Bturn);

//Funktiojn ob der angegebene Zug gültig ist
bool istZugGueltig(Figur board[8][8],Pos from,Pos destination,bool Bturn);
//Funktion um das schlagen einer Figur zu erkennen und zu kontrollieren
bool schlaegtZugFigur(Figur board[8][8], Pos destination, bool Bturn);




#endif // HEADER_H
