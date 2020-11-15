#include "Board.h"
#include "ui_Board.h"

Board::Board(QWidget * parent): QWidget(parent), ui(new Ui::Board) {
    ui -> setupUi(this);

    /* Siempre declarar para que funcione */
    setAcceptDrops(true);

    /* Inicializar tablero de ajedrez */
    InitializeBoard();
}

Board::~Board() {
    delete ui;
}

void Board::paintEvent(QPaintEvent * ) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), BoardIcon);

}

void Board::dragEnterEvent(QDragEnterEvent * event) {
    if (event -> mimeData() -> hasFormat("application/x-dnditemdata")) {
        if (event -> source() == this) {
            event -> setDropAction(Qt::MoveAction);
            event -> accept();
        } else {
            event -> acceptProposedAction();
        }
    } else {
        event -> ignore();
    }
}

void Board::dragMoveEvent(QDragMoveEvent * event) {
    if (event -> mimeData() -> hasFormat("application/x-dnditemdata")) {
        if (event -> source() == this) {
            event -> setDropAction(Qt::MoveAction);
            event -> accept();
        } else {
            event -> acceptProposedAction();
        }
    } else {
        event -> ignore();
    }
}

void Board::dropEvent(QDropEvent * event) {
    if (event -> mimeData() -> hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event -> mimeData() -> data("application/x-dnditemdata");
        QDataStream dataStream( & itemData, QIODevice::ReadOnly);

        /* Recalcular posicion para centrar la pieza */
        int positionX = (event -> pos().x() / 80);
        int positionY = (event -> pos().y() / 80);

        /* Condicion para no sobreponer piezas */
        /*
         * Mejorar con casos de captuas
         */

        if (MyBoardMapping[positionY][positionX] == nullptr) {

            MyBoardMapping[ReferentialPositionX][ReferentialPositionY] -> move(positionX * 80, positionY * 80);
            MyBoardMapping[positionY][positionX] = MyBoardMapping[ReferentialPositionX][ReferentialPositionY];
            MyBoardMapping[ReferentialPositionX][ReferentialPositionY] = nullptr;

            if (event -> source() == this) {
                event -> setDropAction(Qt::MoveAction);
                event -> accept();
            } else {
                event -> acceptProposedAction();
            }
        } else {
            event -> ignore();
        }
    } else {
        return;
    }

}

void Board::mousePressEvent(QMouseEvent * event) {
    auto child = childAt(event -> pos());
    if (child == nullptr) {
        return;
    }

    ReferentialPositionX = event -> pos().y() / 80;
    ReferentialPositionY = event -> pos().x() / 80;

    QByteArray itemData;
    QDataStream dataStream( & itemData, QIODevice::WriteOnly);
    dataStream << QPoint(event -> pos() - child -> pos());

    QMimeData * mimeData = new QMimeData();
    mimeData -> setData("application/x-dnditemdata", itemData);

    QDrag * drag = new QDrag(this);
    drag -> setMimeData(mimeData);

    drag -> exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
}

void Board::InitializeBoard() {
    /* Leer icono */
    BoardIcon.load("../Chess_Final_Project_TO/Images/chess_board.png");

    /* Mapping Board */
    auto size = sizeof(MyBoardMapping) / sizeof( * MyBoardMapping);

    /* Inicializar punteros */
    for (size_t row = 0; row < size; ++row) {
        for (size_t col = 0; col < size; ++col) {
            MyBoardMapping[row][col] = nullptr;
        }
    }

    /* Inicializar piezas en el tablero */
    InitializePieces();
}

