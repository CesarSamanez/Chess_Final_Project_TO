#ifndef WHITE_PAWN_H
#define WHITE_PAWN_H

#include "Piece.h"

class White_Pawn : public Piece
{
public:
    explicit White_Pawn(QWidget *parent = nullptr);
    void MovePiece(){};
};

#endif // WHITE_PAWN_H
