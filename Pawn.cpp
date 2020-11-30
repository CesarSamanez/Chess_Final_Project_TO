#include "Pawn.h"

Pawn::Pawn(QWidget * parent, std::string _color): Piece(parent, _color) {
    if (Color.compare("White") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_pawn.png");
    } else if (Color.compare("Black") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_pawn.png");
    } else {
        std::cout << "Invalid color" << std::endl;
        return;
    }
    this -> setPixmap(PieceIcon.scaled(QSize(80, 80), Qt::KeepAspectRatio));
}

std::string Pawn::GetName() const {
    return "Pawn";
}

bool Pawn::GetStatus() const {
    return Status;
}

unsigned Pawn::GetID() const {
    return ID;
}

std::string Pawn::GetColor() const {
    return Color;
}

void Pawn::SetPosition(int _row, int _col) {
    Row = _row;
    Col = _col;
}

int Pawn::GetRow() const {
    return Row;
}

int Pawn::GetCol() const {
    return Col;
}

bool Pawn::MovePiece(Piece * MyBoardMapping[8][8], int rowFinal, int colFinal) {

    /*
     * Falta considerar promoción de piezas
     */

    Piece * tmp = MyBoardMapping[rowFinal][colFinal];

    int increment = (GetColor().compare("White") == 0) ? -1 : 1;
    int rowTmp = (GetColor().compare("White") == 0) ? 6 : 1;

    // Movimiento normal de peones
    if ((GetCol() == colFinal) && (GetRow() + increment == rowFinal)) {
        if (tmp != nullptr)
            return false;
        return true;
        //Movimiento inicial de peones
    } else if ((GetCol() == colFinal) && (GetRow() == rowTmp) && (rowFinal == (rowTmp + 2 * increment))) {
        if (tmp != nullptr)
            return false;
        tmp = MyBoardMapping[GetRow() + increment][GetCol()];
        if (tmp != nullptr)
            return false;
        return true;
        //Movimiento de captura
    } else if (((colFinal == GetCol() + 1) || (colFinal == GetCol() - 1)) && (rowFinal == GetRow() + increment)) {
        // No hay nada que comer
        if (tmp == nullptr)
            return false;
        //No es ficha rival
        if (tmp -> GetColor().compare(GetColor()) == 0)
            return false;
        return true;
    }
    return false;

}

std::vector<std::pair<int, int> > Pawn::PossibleMoves(Piece *MyBoardMapping[8][8]){
    std::vector<std::pair<int, int>> movements;

    for(int i=0; i< 8; i++)
        for(int j=0;j<8;j++)
            if(MovePiece(MyBoardMapping, i, j))
                movements.push_back(std::pair(i,j));

    return movements;
}

bool Pawn::Capture(Piece * MyBoardMapping[8][8], int rowFinal, int colFinal) {
    return (MyBoardMapping[rowFinal][colFinal] != nullptr && (MyBoardMapping[rowFinal][colFinal] -> GetColor().compare(GetColor()) != 0));
}

Pawn::~Pawn() {}
