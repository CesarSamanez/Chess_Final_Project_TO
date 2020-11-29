#ifndef PIECE_H
#define PIECE_H

#include <QLabel>
#include <QPixmap>
#include <iostream>
#include <cmath>

namespace Ui {
class Piece;
}

class Piece: public QLabel {
    Q_OBJECT

protected:
    Ui::Piece * ui;

    unsigned ID;
    std::string Color;
    bool Status;
    QPixmap PieceIcon;
    unsigned Row, Col;

public:
    /* Constructor explicito */
    explicit Piece(QWidget * parent = nullptr, std::string _color = "");

    virtual std::string GetName() const = 0;
    virtual bool GetStatus() const = 0;
    virtual unsigned GetID() const = 0;
    virtual std::string GetColor() const = 0;
    virtual bool MovePiece(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal) = 0;
    virtual bool Capture(Piece *MyBoardMapping[8][8], unsigned rowFinal, unsigned colFinal) = 0;
    virtual void SetPosition(unsigned _row, unsigned _col) = 0;
    virtual unsigned GetRow() const = 0;
    virtual unsigned GetCol() const = 0;
    virtual~Piece() {};
};

#endif // PIECE_H
