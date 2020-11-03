#ifndef BOARD_H
#define BOARD_H

/* QT */
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QtWidgets>

/* STL */
#include <iostream>
#include <memory>

/* Local */
#include "Piece.h"
#include "Black_Rook.h"
#include "Black_Knight.h"
#include "Black_Bishop.h"
#include "Black_Queen.h"
#include "Black_King.h"
#include "Black_Pawn.h"

#include "White_Rook.h"
#include "White_Knight.h"
#include "White_Bishop.h"
#include "White_King.h"
#include "White_Queen.h"
#include "White_Pawn.h"

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

    void paintEvent(QPaintEvent *event) override;

private:
    /* Icono */
    QPixmap BoardIcon;
    Ui::Board *ui;
   /*
    *  FICHAS NEGRAS
    */

    /* Torres */
    std::unique_ptr<Black_Rook> black_rook1;
    std::unique_ptr<Black_Rook> black_rook2;

    /* Caballos */
    std::unique_ptr<Black_Knight> black_knight1;
    std::unique_ptr<Black_Knight> black_knight2;

    /* Alfiles */
    std::unique_ptr<Black_Bishop> black_bishop1;
    std::unique_ptr<Black_Bishop> black_bishop2;

    /* Rey */
    std::unique_ptr<Black_King> black_king;

    /* Reyna */
    std::unique_ptr<Black_Queen> black_queen;

    /* Peones */
    std::unique_ptr<Black_Pawn> black_pawn1;
    std::unique_ptr<Black_Pawn> black_pawn2;
    std::unique_ptr<Black_Pawn> black_pawn3;
    std::unique_ptr<Black_Pawn> black_pawn4;
    std::unique_ptr<Black_Pawn> black_pawn5;
    std::unique_ptr<Black_Pawn> black_pawn6;
    std::unique_ptr<Black_Pawn> black_pawn7;
    std::unique_ptr<Black_Pawn> black_pawn8;


    /*
     * FICHAS BLANCAS
     */

    /* Torres */
    std::unique_ptr<White_Rook> white_rook1;
    std::unique_ptr<White_Rook> white_rook2;

    /* Caballos */
    std::unique_ptr<White_Knight> white_knight1;
    std::unique_ptr<White_Knight> white_knight2;

    /* Alfiles */
    std::unique_ptr<White_Bishop> white_bishop1;
    std::unique_ptr<White_Bishop> white_bishop2;

    /* Rrey */
    std::unique_ptr<White_King> white_king;

    /* Reyna */
    std::unique_ptr<White_Queen> white_queen;

    /* Peones */
    std::unique_ptr<White_Pawn> white_pawn1;
    std::unique_ptr<White_Pawn> white_pawn2;
    std::unique_ptr<White_Pawn> white_pawn3;
    std::unique_ptr<White_Pawn> white_pawn4;
    std::unique_ptr<White_Pawn> white_pawn5;
    std::unique_ptr<White_Pawn> white_pawn6;
    std::unique_ptr<White_Pawn> white_pawn7;
    std::unique_ptr<White_Pawn> white_pawn8;



    void mousePressEvent(QMouseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

};

#endif // BOARD_H
