#include "Knight.h"

Knight::Knight(QWidget *parent, std::string _color) : Piece(parent, _color)
{
    if(Color.compare("White") == 0){
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_knight.png");
    }
    else if(Color.compare("Black") == 0)
    {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_knight.png");
    }
    else
    {
        std::cout<<"Invalid color"<<std::endl;
        return;
    }
    this->setPixmap(PieceIcon.scaled(QSize(80,80), Qt::KeepAspectRatio));
}

std::string Knight::GetName() const
{
    return "Knight";
}

bool Knight::GetStatus() const
{
    return Status;
}

unsigned Knight::GetID() const
{
    return ID;
}

std::string Knight::GetColor() const
{
    return Color;
}

void Knight::MovePiece()
{

}

Knight::~Knight()
{
}
