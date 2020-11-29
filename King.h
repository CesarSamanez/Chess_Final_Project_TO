#ifndef KING_H
#define KING_H

#include "Piece.h"

class King: public Piece {
public:
    explicit King(QWidget * parent = nullptr, std::string _color = "");
    std::string GetName() const;
    bool GetStatus() const;
    unsigned GetID() const;
    std::string GetColor() const;
    void SetPosition(int _row, int _col);
    int GetRow() const;
    int GetCol() const;
    bool MovePiece(Piece *MyBoardMapping[8][8], int rowFinal, int colFinal);
    bool Capture(Piece *MyBoardMapping[8][8], int rowFinal, int colFinal);
    ~King();
};

#endif // KING_H
