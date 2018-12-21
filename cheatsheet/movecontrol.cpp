#include "movecontrol.h"

bool istBauernZugGueltig(Figur arr[8][8],Pos from,Pos dest,bool Bturn){
    int dir = 0;
    if(Bturn){ cout << "Bturn\r\n"; dir = -1;}
    else dir = 1;
    //schlägt keinen eigenen und bewegt eine eigene
    if((arr[dest.pos1][dest.pos2].player != int(Bturn) + 1))
    {
        //stay in row?
        if(from.pos2 == dest.pos2){
            //Doppelschrittversuch?
            if((dest.pos1*dir)-(from.pos1 * dir) == 2){
                //Darf noch?
                if(arr[from.pos1][from.pos2].firstmove){
                    //cout << "1st move\r\n";
                    //Feld zwischen drin frei?
                    if(arr[dest.pos1 - dir][dest.pos2].player == 0){
                        if(arr[dest.pos1][dest.pos2].player == 0){
                            return true;
                        }else cout << "Zielfeld blockiert\r\n";
                    } else cout << "Doppelschritt durch Gegner blockiert\r\n";
                }else cout << "Doppelschritt nur als erster Zug des Bauern\r\n";

            }
            //Einzelschritt
            else{
                if((dest.pos1*dir)-(from.pos1 * dir) == 1){
                    if(arr[dest.pos1][dest.pos2].player != int(!Bturn) + 1)
                    {
                        return true;
                    }else cout << "Durch Gegner Blockiert\r\n";
                }else cout << "Falsche Schrittweite\r\n";
            }
        }
        //has to attack
        else{
            if(arr[dest.pos1][dest.pos2].player == int(!Bturn)+1){
                if(((dest.pos1*dir)-(from.pos1 * dir) == 1)
                        && abs((dest.pos2*dir)-(from.pos2 * dir)) == 1){
                    return true;

                }else cout << "falsches Schrittmuster\r\n";

            }else cout << "seitlich ohne gegner zu schlagen geht nicht (dest: " << arr[dest.pos1][dest.pos2].player << " should be: " << int(!Bturn)+1 << "\r\n";

        }

    }
    else cout << "wuerde eigenen schlagen\r\n";

    return false;
}


bool istLauferZugGueltig(Figur arr[8][8],Pos from,Pos dest){
    //Diagonal?
    if(abs(from.pos1-dest.pos1) == abs(from.pos2-dest.pos2)){

        int dir1 = 1;
        int dir2 = 1;
        if(from.pos1>dest.pos1){
            dir1 = -1;
        }
        if(from.pos2>dest.pos2){
            dir2 = -1;
        }
        for(int i=1;i<abs(from.pos1-dest.pos1);i++){
            if(arr[i*dir1 + from.pos1][i*dir2 + from.pos2].player != 0)
            {
                cout << "zug blockiert bei: " << i*dir1 + from.pos1 << ":" << i*dir2 + from.pos2 << "\r\n"; return false;
            }
        }return true;
    }//else cout << "Laufer bewegen sich nur Diagonal\r\n";
    return false;
}

bool istTurmZugGueltig(Figur arr[8][8],Pos from,Pos dest){
    //ud
    if(from.pos1==dest.pos1){
        for(int i = min(from.pos2,dest.pos2)+1;i<max(from.pos2,dest.pos2);i++){
            if(arr[from.pos1][i].player != 0){
                cout << "zug blockiert bei: " << from.pos1 << ":" << i << "\r\n"; return false;

            }
        }return true;
    }
    //lr
    if(from.pos2==dest.pos2){
        for(int i = min(from.pos1,dest.pos1)+1;i<max(from.pos1,dest.pos1);i++){
            if(arr[i][from.pos2].player != 0){
                cout << "zug blockiert bei: " << i << ":" << from.pos2 << "\r\n"; return false;
            }
        }return true;
    }
    //cout << "Tuerme bewegen sich gerade\r\n";
    return false;
}

bool istSpringerZugGueltig(Pos from,Pos dest){

    if((abs(from.pos1-dest.pos1)==2 && abs(from.pos2-dest.pos2)==1)
            || (abs(from.pos2-dest.pos2)==2 && abs(from.pos1-dest.pos1)==1)
            ) return true;
    else cout << "falsches Bewegungsmuster fuer Springer\r\n";

    return false;
}

bool istDamenZugGueltig(Figur arr[8][8],Pos from,Pos dest){

    return (istLauferZugGueltig(arr,from,dest) || istTurmZugGueltig(arr,from,dest));
}


bool istKoenigsZugGueltig(Figur arr[8][8],Pos from,Pos dest,bool Bturn){
    if(not((abs(from.pos1-dest.pos1) <= 1) && (abs(from.pos2-dest.pos2) <= 1))) return false;
    //prüfen ob er im schach wäre
    //to lazy, do move on copied board and run schach()
    Figur chess[8][8];
    for(int i=0;i<8;i++) memcpy(chess[i],arr[i],sizeof (arr[i]));

    chess[dest.pos1][dest.pos2] = chess[from.pos1][from.pos2];
    chess[from.pos1][from.pos2] = {0,0,0};

    return (!schach(chess,Bturn));
}


bool istZugGueltig(Figur arr[8][8],Pos from,Pos dest,bool Bturn){

    //zug mit meinem Spieler?
    if(arr[from.pos1][from.pos2].player == int(Bturn)+1){
        if((arr[dest.pos1][dest.pos2].player != int(Bturn) + 1))
        {
            switch (arr[from.pos1][from.pos2].type) {
                case Bauer: return istBauernZugGueltig(arr,from,dest,Bturn);
                case Laeufer: return istLauferZugGueltig(arr,from,dest);
                case Turm: return istTurmZugGueltig(arr,from,dest);
                case Springer: return istSpringerZugGueltig(from,dest);
                case Dame: return istDamenZugGueltig(arr,from,dest);
                case Koenig: return istKoenigsZugGueltig(arr,from,dest,Bturn);
                default: return false;
            }
        }
        else cout << "du kannst keine eigenen schlagen\r\n";
    }
    else cout << "Eigene Figur waehlen\r\n" << "gewaehlt: " << arr[from.pos1][from.pos2].player << " selbst: " << int(Bturn)+1 << endl;

    return false;
}

bool schlaegtZugFigur(Figur arr[8][8], Pos dest, bool Bturn){
    return (arr[dest.pos1][dest.pos2].player == int(!Bturn) + 1);
}
