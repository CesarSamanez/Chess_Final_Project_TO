#ifndef BLACK_PAWN_H
#define BLACK_PAWN_H

#include "Piece.h"

class Black_Pawn : public Piece
{
public:
    explicit Black_Pawn(QWidget *parent = nullptr);
    void MovePiece() {};
};

#endif // BLACK_PAWN_H
