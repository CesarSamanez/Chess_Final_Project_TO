#ifndef WHITE_QUEEN_H
#define WHITE_QUEEN_H

#include "Piece.h"

class White_Queen : public Piece
{
public:
    explicit White_Queen(QWidget *parent = nullptr);
    void MovePiece(){};
};

#endif // WHITE_QUEEN_H
