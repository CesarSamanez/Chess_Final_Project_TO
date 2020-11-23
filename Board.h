#ifndef BOARD_H
#define BOARD_H

/* QT */
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QtWidgets>

/* STL */
#include <iostream>
#include <string>
#include <cmath>
#include <memory>
#include <vector>

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

class Board: public QWidget {
    Q_OBJECT

public:
    explicit Board(QWidget * parent = nullptr);
    ~Board();

    void paintEvent(QPaintEvent * event) override;
    void InitializeBoard();
    void InitializePieces();
    void CreationOfPieces();
    void MappingOfPieces();

    bool ValidateMovement(unsigned rowInitial, unsigned colInitial, unsigned rowFinal, unsigned colFinal);
private:
    /* Icono */
    QPixmap BoardIcon;
    Ui::Board * ui;

    //Variables auxiliares
     int ReferentialPositionX, ReferentialPositionY, positionX, positionY;

    /* Mapear tablero */
    Piece *MyBoardMapping[8][8];

    /*
     *  FICHAS NEGRAS
     */

    /* Torres */
    Piece * black_rook1;
    Piece * black_rook2;

    /* Caballos */
    Piece * black_knight1;
    Piece * black_knight2;

    /* Alfiles */
    Piece * black_bishop1;
    Piece * black_bishop2;

    /* Rey */
    Piece * black_king;

    /* Reyna */
    Piece * black_queen;

    /* Peones */
    Piece * black_pawn1;
    Piece * black_pawn2;
    Piece * black_pawn3;
    Piece * black_pawn4;
    Piece * black_pawn5;
    Piece * black_pawn6;
    Piece * black_pawn7;
    Piece * black_pawn8;

    /*
     * FICHAS BLANCAS
     */

    /* Torres */
    Piece * white_rook1;
    Piece * white_rook2;

    /* Caballos */
    Piece * white_knight1;
    Piece * white_knight2;

    /* Alfiles */
    Piece * white_bishop1;
    Piece * white_bishop2;

    /* Rrey */
    Piece * white_king;

    /* Reyna */
    Piece * white_queen;

    /* Peones */
    Piece * white_pawn1;
    Piece * white_pawn2;
    Piece * white_pawn3;
    Piece * white_pawn4;
    Piece * white_pawn5;
    Piece * white_pawn6;
    Piece * white_pawn7;
    Piece * white_pawn8;

    void mousePressEvent(QMouseEvent * event) override;
    void dragEnterEvent(QDragEnterEvent * event) override;
    void dragMoveEvent(QDragMoveEvent * event) override;
    void dropEvent(QDropEvent * event) override;
};

#endif // BOARD_H
