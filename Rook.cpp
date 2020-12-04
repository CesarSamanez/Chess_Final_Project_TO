#include "Rook.h"

Rook::Rook(QWidget * parent, const std::string _color): Piece(parent, _color) {
    if (Color.compare("White") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_rook.png");
    } else if (Color.compare("Black") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_rook.png");
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

void Rook::SetPosition(const int& _row, const int& _col) {
    Row = _row;
    Col = _col;
}

int Rook::GetRow() const {
    return Row;
}

int Rook::GetCol() const {
    return Col;
}

bool Rook::MovePiece(Piece * MyBoardMapping[8][8], const int& rowFinal, const int& colFinal) const{
    Piece * tmp = MyBoardMapping[rowFinal][colFinal];

    int rowDifference = rowFinal - GetRow(); //diferencia de filas
    int colDifference = colFinal - GetCol(); //diferencia de columnas

    if ((GetRow() == rowFinal) || (GetCol() == colFinal)) {
        if (tmp != nullptr) {
            if (tmp -> GetColor().compare(GetColor()) == 0) {
                return false;
            }
        }
        /*
         * Validación de movimiento, evitar que salte alguna ficha
         */
        int diferencia = abs(rowDifference) + abs(colDifference);
        for (int i = 1; i < diferencia; i++) {
            tmp = MyBoardMapping[GetRow() + i * (rowDifference / diferencia)][GetCol() + i * (colDifference / diferencia)];
            if (tmp != nullptr) {
                return false;
            }
        }
        return true;
    } else
        return false;
}

std::vector<std::pair<int, int> > Rook::PossibleMoves(Piece *MyBoardMapping[8][8]) const{
    std::vector<std::pair<int, int>> movements;

    for(int i=0; i< 8; i++)
        for(int j=0;j<8;j++)
            if(MovePiece(MyBoardMapping, i, j))
                movements.push_back(std::pair(i,j));

    return movements;
}

bool Rook::Capture(Piece * MyBoardMapping[8][8], const int& rowFinal, const int& colFinal) const{
    return (MyBoardMapping[rowFinal][colFinal] != nullptr && (MyBoardMapping[rowFinal][colFinal] -> GetColor().compare(GetColor()) != 0));
}

Rook::~Rook() {}
