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

    int resfil = abs((int)rowInitial - (int)rowFinal); //resta de filas
    int rescol = abs((int)colInitial - (int)colFinal); // resta de columnas

    //Piece *aux = MyBoardMapping[rowFinal][colFinal];
    if(Color.compare("White")==0){
        if(resfil == rescol){
            if(MyBoardMapping[rowFinal][colFinal]!=nullptr){
                if(MyBoardMapping[rowFinal][colFinal]->GetColor().compare(this->GetColor())!=0 ){
                    return Capture(MyBoardMapping, rowInitial, colInitial, rowFinal, colFinal);
                }else{
                    return false;
                }
            }

            //verificar que no se salte otras fichas
           /* for(int i=1;i<resfil;i++){
                aux = MyBoardMapping[rowInitial+i*((rowFinal-rowInitial)/resfil)][colInitial+i*((colFinal-colInitial)/resfil)];
                if(aux!=nullptr){
                    return false;
                }
            }*/
            return true;
        }
    }else if (Color.compare("Black")==0){
        if(resfil == rescol){
            if(MyBoardMapping[rowFinal][colFinal]!=nullptr){
                if(MyBoardMapping[rowFinal][colFinal]->GetColor().compare(this->GetColor())!=0 ){
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

bool Bishop::Capture(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal){
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
    return  false;
}


Bishop::~Bishop() {}
