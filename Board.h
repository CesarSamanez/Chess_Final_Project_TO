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
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"

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
    std::unique_ptr<Rook> black_rook1;
    std::unique_ptr<Rook> black_rook2;

    /* Caballos */
    std::unique_ptr<Knight> black_knight1;
    std::unique_ptr<Knight> black_knight2;

    /* Alfiles */
    std::unique_ptr<Bishop> black_bishop1;
    std::unique_ptr<Bishop> black_bishop2;

    /* Rey */
    std::unique_ptr<King> black_king;

    /* Reyna */
    std::unique_ptr<Queen> black_queen;

    /* Peones */
    std::unique_ptr<Pawn> black_pawn1;
    std::unique_ptr<Pawn> black_pawn2;
    std::unique_ptr<Pawn> black_pawn3;
    std::unique_ptr<Pawn> black_pawn4;
    std::unique_ptr<Pawn> black_pawn5;
    std::unique_ptr<Pawn> black_pawn6;
    std::unique_ptr<Pawn> black_pawn7;
    std::unique_ptr<Pawn> black_pawn8;


    /*
     * FICHAS BLANCAS
     */

    /* Torres */
    std::unique_ptr<Rook> white_rook1;
    std::unique_ptr<Rook> white_rook2;

    /* Caballos */
    std::unique_ptr<Knight> white_knight1;
    std::unique_ptr<Knight> white_knight2;

    /* Alfiles */
    std::unique_ptr<Bishop> white_bishop1;
    std::unique_ptr<Bishop> white_bishop2;

    /* Rrey */
    std::unique_ptr<King> white_king;

    /* Reyna */
    std::unique_ptr<Queen> white_queen;

    /* Peones */
    std::unique_ptr<Pawn> white_pawn1;
    std::unique_ptr<Pawn> white_pawn2;
    std::unique_ptr<Pawn> white_pawn3;
    std::unique_ptr<Pawn> white_pawn4;
    std::unique_ptr<Pawn> white_pawn5;
    std::unique_ptr<Pawn> white_pawn6;
    std::unique_ptr<Pawn> white_pawn7;
    std::unique_ptr<Pawn> white_pawn8;



    void mousePressEvent(QMouseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

};

#endif // BOARD_H
