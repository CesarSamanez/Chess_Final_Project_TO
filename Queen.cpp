#include "Queen.h"

Queen::Queen(QWidget * parent, std::string _color): Piece(parent, _color) {
    if (Color.compare("White") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_queen.png");
    } else if (Color.compare("Black") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_queen.png");
    } else {
        std::cout << "Invalid color" << std::endl;
        return;
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

std::string Queen::GetColor() const {
    return Color;
}

void Queen::SetPosition(unsigned _row, unsigned _col){
    Row = _row;
    Col = _col;
}

unsigned Queen::GetRow() const {
    return Row;
}

unsigned Queen::GetCol() const {
    return Col;
}

bool Queen::MovePiece(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal) {
    /*
     * Queen se mueve como un Alfil
     * Queen se mueve como una Torre
     */

    Rook* tmpRook = new Rook(this, GetColor());
    tmpRook->SetPosition(GetRow(), GetCol());

    Bishop* tmpBishop = new Bishop(this, GetColor());
    tmpBishop->SetPosition(GetRow(), GetCol());

    if(tmpRook->MovePiece(MyBoardMapping, rowInitial, colInitial, rowFinal, colFinal) ||
            tmpBishop->MovePiece(MyBoardMapping, rowInitial, colInitial, rowFinal, colFinal)){
        return true;
    }
    return false;
}

bool Queen::Capture(Piece *MyBoardMapping[8][8], unsigned rowFinal, unsigned colFinal){
    if(MyBoardMapping[rowFinal][colFinal]!= nullptr && (MyBoardMapping[rowFinal][colFinal]->GetColor().compare(GetColor())!=0))
        return true;

    return false;
}

Queen::~Queen() {}
