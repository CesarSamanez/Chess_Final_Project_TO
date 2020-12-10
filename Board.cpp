#include "Board.h"

#include "ui_Board.h"

Board::Board(QWidget * parent): QWidget(parent), ui(new Ui::Board) {
    ui -> setupUi(this);

    // Siempre declarar para que funcione
    setAcceptDrops(true);

    // Imagen del tablero
    BoardIcon.load("../Chess_Final_Project_TO/Images/chess_board.png");

    // Inicializar tablero de ajedrez
    InitializeBoard();
}

void Board::InitializeBoard() {
    // Mapeo de piezas
    MappingOfPieces();

    // Inicializar piezas en el tablero
    PositionPiecesInBoard();
}

void Board::PositionPiecesInBoard() {
    // Creacion de piezas y colocarlos en el tablero mediante posiciones
    for (size_t row = 0; row < 8; row++) {
        for (size_t col = 0; col < 8; col++) {
            if (row < 2 || row > 5) {
                MyBoard[row][col] -> move(col * 80, row * 80);
                MyBoard[row][col] -> show();
                MyBoard[row][col] -> SetPosition(row, col);
            }
        }
    }
}

void Board::MappingOfPieces() {
    /* Piezas negras */
    MyBoard[0][0] = black_rook1;
    MyBoard[0][1] = black_knight1;
    MyBoard[0][2] = black_bishop1;
    MyBoard[0][3] = black_king;
    MyBoard[0][4] = black_queen;
    MyBoard[0][5] = black_bishop2;
    MyBoard[0][6] = black_knight2;
    MyBoard[0][7] = black_rook2;
    MyBoard[1][0] = black_pawn1;
    MyBoard[1][1] = black_pawn2;
    MyBoard[1][2] = black_pawn3;
    MyBoard[1][3] = black_pawn4;
    MyBoard[1][4] = black_pawn5;
    MyBoard[1][5] = black_pawn6;
    MyBoard[1][6] = black_pawn7;
    MyBoard[1][7] = black_pawn8;

    /* Piezas blancas */
    MyBoard[7][0] = white_rook1;
    MyBoard[7][1] = white_knight1;
    MyBoard[7][2] = white_bishop1;
    MyBoard[7][3] = white_queen;
    MyBoard[7][4] = white_king;
    MyBoard[7][5] = white_bishop2;
    MyBoard[7][6] = white_knight2;
    MyBoard[7][7] = white_rook2;
    MyBoard[6][0] = white_pawn1;
    MyBoard[6][1] = white_pawn2;
    MyBoard[6][2] = white_pawn3;
    MyBoard[6][3] = white_pawn4;
    MyBoard[6][4] = white_pawn5;
    MyBoard[6][5] = white_pawn6;
    MyBoard[6][6] = white_pawn7;
    MyBoard[6][7] = white_pawn8;

}

bool Board::ValidateMovement(const int & rowInitial, const int & colInitial, const int & rowFinal, const int & colFinal) {
    auto piecePosition = MyBoard[rowInitial][colInitial];
    std::vector < std::pair < int, int >> misMovimientos;

    misMovimientos = piecePosition -> PossibleMoves(MyBoard);
    DrawMovements(misMovimientos);
    piecePosition -> PossibleMoves(MyBoard);

    if (piecePosition -> GetName().compare("Rook") == 0) {
        return piecePosition -> MovePiece(MyBoard, rowFinal, colFinal);
    } else if (piecePosition -> GetName().compare("Knight") == 0) {
        return piecePosition -> MovePiece(MyBoard, rowFinal, colFinal);
    } else if (piecePosition -> GetName().compare("Bishop") == 0) {
        return piecePosition -> MovePiece(MyBoard, rowFinal, colFinal);
    } else if (piecePosition -> GetName().compare("Queen") == 0) {
        return piecePosition -> MovePiece(MyBoard, rowFinal, colFinal);
    } else if (piecePosition -> GetName().compare("King") == 0) {
        return piecePosition -> MovePiece(MyBoard, rowFinal, colFinal);
    } else if (piecePosition -> GetName().compare("Pawn") == 0) {
        return piecePosition -> MovePiece(MyBoard, rowFinal, colFinal);
    }

    return false;
}

