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

    bool ValidateMovement(int rowInitial, int colInitial, int rowFinal, int colFinal);
    void DrawMovements(std::vector<std::pair<int, int>> movements);
    void RemoveDrawnMovements();
private:
    /* Icono */
    QPixmap BoardIcon;
    Ui::Board * ui;

    //Variables auxiliares
    int ReferentialPositionX, ReferentialPositionY, positionX, positionY;

    /* Mapear tablero */
    Piece *MyBoardMapping[8][8];

    Piece * black_rook1;
    Piece * black_rook2;
    Piece * black_knight1;
    Piece * black_knight2;
    Piece * black_bishop1;
    Piece * black_bishop2;
    Piece * black_king;
    Piece * black_queen;
    Piece * black_pawn1;
    Piece * black_pawn2;
    Piece * black_pawn3;
    Piece * black_pawn4;
    Piece * black_pawn5;
    Piece * black_pawn6;
    Piece * black_pawn7;
    Piece * black_pawn8;

    Piece * white_rook1;
    Piece * white_rook2;
    Piece * white_knight1;
    Piece * white_knight2;
    Piece * white_bishop1;
    Piece * white_bishop2;
    Piece * white_king;
    Piece * white_queen;
    Piece * white_pawn1;
    Piece * white_pawn2;
    Piece * white_pawn3;
    Piece * white_pawn4;
    Piece * white_pawn5;
    Piece * white_pawn6;
    Piece * white_pawn7;
    Piece * white_pawn8;

    // Vector de posibles movimientos
    std::vector<QLabel*> movementsInBoard;

    //Valida que no es una ficha de ajedrez
    bool isAdvertenceWidget();

    void mousePressEvent(QMouseEvent * event) override;
    void dragEnterEvent(QDragEnterEvent * event) override;
    void dragMoveEvent(QDragMoveEvent * event) override;
    void dropEvent(QDropEvent * event) override;
};

#endif // BOARD_H
