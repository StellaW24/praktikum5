#include <iostream>
#include "p5.h"

using namespace std;


//main funktion
int main()
{
    //erstellung des arrays
    Figur chess[8][8] = {{{0,0,0}}};
    bool Bturn = false;

    Figur WS[8] = {{weis,Turm,1},
                   {weis,Springer,1},
                   {weis,Laeufer,1},
                   {weis,Dame,1},
                   {weis,Koenig,1},
                   {weis,Laeufer,1},
                   {weis,Springer,1},
                   {weis,Turm,1}};

    Figur SS[8] = {{schwarz,Turm,1},
                   {schwarz,Springer,1},
                   {schwarz,Laeufer,1},
                   {schwarz,Dame,1},
                   {schwarz,Koenig,1},
                   {schwarz,Laeufer,1},
                   {schwarz,Springer,1},
                   {schwarz,Turm,1}};
    Figur WB[8];
    Figur SB[8];
    for(int i=0;i<8;i++){
        WB[i] = {weis,Bauer,1};
        SB[i] = {schwarz,Bauer,1};
    }

    //kopierung des Speichers
    memcpy(chess[0],WS, sizeof (WS));
    memcpy(chess[1],WB, sizeof (WB));
    memcpy(chess[6],SB, sizeof (SB));
    memcpy(chess[7],SS, sizeof (SS));


    //eingabe und auswertung der selbigen
    string inp = "";
    while(inp != "exit")
    {
        ausgabeSpielbrett(chess);
        //spieler A ist weiß, spieler B ist schwarz
        if(Bturn) cout << "PlayerS (a2-a3):";
        else cout << "PlayerW (a2-a3):";
        cin >> inp;
        system("cls");
        //erkennung der zeichen über ASCII
        if(((int(inp[1])-49 >= 0) && (int(inp[1])-49 <= 7))
            && ((int(inp[4])-49 >= 0) && (int(inp[4])-49 <= 7))
            && ((int(inp[0])-97 >= 0) && (int(inp[0])-97 <= 7))
            && ((int(inp[3])-97 >= 0) && (int(inp[3])-97 <= 7))
            )
        {
            //erkennung des zielortes und dem ort von dem die Figur kam
            Pos zielort = {int(inp[4])-49, Pos2(int(inp[3])-97)};
            Pos from = {int(inp[1])-49, Pos2(int(inp[0])-97)};

            //cout << "from: " << from.pos1 << ":" << from.pos2 << " to:" << dest.pos1 << ":" << dest.pos2 << endl;
            //verschiedene Funktionaufrufe
            if(istZugGueltig(chess,from,zielort,Bturn)){
                if(schlaegtZugFigur(chess,zielort,Bturn)){
                    ausgabeFiguren(chess,zielort);
                    cout << " geschlagen\r\n";
                }
                chess[zielort.pos1][zielort.pos2] = chess[from.pos1][from.pos2];
                chess[from.pos1][from.pos2] = {0,0,0};
                if(chess[zielort.pos1][zielort.pos2].firstmove == 1){
                    chess[zielort.pos1][zielort.pos2].firstmove = 0;
                }
                Bturn = !Bturn;
                if(schach(chess,Bturn)) cout << "SCHACH\r\n";
            }else cout << "Bitte Zug korrigieren\r\n";
        }

    }

    return 0;
}
