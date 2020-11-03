#ifndef WHITE_KING_H
#define WHITE_KING_H

#include "Piece.h"

class White_King : public Piece
{
public:
    explicit White_King(QWidget *parent = nullptr);
    void MovePiece() {};
};

#endif // WHITE_KING_H
