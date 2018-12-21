#include <iostream>
#include <aufgabe1h.h>
#include <movement.h>

using namespace std;

//Names defined in constants
const string whiteQueen = "wD";
const string blackQueen = "sD";
const string whiteKing = "wK";
const string blackKing = "bK";
const string whiteKnight = "wS";
const string blackKnight = "sS";
const string whiteBishop = "wL";
const string blackBishop = "sL";
const string whiteRook = "wT";
const string blackRook = "sT";
const string whitePawn = "wB";
const string blackPawn = "sB";

string player(string one, string two, bool turn)
{
    string player;
    if(turn)
    {
        player = one;
    }
    else
    {
        player = two;
    }
    return player;
}

string adapt(figure fig)
{
    string name = "";
    char color = '-';
    if(fig.colour == 0)
    {
        color = 'w';
    }
    else if (fig.colour == 1) {
        color = 's';
    }
    name.push_back(color);
    name.push_back(fig.contraction);
    return name;
}

//Creating the Chessboard as ist is at the beginning
void createBoard(figure board[8][8])
{
    //Pawns
    for(int i = 0; i < 8; i++)
    {
        board[1][i] = {0, "pawn", 'B'};
    }
    for(int i = 0; i < 8; i++)
    {
        board[6][i] = {1, "pawn", 'B'};
    }
    //Empty Spots
    for(int i = 0; i < 8; i++)
    {
        for(int j = 2; j < 6; j++)
        {
            board[j][i] = {9, "", '-'};
        }
    }
    //Queens
    board[7][3] = {1, "queen", 'D'};
    board[0][3] = {0, "queen", 'D'};
    //Kings
    board[7][4] = {1, "king", 'K'};
    board[0][4] = {0, "king", 'K'};
    //Bishops
    board[7][2] = {1, "bishop", 'L'};
    board[0][2] = {0, "bishop", 'L'};
    board[7][5] = {1, "bishop", 'L'};
    board[0][5] = {0, "bishop", 'L'};
    //Knights
    board[7][1] = {1, "knight", 'S'};
    board[0][1] = {0, "knight", 'S'};
    board[7][6] = {1, "knight", 'S'};
    board[0][6] = {0, "knight", 'S'};
    //Rooks
    board[7][0] = {1, "rook", 'T'};
    board[0][0] = {0, "rook", 'T'};
    board[7][7] = {1, "rook", 'T'};
    board[0][7] = {0, "rook", 'T'};

    //Output Board
    for(int j = 0; j < 8; j++)
    {
        cout << adapt(board[j][0]) << " "<< adapt(board[j][1]) << " " << adapt(board [j][2]) << " "<< adapt(board[j][3]) << " "<< adapt(board[j][4]) << " "<< adapt(board[j][5]) << " "<< adapt(board [j][6]) << " "<< adapt(board[j][7]) << " " << j+1 << endl;
    }
    cout << " a " << " b " << " c " << " d " << " e " << " f " << " g " << " h " << endl;
}

string to(string position)
{
    string to = "";
    string copy = position;
    copy.pop_back();
    char first;
    char last;
    first = copy.back();
    last = position.back();
    to.push_back(first);
    to.push_back(last);
    return to;
}

string from(string position)
{
    string from = "";
    char first = position.front();
    char last = position.at(1);
    from.push_back(first);
    from.push_back(last);
    return from;
}

int getCol(string position)
{
    int i = 0;
    //row position
    switch (position.at(0)) {
        case 'a': i = 0; break;
        case 'b': i = 1; break;
        case 'c': i = 2; break;
        case 'd': i = 3; break;
        case 'e': i = 4; break;
        case 'f': i = 5; break;
        case 'g': i = 6; break;
        case 'h': i = 7; break;
        default: inputError = true; break;
    }
    return i;
}

int getRow(string position)
{
    int j = 0;
    //column position
    switch (position.at(1)) {
        case '1': j = 0; break;
        case '2': j = 1; break;
        case '3': j = 2; break;
        case '4': j = 3; break;
        case '5': j = 4; break;
        case '6': j = 5; break;
        case '7': j = 6; break;
        case '8': j = 7; break;
        default: inputError = true; break;
    }
    return j;
}

string getPositionTo(string position, figure board[8][8]){
    return "0";
}

string getPiece(string position, figure board[8][8])
{
    int i = getCol(position);
    int j = getRow(position);
    string piece = "";
    figure fig = board[j][i];
    if(fig.colour == 0)
    {
        piece.push_back('w');
    }
    else if (fig.colour == 1)
    {
        piece.push_back('s');
    }
    return piece;
}

//istZugGültig funktion
bool inputCheck(string position, bool turn, figure board[8][8]) //piece als zusätzliche eingabe?
{
    figure piece;
    string pFrom = from(position);
    piece = board[getRow(pFrom)][getCol(pFrom)];

    //vollständige eingabe?
    if(position.size() >= 4)
    {
        //innerhalb des spielfelds?
        if(position.at(0) == 'a' || position.at(0) == 'b' || position.at(0) == 'c' || position.at(0) == 'd' || position.at(0) == 'e' || position.at(0) == 'f' || position.at(0) == 'g' || position.at(0) == 'h')
        {
            if(position.at(1) == '1' || position.at(1) == '2' || position.at(1) == '3' || position.at(1) == '4' || position.at(1) == '5' || position.at(1) == '6' || position.at(1) == '7'|| position.at(1) == '8')
            {
                if(position.at(position.size() - 2) == 'a' || position.at(position.size() - 2) == 'b' || position.at(position.size() - 2) == 'c' || position.at(position.size() - 2) == 'd' || position.at(position.size() - 2) == 'e' || position.at(position.size() - 2) == 'f' || position.at(position.size() - 2) == 'g' || position.at(position.size() - 2) == 'h')
                {
                    if(position.at(position.size() - 1) == '1' || position.at(position.size() - 1) == '2' || position.at(position.size() - 1) == '3' || position.at(position.size() - 1) == '4' || position.at(position.size() - 1) == '5' || position.at(position.size() - 1) == '6' || position.at(position.size() - 1) == '7'|| position.at(position.size() - 1) == '8')
                    {
                        //check if you move your piece and do not hurt your own
                        if((turn && piece.colour == 0 && (char)(from(getPiece(position, board)).front()) == 'w')||(!turn && piece.colour == 1 && (char)(from(getPiece(position, board)).front()) == 's'))
                        {
                            if(checkMove(position, piece, turn, board))
                            {
                                return true;
                            }
                            else
                            {
                                cout << "Dieser Zug ist nicht moeglich. Bitte versuchen sie es nochmal." << endl;
                            }
                        }
                        else
                        {
                            cout << "Bitte versuchen sie nicht Figuren von ihres Gegenspielers zu bewegen oder ihre eigenen zu schlagen." << endl;
                        }
                    }
                }
            }
        }
    }
    else
    {
        cout << "Ihre Eingabe ist zu klein um zwei Positionen ermitteln zu koennen." << endl;
    }
    cout << "Diese Eingabe ist unguelig. Bitte geben Sie ihren Zug erneut ein." << endl;
    return false;
}
