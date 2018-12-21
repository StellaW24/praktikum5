#include "print.h"


void printFigAt(Figur chess[8][8],Pos dest){
    switch (chess[dest.pos1][dest.pos2].player) {
        case schwarz: cout << "s"; break;
        case weis: cout << "w"; break;
        default: cout << "-"; break;
    }
    switch (chess[dest.pos1][dest.pos2].type) {
        case Bauer: cout << "B"; break;
        case Laeufer: cout << "L"; break;
        case Springer: cout << "S"; break;
        case Turm: cout << "T"; break;
        case Dame: cout << "D"; break;
        case Koenig: cout << "K"; break;
        default: cout << "-"; break;
    }
}


void printChessArr(Figur arr[8][8]){
    cout << "  | a  | b  | c  | d  | e  | f  | g  | h  |\r\n";
    for(int i=0;i<8;i++){
        cout << "------------------------------------------\r\n";
        cout << i+1 << " | ";
        for(int j = 0;j<8;j++){
            printFigAt(arr,{i,Pos2(j)});
            cout << " | ";
        }
        cout << endl;
    }
}
