#include "Black_Knight.h"

Black_Knight::Black_Knight(QWidget *parent) : Piece(parent)
{
    PieceIcon.load("../Chess_Final_Project_TO/Images/black_knight.png");
    this->setPixmap(PieceIcon.scaled(QSize(80,80), Qt::KeepAspectRatio));
}
