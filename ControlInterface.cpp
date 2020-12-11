#include "ControlInterface.h"
#include "ui_ControlInterface.h"

ControlInterface::ControlInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlInterface)
{
    ui->setupUi(this);
    //Piezas blancas mueven primero
    ui->mensajeTurnBlack->setVisible(false);
}

void ControlInterface::UpdateTurn(const std::string color){
    if(color.compare("White") == 0){
        ui->mensajeTurnWhite->setVisible(true);
        ui->mensajeTurnBlack->setVisible(false);
    }
    if(color.compare("Black") == 0){
        ui->mensajeTurnWhite->setVisible(false);
        ui->mensajeTurnBlack->setVisible(true);
    }
}

void ControlInterface::UpdateCounterPieces(const std::string typeOfPiece, const std::string colorOfPiece){
    if(colorOfPiece.compare("White") == 0){
        if(typeOfPiece.compare("Pawn") == 0){
            ui->white_pawn_counter->setText(QString::number(ui->white_pawn_counter->text().toInt() +1));
        }
        if(typeOfPiece.compare("Bishop") == 0){
            ui->white_bishop_counter->setText(QString::number(ui->white_bishop_counter->text().toInt()+1));
        }
        if(typeOfPiece.compare("Rook") == 0){
            ui->white_rook_counter->setText(QString::number(ui->white_rook_counter->text().toInt()+1));
        }
        if(typeOfPiece.compare("Knight") == 0){
            ui->white_knight_counter->setText(QString::number(ui->white_knight_counter->text().toInt()+1));
        }
        if(typeOfPiece.compare("Queen") == 0){
            ui->white_queen_counter->setText(QString::number(ui->white_queen_counter->text().toInt()+1));
        }
    }

    if(colorOfPiece.compare("Black") == 0){
        if(typeOfPiece.compare("Pawn") == 0){
            ui->black_pawn_counter->setText(QString::number(ui->black_pawn_counter->text().toInt()+1));
        }
        if(typeOfPiece.compare("Bishop") == 0){
            ui->black_bishop_counter->setText(QString::number(ui->black_bishop_counter->text().toInt()+1));
        }
        if(typeOfPiece.compare("Rook") == 0){
            ui->black_rook_counter->setText(QString::number(ui->black_rook_counter->text().toInt()+1));
        }
        if(typeOfPiece.compare("Knight") == 0){
            ui->black_knight_counter->setText(QString::number(ui->black_knight_counter->text().toInt()+1));
        }
        if(typeOfPiece.compare("Queen") == 0){
            ui->black_queen_counter->setText(QString::number(ui->black_queen_counter->text().toInt()+1));
        }
    }
}

ControlInterface::~ControlInterface()
{
    delete ui;
}
