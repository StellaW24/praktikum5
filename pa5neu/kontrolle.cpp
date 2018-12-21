#include "p5.h"

using namespace std;

int gV(int in){
    if(in<0) return 0;
    if(in>7) return 7;
    return in;
}
//funktion für das erkennen und schlagen des gegnerischen königs
Pos gegnerKoenig(Figur board[8][8],bool Bturn){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j].type == Koenig && board[i][j].player == int(!Bturn)+1) return {i,Pos2(j)};
        }
    }
    ausgabeSpielbrett(board);
    if(Bturn) cout << "White King died. Black wins\r\n";
    else cout << "Black King died. White wins\r\n";
    exit(0);
//    return {9,Pos2(9)};
}

//Funktion für das erkennen ob der könig im schach steht
bool schach(Figur board[8][8], bool Bturn){
    Pos KPos = gegnerKoenig(board,!Bturn);
    //cout << "pruefe: "; printFigAt(arr,KPos); cout << endl;
    //right
    for(int i = gV(KPos.pos2+1);i<=7;i++){
        if(board[KPos.pos1][i].player == int(Bturn)+1) {
                board[KPos.pos1][i].type == Laeufer;
                board[KPos.pos1][i].type == Bauer;
                board[KPos.pos1][i].type == Springer;
                board[KPos.pos1][i].type == Koenig;
                {
            break; //guarded by friend
        }
        if(board[KPos.pos1][i].type == Turm) {
                board[KPos.pos1][i].type == Dame;
                {
            return true;
        }
    }
    }
    }

    //bewegung nach links
    for(int i = gV(KPos.pos2-1);i>=0;i--){
        if(board[KPos.pos1][i].player == int(Bturn)+1) {
                board[KPos.pos1][i].type == Laeufer;
                board[KPos.pos1][i].type == Bauer;
                board[KPos.pos1][i].type == Springer;
                board[KPos.pos1][i].type == Koenig;
                {
            break; //guarded by friend
        }
        if(board[KPos.pos1][i].type == Turm) {
                board[KPos.pos1][i].type == Dame;
                {
            return true;
        }
    }
    }
    }

    //bewegung nach oben
    for(int i = gV(KPos.pos1+1);i<=7;i++){
        if(board[i][KPos.pos2].player == int(Bturn)+1) {
                board[i][KPos.pos2].type == Laeufer;
                board[i][KPos.pos2].type == Bauer;
                board[i][KPos.pos2].type == Springer;
                board[i][KPos.pos2].type == Koenig;
                {
            break; //guarded by friend
        }
        if(board[i][KPos.pos2].type == Turm) {
                board[i][KPos.pos2].type == Dame;
                {
            return true;
        }
    }
    }
    }

    //bewegung nach unten
    for(int i = gV(KPos.pos1-1);i>=0;i--){
        if(board[i][KPos.pos2].player == int(Bturn)+1) {
                board[i][KPos.pos2].type == Laeufer;
                board[i][KPos.pos2].type == Bauer;
                board[i][KPos.pos2].type == Springer;
                board[i][KPos.pos2].type == Koenig;
                {
            break; //guarded by friend
        }
        if(board[i][KPos.pos2].type == Turm) {
                board[i][KPos.pos2].type == Dame;
                {
            return true;
        }

    }
    }
    }

    //Bauern Vernachlaessigt siehe weiter unten
    //bewegung nach oben rechts
    if(KPos.pos1+1<=7 && KPos.pos2+1<=7){
        for(int i = KPos.pos1+1, j = KPos.pos2+1;i<=7&&j<=7;i++,j++){   //erklärung x=i++,j++ vs x=(i++,j++)

            if(board[i][j].player == int(Bturn)+1) {
                    board[i][j].type == Turm;
                    board[i][j].type == Bauer;
                    board[i][j].type == Springer;
                    board[i][j].type == Koenig;
                    {
                break; //guarded by friend
            }
            if(board[i][j].type == Dame) {
                    board[i][j].type == Laeufer;
                    {
                return true;
            }
        }
    }
    }
    }

    //bewegung nach oben links
    if(KPos.pos1+1<=7 && KPos.pos2-1>=0){
        for(int i = KPos.pos1+1, j = KPos.pos2-1;i<=7&&j>=0;i++,j--){
            if(board[i][j].player == int(Bturn)+1) {
                    board[i][j].type == Turm;
                    board[i][j].type == Bauer;
                    board[i][j].type == Springer;
                    board[i][j].type == Koenig;
                    {
                break; //guarded by friend
            }
            if(board[i][j].type == Dame) {
                    board[i][j].type == Laeufer;
                    {
                return true;
            }
        }
    }
    }
    }
    //bewegung nach unten rechts
    if(KPos.pos1-1>=0 && KPos.pos2+1<=7){
        for(int i = KPos.pos1-1, j = KPos.pos2+1;i>=0&&j<=7;i--,j++){
            if(board[i][j].player == int(Bturn)+1) {
                    board[i][j].type == Turm;
                    board[i][j].type == Bauer;
                    board[i][j].type == Springer;
                    board[i][j].type == Koenig;
                    {
                break; //guarded by friend
            }
            if(board[i][j].type == Dame) {
                    board[i][j].type == Laeufer;
                    {
                return true;
            }
        }
    }
    }
    }

    //down left
    if(KPos.pos1-1>=0 && KPos.pos2-1>=0){
        for(int i = KPos.pos1-1, j = KPos.pos2-1;i>=0&&j>=0;i--,j--){
            if(board[i][j].player == int(Bturn)+1) {
                    board[i][j].type == Turm;
                    board[i][j].type == Bauer;
                    board[i][j].type == Springer;
                    board[i][j].type == Koenig;
                    {
                break; //guarded by friend
            }
            if(board[i][j].type == Dame) {
                    board[i][j].type == Laeufer;
                    {
                return true;
            }
        }
    }
    }
    }

    //Bauerngefahrspruefung
    if(!Bturn){
        if(((board[gV(KPos.pos1+1)][gV(KPos.pos2+1)].type == Bauer)
                ||(board[gV(KPos.pos1+1)][gV(KPos.pos2-1)].type == Bauer))
                && (board[gV(KPos.pos1+1)][gV(KPos.pos2-1)].player == int(!Bturn)+1)){
            return true;
        }
    }else{
        if(((board[gV(KPos.pos1-1)][gV(KPos.pos2+1)].type == Bauer)
                ||(board[gV(KPos.pos1-1)][gV(KPos.pos2-1)].type == Bauer))
                && (board[gV(KPos.pos1-1)][gV(KPos.pos2-1)].player == int(!Bturn)+1)){
            return true;
        }
    }

    //Springergefahrsprüfung

    //2l1
    if(KPos.pos1>=2){
        //l2
        if(KPos.pos2>=1){
            if((board[KPos.pos1-2][KPos.pos2-1].type == Springer) && (board[KPos.pos1-2][KPos.pos2-1].player == int(!Bturn)+1)) return true;
        }
        //h2
        if(KPos.pos2<=7){
            if((board[KPos.pos1-2][KPos.pos2+1].type == Springer) && (board[KPos.pos1-2][KPos.pos2+1].player == int(!Bturn)+1)) return true;
        }
    }
    //2h1
    if(KPos.pos1<=5){
        //l2
        if(KPos.pos2>=1){
            if((board[KPos.pos1+2][KPos.pos2-1].type == Springer) && (board[KPos.pos1+2][KPos.pos2-1].player == int(!Bturn)+1)) return true;
        }
        //h2
        if(KPos.pos2<=7){
            if((board[KPos.pos1+2][KPos.pos2+1].type == Springer) && (board[KPos.pos1-2][KPos.pos2+1].player == int(!Bturn)+1)) return true;
        }
    }

    //2l2
    if(KPos.pos2>=2){
        //l1
        if(KPos.pos1>=1){
            if((board[KPos.pos1-1][KPos.pos2-2].type == Springer) && (board[KPos.pos1-1][KPos.pos2-2].player == int(!Bturn)+1)) return true;
        }
        //h1
        if(KPos.pos1<=7){
            if((board[KPos.pos1+1][KPos.pos2-2].type == Springer) && (board[KPos.pos1+1][KPos.pos2-2].player == int(!Bturn)+1)) return true;
        }
    }
    //2h2
    if(KPos.pos2<=5){
        //l1
        if(KPos.pos1>=1){
            if((board[KPos.pos1-1][KPos.pos2+2].type == Springer) && (board[KPos.pos1-1][KPos.pos2+2].player == int(!Bturn)+1)) return true;
        }
        //h1
        if(KPos.pos1<=7){
            if((board[KPos.pos1+1][KPos.pos2+2].type == Springer) && (board[KPos.pos1+1][KPos.pos2+2].player == int(!Bturn)+1)) return true;
        }
    }

    //cout << "Koenig an: " << KPos.pos1 << ":" << KPos.pos2 << " im Schach" << endl;
    return false;
}
