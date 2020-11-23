#include "King.h"

King::King(QWidget * parent, std::string _color): Piece(parent, _color) {
    if (Color.compare("White") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_king.png");
    } else if (Color.compare("Black") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_king.png");
    } else {
        std::cout << "Invalid color" << std::endl;
        return;
    }
    this -> setPixmap(PieceIcon.scaled(QSize(80, 80), Qt::KeepAspectRatio));
}

std::string King::GetName() const {
    return "King";
}

bool King::GetStatus() const {
    return Status;
}

unsigned King::GetID() const {
    return ID;
}

std::string King::GetColor() const {
    return Color;
}

void King::SetPosition(unsigned _row, unsigned _col){
    Row = _row;
    Col = _col;
}

unsigned King::GetRow() const {
    return Row;
}

unsigned King::GetCol() const {
    return Col;
}

bool King::MovePiece(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal) {
return false;
}

bool King::Capture(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal){
    return false;
}

King::~King() {}
