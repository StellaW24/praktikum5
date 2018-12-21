#include <iostream>
#include <aufgabe1h.h>
#include <movement.h>

using namespace std;

int main()
{
        string input = "";
        string nameOne;
        string nameTwo;
        bool turn = true;
        figure board[8][8];
        createBoard(board);

        //player naming process
        cout << "Geben sie den Namen des ersten Spielers ein:" << endl;
        cin >> nameOne;
        cout << endl;
        cout << "Geben sie den Namen des zweiten Spielers ein:" << endl;
        cin >> nameTwo;
        cout << endl;

        //Turn loop; ends with entering exit
        while(input != "exit")
        {
            cout << player(nameOne, nameTwo, turn) << " du bist am Zug." << endl;
            cout << "Bitte Zug eingeben (z.B. b1-c3)" << endl << "Zum Abbruch geben sie exit ein." << endl;
            cin >> input;

            //checking if the input does display a move
            cout << getPiece(input, board) << endl;
            if(input == "exit")
            {
                break;
            }
            if(inputCheck(input, turn, board) == true)
            {
                //making a move, displaying the new board
                movePiece(board, input);

                //changing players
                turn = !turn;
            }
            cin.clear();
            cin.ignore();
        }
        return 0;
}
