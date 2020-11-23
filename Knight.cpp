#include "Knight.h"

Knight::Knight(QWidget * parent, std::string _color): Piece(parent, _color) {
    if (Color.compare("White") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_knight.png");
    } else if (Color.compare("Black") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_knight.png");
    } else {
        std::cout << "Invalid color" << std::endl;
        return;
    }
    this -> setPixmap(PieceIcon.scaled(QSize(80, 80), Qt::KeepAspectRatio));
}

std::string Knight::GetName() const {
    return "Knight";
}

bool Knight::GetStatus() const {
    return Status;
}

unsigned Knight::GetID() const {
    return ID;
}

std::string Knight::GetColor() const {
    return Color;
}

void Knight::SetPosition(unsigned _row, unsigned _col){
    Row = _row;
    Col = _col;
}

unsigned Knight::GetRow() const {
    return Row;
}

unsigned Knight::GetCol() const {
    return Col;
}

bool Knight::MovePiece(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal) {
return false;
}

bool Knight::Capture(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal){
  return false;
}

Knight::~Knight() {}
