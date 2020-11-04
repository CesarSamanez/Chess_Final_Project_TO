#include "Piece.h"

Piece::Piece(QWidget *parent, std::string _color) : QLabel(parent)
{
    Color = _color;
}
