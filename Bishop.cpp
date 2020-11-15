#include "Bishop.h"

Bishop::Bishop(QWidget * parent, std::string _color): Piece(parent, _color) {
    if (Color.compare("White") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_bishop.png");
    } else if (Color.compare("Black") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_bishop.png");
    } else {
        std::cout << "Invalid color" << std::endl;
        return;
    }
    this -> setPixmap(PieceIcon.scaled(QSize(80, 80), Qt::KeepAspectRatio));
}

std::string Bishop::GetName() const {
    return "Bishop";
}

bool Bishop::GetStatus() const {
    return Status;
}

unsigned Bishop::GetID() const {
    return ID;
}

void Bishop::SetRow(char _row) {
    row = _row;
}

void Bishop::SetCol(char _col) {
    col = _col;
}

char Bishop::GetRow() const {
    return row;
}

char Bishop::GetCol() const {
    return col;
}

std::string Bishop::GetColor() const {
    return Color;
}

void Bishop::MovePiece() {

}

Bishop::~Bishop() {}
