#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop: public Piece {
public:
    explicit Bishop(QWidget * parent = nullptr, std::string _color = "");
    std::string GetName() const;
    bool GetStatus() const;
    unsigned GetID() const;
    std::string GetColor() const;
    void SetPosition(int _row, int _col);
    int GetRow() const;
    int GetCol() const;
    bool MovePiece(Piece *MyBoardMapping[8][8], int rowFinal, int colFinal);
    bool Capture(Piece *MyBoardMapping[8][8], int rowFinal, int colFinal);
    std::vector<std::pair<int,int>> PossibleMoves(Piece *MyBoardMapping[8][8]);
    ~Bishop();
};

#endif // BISHOP_H