void Board::InitializePieces() {
    /* Asignar memoria a objetos creados */
    // Piezas negras

    black_rook1 = new Rook(this, "Black");
    black_rook2 = new Rook(this, "Black");
    black_knight1 = new Knight(this, "Black");
    black_knight2 = new Knight(this, "Black");
    black_bishop1 = new Bishop(this, "Black");
    black_bishop2 = new Bishop(this, "Black");
    black_king = new King(this, "Black");
    black_queen = new Queen(this, "Black");
    black_pawn1 = new Pawn(this, "Black");
    black_pawn2 = new Pawn(this, "Black");
    black_pawn3 = new Pawn(this, "Black");
    black_pawn4 = new Pawn(this, "Black");
    black_pawn5 = new Pawn(this, "Black");
    black_pawn6 = new Pawn(this, "Black");
    black_pawn7 = new Pawn(this, "Black");
    black_pawn8 = new Pawn(this, "Black");

    // Piezas blancas
    white_rook1 = new Rook(this, "White");
    white_rook2 = new Rook(this, "White");
    white_knight1 = new Knight(this, "White");
    white_knight2 = new Knight(this, "White");
    white_bishop1 = new Bishop(this, "White");
    white_bishop2 = new Bishop(this, "White");
    white_king = new King(this, "White");
    white_queen = new Queen(this, "White");
    white_pawn1 = new Pawn(this, "White");
    white_pawn2 = new Pawn(this, "White");
    white_pawn3 = new Pawn(this, "White");
    white_pawn4 = new Pawn(this, "White");
    white_pawn5 = new Pawn(this, "White");
    white_pawn6 = new Pawn(this, "White");
    white_pawn7 = new Pawn(this, "White");
    white_pawn8 = new Pawn(this, "White");

    /* Crear piezas y asignarlas a su posicion de inicio */
    CreationOfPieces();
}

void Board::CreationOfPieces() {

    /*
     * Creacion de piezas y colocarlos en el tablero
     * mediante posiciones
     */

    // Piezas negras
    black_rook1 -> move(0, 0);
    black_rook1 -> show();
    black_rook1 -> SetRow('8');
    black_rook1 -> SetCol('a');

    black_rook2 -> move(560, 0);
    black_rook2 -> show();
    black_rook2 -> SetRow('8');
    black_rook2 -> SetCol('h');

    black_knight1 -> move(80, 0);
    black_knight1 -> show();
    black_knight1 -> SetRow('8');
    black_knight1 -> SetCol('b');

    black_knight2 -> move(480, 0);
    black_knight2 -> show();
    black_knight2 -> SetRow('8');
    black_knight2 -> SetCol('g');

    black_bishop1 -> move(160, 0);
    black_bishop1 -> show();
    black_bishop1 -> SetRow('8');
    black_bishop1 -> SetCol('c');

    black_bishop2 -> move(400, 0);
    black_bishop2 -> show();
    black_bishop2 -> SetRow('8');
    black_bishop2 -> SetCol('f');

    black_king -> move(320, 0);
    black_king -> show();
    black_king -> SetRow('8');
    black_king -> SetCol('e');

    black_queen -> move(240, 0);
    black_queen -> show();
    black_queen -> SetRow('8');
    black_queen -> SetCol('d');

    black_pawn1 -> move(0, 80);
    black_pawn1 -> show();
    black_pawn1 -> SetRow('7');
    black_pawn1 -> SetCol('a');

    black_pawn2 -> move(80, 80);
    black_pawn2 -> show();
    black_pawn2 -> SetRow('7');
    black_pawn2 -> SetCol('b');

    black_pawn3 -> move(160, 80);
    black_pawn3 -> show();
    black_pawn3 -> SetRow('7');
    black_pawn3 -> SetCol('c');

    black_pawn4 -> move(240, 80);
    black_pawn4 -> show();
    black_pawn4 -> SetRow('7');
    black_pawn4 -> SetCol('d');

    black_pawn5 -> move(320, 80);
    black_pawn5 -> show();
    black_pawn5 -> SetRow('7');
    black_pawn5 -> SetCol('e');

    black_pawn6 -> move(400, 80);
    black_pawn6 -> show();
    black_pawn6 -> SetRow('7');
    black_pawn6 -> SetCol('f');

    black_pawn7 -> move(480, 80);
    black_pawn7 -> show();
    black_pawn7 -> SetRow('7');
    black_pawn7 -> SetCol('g');

    black_pawn8 -> move(560, 80);
    black_pawn8 -> show();
    black_pawn8 -> SetRow('7');
    black_pawn8 -> SetCol('h');

    // Piezas blancas
    white_rook1 -> move(0, 560);
    white_rook1 -> show();
    white_rook1 -> SetRow('1');
    white_rook1 -> SetCol('a');

    white_rook2 -> move(560, 560);
    white_rook2 -> show();
    white_rook2 -> SetRow('1');
    white_rook2 -> SetCol('h');

    white_knight1 -> move(80, 560);
    white_knight1 -> show();
    white_knight1 -> SetRow('1');
    white_knight1 -> SetCol('b');

    white_knight2 -> move(480, 560);
    white_knight2 -> show();
    white_knight2 -> SetRow('1');
    white_knight2 -> SetCol('g');

    white_bishop1 -> move(160, 560);
    white_bishop1 -> show();
    white_bishop1 -> SetRow('1');
    white_bishop1 -> SetCol('c');

    white_bishop2 -> move(400, 560);
    white_bishop2 -> show();
    white_bishop2 -> SetRow('1');
    white_bishop2 -> SetCol('f');

    white_king -> move(240, 560);
    white_king -> show();
    white_king -> SetRow('1');
    white_king -> SetCol('d');

    white_queen -> move(320, 560);
    white_queen -> show();
    white_queen -> SetRow('1');
    white_queen -> SetCol('e');

    white_pawn1 -> move(0, 480);
    white_pawn1 -> show();
    white_pawn1 -> SetRow('2');
    white_pawn1 -> SetCol('a');

    white_pawn2 -> move(80, 480);
    white_pawn2 -> show();
    white_pawn2 -> SetRow('2');
    white_pawn2 -> SetCol('b');

    white_pawn3 -> move(160, 480);
    white_pawn3 -> show();
    white_pawn3 -> SetRow('2');
    white_pawn3 -> SetCol('c');

    white_pawn4 -> move(240, 480);
    white_pawn4 -> show();
    white_pawn4 -> SetRow('2');
    white_pawn4 -> SetCol('d');

    white_pawn5 -> move(320, 480);
    white_pawn5 -> show();
    white_pawn5 -> SetRow('2');
    white_pawn5 -> SetCol('e');

    white_pawn6 -> move(400, 480);
    white_pawn6 -> show();
    white_pawn6 -> SetRow('2');
    white_pawn6 -> SetCol('f');

    white_pawn7 -> move(480, 480);
    white_pawn7 -> show();
    white_pawn7 -> SetRow('2');
    white_pawn7 -> SetCol('g');

    white_pawn8 -> move(560, 480);
    white_pawn8 -> show();
    white_pawn8 -> SetRow('2');
    white_pawn8 -> SetCol('h');

    MappingOfPieces();
}

