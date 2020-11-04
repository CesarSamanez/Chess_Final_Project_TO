#include "Queen.h"

Queen::Queen(QWidget *parent, std::string _color) : Piece(parent, _color)
{
    if(Color.compare("White") == 0){
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_queen.png");
    }
    else if(Color.compare("Black") == 0)
    {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_queen.png");
    }
    else
    {
        std::cout<<"Invalid color"<<std::endl;
        return;
    }
    this->setPixmap(PieceIcon.scaled(QSize(80,80), Qt::KeepAspectRatio));
}

std::string Queen::GetName() const
{
    return "Queen";
}

bool Queen::GetStatus() const
{
    return Status;
}

unsigned Queen::GetID() const
{
    return ID;
}

std::string Queen::GetColor() const
{
    return Color;
}

void Queen::MovePiece()
{

}

Queen::~Queen()
{
}
