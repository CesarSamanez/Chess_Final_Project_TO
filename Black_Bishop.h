#ifndef BLACK_BISHOP_H
#define BLACK_BISHOP_H

#include "Piece.h"

class Black_Bishop : public Piece
{
public:
    explicit Black_Bishop(QWidget *parent = nullptr);
    void MovePiece() {};
};

#endif // BLACK_BISHOP_H
