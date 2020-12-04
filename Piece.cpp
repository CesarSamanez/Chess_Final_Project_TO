#include "Piece.h"

Piece::Piece(QWidget * parent, const std::string _color): QLabel(parent) {
    Color = _color;
}
