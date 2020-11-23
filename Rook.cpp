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

void Rook::SetPosition(unsigned _row, unsigned _col){
    Row = _row;
    Col = _col;
}

unsigned Rook::GetRow() const {
    return Row;
}

unsigned Rook::GetCol() const {
    return Col;
}

bool Rook::MovePiece(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal) {
return false;
}

bool Rook::Capture(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal){
return false;
}

Rook::~Rook() {}
