#include "p5.h"

//Hier werden die Figuren ausgegeben
void ausgabeFiguren(Figur chess[8][8],Pos zielort){
    //schwitch case um die Farbe zu erkennen
    switch (chess[zielort.pos1][zielort.pos2].player) {
        case schwarz: cout << "  s"; break;
        case weis: cout << "  w"; break;
        default: cout << "  -"; break;
    }
    //switch case um die Figur zu erkennen, hier wird auch das enum genutzt
    switch (chess[zielort.pos1][zielort.pos2].type) {
        case Bauer: cout << "B  "; break;
        case Laeufer: cout << "L  "; break;
        case Springer: cout << "S  "; break;
        case Turm: cout << "T  "; break;
        case Dame: cout << "D  "; break;
        case Koenig: cout << "K  "; break;
        default: cout << "-  "; break;
    }
}

//Ausgabe des fertigen spielfeldes mit einer extra reihe für die buchstaben und einer extra zeile für die ziffern
void ausgabeSpielbrett(Figur board[8][8]){
    //extra reihe für die buchstaben benennung des feldes
    cout << "   a  " << "   b  " << "   c  " <<  "   d  " <<   "   e  " << "   f  " << "   g  " << "   h  " << endl;
    for(int i=0;i<8;i++){
        //extra spalte für die bezifferung des feldes
        cout << i+1;
        for(int j = 0;j<8;j++){
            //aufruf der Funktionn
            ausgabeFiguren(board,{i,Pos2(j)});
        }
        cout << endl;
    }
}
