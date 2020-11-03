#ifndef BLACK_KING_H
#define BLACK_KING_H

#include "Piece.h"

class Black_King : public Piece
{
public:
    explicit Black_King(QWidget *parent = nullptr);
    void MovePiece(){};
};

#endif // BLACK_KING_H
