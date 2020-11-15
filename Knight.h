#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight: public Piece {
public:
    explicit Knight(QWidget * parent = nullptr, std::string _color = "");
    std::string GetName() const;
    bool GetStatus() const;
    unsigned GetID() const;
    std::string GetColor() const;
    void SetRow(char _row);
    void SetCol(char _col);
    char GetRow() const;
    char GetCol() const;
    void MovePiece();~Knight();
};

#endif // KNIGHT_H
