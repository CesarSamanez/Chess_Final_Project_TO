#include "Board.h"

#include "ui_Board.h"

Board::Board(QWidget * parent): QWidget(parent), ui(new Ui::Board) {
    ui -> setupUi(this);
    /* Siempre declarar para que funcione */
    setAcceptDrops(true);

    // Imagen del tablero
    BoardIcon.load("../Chess_Final_Project_TO/Images/chess_board.png");

    /* Inicializar tablero de ajedrez */
    InitializeBoard();
}

void Board::InitializeBoard() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
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
    black_rook1 -> SetPosition(0, 0);

    black_rook2 -> move(560, 0);
    black_rook2 -> show();
    black_rook2 -> SetPosition(0, 7);

    black_knight1 -> move(80, 0);
    black_knight1 -> show();
    black_knight1 -> SetPosition(0, 1);

    black_knight2 -> move(480, 0);
    black_knight2 -> show();
    black_knight2 -> SetPosition(0, 6);

    black_bishop1 -> move(160, 0);
    black_bishop1 -> show();
    black_bishop1 -> SetPosition(0, 2);

    black_bishop2 -> move(400, 0);
    black_bishop2 -> show();
    black_bishop2 -> SetPosition(0, 5);

    black_king -> move(320, 0);
    black_king -> show();
    black_king -> SetPosition(0, 4);

    black_queen -> move(240, 0);
    black_queen -> show();
    black_queen -> SetPosition(0, 3);

    black_pawn1 -> move(0, 80);
    black_pawn1 -> show();
    black_pawn1 -> SetPosition(1, 0);

    black_pawn2 -> move(80, 80);
    black_pawn2 -> show();
    black_pawn2 -> SetPosition(1, 1);

    black_pawn3 -> move(160, 80);
    black_pawn3 -> show();
    black_pawn3 -> SetPosition(1, 2);

    black_pawn4 -> move(240, 80);
    black_pawn4 -> show();
    black_pawn4 -> SetPosition(1, 3);

    black_pawn5 -> move(320, 80);
    black_pawn5 -> show();
    black_pawn5 -> SetPosition(1, 4);

    black_pawn6 -> move(400, 80);
    black_pawn6 -> show();
    black_pawn6 -> SetPosition(1, 5);

    black_pawn7 -> move(480, 80);
    black_pawn7 -> show();
    black_pawn7 -> SetPosition(1, 6);

    black_pawn8 -> move(560, 80);
    black_pawn8 -> show();
    black_pawn8 -> SetPosition(1, 7);

    // Piezas blancas
    white_rook1 -> move(0, 560);
    white_rook1 -> show();
    white_rook1 -> SetPosition(7, 0);

    white_rook2 -> move(560, 560);
    white_rook2 -> show();
    white_rook2 -> SetPosition(7, 7);

    white_knight1 -> move(80, 560);
    white_knight1 -> show();
    white_knight1 -> SetPosition(7, 1);

    white_knight2 -> move(480, 560);
    white_knight2 -> show();
    white_knight2 -> SetPosition(7, 6);

    white_bishop1 -> move(160, 560);
    white_bishop1 -> show();
    white_bishop1 -> SetPosition(7, 2);

    white_bishop2 -> move(400, 560);
    white_bishop2 -> show();
    white_bishop2 -> SetPosition(7, 5);

    white_king -> move(240, 560);
    white_king -> show();
    white_king -> SetPosition(7, 3);

    white_queen -> move(320, 560);
    white_queen -> show();
    white_queen -> SetPosition(7, 4);

    white_pawn1 -> move(0, 480);
    white_pawn1 -> show();
    white_pawn1 -> SetPosition(6, 0);

    white_pawn2 -> move(80, 480);
    white_pawn2 -> show();
    white_pawn2 -> SetPosition(6, 1);

    white_pawn3 -> move(160, 480);
    white_pawn3 -> show();
    white_pawn3 -> SetPosition(6, 2);

    white_pawn4 -> move(240, 480);
    white_pawn4 -> show();
    white_pawn4 -> SetPosition(6, 3);

    white_pawn5 -> move(320, 480);
    white_pawn5 -> show();
    white_pawn5 -> SetPosition(6, 4);

    white_pawn6 -> move(400, 480);
    white_pawn6 -> show();
    white_pawn6 -> SetPosition(6, 5);

    white_pawn7 -> move(480, 480);
    white_pawn7 -> show();
    white_pawn7 -> SetPosition(6, 6);

    white_pawn8 -> move(560, 480);
    white_pawn8 -> show();
    white_pawn8 -> SetPosition(6, 7);

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
    MyBoardMapping[7][3] = white_king;
    MyBoardMapping[7][4] = white_queen;
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

