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
    Piece *aux = MyBoardMapping[rowFinal][colFinal];

    auto resFil = rowFinal - rowInitial; //diferencia de filas
    auto resCol = colInitial - colFinal; //diferencia de columnas
    if(Color.compare("White")==0)    {
        if((rowInitial == rowFinal)||(colInitial==colFinal)){
            if(MyBoardMapping[rowFinal][colFinal]!=nullptr){
                if(MyBoardMapping[rowFinal][colFinal]->GetColor().compare(this->GetColor())!=0 ){
                    return Capture(MyBoardMapping, rowInitial, colInitial, rowFinal, colFinal);
                }else{
                    return false;
                }
            }

            //validar movimiento
            /*int diferencia = abs((int)resFil)+abs((int)resCol);
            for(int i=1; i<diferencia;i++ ){
                aux = MyBoardMapping[rowInitial+i*(resFil/diferencia)][colInitial+i*(resCol/diferencia)];
                    std::cout << rowInitial+i*(resFil/diferencia)<< "," <<colInitial+i*(resCol/diferencia)<<std::endl;
                if(aux!= nullptr){
                    return false;
                }
            }*/
            return true;
        }
    }else if(Color.compare("Black")==0){
        if((rowInitial == rowFinal)||(colInitial==colFinal)){
            if(MyBoardMapping[rowFinal][colFinal]!=nullptr){
                if(MyBoardMapping[rowFinal][colFinal]->GetColor().compare(this->GetColor())!=0 ){ // comparar

                    return Capture(MyBoardMapping, rowInitial, colInitial, rowFinal, colFinal);
                }else{
                    return false;
                }
            }
            return true;
        }
    }
return false;
}

bool Rook::Capture(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal){
    //Piece * aux = MyBoardMapping[rowFinal][colFinal];
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

Rook::~Rook() {}
