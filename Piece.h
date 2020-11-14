#ifndef PIECE_H
#define PIECE_H

#include <QLabel>
#include <QPixmap>
#include <iostream>
#include <string>

namespace Ui {
class Piece;
}

class Piece : public QLabel
{
    Q_OBJECT

protected:
    Ui::Piece *ui;

    unsigned ID;
    std::string Color;
    bool Status;
    QPixmap PieceIcon;

public:
    /* Constructor explicito */
    explicit Piece(QWidget *parent = nullptr, std::string _color = "");

    virtual std::string GetName() const = 0;
    virtual bool GetStatus() const = 0;
    virtual unsigned GetID() const = 0;
    virtual std::string GetColor() const = 0;
    virtual void MovePiece()=0;
    virtual ~Piece(){};
};

#endif // PIECE_H
