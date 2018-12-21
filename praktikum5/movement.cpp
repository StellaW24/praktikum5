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
    return true;
}

bool moveKnight(string position, figure board[8][8])
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
    int jFrom = getCol(position) - '0';

    //string where to move
    string positionTo = to(position);

    //moveTo
    int iTo = getRow(positionTo);
    int jTo = getCol(positionTo) - '0';

    //row move positive
    for(int x = 1; x < (8 - jFrom); x++)
    {
        if (x == jTo && iTo == iFrom)
        {
            cout << "the queen moves to the right" << endl;
            return true;
        }
    }
    //row move negative
    for(int x = jFrom; x >= 0; x--)
    {
        if (x == jTo && iTo == iFrom)
        {
            cout << "the queen moves to the left" << endl;
            return true;
        }
    }
    //column move positive
    for(int y = 1; y < (8 - iFrom); y++)
    {
        if (y == iTo && jTo == jFrom)
        {
            cout << "the queen moves upward" << endl;
            return true;
        }
    }
    //column move negative
    for(int y = iFrom; y >= 0; y--)
    {
        if (y == iTo && jTo == jFrom)
        {
            cout << "the queen moves downward" << endl;
            return true;
        }
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


    //diagonal move up right
    for(int x = 1,y = 1; x < (8 - jFrom) && y < (8 - iFrom); x++, y++)
    {
        if (x == jTo && y == iTo)
        {
            cout << "the bishop moves upward to the right" << endl;
            return true;
        }
    }
    //diagonal move down left
    for(int x = jFrom,y = iFrom; x >= 0 && y >= 0; x--, y--)
    {
        if (x == jTo && y == iTo)
        {
            cout << "the bishop moves downward to the left" << endl;
            return true;
        }
    }
    //diagonal move up left
    for(int x = jFrom,y = 1; x >= 0 && y < (8 - iFrom); x--, y++)
    {
        if (x == jTo && y == iTo)
        {
            cout << "the bishop moves upward to the left" << endl;
            return true;
        }
    }
    //diagonal move down right
    for(int x = 1,y = iFrom; x < (8 - jFrom) && y >= 0; x++, y--)
    {
        if (x == jTo && y == iTo)
        {
            cout << "the bishop moves downward to the right" << endl;
            return true;
        }
    }

    return false;
}

bool moveQueen(string position, figure board[8][8])
{
    //move from
    int iFrom = getRow(position);
    int jFrom = getCol(position);

    //string where to move
    string positionTo = to(position);

    //moveTo
    int iTo = getRow(positionTo);
    int jTo = getCol(positionTo);

    //test if the attemptet move is possible
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
    //letzten character der Ausgabe des Arraywerts an Position x für Spielbrett y
    switch (piece.contraction) {
    case 'D': return moveQueen(position, board);
    case 'K': return moveKing(position, board, turn);
    case 'L': return moveBishop(position, board);
    case 'S': return moveKnight(position, board);
    case 'T': return moveRook(position, board);
    case 'B': return movePawn(position, turn, board);
    case '-': cout << "Leere Felder enthalten keine bewegbaren Figuren." << endl; break;
    }
    return false;
}
