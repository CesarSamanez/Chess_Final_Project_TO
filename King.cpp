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

void King::SetPosition(int _row, int _col) {
    Row = _row;
    Col = _col;
}

int King::GetRow() const {
    return Row;
}

int King::GetCol() const {
    return Col;
}

bool King::MovePiece(Piece * MyBoardMapping[8][8], int rowFinal, int colFinal) {
    Piece * tmp = MyBoardMapping[rowFinal][colFinal];

    int rowDifference = abs(GetRow() - rowFinal);
    int colDifference = abs(GetCol() - colFinal);

    if (abs(rowDifference) <= 1 && abs(colDifference) <= 1) {
        if (tmp != nullptr)
            if (tmp -> GetColor().compare(GetColor()) == 0)
                return false;
        return true;
    } else {
        return false;
    }
}

bool King::Capture(Piece * MyBoardMapping[8][8], int rowFinal, int colFinal) {
    return (MyBoardMapping[rowFinal][colFinal] != nullptr && (MyBoardMapping[rowFinal][colFinal] -> GetColor().compare(GetColor()) != 0));
}

King::~King() {}