void Board::MappingOfPieces() {
    /* Piezas negras */
    MyBoardMapping[0][0] = black_rook1;
    MyBoardMapping[0][1] = black_knight1;
    MyBoardMapping[0][2] = black_bishop1;
    MyBoardMapping[0][3] = black_queen;
    MyBoardMapping[0][4] = black_king;
    MyBoardMapping[0][5] = black_bishop2;
    MyBoardMapping[0][6] = black_knight2;
    MyBoardMapping[0][7] = black_rook2;
    MyBoardMapping[1][0] = black_pawn1;
    MyBoardMapping[1][1] = black_pawn2;
    MyBoardMapping[1][2] = black_pawn3;
    MyBoardMapping[1][3] = black_pawn4;
    MyBoardMapping[1][4] = black_pawn5;
    MyBoardMapping[1][5] = black_pawn6;
    MyBoardMapping[1][6] = black_pawn7;
    MyBoardMapping[1][7] = black_pawn8;

    /* Piezas blancas */
    MyBoardMapping[7][0] = white_rook1;
    MyBoardMapping[7][1] = white_knight1;
    MyBoardMapping[7][2] = white_bishop1;
    MyBoardMapping[7][3] = white_queen;
    MyBoardMapping[7][4] = white_king;
    MyBoardMapping[7][5] = white_bishop2;
    MyBoardMapping[7][6] = white_knight2;
    MyBoardMapping[7][7] = white_rook2;
    MyBoardMapping[6][0] = white_pawn1;
    MyBoardMapping[6][1] = white_pawn2;
    MyBoardMapping[6][2] = white_pawn3;
    MyBoardMapping[6][3] = white_pawn4;
    MyBoardMapping[6][4] = white_pawn5;
    MyBoardMapping[6][5] = white_pawn6;
    MyBoardMapping[6][6] = white_pawn7;
    MyBoardMapping[6][7] = white_pawn8;
}