bool Board::ValidateMovement(const int& rowInitial, const int& colInitial, const int& rowFinal, const int& colFinal) {

    auto piecePosition = MyBoardMapping[rowInitial][colInitial];
    std::vector < std::pair < int, int >> misMovimientos;

    misMovimientos = piecePosition -> PossibleMoves(MyBoardMapping);
    DrawMovements(misMovimientos);
    piecePosition -> PossibleMoves(MyBoardMapping);
    if (piecePosition -> GetName().compare("Rook") == 0) {
        return piecePosition -> MovePiece(MyBoardMapping, rowFinal, colFinal);
    } else if (piecePosition -> GetName().compare("Knight") == 0) {
        return piecePosition -> MovePiece(MyBoardMapping, rowFinal, colFinal);
    } else if (piecePosition -> GetName().compare("Bishop") == 0) {
        return piecePosition -> MovePiece(MyBoardMapping, rowFinal, colFinal);
    } else if (piecePosition -> GetName().compare("Queen") == 0) {
        return piecePosition -> MovePiece(MyBoardMapping, rowFinal, colFinal);
    } else if (piecePosition -> GetName().compare("King") == 0) {
        return piecePosition -> MovePiece(MyBoardMapping, rowFinal, colFinal);
    } else if (piecePosition -> GetName().compare("Pawn") == 0) {
        return piecePosition -> MovePiece(MyBoardMapping, rowFinal, colFinal);
    }

    return false;
}

void Board::Check(const Piece *piece){
    if(piece->GetName().compare("King")!=0){
        std::vector < std::pair < int, int >> futMovements; //futuros movimientos
        futMovements = piece->PossibleMoves(MyBoardMapping);
        for(size_t i=0; i< futMovements.size();i++){
            if(piece->GetColor().compare("White")==0){
                if((futMovements[i].first == black_king->GetRow()) && (futMovements[i].second==black_king->GetCol())){
                    std::cout<< "Jaque pos ["<<futMovements[i].first <<"," << futMovements[i].second<<"]\n";
                }
            }else if(piece->GetColor().compare("Black")==0){
                if((futMovements[i].first == white_king->GetRow()) && (futMovements[i].second==white_king->GetCol())){
                    std::cout<< "Jaque pos ["<<futMovements[i].first <<"," << futMovements[i].second<<"]\n";
                }
            }
        }
    }
}

void Board::ChekMate(const Piece *piece){
    if(piece->GetName().compare("King")==0){
        QMessageBox message;
        message.setText("Jaque Mate");
        message.exec();
        std::cout << "Jaque mate\n";
        exit(1); //reemplazo por menu de inicio
    }
}

void Board::DeadPosition(){
    int count =0;
    for(size_t i=0; i< 8; i++){
        for(size_t j=0; j<8;j++){
            if(MyBoardMapping[i][j]!=nullptr ){
                if(MyBoardMapping[i][j]->GetName().compare("King")!=0){
                    count ++;
                }
            }
        }
    }

    if(count == 0){
        std::cout << "Tablas"<< std::endl;
    }
}
void Board::DrawMovements(const std::vector < std::pair < int, int > >& _movements) {
    //Limpiar movimientos ficha anterior
    RemoveDrawnMovements();

    for (size_t i = 0; i < _movements.size(); i++) {
        QLabel * aux = new QLabel(this);
        aux -> setStyleSheet("QLabel { border-radius : 10px ; background-color : #FFA133; }");
        aux -> setGeometry((_movements[i].second * 80 + 30), (_movements[i].first * 80 + 30), 20, 20);
        aux -> setEnabled(false);
        aux -> show();
        movementsInBoard.push_back(aux);
    }
}

