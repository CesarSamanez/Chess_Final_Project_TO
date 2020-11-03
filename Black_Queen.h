#ifndef BLACK_QUEEN_H
#define BLACK_QUEEN_H

#include "Piece.h"

class Black_Queen : public Piece
{
public:
    explicit Black_Queen(QWidget *parent = nullptr);
    void MovePiece(){};
};

#endif // BLACK_QUEEN_H
