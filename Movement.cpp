#include "Movement.h"

Movement::Movement(Piece * _piece, int _row, int _col)
{
    piece = _piece;
    row = _row;
    col = _col;
}

Piece* Movement::GetPiece(){
    return piece;
}

int Movement::GetRow(){
    return row;
}

int Movement::GetCol(){
    return col;
}

std::string Movement::toString(){
    return "["+std::to_string(GetRow())+","+std::to_string(GetCol())+"]";
}
