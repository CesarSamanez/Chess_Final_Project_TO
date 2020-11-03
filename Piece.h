#ifndef PIECE_H
#define PIECE_H

#include <QLabel>
#include <QPixmap>


namespace Ui {
class Piece;
}

class Piece : public QLabel
{
    /* Macro para utilizar las cosas de QT */
    Q_OBJECT

public:
    /* Constructor explicito */
    explicit Piece(QWidget *parent = nullptr);
    virtual void MovePiece()=0;
    virtual ~Piece(){};

protected:
    Ui::Piece *ui;

    QPixmap PieceIcon;

};

#endif // PIECE_H
