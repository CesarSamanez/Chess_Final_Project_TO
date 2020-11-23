#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn: public Piece {
public:
    explicit Pawn(QWidget * parent = nullptr, std::string _color = "");
    std::string GetName() const;
    bool GetStatus() const;
    unsigned GetID() const;
    std::string GetColor() const;
    void SetPosition(unsigned _row, unsigned _col);
    unsigned GetRow() const;
    unsigned GetCol() const;
    bool MovePiece(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal);
    bool Capture(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal);
    ~Pawn();
};

#endif // PAWN_H
