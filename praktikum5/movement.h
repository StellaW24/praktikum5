#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <iostream>
#include <aufgabe1h.h>

using namespace std;

void movePiece(figure board[8][8], string position);

bool movePawn(string position);

bool moveKnight(string positionS);

bool moveRook(string position);

bool moveBishop(string position);

bool moveQueen(string position);

bool moveKing(string position);

bool checkMove(string position, figure piece, bool turn, figure board[8][8]);

#endif // MOVEMENT_H
