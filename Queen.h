#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen: public Piece {
public:
    explicit Queen(QWidget * parent = nullptr, std::string _color = "");
    std::string GetName() const;
    bool GetStatus() const;
    unsigned GetID() const;
    std::string GetColor() const;
    void SetRow(char _row);
    void SetCol(char _col);
    char GetRow() const;
    char GetCol() const;
    void MovePiece();~Queen();
};

#endif // QUEEN_H
