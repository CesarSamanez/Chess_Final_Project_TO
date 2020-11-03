#include "White_Knight.h"

White_Knight::White_Knight(QWidget *parent) : Piece(parent)
{
    PieceIcon.load("../Chess_Final_Project_TO/Images/white_knight.png");
    this->setPixmap(PieceIcon.scaled(QSize(80,80), Qt::KeepAspectRatio));
}
