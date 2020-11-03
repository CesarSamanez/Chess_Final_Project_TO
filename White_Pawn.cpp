#include "White_Pawn.h"

White_Pawn::White_Pawn(QWidget *parent) : Piece(parent)
{
    PieceIcon.load("../Chess_Final_Project_TO/Images/white_pawn.png");
    this->setPixmap(PieceIcon.scaled(QSize(80,80), Qt::KeepAspectRatio));
}
