#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook: public Piece {
public:
    explicit Rook(QWidget * parent = nullptr, std::string _color = "");
    std::string GetName() const;
    bool GetStatus() const;
    unsigned GetID() const;
    std::string GetColor() const;
    void SetRow(char _row);
    void SetCol(char _col);
    char GetRow() const;
    char GetCol() const;
    void MovePiece();~Rook();
};

#endif // ROOK_H
