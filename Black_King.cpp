#include "Black_King.h"

Black_King::Black_King(QWidget *parent) : Piece(parent)
{
    PieceIcon.load("../Chess_Final_Project_TO/Images/black_king.png");
    this->setPixmap(PieceIcon.scaled(QSize(80,80), Qt::KeepAspectRatio));
}
