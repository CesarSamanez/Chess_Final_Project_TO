#include "White_Queen.h"

White_Queen::White_Queen(QWidget *parent) : Piece(parent)
{
    PieceIcon.load("../Chess_Final_Project_TO/Images/white_queen.png");
    this->setPixmap(PieceIcon.scaled(QSize(80,80), Qt::KeepAspectRatio));
}
