#include <iostream>
#include <aufgabe1h.h>
#include <check.h>

using namespace std;

void movePiece(figure board[8][8], string position)
{
    string piece = getPiece(position, board);
    //move from
    int iFrom = getCol(position);
    int jFrom = getRow(position);

    //string where to move
    string positionTo = to(position);

    //moveTo
    int iTo = getCol(positionTo);
    int jTo = getRow(positionTo);

    //
    board[jTo][iTo].contraction = piece.back();
    board[jFrom][iFrom].contraction = '-';
    board[jFrom][iFrom].type = "";
    board[jFrom][iFrom].colour = 0;

    //Output of the changed Chessboard
    for(int j = 0; j < 8; j++)
    {
        cout << adapt(board[j][0]) << " "<< adapt(board[j][1]) << " " << adapt(board [j][2]) << " "<< adapt(board[j][3]) << " "<< adapt(board[j][4]) << " "<< adapt(board[j][5]) << " "<< adapt(board [j][6]) << " "<< adapt(board[j][7]) << " " << j+1 << endl;
            }
    cout << " a " << " b " << " c " << " d " << " e " << " f " << " g " << " h " << endl;
}

bool movePawn(string position, bool turn, figure board[8][8])
{
    //move from
    int iFrom = getRow(position);
    int jFrom = getCol(position);

    //string where to move
    string positionTo = to(position);

    //moveTo
    int iTo = getRow(positionTo);
    int jTo = getCol(positionTo);

    //direction
    int direction = 0;
    if(turn)
    {
        direction = 1;
    }
    else
    {
        direction = -1;
    }

    //stay in col?
    if(iFrom == iTo)
    {
        if(board[getRow(to(position))][getCol(to(position))].contraction != '-')
        {
            return false;
        }
        //move more than two steps?
        if((iTo * direction) - (iFrom * direction) > 2)
        {
            return false;
        }
        //move two steps?
        else if((iTo * direction) - (iFrom * direction) == 2)
        {
            //first time moving?
            if(jFrom == 1 || jFrom == 6)
            {
                //is there another figure blocking your way?
                if((board[getRow(to(position))-1][getCol(to(position))].contraction != '-' && direction == 1) || ((board[getRow(to(position))+1][getCol(to(position))].contraction != '-' && direction == -1)))
                {
                    return false;
                }
                else if(board[getRow(to(position))][getCol(to(position))].contraction != '-')
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
        //move lesss than one step?
        else if((iTo * direction) - (iFrom * direction) < 1)
        {
            return false;
        }
        //move one step
        else
        {
            //is there another figure blocking your way?
            if(board[getRow(to(position))][getCol(to(position))].contraction != '-')
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
    //attacking another figure?
    //staying in row? or moving more than one?
    if(jFrom == jTo || (jTo * direction) - (jFrom * direction) != 1 || iFrom == iTo || (iTo * direction) - (iFrom * direction) != 1)
    {
        return false;
    }
    else if(board[jTo][iTo].contraction == '-')
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool moveKnight(string position)
{
    //move from
    int iFrom = getRow(position);
    int jFrom = getCol(position);

    //string where to move
    string positionTo = to(position);

    //moveTo
    int iTo = getRow(positionTo);
    int jTo = getCol(positionTo);

    if((abs(jFrom-jTo)==2 && abs(iFrom-iTo)==1) || (abs(iFrom-iTo)==2 && abs(jFrom-jTo)==1))
    {
        return true;
    }
    return false;
}

bool moveRook(string position, figure board[8][8])
{
    //move from
    int iFrom = getRow(position);
    int jFrom = getCol(position);

    //string where to move
    string positionTo = to(position);

    //moveTo
    int iTo = getRow(positionTo);
    int jTo = getCol(positionTo);


    //up and down
    if(jFrom == jTo){
        for(int i = min(iFrom,iTo) + 1; i < max(iFrom,iTo); i++){
            if(board[jFrom][i].colour != 0){
                return false;
            }
        }return true;
    }

    //left and right
    if(iFrom==iTo){
        for(int i = min(jFrom,jTo) + 1; i < max(jFrom,jTo); i++){
            if(board[i][iFrom].colour != 0){
                return false;
            }
        }return true;
    }

    return false;
}

bool moveBishop(string position, figure board[8][8])
{
    //move from
    int iFrom = getRow(position);
    int jFrom = getCol(position);

    //string where to move
    string positionTo = to(position);

    //moveTo
    int iTo = getRow(positionTo);
    int jTo = getCol(positionTo);

    int dir1 = 1;
    int dir2 = 1;

    if(jFrom > jTo)
    {
        dir1 = -1;
    }
    if(iFrom > iTo)
    {
        dir2 = -1;
    }

    //not diagonal?
    if(iFrom == iTo || jFrom == jTo)
    {
        return false;
    }
    else
    {
        for(int i=1; i < abs(jFrom-jTo); i++){
            if(board[i * dir1 + jFrom][i*dir2 + iFrom].colour != 0)
            {
                cout << "zug blockiert bei: " << i*dir1 + jFrom << ":" << i*dir2 + iFrom << endl;
                return false;
            }
        }
        return true;
    }
}

bool moveQueen(string position, figure board[8][8])
{
    if(moveBishop(position, board))
    {
        return true;
    }
    else if (moveRook(position, board)) {
        return true;
    }
    cout << "the queen does not move, enter another move" << endl;
    return false;
}

bool moveKing(string position, figure board[8][8], bool turn)
{
    //move from
    int iFrom = getRow(position);
    int jFrom = getCol(position);

    //string where to move
    string positionTo = to(position);

    //moveTo
    int iTo = getRow(positionTo);
    int jTo = getCol(positionTo);

    if(not((abs(jFrom-jTo) <= 1) && (abs(iFrom-iTo) <= 1))) return false;
       //prüfen ob er im schach wäre
       //to lazy, do move on copied board and run schach()
       figure chess[8][8];
       for(int i=0;i<8;i++)
       {
           memcpy(chess[i], board[i],sizeof (board[i]));
       }

       chess[jTo][iTo] = chess[jFrom][iFrom];
       chess[jFrom][iFrom] = {9, "", '-'};

       return (!check(chess, turn));
}

bool checkMove(string position, figure piece, bool turn, figure board[8][8])
{
    //letzten character der Ausgabe des boardaywerts an Position x für Spielbrett y
    switch (piece.contraction) {
    case 'D': return moveQueen(position, board);
    case 'K': return moveKing(position, board, turn);
    case 'L': return moveBishop(position, board);
    case 'S': return moveKnight(position);
    case 'T': return moveRook(position, board);
    case 'B': return movePawn(position, turn, board);
    case '-': cout << "Leere Felder enthalten keine bewegbaren Figuren." << endl; break;
    }
    return false;
}
