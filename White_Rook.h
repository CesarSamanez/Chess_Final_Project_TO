#ifndef WHITE_ROOK_H
#define WHITE_ROOK_H

#include "Piece.h"

class White_Rook : public Piece
{
public:
    explicit White_Rook(QWidget *parent = nullptr);
    void MovePiece() {};
};

#endif // WHITE_ROOK_H
