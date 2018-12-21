#ifndef DATATYPES_H
#define DATATYPES_H

struct Figur{
    int player;
    int type;
    bool firstmove;
};

enum Player{
    undef,
    weis,
    schwarz,
};
enum Type{
  Bauer = 1,
  Laeufer,
  Springer,
  Turm,
  Dame,
  Koenig,
};
enum Pos2{
    a,
    b,
    c,
    d,
    e,
    f,
    g,
    h,
    i,
};
//num,char
struct Pos{
    int  pos1;
    Pos2 pos2;
};


#endif // DATATYPES_H
