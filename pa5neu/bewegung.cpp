#include "p5.h"

//Funktion für die Bewegung des Bauern
bool istBauernZugGueltig(Figur board[8][8],Pos from,Pos zielort,bool Bturn){
    int richtung = 0;
    if(Bturn){ cout << "Bturn\r\n"; richtung = -1;}
    else richtung = 1;
    //schlägt keinen eigenen und bewegt eine eigene
    if((board[zielort.pos1][zielort.pos2].player != int(Bturn) + 1))
    {
        //bleibt der Bauer in der selben spalte
        if(from.pos2 == zielort.pos2){
            //Darf der Bauer zwei schritte gehen
            if((zielort.pos1*richtung)-(from.pos1 * richtung) == 2){
                //Noch ein Schritt möglich?
                if(board[from.pos1][from.pos2].firstmove){
                    //Test ob die Felder dazwischen belegt sind oder ob es freie felder sind
                    if(board[zielort.pos1 - richtung][zielort.pos2].player == 0){
                        if(board[zielort.pos1][zielort.pos2].player == 0){
                            return true;
                            //Ausgaben bei fehlermeldungen also wenn der Zug verboten ist
                        }else cout << "Zielfeld blockiert\r\n";
                    } else cout << "Doppelschritt durch Gegner blockiert\r\n";
                }else cout << "Doppelschritt nur als erster Zug des Bauern\r\n";

            }
            //abfrage der gültigkeit wenn der bauer nur einen schritt machen darf
            else{
                if((zielort.pos1*richtung)-(from.pos1 * richtung) == 1){
                    if(board[zielort.pos1][zielort.pos2].player != int(!Bturn) + 1)
                    {
                        //Wenn alles ok war wird true zurückgegeben
                        return true;
                        //Kommt ein fehler auf wird false zurückgegeben
                    }else cout << "Durch Gegner Blockiert\r\n";
                }else cout << "Falsche Schrittweite\r\n";
            }
        }
        //Abfolge von Bewegungen wenn der Bauer eine Figur schlägt
        else{
            if(board[zielort.pos1][zielort.pos2].player == int(!Bturn)+1){
                if(((zielort.pos1*richtung)-(from.pos1 * richtung) == 1)
                        && abs((zielort.pos2*richtung)-(from.pos2 * richtung)) == 1){
                    return true;

                }else cout << "falsches Schrittmuster\r\n";

            }else cout << "seitlich ohne gegner zu schlagen geht nicht (zielort: "
                       << board[zielort.pos1][zielort.pos2].player
                    << " sollte folgender ort sein: " << int(!Bturn)+1 << "\r\n";

        }

    }
    //Wenn der Zug eine eigene Spielfigur schlagen würde
    else cout << "wuerde eigenen schlagen\r\n";

    return false;
}

//Funktion für die Bewegung des Läufers
bool istLauferZugGueltig(Figur board[8][8],Pos from,Pos zielort){
    //Diagonale bbewegung des läufers
    if(abs(from.pos1-zielort.pos1) == abs(from.pos2-zielort.pos2)){
        //variablen für die richtung
        int richtung1  {1};
        int richtung2  {1};
        //schleifen für die erkennung der richtung
        if(from.pos1>zielort.pos1){
            richtung1 = -1;
        }
        if(from.pos2>zielort.pos2){
            richtung2 = -1;
        }
        //erkennung ob der Zug von einer anderen Figur blockiert wird
        for(int i=1;i<abs(from.pos1-zielort.pos1);i++){
            if(board[i*richtung1 + from.pos1][i*richtung2 + from.pos2].player != 0)
            {
                //wenn dem so ist, so ist der zug nicht gültig
                cout << "zug blockiert bei: " << i*richtung1 + from.pos1 << ":" << i*richtung2 + from.pos2 << "\r\n";
                return false;
            }
            //ansonsten kann der Zug ausgeführt werden
        }return true;
        //wennn allles nicht zutrifft, dann false
    return false;
}
}

