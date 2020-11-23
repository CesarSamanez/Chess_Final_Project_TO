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

void Pawn::SetPosition(unsigned _row, unsigned _col){
    Row = _row;
    Col = _col;
}

unsigned Pawn::GetRow() const {
    return Row;
}

unsigned Pawn::GetCol() const {
    return Col;
}

bool Pawn::MovePiece(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal) {
    if(Color.compare("White") == 0){
        if(rowFinal != 0){
            if(colInitial == colFinal){
                /* Movimiento de peon - Avanzar 2 posiciones en la primera jugada */
                if((rowInitial == 6) && (rowInitial - rowFinal == 2))
                    return true;

                /* Movimiento de abajo hacia en frente */
                if(((rowInitial - rowFinal)==1))
                    return true;
            }

            if(colInitial != colFinal){
                if(rowFinal == (rowInitial - 1)){
                    // =======================================================================
                    /* Captura de peon */
                    if((colInitial!=0) && (colInitial!=7)){
                        if((colFinal == colInitial +1) || (colFinal == colInitial - 1))
                            return Capture(MyBoardMapping, rowInitial, colInitial, rowFinal, colFinal);
                    }

                    /* Movimiento hacia la derecha */
                    if((colInitial == 0) && (colFinal == colInitial + 1)){
                        return Capture(MyBoardMapping, rowInitial, colInitial, rowFinal, colFinal);
                    }

                    /* Movimiento hacia la izquierda */
                    if((colInitial == 7) && (colFinal == colInitial - 1)){
                        return Capture(MyBoardMapping, rowInitial, colInitial, rowFinal, colFinal);
                    }
                }
            }
        }else{
            /* Condiciones de promocion de pieza */
            std::cout<<"Promoción de pieza peon Blanca\n"<<std::endl;
        }

    }else if(Color.compare("Black") == 0){
        if(rowFinal != 7){
            if(colInitial == colFinal){
                /* Movimiento de peon - Avanzar 2 posiciones en la primera jugada */
                if((rowInitial == 1) && (rowFinal - rowInitial == 2))
                    return true;

                /* Movimiento de frente hacia abajo */
                if(((rowFinal - rowInitial)==1))
                    return true;
            }
            if(colInitial != colFinal){
                if(rowInitial == (rowFinal-1)){
                    /* Captura de peon */
                    if((colInitial!=0) && (colInitial!=7)){
                        if((colFinal + 1 == colInitial) || (colFinal -1 == colInitial))
                            return Capture(MyBoardMapping, rowInitial, colInitial, rowFinal, colFinal);
                    }

                    /* Movimiento hacia la derecha */
                    if((colInitial == 0) && (colFinal-1 == colInitial)){
                        return Capture(MyBoardMapping, rowInitial, colInitial, rowFinal, colFinal);
                    }

                    /* Movimiento hacia la izquierda */
                    if((colInitial == 7) && (colFinal+1 == colInitial)){
                        return Capture(MyBoardMapping, rowInitial, colInitial, rowFinal, colFinal);
                    }
                }
            }else{
                return false;
            }
        }else{
            /* Condiciones de promocion de pieza */
            std::cout<<"Promoción de pieza peon Negra\n"<<std::endl;
        }
    }

    return false;
}

bool Pawn::Capture(Piece *MyBoardMapping[8][8], unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal){
    if(colFinal != colInitial){
        if(Color.compare("White") == 0){
            if((MyBoardMapping[rowFinal][colFinal] != nullptr) && (MyBoardMapping[rowFinal][colFinal]->GetColor().compare("Black") == 0))
                return true;
        }else if(Color.compare("Black") == 0){
            if((MyBoardMapping[rowFinal][colFinal] != nullptr) && (MyBoardMapping[rowFinal][colFinal]->GetColor().compare("White") == 0))
                return true;
        }
    }
    return false;
}

Pawn::~Pawn() {}