void Board::Check(const Piece * piece) {
    if (piece -> GetName().compare("King") != 0) {
        // Futuros movimientos
        std::vector < std::pair < int, int >> futureMovements = piece -> PossibleMoves(MyBoard);
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
    std::string tmpColor;
    int countKings = 0, countBishops = 0, countBishopsDifferentColor = 0, countKnights = 0, totalPieces = 0;
    for (size_t row = 0; row < 8; row++) {
        for (size_t col = 0; col < 8; col++) {
            if(MyBoard[row][col]!=nullptr){
                if (MyBoard[row][col]->GetName().compare("King") == 0) {
                    countKings++;
                }else if(MyBoard[row][col]->GetName().compare("Bishop") == 0){
                    if(countBishops == 0) //Asignar el color al primer alfil
                    {
                        tmpColor=MyBoard[row][col]->GetColor();
                        countBishopsDifferentColor++;
                    }
                    if(MyBoard[row][col]->GetColor().compare(tmpColor)!= 0)
                    {
                        countBishopsDifferentColor++;
                    }
                    countBishops++;
                }else if(MyBoard[row][col]->GetName().compare("Knight") == 0){
                    countKnights++;
                }else{
                    totalPieces++;
                }
            }
        }
    }

    std::cout<<"TOTAL PIECES: "<<totalPieces<<std::endl;

    // Casos: Rey contra rey, rey contra rey y alfil, rey contra rey y caballo, rey, alfil contra rey, alfil del mismo color
    if(totalPieces == 0 && ((countKings == 2)||((countKings + countBishops) == 3)||((countKings + countBishopsDifferentColor) == 4))){
        QMessageBox message;
        message.setText("Dead Position");
        message.exec();
        std::cout << "Dead Position\n";
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
        if (posibbleMovementsInBoard[index] -> y() == PositionInitialX * 80 + 30 && posibbleMovementsInBoard[index] -> x() == PositionInitialY * 80 + 30) {
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

        //Recalcular posicion de cada pieza
        PositionFinalX = (event -> pos().y() / 80);
        PositionFinalY = (event -> pos().x() / 80);
        std::cout << "Posicion hacia donde me dirijo [" << PositionFinalX << "," << PositionFinalY << "]\n";

        if (isCastlingKing()) { //Enroque
            if (TurnColor.compare("White") == 0) {
                if (PositionFinalY == 0) //Enroque largo
                    CastlingKing(PositionInitialY - 1, PositionFinalY + 2);

                if (PositionFinalY == 7) //Enroque corto
                    CastlingKing(PositionInitialY + 1, PositionFinalY - 1);
            } else if (TurnColor.compare("Black") == 0) {
                if (PositionFinalY == 7) //Enroque largo
                    CastlingKing(PositionInitialY + 1, PositionFinalY - 2);

                if (PositionFinalY == 0) //Enroque corto
                    CastlingKing(PositionInitialY - 1, PositionFinalY + 1);
            }
            return;
        }

        //Movimientos normales y capturas
        if (ValidateMovement(PositionInitialX, PositionInitialY, PositionFinalX, PositionFinalY)) {
            if (MyBoard[PositionInitialX][PositionInitialY] -> Capture(MyBoard, PositionFinalX, PositionFinalY)) {
                // Validacion para promocion de peon
                if (MyBoard[PositionInitialX][PositionInitialY] -> GetName().compare("Pawn") == 0 && (PositionFinalX == 0 || PositionFinalX == 7)) {
                    MyBoard[PositionFinalX][PositionFinalY] -> setVisible(false);
                    std::cout << "Se capturo la pieza [" << PositionFinalX << "," << PositionFinalY << "]\n";
                    ChekMate(MyBoard[PositionFinalX][PositionFinalY]); //validar JaqueMate
                    MyBoard[PositionInitialX][PositionInitialY] -> setVisible(false);

                    // Promocion de peon
                    Piece * tmp = PromotionOfPawn(TurnColor);
                    tmp -> move(PositionFinalY * 80, PositionFinalX * 80);
                    tmp -> setVisible(true);

                    MyBoard[PositionFinalX][PositionFinalY] = tmp;
                    MyBoard[PositionFinalX][PositionFinalY] -> SetColor(MyBoard[PositionInitialX][PositionInitialY] -> GetColor());
                    MyBoard[PositionFinalX][PositionFinalY] -> SetPosition(PositionFinalX, PositionFinalY);
                    Check(MyBoard[PositionFinalX][PositionFinalY]); //chequea jaque
                    MyBoard[PositionInitialX][PositionInitialY] = nullptr;

                    DeadPosition(); //Verifica posicion muerta
                } else {
                    // Captura de pieza
                    MyBoard[PositionFinalX][PositionFinalY] -> setVisible(false);
                    std::cout << "Se capturo la pieza [" << PositionFinalX << "," << PositionFinalY << "]\n";
                    ChekMate(MyBoard[PositionFinalX][PositionFinalY]); //validar JaqueMate
                    MyBoard[PositionInitialX][PositionInitialY] -> move(PositionFinalY * 80, PositionFinalX * 80);
                    MyBoard[PositionFinalX][PositionFinalY] = MyBoard[PositionInitialX][PositionInitialY];
                    MyBoard[PositionFinalX][PositionFinalY] -> SetColor(MyBoard[PositionInitialX][PositionInitialY] -> GetColor());
                    MyBoard[PositionFinalX][PositionFinalY] -> SetPosition(PositionFinalX, PositionFinalY);
                    Check(MyBoard[PositionFinalX][PositionFinalY]); //chequea jaque
                    MyBoard[PositionInitialX][PositionInitialY] = nullptr;

                    DeadPosition(); //Verifica posicion muerta
                }
            } else if (MyBoard[PositionFinalX][PositionFinalY] == nullptr) {
                if (MyBoard[PositionInitialX][PositionInitialY] -> GetName().compare("Pawn") == 0 && (PositionFinalX == 0 || PositionFinalX == 7)) {
                    MyBoard[PositionInitialX][PositionInitialY] -> setVisible(false);
                    // Promocion de peon
                    Piece * tmp = PromotionOfPawn(TurnColor);
                    tmp -> move(PositionFinalY * 80, PositionFinalX * 80);
                    tmp -> setVisible(true);

                    MyBoard[PositionFinalX][PositionFinalY] = tmp;
                    MyBoard[PositionFinalX][PositionFinalY] -> SetColor(MyBoard[PositionInitialX][PositionInitialY] -> GetColor());
                    MyBoard[PositionFinalX][PositionFinalY] -> SetPosition(PositionFinalX, PositionFinalY);
                    Check(MyBoard[PositionFinalX][PositionFinalY]); //chequea jaque
                    MyBoard[PositionInitialX][PositionInitialY] = nullptr;

                    DeadPosition(); //Verifica posicion muerta
                } else {
                    //Mover pieza nueva posicion
                    MyBoard[PositionInitialX][PositionInitialY] -> move(PositionFinalY * 80, PositionFinalX * 80);
                    MyBoard[PositionFinalX][PositionFinalY] = MyBoard[PositionInitialX][PositionInitialY];
                    MyBoard[PositionFinalX][PositionFinalY] -> SetColor(MyBoard[PositionInitialX][PositionInitialY] -> GetColor());
                    MyBoard[PositionFinalX][PositionFinalY] -> SetPosition(PositionFinalX, PositionFinalY);
                    MyBoard[PositionInitialX][PositionInitialY] = nullptr;
                    //chequear jaque de la nueva posicion
                    Check(MyBoard[PositionFinalX][PositionFinalY]);
                }

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
            ChangeTurnColor(); // Cambio de turno de jugador
        } else {
            event -> ignore();
        }
        DeadPosition();
    } else {
        return;
    }

}

Piece * Board::PromotionOfPawn(const std::string & _color) {
    Piece * PawnPromotionPiece;

    QStringList piecesPromotion;
    piecesPromotion << "Bishop";
    piecesPromotion << "Knight";
    piecesPromotion << "Queen";
    piecesPromotion << "Rook";

    std::string itemPromotion = QInputDialog::getItem(this, "Promotion", "Choose one", piecesPromotion).toStdString();

    if (itemPromotion.compare("Bishop") == 0) {
        PawnPromotionPiece = new Bishop(this, _color);
    } else if (itemPromotion.compare("Knight") == 0) {
        PawnPromotionPiece = new Knight(this, _color);
    } else if (itemPromotion.compare("Queen") == 0) {
        PawnPromotionPiece = new Queen(this, _color);
    } else if (itemPromotion.compare("Rook") == 0) {
        PawnPromotionPiece = new Rook(this, _color);
    } else {
        PawnPromotionPiece = nullptr;
    }

    return PawnPromotionPiece;
}

void Board::mousePressEvent(QMouseEvent * event) {
    auto child = childAt(event -> pos());

    PositionInitialX = event -> pos().y() / 80;
    PositionInitialY = event -> pos().x() / 80;

    if (child == nullptr || isAdvertenceWidget() || MyBoard[PositionInitialX][PositionInitialY] -> GetColor().compare(TurnColor) != 0) {
        std::cerr << "TURNO DEL JUGADOR " << TurnColor << std::endl;
        return;
    }

    std::cout << "Posicion donde presiono primero [" << PositionInitialX << "," << PositionInitialY << "]\n";

    QByteArray itemData;
    QDataStream dataStream( & itemData, QIODevice::WriteOnly);
    dataStream << QPoint(event -> pos() - child -> pos());

    QMimeData * mimeData = new QMimeData();
    mimeData -> setData("application/x-dnditemdata", itemData);

    QDrag * drag = new QDrag(this);
    drag -> setMimeData(mimeData);

    drag -> exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
}

bool Board::isCastlingKing() {
    if (MyBoard[PositionInitialX][PositionInitialY] -> GetName().compare("King") == 0) {
        if ((PositionFinalX == 7 || PositionFinalX == 0) && (PositionFinalY == 0 || PositionFinalY == 7)) {
            if (MyBoard[PositionFinalX][PositionFinalY] -> GetName().compare("Rook") == 0 && MyBoard[PositionInitialX][PositionInitialY] -> GetColor().compare(TurnColor) == 0) {
                if (PositionFinalY == 0) {
                    return MyBoard[PositionFinalX][PositionFinalY] -> MovePiece(MyBoard, PositionInitialX, PositionInitialY - 1);
                }
                if (PositionFinalY == 7) {
                    return MyBoard[PositionFinalX][PositionFinalY] -> MovePiece(MyBoard, PositionInitialX, PositionInitialY + 1);
                }
            }
        }
    }

    return false;
}

void Board::CastlingKing(const int PositionModifiedInitialY, const int PositionModifiedFinalY) {
    std::cout << "Mover Rey ->[" << PositionFinalX << "," << PositionModifiedFinalY << "]" << std::endl;
    std::cout << "Mover Torre ->[" << PositionInitialX << "," << PositionModifiedInitialY << "]" << std::endl;

    MyBoard[PositionFinalX][PositionModifiedFinalY] = MyBoard[PositionInitialX][PositionInitialY];
    MyBoard[PositionFinalX][PositionModifiedFinalY] -> move(PositionModifiedFinalY * 80, PositionFinalX * 80);
    MyBoard[PositionFinalX][PositionModifiedFinalY] -> SetPosition(PositionFinalX, PositionModifiedFinalY);
    MyBoard[PositionInitialX][PositionInitialY] = nullptr;

    MyBoard[PositionInitialX][PositionModifiedInitialY] = MyBoard[PositionFinalX][PositionFinalY];
    MyBoard[PositionInitialX][PositionModifiedInitialY] -> move(PositionModifiedInitialY * 80, PositionInitialX * 80);
    MyBoard[PositionInitialX][PositionModifiedInitialY] -> SetPosition(PositionInitialX, PositionModifiedInitialY);
    MyBoard[PositionFinalX][PositionFinalY] = nullptr;

    RemoveDrawnMovements();
    ChangeTurnColor();
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
