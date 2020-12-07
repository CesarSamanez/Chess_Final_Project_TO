#include "Queen.h"

Queen::Queen(QWidget * parent, const std::string _color): Piece(parent, _color) {
    if (Color.compare("White") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_queen.png");
    } else if (Color.compare("Black") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_queen.png");
    }

    this -> setPixmap(PieceIcon.scaled(QSize(80, 80), Qt::KeepAspectRatio));
}

std::string Queen::GetName() const {
    return "Queen";
}

bool Queen::GetStatus() const {
    return Status;
}

unsigned Queen::GetID() const {
    return ID;
}

void Queen::SetColor(const std::string _color){
    Color = _color;
}

std::string Queen::GetColor() const {
    return Color;
}

void Queen::SetPosition(const int& _row, const int& _col) {
    Row = _row;
    Col = _col;
}

int Queen::GetRow() const {
    return Row;
}

int Queen::GetCol() const {
    return Col;
}

bool Queen::MovePiece(Piece * MyBoardMapping[8][8], const int& rowFinal, const int& colFinal) const{

    /*
     * Queen se mueve como un Alfil
     * Queen se mueve como una Torre
     */

    Piece * tmpRook = new Rook(parentWidget(), GetColor());
    tmpRook -> SetPosition(GetRow(), GetCol());

    Piece * tmpBishop = new Bishop(parentWidget(), GetColor());
    tmpBishop -> SetPosition(GetRow(), GetCol());

    if (tmpRook -> MovePiece(MyBoardMapping, rowFinal, colFinal) ||
            tmpBishop -> MovePiece(MyBoardMapping, rowFinal, colFinal)) {
        return true;
    }
    return false;
}

std::vector<std::pair<int, int> > Queen::PossibleMoves(Piece *MyBoardMapping[8][8]) const{
    std::vector<std::pair<int, int>> movements;

    for(int i=0; i< 8; i++)
        for(int j=0;j<8;j++)
            if(MovePiece(MyBoardMapping, i, j))
                movements.push_back(std::pair(i,j));

    return movements;
}

bool Queen::Capture(Piece * MyBoardMapping[8][8], const int& rowFinal, const int& colFinal) const{
    return (MyBoardMapping[rowFinal][colFinal] != nullptr && (MyBoardMapping[rowFinal][colFinal] -> GetColor().compare(GetColor()) != 0));
}

Queen::~Queen() {}
