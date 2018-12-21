#include "check.h"

int gV(int in){
    if(in<0) return 0;
    if(in>7) return 7;
    return in;
}

Pos findEnemyKing(Figur arr[8][8],bool Bturn){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j].type == Koenig && arr[i][j].player == int(!Bturn)+1) return {i,Pos2(j)};
        }
    }
    printChessArr(arr);
    if(Bturn) cout << "White King died. Black wins\r\n";
    else cout << "Black King died. White wins\r\n";
    exit(0);
//    return {9,Pos2(9)};
}

bool schach(Figur arr[8][8], bool Bturn){
    Pos KPos = findEnemyKing(arr,!Bturn);
    //cout << "pruefe: "; printFigAt(arr,KPos); cout << endl;
    //r
    for(int i = gV(KPos.pos2+1);i<=7;i++){
        if(arr[KPos.pos1][i].player == int(Bturn)+1
                ||arr[KPos.pos1][i].type == Laeufer
                ||arr[KPos.pos1][i].type == Bauer
                ||arr[KPos.pos1][i].type == Springer
                ||arr[KPos.pos1][i].type == Koenig
                ){
            break; //guarded by friend
        }
        if(arr[KPos.pos1][i].type == Turm
                ||arr[KPos.pos1][i].type == Dame
                ){
            return true;
        }
    }

    //l
    for(int i = gV(KPos.pos2-1);i>=0;i--){
        if(arr[KPos.pos1][i].player == int(Bturn)+1
                ||arr[KPos.pos1][i].type == Laeufer
                ||arr[KPos.pos1][i].type == Bauer
                ||arr[KPos.pos1][i].type == Springer
                ||arr[KPos.pos1][i].type == Koenig
                ){
            break; //guarded by friend
        }
        if(arr[KPos.pos1][i].type == Turm
                ||arr[KPos.pos1][i].type == Dame
                ){
            return true;
        }
    }

    //u
    for(int i = gV(KPos.pos1+1);i<=7;i++){
        if(arr[i][KPos.pos2].player == int(Bturn)+1
                ||arr[i][KPos.pos2].type == Laeufer
                ||arr[i][KPos.pos2].type == Bauer
                ||arr[i][KPos.pos2].type == Springer
                ||arr[i][KPos.pos2].type == Koenig
                ){
            break; //guarded by friend
        }
        if(arr[i][KPos.pos2].type == Turm
                ||arr[i][KPos.pos2].type == Dame
                ){
            return true;
        }
    }

    //d
    for(int i = gV(KPos.pos1-1);i>=0;i--){
        if(arr[i][KPos.pos2].player == int(Bturn)+1
                ||arr[i][KPos.pos2].type == Laeufer
                ||arr[i][KPos.pos2].type == Bauer
                ||arr[i][KPos.pos2].type == Springer
                ||arr[i][KPos.pos2].type == Koenig
                ){
            break; //guarded by friend
        }
        if(arr[i][KPos.pos2].type == Turm
                ||arr[i][KPos.pos2].type == Dame
                ){
            return true;
        }

    }

    //Bauern Vernachlaessigt siehe weiter unten
    //ur
    if(KPos.pos1+1<=7 && KPos.pos2+1<=7){
        for(int i = KPos.pos1+1, j = KPos.pos2+1;i<=7&&j<=7;i++,j++){   //erklärung x=i++,j++ vs x=(i++,j++)

            if(arr[i][j].player == int(Bturn)+1
                    ||arr[i][j].type == Turm
                    ||arr[i][j].type == Bauer
                    ||arr[i][j].type == Springer
                    ||arr[i][j].type == Koenig
                    ){
                break; //guarded by friend
            }
            if(arr[i][j].type == Dame
                    ||arr[i][j].type == Laeufer
                    ){
                return true;
            }
        }
    }

    //ul
    if(KPos.pos1+1<=7 && KPos.pos2-1>=0){
        for(int i = KPos.pos1+1, j = KPos.pos2-1;i<=7&&j>=0;i++,j--){
            if(arr[i][j].player == int(Bturn)+1
                    ||arr[i][j].type == Turm
                    ||arr[i][j].type == Bauer
                    ||arr[i][j].type == Springer
                    ||arr[i][j].type == Koenig
                    ){
                break; //guarded by friend
            }
            if(arr[i][j].type == Dame
                    ||arr[i][j].type == Laeufer
                    ){
                return true;
            }
        }
    }
    //dr
    if(KPos.pos1-1>=0 && KPos.pos2+1<=7){
        for(int i = KPos.pos1-1, j = KPos.pos2+1;i>=0&&j<=7;i--,j++){
            if(arr[i][j].player == int(Bturn)+1
                    ||arr[i][j].type == Turm
                    ||arr[i][j].type == Bauer
                    ||arr[i][j].type == Springer
                    ||arr[i][j].type == Koenig
                    ){
                break; //guarded by friend
            }
            if(arr[i][j].type == Dame
                    ||arr[i][j].type == Laeufer
                    ){
                return true;
            }
        }
    }

    //dl
    if(KPos.pos1-1>=0 && KPos.pos2-1>=0){
        for(int i = KPos.pos1-1, j = KPos.pos2-1;i>=0&&j>=0;i--,j--){
            if(arr[i][j].player == int(Bturn)+1
                    ||arr[i][j].type == Turm
                    ||arr[i][j].type == Bauer
                    ||arr[i][j].type == Springer
                    ||arr[i][j].type == Koenig
                    ){
                break; //guarded by friend
            }
            if(arr[i][j].type == Dame
                    ||arr[i][j].type == Laeufer
                    ){
                return true;
            }
        }
    }

    //Bauerngefahrspruefung
    if(!Bturn){
        if(((arr[gV(KPos.pos1+1)][gV(KPos.pos2+1)].type == Bauer)
                ||(arr[gV(KPos.pos1+1)][gV(KPos.pos2-1)].type == Bauer))
                && (arr[gV(KPos.pos1+1)][gV(KPos.pos2-1)].player == int(!Bturn)+1)){
            return true;
        }
    }else{
        if(((arr[gV(KPos.pos1-1)][gV(KPos.pos2+1)].type == Bauer)
                ||(arr[gV(KPos.pos1-1)][gV(KPos.pos2-1)].type == Bauer))
                && (arr[gV(KPos.pos1-1)][gV(KPos.pos2-1)].player == int(!Bturn)+1)){
            return true;
        }
    }

    //Springergefahrsprüfung

    //2l1
    if(KPos.pos1>=2){
        //l2
        if(KPos.pos2>=1){
            if((arr[KPos.pos1-2][KPos.pos2-1].type == Springer) && (arr[KPos.pos1-2][KPos.pos2-1].player == int(!Bturn)+1)) return true;
        }
        //h2
        if(KPos.pos2<=7){
            if((arr[KPos.pos1-2][KPos.pos2+1].type == Springer) && (arr[KPos.pos1-2][KPos.pos2+1].player == int(!Bturn)+1)) return true;
        }
    }
    //2h1
    if(KPos.pos1<=5){
        //l2
        if(KPos.pos2>=1){
            if((arr[KPos.pos1+2][KPos.pos2-1].type == Springer) && (arr[KPos.pos1+2][KPos.pos2-1].player == int(!Bturn)+1)) return true;
        }
        //h2
        if(KPos.pos2<=7){
            if((arr[KPos.pos1+2][KPos.pos2+1].type == Springer) && (arr[KPos.pos1-2][KPos.pos2+1].player == int(!Bturn)+1)) return true;
        }
    }

    //2l2
    if(KPos.pos2>=2){
        //l1
        if(KPos.pos1>=1){
            if((arr[KPos.pos1-1][KPos.pos2-2].type == Springer) && (arr[KPos.pos1-1][KPos.pos2-2].player == int(!Bturn)+1)) return true;
        }
        //h1
        if(KPos.pos1<=7){
            if((arr[KPos.pos1+1][KPos.pos2-2].type == Springer) && (arr[KPos.pos1+1][KPos.pos2-2].player == int(!Bturn)+1)) return true;
        }
    }
    //2h2
    if(KPos.pos2<=5){
        //l1
        if(KPos.pos1>=1){
            if((arr[KPos.pos1-1][KPos.pos2+2].type == Springer) && (arr[KPos.pos1-1][KPos.pos2+2].player == int(!Bturn)+1)) return true;
        }
        //h1
        if(KPos.pos1<=7){
            if((arr[KPos.pos1+1][KPos.pos2+2].type == Springer) && (arr[KPos.pos1+1][KPos.pos2+2].player == int(!Bturn)+1)) return true;
        }
    }

    //cout << "Koenig an: " << KPos.pos1 << ":" << KPos.pos2 << " im Schach" << endl;
    return false;
}
