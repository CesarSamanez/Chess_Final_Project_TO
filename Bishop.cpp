#include "Bishop.h"

Bishop::Bishop(QWidget * parent, const std::string _color): Piece(parent, _color) {
    if (Color.compare("White") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_bishop.png");
    } else if (Color.compare("Black") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_bishop.png");
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

void Bishop::SetPosition(const int& _row, const int& _col) {
    Row = _row;
    Col = _col;
}

int Bishop::GetRow() const {
    return Row;
}

int Bishop::GetCol() const {
    return Col;
}

void Bishop::SetColor(const std::string _color){
    Color = _color;
}

std::string Bishop::GetColor() const {
    return Color;
}

bool Bishop::MovePiece(Piece * MyBoardMapping[8][8], const int& rowFinal, const int& colFinal) const {
    Piece * tmp = MyBoardMapping[rowFinal][colFinal];

    int rowDifference = abs(GetRow() - rowFinal);
    int colDifference = abs(GetCol() - colFinal);

    if (rowDifference == colDifference) {
        if (tmp != nullptr)
            if (tmp -> GetColor().compare(GetColor()) == 0)
                return false;

        for (int i = 1; i < rowDifference; i++) {
            tmp = MyBoardMapping[GetRow() + i * ((rowFinal - GetRow()) / rowDifference)][GetCol() + i * ((colFinal - GetCol()) / rowDifference)];
            if (tmp != nullptr)
                return false;
        }
        return true;
    } else
        return false;
}

bool Bishop::Capture(Piece * MyBoardMapping[8][8], const int& rowFinal, const int& colFinal) const{
    return (MyBoardMapping[rowFinal][colFinal] != nullptr && (MyBoardMapping[rowFinal][colFinal] -> GetColor().compare(GetColor()) != 0));
}

std::vector<std::pair<int, int> > Bishop::PossibleMoves(Piece *MyBoardMapping[8][8]) const{
    std::vector<std::pair<int, int>> movements;

    for(int i=0; i< 8; i++)
        for(int j=0;j<8;j++)
            if(MovePiece(MyBoardMapping, i, j))
                movements.push_back(std::pair(i,j));

    return movements;
}


Bishop::~Bishop() {}
