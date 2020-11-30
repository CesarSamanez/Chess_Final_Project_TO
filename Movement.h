#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Piece.h"

class Movement
{
private:
    Piece* piece;
    int row, col;
public:
    Movement() = delete;
    explicit Movement(Piece * _piece, int _row, int _col);
    Piece* GetPiece();
    int GetRow();
    int GetCol();
    std::string toString();

};

#endif // MOVEMENT_H
