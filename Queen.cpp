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
    int resfil = abs((int)rowInitial - (int)rowFinal); //resta de filas
    int rescol = abs((int)colInitial - (int)colFinal); // resta de columnas

    if(Color.compare("White")==0){
        if((resfil==rescol) || (rowInitial==rowFinal)||(colInitial==colFinal)){
            if(MyBoardMapping[rowFinal][colFinal]!=nullptr){ // si hay ficha para comer
                if(MyBoardMapping[rowFinal][colFinal]->GetColor().compare(this->GetColor())!=0){
                    return Capture(MyBoardMapping, rowFinal,colFinal);
                }else{
                    return false;
                }
            }

            //validar movimiento
            return true;
        }
    }else if(Color.compare("Black")==0){
        if((resfil==rescol) || (rowInitial==rowFinal)||(colInitial==colFinal)){
            if(MyBoardMapping[rowFinal][colFinal]!=nullptr){ // si hay ficha para comer
                if(MyBoardMapping[rowFinal][colFinal]->GetColor().compare(this->GetColor())!=0){
                    return Capture(MyBoardMapping, rowFinal,colFinal);
                }else{
                    return false;
                }
            }

            //validar movimiento
            return true;
        }
    }
    return false;
}

bool Queen::Capture(Piece *MyBoardMapping[8][8], unsigned rowFinal, unsigned colFinal){
    if(Color.compare("White")==0){
        if((MyBoardMapping[rowFinal][colFinal]!=nullptr) && (MyBoardMapping[rowFinal][colFinal]->GetColor().compare("Black")==0)){
            return  true;
        }
    }else if (Color.compare("Black")==0){
        if((MyBoardMapping[rowFinal][colFinal]!=nullptr) && (MyBoardMapping[rowFinal][colFinal]->GetColor().compare("White")==0)){
            return  true;
        }
    }
    return false;
}

Queen::~Queen() {}
