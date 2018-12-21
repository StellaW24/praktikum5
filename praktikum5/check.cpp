#include <iostream>
#include <aufgabe1h.h>
#include <movement.h>

using namespace std;

int gV(int in){
    if(in<0) return 0;
    if(in>7) return 7;
    return in;
}

string findEnemyKing(figure board[8][8],bool turn){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j].contraction == 'K') //something missing
            {
               // return {i,Pos2(j)};
            }
        }
    }
    createBoard(board);
    if(!turn) cout << "White King died. Black wins\r\n";
    else cout << "Black King died. White wins\r\n";
    exit(0);
//    return {9,Pos2(9)};
}

bool check(figure board[8][8], bool turn){
    string king = findEnemyKing(board,!turn);
    //cout << "pruefe: "; printFigAt(board,king); cout << endl;
    //r
    for(int i = gV(getCol(king)+1);i<=7;i++){
        if(board[getRow(king)][i].colour == int(turn)+1
                ||board[getRow(king)][i].contraction == 'L'
                ||board[getRow(king)][i].contraction == 'B'
                ||board[getRow(king)][i].contraction == 'S'
                ||board[getRow(king)][i].contraction == 'K'
                ){
            break; //guarded by friend
        }
        if(board[getRow(king)][i].contraction == 'T'
                ||board[getRow(king)][i].contraction == 'D'
                ){
            return true;
        }
    }

    //l
    for(int i = gV(getCol(king)-1);i>=0;i--){
        if(board[getRow(king)][i].colour == int(turn)+1
                ||board[getRow(king)][i].contraction == 'L'
                ||board[getRow(king)][i].contraction == 'B'
                ||board[getRow(king)][i].contraction == 'S'
                ||board[getRow(king)][i].contraction == 'K'
                ){
            break; //guarded by friend
        }
        if(board[getRow(king)][i].contraction == 'T'
                ||board[getRow(king)][i].contraction == 'D'
                ){
            return true;
        }
    }

    //u
    for(int i = gV(getRow(king)+1);i<=7;i++){
        if(board[i][getCol(king)].colour == int(turn)+1
                ||board[i][getCol(king)].contraction == 'L'
                ||board[i][getCol(king)].contraction == 'B'
                ||board[i][getCol(king)].contraction == 'S'
                ||board[i][getCol(king)].contraction == 'K'
                ){
            break; //guarded by friend
        }
        if(board[i][getCol(king)].contraction == 'T'
                ||board[i][getCol(king)].contraction == 'D'
                ){
            return true;
        }
    }

    //d
    for(int i = gV(getRow(king)-1);i>=0;i--){
        if(board[i][getCol(king)].colour == int(turn)+1
                ||board[i][getCol(king)].contraction == 'L'
                ||board[i][getCol(king)].contraction == 'B'
                ||board[i][getCol(king)].contraction == 'S'
                ||board[i][getCol(king)].contraction == 'K'
                ){
            break; //guarded by friend
        }
        if(board[i][getCol(king)].contraction == 'T'
                ||board[i][getCol(king)].contraction == 'D'
                ){
            return true;
        }

    }

    //'B'n Vernachlaessigt siehe weiter unten
    //ur
    if(getRow(king)+1<=7 && getCol(king)+1<=7){
        for(int i = getRow(king)+1, j = getCol(king)+1;i<=7&&j<=7;i++,j++){   //erklärung x=i++,j++ vs x=(i++,j++)

            if(board[i][j].colour == int(turn)+1
                    ||board[i][j].contraction == 'T'
                    ||board[i][j].contraction == 'B'
                    ||board[i][j].contraction == 'S'
                    ||board[i][j].contraction == 'K'
                    ){
                break; //guarded by friend
            }
            if(board[i][j].contraction == 'D'
                    ||board[i][j].contraction == 'L'
                    ){
                return true;
            }
        }
    }

    //ul
    if(getRow(king)+1<=7 && getCol(king)-1>=0){
        for(int i = getRow(king)+1, j = getCol(king)-1;i<=7&&j>=0;i++,j--){
            if(board[i][j].colour == int(turn)+1
                    ||board[i][j].contraction == 'T'
                    ||board[i][j].contraction == 'B'
                    ||board[i][j].contraction == 'S'
                    ||board[i][j].contraction == 'K'
                    ){
                break; //guarded by friend
            }
            if(board[i][j].contraction == 'D'
                    ||board[i][j].contraction == 'L'
                    ){
                return true;
            }
        }
    }
    //dr
    if(getRow(king)-1>=0 && getCol(king)+1<=7){
        for(int i = getRow(king)-1, j = getCol(king)+1;i>=0&&j<=7;i--,j++){
            if(board[i][j].colour == int(turn)+1
                    ||board[i][j].contraction == 'T'
                    ||board[i][j].contraction == 'B'
                    ||board[i][j].contraction == 'S'
                    ||board[i][j].contraction == 'K'
                    ){
                break; //guarded by friend
            }
            if(board[i][j].contraction == 'D'
                    ||board[i][j].contraction == 'L'
                    ){
                return true;
            }
        }
    }

    //dl
    if(getRow(king)-1>=0 && getCol(king)-1>=0){
        for(int i = getRow(king)-1, j = getCol(king)-1;i>=0&&j>=0;i--,j--){
            if(board[i][j].colour == int(turn)+1
                    ||board[i][j].contraction == 'T'
                    ||board[i][j].contraction == 'B'
                    ||board[i][j].contraction == 'S'
                    ||board[i][j].contraction == 'K'
                    ){
                break; //guarded by friend
            }
            if(board[i][j].contraction == 'D'
                    ||board[i][j].contraction == 'L'
                    ){
                return true;
            }
        }
    }

    //'B'ngefahrspruefung
    if(!turn){
        if(((board[gV(getRow(king)+1)][gV(getCol(king)+1)].contraction == 'B')
                ||(board[gV(getRow(king)+1)][gV(getCol(king)-1)].contraction == 'B'))
                && (board[gV(getRow(king)+1)][gV(getCol(king)-1)].colour == int(!turn)+1)){
            return true;
        }
    }else{
        if(((board[gV(getRow(king)-1)][gV(getCol(king)+1)].contraction == 'B')
                ||(board[gV(getRow(king)-1)][gV(getCol(king)-1)].contraction == 'B'))
                && (board[gV(getRow(king)-1)][gV(getCol(king)-1)].colour == int(!turn)+1)){
            return true;
        }
    }

    //'S'gefahrsprüfung

    //2l1
    if(getRow(king)>=2){
        //l2
        if(getCol(king)>=1){
            if((board[getRow(king)-2][getCol(king)-1].contraction == 'S') && (board[getRow(king)-2][getCol(king)-1].colour == int(!turn)+1)) return true;
        }
        //h2
        if(getCol(king)<=7){
            if((board[getRow(king)-2][getCol(king)+1].contraction == 'S') && (board[getRow(king)-2][getCol(king)+1].colour == int(!turn)+1)) return true;
        }
    }
    //2h1
    if(getRow(king)<=5){
        //l2
        if(getCol(king)>=1){
            if((board[getRow(king)+2][getCol(king)-1].contraction == 'S') && (board[getRow(king)+2][getCol(king)-1].colour == int(!turn)+1)) return true;
        }
        //h2
        if(getCol(king)<=7){
            if((board[getRow(king)+2][getCol(king)+1].contraction == 'S') && (board[getRow(king)-2][getCol(king)+1].colour == int(!turn)+1)) return true;
        }
    }

    //2l2
    if(getCol(king)>=2){
        //l1
        if(getRow(king)>=1){
            if((board[getRow(king)-1][getCol(king)-2].contraction == 'S') && (board[getRow(king)-1][getCol(king)-2].colour == int(!turn)+1)) return true;
        }
        //h1
        if(getRow(king)<=7){
            if((board[getRow(king)+1][getCol(king)-2].contraction == 'S') && (board[getRow(king)+1][getCol(king)-2].colour == int(!turn)+1)) return true;
        }
    }
    //2h2
    if(getCol(king)<=5){
        //l1
        if(getRow(king)>=1){
            if((board[getRow(king)-1][getCol(king)+2].contraction == 'S') && (board[getRow(king)-1][getCol(king)+2].colour == int(!turn)+1)) return true;
        }
        //h1
        if(getRow(king)<=7){
            if((board[getRow(king)+1][getCol(king)+2].contraction == 'S') && (board[getRow(king)+1][getCol(king)+2].colour == int(!turn)+1)) return true;
        }
    }

    //cout << "'K' an: " << getRow(king) << ":" << getCol(king) << " im Schach" << endl;
    return false;
}