void Board::RemoveDrawnMovements() {
    for (size_t i = 0; i < movementsInBoard.size(); i++) {
        movementsInBoard[i] -> ~QLabel();
    }
    movementsInBoard.clear();
}

bool Board::isAdvertenceWidget() {
    for (size_t i = 0; i < movementsInBoard.size(); i++) {
        if (movementsInBoard[i] -> y() == ReferentialPositionX * 80 + 30 && movementsInBoard[i] -> x() == ReferentialPositionY * 80 + 30) {
            return true;
        }
    }
    return false;
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
        positionX = (event -> pos().x() / 80);
        positionY = (event -> pos().y() / 80);

        std::cout << "Posicion hacia donde me dirijo [" << positionY << "," << positionX << "]\n";

        /* Condicion para no sobreponer piezas */
        /*
         * Mejorar con casos de captuas
         */
        if (ValidateMovement(ReferentialPositionX, ReferentialPositionY, positionY, positionX)) {
            if (MyBoardMapping[ReferentialPositionX][ReferentialPositionY] -> Capture(MyBoardMapping, positionY, positionX)) {
                /* Captura de pieza */
                MyBoardMapping[positionY][positionX] -> setVisible(false);
                std::cout << "Se capturo la pieza [" << positionY << "," << positionX << "]\n";
                ChekMate(MyBoardMapping[positionY][positionX]); //validar JaqueMate
                MyBoardMapping[ReferentialPositionX][ReferentialPositionY] -> move(positionX * 80, positionY * 80);
                MyBoardMapping[positionY][positionX] = MyBoardMapping[ReferentialPositionX][ReferentialPositionY];
                MyBoardMapping[positionY][positionX] -> SetPosition(positionY, positionX);
                Check(MyBoardMapping[positionY][positionX]);//chequea jaque
                MyBoardMapping[ReferentialPositionX][ReferentialPositionY] = nullptr;
            } else if (MyBoardMapping[positionY][positionX] == nullptr) {
                //Mover pieza nueva posicion
                MyBoardMapping[ReferentialPositionX][ReferentialPositionY] -> move(positionX * 80, positionY * 80);
                MyBoardMapping[positionY][positionX] = MyBoardMapping[ReferentialPositionX][ReferentialPositionY];
                MyBoardMapping[positionY][positionX] -> SetPosition(positionY, positionX);
                MyBoardMapping[ReferentialPositionX][ReferentialPositionY] = nullptr;
                //chequear jaque de la nueva posicion
                Check(MyBoardMapping[positionY][positionX]);
            } else {
                return;
            }
            if (event -> source() == this) {
                event -> setDropAction(Qt::MoveAction);
                event -> accept();
                RemoveDrawnMovements();
            } else {
                event -> acceptProposedAction();
            }
        } else {
            event -> ignore();
        }

        DeadPosition();
    } else {
        return;
    }

}

void Board::mousePressEvent(QMouseEvent * event) {
    auto child = childAt(event -> pos());

    ReferentialPositionX = event -> pos().y() / 80;
    ReferentialPositionY = event -> pos().x() / 80;

    if (child == nullptr || isAdvertenceWidget()) {
        return;
    }

    std::cout << "Posicion donde presiono primero [" << ReferentialPositionX << "," << ReferentialPositionY << "]\n";
    // EliminaMovimientosGraficados();

    QByteArray itemData;
    QDataStream dataStream( & itemData, QIODevice::WriteOnly);
    dataStream << QPoint(event -> pos() - child -> pos());

    QMimeData * mimeData = new QMimeData();
    mimeData -> setData("application/x-dnditemdata", itemData);

    QDrag * drag = new QDrag(this);
    drag -> setMimeData(mimeData);

    drag -> exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
}

Board::~Board() {
    delete ui;
}
