#ifndef AUFGABE1H_H
#define AUFGABE1H_H

#include <iostream>

using namespace :: std;

static bool inputError = false;

struct figure
{
    int colour;
    string type;
    char contraction;
};

string player(string one, string two, bool turn);

string adapt(figure fig);

void createBoard(figure board[8][8]);

string to(string position);

string from(string position);

int getCol(string position);

int getRow(string position);

string getPiece(string position, figure board[8][8]);

int getColor(string position, figure board[8][8]);

bool inputCheck(string position, bool turn, figure board[8][8]);

#endif // AUFGABE1H_H
