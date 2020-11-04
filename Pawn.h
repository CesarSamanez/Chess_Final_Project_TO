#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn: public Piece
{
public:
    explicit Pawn(QWidget *parent = nullptr, std::string _color = "");
    std::string GetName() const;
    bool GetStatus() const;
    unsigned GetID() const;
    std::string GetColor() const;
    void MovePiece();
    ~Pawn();
};

#endif // PAWN_H
