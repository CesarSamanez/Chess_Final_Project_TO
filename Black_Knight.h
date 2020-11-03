#ifndef BLACK_KNIGHT_H
#define BLACK_KNIGHT_H

#include "Piece.h"

class Black_Knight : public Piece
{
public:
    explicit Black_Knight(QWidget *parent = nullptr);
    void MovePiece() {};
};

#endif // BLACK_KNIGHT_H
