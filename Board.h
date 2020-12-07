#ifndef BOARD_H
#define BOARD_H

/* QT */
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QtWidgets>
#include <QInputDialog>

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
    void PositionPiecesInBoard();
    void MappingOfPieces();

    bool ValidateMovement(const int& rowInitial, const int& colInitial, const int& rowFinal, const int& colFinal);
    //Valida que no es una ficha de ajedrez
    bool isAdvertenceWidget();
    void DrawMovements(const std::vector<std::pair<int, int>>& movements);
    void Check(const Piece *piece);
    void ChekMate(const Piece *piece);
    void DeadPosition();
    void RemoveDrawnMovements();

private:
    /* Icono */
    QPixmap BoardIcon;
    Ui::Board * ui;

    std::string TurnColor = "White";

    /* Mapear tablero */
    Piece *MyBoardMapping[8][8];

    Piece * black_rook1 = new Rook(this, "Black");
    Piece * black_rook2 = new Rook(this, "Black");
    Piece * black_knight1 = new Knight(this, "Black");
    Piece * black_knight2 = new Knight(this, "Black");
    Piece * black_bishop1 = new Bishop(this, "Black");
    Piece * black_bishop2 = new Bishop(this, "Black");
    Piece * black_king = new King(this, "Black");
    Piece * black_queen = new Queen(this, "Black");
    Piece * black_pawn1 = new Pawn(this, "Black");
    Piece * black_pawn2 = new Pawn(this, "Black");
    Piece * black_pawn3 = new Pawn(this, "Black");
    Piece * black_pawn4 = new Pawn(this, "Black");
    Piece * black_pawn5 = new Pawn(this, "Black");
    Piece * black_pawn6 = new Pawn(this, "Black");
    Piece * black_pawn7 = new Pawn(this, "Black");
    Piece * black_pawn8 = new Pawn(this, "Black");

    Piece * white_rook1 = new Rook(this, "White");
    Piece * white_rook2 = new Rook(this, "White");
    Piece * white_knight1 = new Knight(this, "White");
    Piece * white_knight2 = new Knight(this, "White");
    Piece * white_bishop1 = new Bishop(this, "White");
    Piece * white_bishop2 = new Bishop(this, "White");
    Piece * white_king = new King(this, "White");
    Piece * white_queen = new Queen(this, "White");
    Piece * white_pawn1 = new Pawn(this, "White");
    Piece * white_pawn2 = new Pawn(this, "White");
    Piece * white_pawn3 = new Pawn(this, "White");
    Piece * white_pawn4 = new Pawn(this, "White");
    Piece * white_pawn5 = new Pawn(this, "White");
    Piece * white_pawn6 = new Pawn(this, "White");
    Piece * white_pawn7 = new Pawn(this, "White");
    Piece * white_pawn8 = new Pawn(this, "White");

    // Vector de posibles movimientos
    std::vector<QLabel*> posibbleMovementsInBoard;

    //Variables auxiliares
    int ReferentialPositionX, ReferentialPositionY, positionX, positionY;

    Piece* PromotionOfPawn(const std::string& _color);
    void ChangeTurnColor();
    void mousePressEvent(QMouseEvent * event) override;
    void dragEnterEvent(QDragEnterEvent * event) override;
    void dragMoveEvent(QDragMoveEvent * event) override;
    void dropEvent(QDropEvent * event) override;
};

#endif // BOARD_H
