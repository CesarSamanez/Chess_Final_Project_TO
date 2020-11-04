#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
public:
    explicit King(QWidget *parent = nullptr, std::string _color = "");
    std::string GetName() const;
    bool GetStatus() const;
    unsigned GetID() const;
    std::string GetColor() const;
    void MovePiece();
    ~King();
};

#endif // KING_H
