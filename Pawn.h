#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn: public Piece {
public:
    explicit Pawn(QWidget * parent = nullptr, const std::string _color = "");
    std::string GetName() const;
    bool GetStatus() const;
    unsigned GetID() const;
    std::string GetColor() const;
    void SetPosition(const int& _row, const int& _col);
    int GetRow() const;
    int GetCol() const;
    bool MovePiece(Piece *MyBoardMapping[8][8], const int& rowFinal, const int& colFinal) const;
    bool Capture(Piece *MyBoardMapping[8][8], const int& rowFinal, const int& colFinal) const;
    std::vector<std::pair<int,int>> PossibleMoves(Piece *MyBoardMapping[8][8]) const;
    ~Pawn();
};

#endif // PAWN_H
