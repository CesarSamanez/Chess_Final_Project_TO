#include "Pawn.h"

Pawn::Pawn(QWidget *parent, std::string _color) : Piece(parent, _color)
{
    if(Color.compare("White") == 0){
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_pawn.png");
    }
    else if(Color.compare("Black") == 0)
    {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_pawn.png");
    }
    else
    {
        std::cout<<"Invalid color"<<std::endl;
        return;
    }
    this->setPixmap(PieceIcon.scaled(QSize(80,80), Qt::KeepAspectRatio));
}

std::string Pawn::GetName() const
{
    return "Pawn";
}

bool Pawn::GetStatus() const
{
    return Status;
}

unsigned Pawn::GetID() const
{
    return ID;
}

std::string Pawn::GetColor() const
{
    return Color;
}

void Pawn::MovePiece()
{

}

Pawn::~Pawn()
{
}
