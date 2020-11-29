#include "Rook.h"

Rook::Rook(QWidget * parent, std::string _color): Piece(parent, _color) {
    if (Color.compare("White") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_rook.png");
    } else if (Color.compare("Black") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_rook.png");
    } else {
        std::cout << "Invalid color" << std::endl;
        return;
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

void Rook::SetPosition(unsigned _row, unsigned _col){
    Row = _row;
    Col = _col;
}

unsigned Rook::GetRow() const {
    return Row;
}

unsigned Rook::GetCol() const {
    return Col;
}

bool Rook::MovePiece(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal) {
    int rowDifference = rowFinal - rowInitial; //diferencia de filas
    int colDifference = colFinal - colInitial; //diferencia de columnas

    if((rowInitial == rowFinal)||(colInitial==colFinal)){
        if(MyBoardMapping[rowFinal][colFinal]!=nullptr){
            if(MyBoardMapping[rowFinal][colFinal]->GetColor().compare(GetColor())==0 ){
                return false;
            }
        }
        /*
         * Validación de movimiento, evitar que salte alguna ficha
         */
        int diferencia = abs(rowDifference)+abs(colDifference);
        for(int i=1; i<diferencia;i++ ){
            Piece* pivot = MyBoardMapping[rowInitial+i*(rowDifference/diferencia)][colInitial+i*(colDifference/diferencia)];
            if(pivot != nullptr){
                return false;
            }
        }
        return true;
    }
    else
        return false;
}

bool Rook::Capture(Piece *MyBoardMapping[8][8], unsigned rowFinal, unsigned colFinal){
    if(MyBoardMapping[rowFinal][colFinal]!= nullptr && (MyBoardMapping[rowFinal][colFinal]->GetColor().compare(GetColor())!=0))
        return true;

    return false;
}

Rook::~Rook() {}
