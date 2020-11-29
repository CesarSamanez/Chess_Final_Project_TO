#include "King.h"

King::King(QWidget * parent, std::string _color): Piece(parent, _color) {
    if (Color.compare("White") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/white_king.png");
    } else if (Color.compare("Black") == 0) {
        PieceIcon.load("../Chess_Final_Project_TO/Images/black_king.png");
    } else {
        std::cout << "Invalid color" << std::endl;
        return;
    }
    this -> setPixmap(PieceIcon.scaled(QSize(80, 80), Qt::KeepAspectRatio));
}

std::string King::GetName() const {
    return "King";
}

bool King::GetStatus() const {
    return Status;
}

unsigned King::GetID() const {
    return ID;
}

std::string King::GetColor() const {
    return Color;
}

void King::SetPosition(unsigned _row, unsigned _col){
    Row = _row;
    Col = _col;
}

unsigned King::GetRow() const {
    return Row;
}

unsigned King::GetCol() const {
    return Col;
}

bool King::MovePiece(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal) {
    int resFil = abs((int)rowInitial-(int)rowFinal);
    int resCol = abs((int)colInitial-(int)colFinal);

    if(Color.compare("White")==0){
        if((resFil <=1) && (resCol<= 1)){
            if(MyBoardMapping[rowFinal][colFinal]!=nullptr){
                if(MyBoardMapping[rowFinal][colFinal]->GetColor().compare(this->GetColor())!=0){
                    return Capture(MyBoardMapping, rowFinal,colFinal);
                }else{
                    return false;
                }
            }
            //valida movimiento
            return true;
        }
    }else if(Color.compare("Black")==0){
        if((resFil <=1) && (resCol<= 1)){
            if(MyBoardMapping[rowFinal][colFinal]!=nullptr){
                if(MyBoardMapping[rowFinal][colFinal]->GetColor().compare(this->GetColor())!=0){
                    return Capture(MyBoardMapping, rowFinal,colFinal);
                }else{
                    return false;
                }
            }

            //valida movimiento
            return true;
        }
    }
    return false;
}

bool King::Capture(Piece *MyBoardMapping[8][8], unsigned rowFinal, unsigned colFinal){
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

King::~King() {}
