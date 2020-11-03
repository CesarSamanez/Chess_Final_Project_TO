#ifndef WHITE_KNIGHT_H
#define WHITE_KNIGHT_H

#include "Piece.h"

class White_Knight : public Piece
{
public:
    explicit White_Knight(QWidget *parent = nullptr);
    void MovePiece(){};
};

#endif // WHITE_KNIGHT_H
