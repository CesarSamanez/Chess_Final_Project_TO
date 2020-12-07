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
    // Mapeo de piezas
    MappingOfPieces();

    /* Inicializar piezas en el tablero */
    PositionPiecesInBoard();
}

void Board::PositionPiecesInBoard() {

    /*
     * Creacion de piezas y colocarlos en el tablero
     * mediante posiciones
     */

    for (size_t row = 0; row < 8; row++) {
        for (size_t col = 0; col < 8; col++) {
            if (row < 2 || row > 5) {
                MyBoardMapping[row][col] -> move(col * 80, row * 80);
                MyBoardMapping[row][col] -> show();
                MyBoardMapping[row][col] -> SetPosition(row, col);
            }
        }
    }
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

bool Board::ValidateMovement(const int & rowInitial, const int & colInitial, const int & rowFinal, const int & colFinal) {

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

void Board::Check(const Piece * piece) {
    if (piece -> GetName().compare("King") != 0) {
        std::vector < std::pair < int, int >> futureMovements; //futuros movimientos
        futureMovements = piece -> PossibleMoves(MyBoardMapping);
        for (size_t i = 0; i < futureMovements.size(); i++) {
            if (piece -> GetColor().compare("White") == 0) {
                if ((futureMovements[i].first == black_king -> GetRow()) && (futureMovements[i].second == black_king -> GetCol())) {
                    std::cout << "Jaque pos [" << futureMovements[i].first << "," << futureMovements[i].second << "]\n";
                }
            } else if (piece -> GetColor().compare("Black") == 0) {
                if ((futureMovements[i].first == white_king -> GetRow()) && (futureMovements[i].second == white_king -> GetCol())) {
                    std::cout << "Jaque pos [" << futureMovements[i].first << "," << futureMovements[i].second << "]\n";
                }
            }
        }
    }
}

void Board::ChekMate(const Piece * piece) {
    if (piece -> GetName().compare("King") == 0) {
        QMessageBox message;
        message.setText("Jaque Mate");
        message.exec();
        std::cout << "Jaque mate\n";
        exit(1); //reemplazo por menu de inicio
    }
}

void Board::DeadPosition() {
    int count = 0;
    for (size_t row = 0; row < 8; row++) {
        for (size_t col = 0; col < 8; col++) {
            if (MyBoardMapping[row][col] != nullptr) {
                if (MyBoardMapping[row][col] -> GetName().compare("King") != 0) {
                    count++;
                }
            }
        }
    }

    if (count == 0) {
        std::cout << "Tablas" << std::endl;
    }
}

void Board::DrawMovements(const std::vector < std::pair < int, int > > & _movements) {
    //Limpiar movimientos ficha anterior
    RemoveDrawnMovements();

    for (size_t i = 0; i < _movements.size(); i++) {
        QLabel * aux = new QLabel(this);
        aux -> setStyleSheet("QLabel { border-radius : 10px ; background-color : #FFA133; }");
        aux -> setGeometry((_movements[i].second * 80 + 30), (_movements[i].first * 80 + 30), 20, 20);
        aux -> setEnabled(false);
        aux -> show();
        posibbleMovementsInBoard.push_back(aux);
    }
}

void Board::RemoveDrawnMovements() {
    for (size_t index = 0; index < posibbleMovementsInBoard.size(); index++) {
        posibbleMovementsInBoard[index] -> ~QLabel();
    }
    posibbleMovementsInBoard.clear();
}

bool Board::isAdvertenceWidget() {
    for (size_t index = 0; index < posibbleMovementsInBoard.size(); index++) {
        if (posibbleMovementsInBoard[index] -> y() == ReferentialPositionX * 80 + 30 && posibbleMovementsInBoard[index] -> x() == ReferentialPositionY * 80 + 30) {
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
                // Validacion para promocion de peon
                if(MyBoardMapping[ReferentialPositionX][ReferentialPositionY]->GetName().compare("Pawn") == 0 && (positionY == 0 || positionY == 7)){
                    MyBoardMapping[positionY][positionX] -> setVisible(false);
                    std::cout << "Se capturo la pieza [" << positionY << "," << positionX << "]\n";
                    ChekMate(MyBoardMapping[positionY][positionX]); //validar JaqueMate
                    MyBoardMapping[ReferentialPositionX][ReferentialPositionY]->setVisible(false);
                    // Promocion de peon
                    Piece * tmp = PromotionOfPawn(TurnColor);
                    tmp->move(positionX*80, positionY*80);
                    tmp->setVisible(true);

                    MyBoardMapping[positionY][positionX] = tmp;
                    MyBoardMapping[positionY][positionX] -> SetColor(MyBoardMapping[ReferentialPositionX][ReferentialPositionY] -> GetColor());
                    MyBoardMapping[positionY][positionX] -> SetPosition(positionY, positionX);
                    Check(MyBoardMapping[positionY][positionX]); //chequea jaque
                    MyBoardMapping[ReferentialPositionX][ReferentialPositionY] = nullptr;

                }else{
                    /* Captura de pieza */
                    MyBoardMapping[positionY][positionX] -> setVisible(false);
                    std::cout << "Se capturo la pieza [" << positionY << "," << positionX << "]\n";
                    ChekMate(MyBoardMapping[positionY][positionX]); //validar JaqueMate
                    MyBoardMapping[ReferentialPositionX][ReferentialPositionY] -> move(positionX * 80, positionY * 80);
                    MyBoardMapping[positionY][positionX] = MyBoardMapping[ReferentialPositionX][ReferentialPositionY];
                    MyBoardMapping[positionY][positionX] -> SetColor(MyBoardMapping[ReferentialPositionX][ReferentialPositionY] -> GetColor());
                    MyBoardMapping[positionY][positionX] -> SetPosition(positionY, positionX);
                    Check(MyBoardMapping[positionY][positionX]); //chequea jaque
                    MyBoardMapping[ReferentialPositionX][ReferentialPositionY] = nullptr;

                }
            } else if (MyBoardMapping[positionY][positionX] == nullptr) {
                if(MyBoardMapping[ReferentialPositionX][ReferentialPositionY]->GetName().compare("Pawn") == 0 && (positionY == 0 || positionY == 7)){
                    MyBoardMapping[ReferentialPositionX][ReferentialPositionY]->setVisible(false);
                    // Promocion de peon
                    Piece * tmp = PromotionOfPawn(TurnColor);
                    tmp->move(positionX*80, positionY*80);
                    tmp->setVisible(true);

                    MyBoardMapping[positionY][positionX] = tmp;
                    MyBoardMapping[positionY][positionX] -> SetColor(MyBoardMapping[ReferentialPositionX][ReferentialPositionY] -> GetColor());
                    MyBoardMapping[positionY][positionX] -> SetPosition(positionY, positionX);
                    Check(MyBoardMapping[positionY][positionX]); //chequea jaque
                    MyBoardMapping[ReferentialPositionX][ReferentialPositionY] = nullptr;

                }else{
                    //Mover pieza nueva posicion
                    MyBoardMapping[ReferentialPositionX][ReferentialPositionY] -> move(positionX * 80, positionY * 80);
                    MyBoardMapping[positionY][positionX] = MyBoardMapping[ReferentialPositionX][ReferentialPositionY];
                    MyBoardMapping[positionY][positionX] -> SetColor(MyBoardMapping[ReferentialPositionX][ReferentialPositionY] -> GetColor());
                    MyBoardMapping[positionY][positionX] -> SetPosition(positionY, positionX);
                    MyBoardMapping[ReferentialPositionX][ReferentialPositionY] = nullptr;
                    //chequear jaque de la nueva posicion
                    Check(MyBoardMapping[positionY][positionX]);
                }

            } else {
                return;
            }
            if (event -> source() == this) {
                event -> setDropAction(Qt::MoveAction);
                event -> accept();
                RemoveDrawnMovements();
                // ChangeTurnColor();
            } else {
                event -> acceptProposedAction();
            }
            // Cambio de turno de jugador
            ChangeTurnColor();
        } else {
            event -> ignore();
        }

        DeadPosition();
    } else {
        return;
    }

}

Piece* Board::PromotionOfPawn(const std::string& _color){
    Piece* PawnPromotionPiece;

    QStringList piecesPromotion;
    piecesPromotion<<"Bishop";
    piecesPromotion<<"Knight";
    piecesPromotion<<"Queen";
    piecesPromotion<<"Rook";

    std::string itemPromotion = QInputDialog::getItem(this, "Promotion", "Choose one", piecesPromotion).toStdString();

    if(itemPromotion.compare("Bishop") == 0){
        PawnPromotionPiece = new Bishop(this, _color);
    }else if(itemPromotion.compare("Knight") == 0){
        PawnPromotionPiece = new Knight(this, _color);
    }else if(itemPromotion.compare("Queen") == 0){
        PawnPromotionPiece = new Queen(this, _color);
    }else if(itemPromotion.compare("Rook") == 0){
        PawnPromotionPiece = new Rook(this, _color);
    }else{
        PawnPromotionPiece = nullptr;
    }

    return PawnPromotionPiece;
}

void Board::mousePressEvent(QMouseEvent * event) {
    auto child = childAt(event -> pos());

    ReferentialPositionX = event -> pos().y() / 80;
    ReferentialPositionY = event -> pos().x() / 80;

    if (child == nullptr || isAdvertenceWidget() || MyBoardMapping[ReferentialPositionX][ReferentialPositionY] -> GetColor().compare(TurnColor) != 0) {
        std::cerr << "TURNO DEL JUGADOR " << TurnColor << std::endl;
        return;
    }

    std::cout << "Posicion donde presiono primero [" << ReferentialPositionX << "," << ReferentialPositionY << "]\n";

    QByteArray itemData;
    QDataStream dataStream( & itemData, QIODevice::WriteOnly);
    dataStream << QPoint(event -> pos() - child -> pos());

    QMimeData * mimeData = new QMimeData();
    mimeData -> setData("application/x-dnditemdata", itemData);

    QDrag * drag = new QDrag(this);
    drag -> setMimeData(mimeData);

    drag -> exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
}

void Board::ChangeTurnColor() {
    if (TurnColor.compare("White") == 0)
        TurnColor = "Black";
    else
        TurnColor = "White";
}

Board::~Board() {
    delete ui;
}