//Funktiion für die Bewegung des Turms
bool istTurmZugGueltig(Figur board[8][8],Pos from,Pos zielort){
    //bewegung nach oben und nach unten des turms
    if(from.pos1==zielort.pos1){
        for(int i = min(from.pos2,zielort.pos2)+1;i<max(from.pos2,zielort.pos2);i++){
            if(board[from.pos1][i].player != 0){
                cout << "zug wird blockiert bei: " << from.pos1 << ":" << i << "\r\n"; return false;

            }
        }return true;
    }
    //bewegung nach links und nacnh rechts des turms
    if(from.pos2==zielort.pos2){
        for(int i = min(from.pos1,zielort.pos1)+1;i<max(from.pos1,zielort.pos1);i++){
            if(board[i][from.pos2].player != 0){
                cout << "zug wird blockiert bei: " << i << ":" << from.pos2 << "\r\n"; return false;
            }
        }return true;
    }
    //cout << "Tuerme bewegen sich in geraden linien\r\n";
    return false;
}

//Funktion für die Bewegung des Springers
bool istSpringerZugGueltig(Pos from,Pos zielort){
    //Schleife für die Bewegung des Springers
    if((abs(from.pos1-zielort.pos1)==2 && abs(from.pos2-zielort.pos2)==1)
            || (abs(from.pos2-zielort.pos2)==2 && abs(from.pos1-zielort.pos1)==1)
            //Wenn der Zug stimmt wird true zurückgegeben
            ) return true;
    //ansonsten ist der Zug ungültig
    else cout << "falsches Bewegungsmuster fuer Springer\r\n";
    //und false wird wiedergegeben
    return false;
}


//Funktion der Bewegung der Dame, relativ simpel da sie eine kombination aus turm und läufer ist
bool istDamenZugGueltig(Figur board[8][8],Pos from,Pos zielort){
    //hier die kombination beider figurne
    return (istLauferZugGueltig(board,from,zielort) || istTurmZugGueltig(board,from,zielort));
}

//Funktion der Bewegung des Königs
bool istKoenigsZugGueltig(Figur board[8][8],Pos from,Pos zielort,bool Bturn){
    if(not((abs(from.pos1-zielort.pos1) <= 1) && (abs(from.pos2-zielort.pos2) <= 1))) return false;
    //prüfen ob sich der König im schach befinden würde
    Figur chess[8][8];
    for(int i=0;i<8;i++) memcpy(chess[i],board[i],sizeof (board[i]));

    chess[zielort.pos1][zielort.pos2] = chess[from.pos1][from.pos2];
    chess[from.pos1][from.pos2] = {0,0,0};

    return (!schach(chess,Bturn));
}

//Funktion für die Aufrufe der Funktionen
bool istZugGueltig(Figur board[8][8],Pos from,Pos zielort,bool Bturn){

    //Test ob der Zug mit dem richtigen spieler gemacht wird
    if(board[from.pos1][from.pos2].player == int(Bturn)+1){
        if((board[zielort.pos1][zielort.pos2].player != int(Bturn) + 1))
        {
            //switch case um die gültigkeits-funktion der jeweiligen Figur aufzurufen
            switch (board[from.pos1][from.pos2].type) {
                case Bauer: return istBauernZugGueltig(board,from,zielort,Bturn);
                case Laeufer: return istLauferZugGueltig(board,from,zielort);
                case Turm: return istTurmZugGueltig(board,from,zielort);
                case Springer: return istSpringerZugGueltig(from,zielort);
                case Dame: return istDamenZugGueltig(board,from,zielort);
                case Koenig: return istKoenigsZugGueltig(board,from,zielort,Bturn);
                default: return false;
            }
        }
        else cout << "du kannst keine eigenen schlagen\r\n";
    }
    else cout << "Eigene Figur waehlen\r\n" << "gewaehlt: "
              << board[from.pos1][from.pos2].player
            << " selbst: " << int(Bturn)+1 << endl;

    return false;
}

//funktion für das schlagen von figuren
bool schlaegtZugFigur(Figur board[8][8], Pos zielort, bool Bturn){
    return (board[zielort.pos1][zielort.pos2].player == int(!Bturn) + 1);
}
