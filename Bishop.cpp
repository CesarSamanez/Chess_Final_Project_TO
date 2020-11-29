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

void Bishop::SetPosition(unsigned _row, unsigned _col){
    Row = _row;
    Col = _col;
}

unsigned Bishop::GetRow() const {
    return Row;
}

unsigned Bishop::GetCol() const {
    return Col;
}

std::string Bishop::GetColor() const {
    return Color;
}


bool Bishop::MovePiece(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal) {

    int rowDifference, colDifference;
    Piece* tmp = MyBoardMapping[rowFinal][colFinal];

    rowDifference = abs(static_cast<int>(rowInitial - rowFinal));
    colDifference = abs(static_cast<int>(colInitial - colFinal));

    if(rowDifference == colDifference){
        if(tmp != nullptr)
            if(tmp->GetColor().compare(GetColor()) == 0)
                return false;

        /*
         * Desbordamiento de memoria error -> indice incorrecto
         */
        /*
        for(int i=1; i<rowDifference; i++){
            tmp = MyBoardMapping[GetRow() + i * ((rowFinal - GetRow())/rowDifference)][GetCol() + i * ((colFinal - GetCol())/rowDifference)];
            if(tmp != nullptr)
                return false;
        }
        */

    }

    return false;
}

bool Bishop::Capture(Piece *MyBoardMapping[8][8],  unsigned rowFinal, unsigned colFinal){
    if(MyBoardMapping[rowFinal][colFinal]!= nullptr && (MyBoardMapping[rowFinal][colFinal]->GetColor().compare(GetColor())!=0))
        return true;

    return  false;
}


Bishop::~Bishop() {}
