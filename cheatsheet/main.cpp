#include <iostream>
#include "print.h"
#include "datatypes.h"
#include "check.h"
#include "movecontrol.h"

using namespace std;

int main()
{
    Figur chess[8][8] = {{{0,0,0}}};
    bool Bturn = false;

    Figur WS[8] = {{weis,Turm,1},{weis,Springer,1},{weis,Laeufer,1},{weis,Dame,1},{weis,Koenig,1},{weis,Laeufer,1},{weis,Springer,1},{weis,Turm,1}};
    Figur SS[8] = {{schwarz,Turm,1},{schwarz,Springer,1},{schwarz,Laeufer,1},{schwarz,Dame,1},{schwarz,Koenig,1},{schwarz,Laeufer,1},{schwarz,Springer,1},{schwarz,Turm,1}};
    Figur WB[8];
    Figur SB[8];
    for(int i=0;i<8;i++){
        WB[i] = {weis,Bauer,1};
        SB[i] = {schwarz,Bauer,1};
    }

    memcpy(chess[0],WS, sizeof (WS));
    memcpy(chess[1],WB, sizeof (WB));
    memcpy(chess[6],SB, sizeof (SB));
    memcpy(chess[7],SS, sizeof (SS));



    string inp = "";
    while(inp != "exit")
    {
        printChessArr(chess);

        if(Bturn) cout << "PlayerS (a2-a3):";
        else cout << "PlayerW (a2-a3):";    //A is white
        cin >> inp;
        system("cls");

        if(((int(inp[1])-49 >= 0) && (int(inp[1])-49 <= 7))
            && ((int(inp[4])-49 >= 0) && (int(inp[4])-49 <= 7))
            && ((int(inp[0])-97 >= 0) && (int(inp[0])-97 <= 7))
            && ((int(inp[3])-97 >= 0) && (int(inp[3])-97 <= 7))
            )
        {
            Pos dest = {int(inp[4])-49, Pos2(int(inp[3])-97)};
            Pos from = {int(inp[1])-49, Pos2(int(inp[0])-97)};

            //cout << "from: " << from.pos1 << ":" << from.pos2 << " to:" << dest.pos1 << ":" << dest.pos2 << endl;

            if(istZugGueltig(chess,from,dest,Bturn)){
                if(schlaegtZugFigur(chess,dest,Bturn)){
                    printFigAt(chess,dest);
                    cout << " geschlagen\r\n";
                }
                chess[dest.pos1][dest.pos2] = chess[from.pos1][from.pos2];
                chess[from.pos1][from.pos2] = {0,0,0};
                if(chess[dest.pos1][dest.pos2].firstmove == 1){
                    chess[dest.pos1][dest.pos2].firstmove = 0;
                }
                Bturn = !Bturn;
                if(schach(chess,Bturn)) cout << "SCHACH\r\n";
            }else cout << "Bitte Zug korrigieren\r\n";



        }

    }

    return 0;
}
