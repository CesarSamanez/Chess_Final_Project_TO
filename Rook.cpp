#include "Rook.h"

Rook::Rook(QWidget * parent, std::string _color): Piece(parent, _color) {
    if (Color.compare("White") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_rook.png");
    } else if (Color.compare("Black") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_rook.png");
    } else {
        std::cout << "Invalid color" << std::endl;
        return;
    }
    this -> setPixmap(PieceIcon.scaled(QSize(80, 80), Qt::KeepAspectRatio));
}

std::string Rook::GetName() const {
    return "Rook";
}

bool Rook::GetStatus() const {
    return Status;
}

unsigned Rook::GetID() const {
    return ID;
}

std::string Rook::GetColor() const {
    return Color;
}

void Rook::SetRow(char _row) {
    row = _row;
}

void Rook::SetCol(char _col) {
    col = _col;
}

char Rook::GetRow() const {
    return row;
}

char Rook::GetCol() const {
    return col;
}

void Rook::MovePiece() {

}

Rook::~Rook() {}
