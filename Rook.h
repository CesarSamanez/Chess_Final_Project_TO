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
    void SetPosition(unsigned _row, unsigned _col);
    unsigned GetRow() const;
    unsigned GetCol() const;
    bool MovePiece(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal);
    bool Capture(Piece *MyBoardMapping[8][8], unsigned rowFinal, unsigned colFinal);
    ~Rook();
};

#endif // ROOK_H
