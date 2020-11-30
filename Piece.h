#ifndef PIECE_H
#define PIECE_H

#include <QLabel>
#include <QPixmap>
#include <iostream>
#include <cmath>
#include <vector>

class Piece: public QLabel {
    Q_OBJECT

protected:
    Piece * ui;

    unsigned ID;
    std::string Color;
    bool Status;
    QPixmap PieceIcon;
    int Row, Col;

public:
    /* Constructor explicito */
    explicit Piece(QWidget * parent = nullptr, std::string _color = "");

    virtual std::string GetName() const = 0;
    virtual bool GetStatus() const = 0;
    virtual unsigned GetID() const = 0;
    virtual std::string GetColor() const = 0;
    virtual bool MovePiece(Piece *MyBoardMapping[8][8], int rowFinal, int colFinal) = 0;
    virtual bool Capture(Piece *MyBoardMapping[8][8], int rowFinal, int colFinal) = 0;
    virtual std::vector<std::pair<int,int>> PossibleMoves(Piece *MyBoardMapping[8][8]) = 0;
    virtual void SetPosition(int _row, int _col) = 0;
    virtual int GetRow() const = 0;
    virtual int GetCol() const = 0;
    virtual~Piece() {};
};

#endif // PIECE_H
