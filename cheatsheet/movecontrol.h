#ifndef MOVECONTROL_H
#define MOVECONTROL_H

#include "datatypes.h"
#include "check.h"
#include <iostream>

using namespace::std;

bool istZugGueltig(Figur arr[8][8],Pos from,Pos dest,bool Bturn);
bool schlaegtZugFigur(Figur arr[8][8], Pos dest, bool Bturn);

#endif // MOVECONTROL_H
