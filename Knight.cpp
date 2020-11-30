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

void Knight::SetPosition(int _row, int _col) {
    Row = _row;
    Col = _col;
}

int Knight::GetRow() const {
    return Row;
}

int Knight::GetCol() const {
    return Col;
}

bool Knight::MovePiece(Piece * MyBoardMapping[8][8], int rowFinal, int colFinal) {
    Piece * tmp = MyBoardMapping[rowFinal][colFinal];
    int rowDifference = GetRow() - rowFinal;
    int colDifference = GetCol() - colFinal;

    if (((abs(rowDifference) == 1) && (abs(colDifference) == 2)) || ((abs(rowDifference) == 2) && (abs(colDifference) == 1))) {
        if (tmp != nullptr)
            if (tmp -> GetColor().compare(GetColor()) == 0)
                return false;
        return true;
    } else {
        return false;
    }
}

std::vector<std::pair<int, int> > Knight::PossibleMoves(Piece *MyBoardMapping[8][8]){
    std::vector<std::pair<int, int>> movements;

    for(int i=0; i< 8; i++)
        for(int j=0;j<8;j++)
            if(MovePiece(MyBoardMapping, i, j))
                movements.push_back(std::pair(i,j));

    return movements;
}

bool Knight::Capture(Piece * MyBoardMapping[8][8], int rowFinal, int colFinal) {
    return (MyBoardMapping[rowFinal][colFinal] != nullptr && (MyBoardMapping[rowFinal][colFinal] -> GetColor().compare(GetColor()) != 0));
}

Knight::~Knight() {}
