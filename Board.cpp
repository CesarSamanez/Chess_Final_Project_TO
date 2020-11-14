#include "Board.h"
#include "ui_Board.h"

Board::Board(QWidget *parent) : QWidget(parent), ui(new Ui::Board)
{
    ui->setupUi(this);

    /* Siempre declarar para que funcione */
    setAcceptDrops(true);

    /* Inicializar tablero de ajedrez */
    initializeBoard();
}

Board::~Board()
{
    delete ui;
}

void Board::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0, width(), height(), BoardIcon);

}

void Board::dragMoveEvent(QDragMoveEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if(event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void Board::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if(event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void Board::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        QByteArray data = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&data, QIODevice::ReadOnly);

        QPoint offset;
        dataStream >> offset;

        black_queen->move(event->pos() - offset);


        if(event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();

    }
}

void Board::mousePressEvent(QMouseEvent *event)
{

    auto child = childAt(event->pos());
    if(child == nullptr)
    {
        std::cout<<"null\n";
        return;
    }
    std::cout<<"child\n";

    QByteArray data;
    QDataStream dataStream(&data, QIODevice::WriteOnly);
    dataStream<<QPoint(event->pos()-child->pos());

    QMimeData *mimeData = new QMimeData();
    mimeData->setData("application/x-dnditemdata", data);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);

    drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);


}

void Board::initializeBoard(){
    /* Leer icono */
    BoardIcon.load("../Chess_Final_Project_TO/Images/chess_board.png");

    /* Inicializar piezas en el tablero */
    initializePieces();
}

void Board::initializePieces(){
    /* Asignar memoria a objetos creados */
    // Piezas negras
    black_rook1 = std::make_unique<Rook>(this, "Black");
    black_rook2 = std::make_unique<Rook>(this, "Black");
    black_knight1 = std::make_unique<Knight>(this, "Black");
    black_knight2 = std::make_unique<Knight>(this, "Black");
    black_bishop1 = std::make_unique<Bishop>(this, "Black");
    black_bishop2 = std::make_unique<Bishop>(this, "Black");
    black_king = std::make_unique<King>(this, "Black");
    black_queen = std::make_unique<Queen>(this, "Black");
    black_pawn1 = std::make_unique<Pawn>(this, "Black");
    black_pawn2 = std::make_unique<Pawn>(this, "Black");
    black_pawn3 = std::make_unique<Pawn>(this, "Black");
    black_pawn4 = std::make_unique<Pawn>(this, "Black");
    black_pawn5 = std::make_unique<Pawn>(this, "Black");
    black_pawn6 = std::make_unique<Pawn>(this, "Black");
    black_pawn7 = std::make_unique<Pawn>(this, "Black");
    black_pawn8 = std::make_unique<Pawn>(this, "Black");

    // Piezas blancas
    white_rook1 = std::make_unique<Rook>(this, "White");
    white_rook2 = std::make_unique<Rook>(this, "White");
    white_knight1 = std::make_unique<Knight>(this, "White");
    white_knight2 = std::make_unique<Knight>(this, "White");
    white_bishop1 = std::make_unique<Bishop>(this, "White");
    white_bishop2 = std::make_unique<Bishop>(this, "White");
    white_king = std::make_unique<King>(this, "White");
    white_queen = std::make_unique<Queen>(this, "White");
    white_pawn1 = std::make_unique<Pawn>(this, "White");
    white_pawn2 = std::make_unique<Pawn>(this, "White");
    white_pawn3 = std::make_unique<Pawn>(this, "White");
    white_pawn4 = std::make_unique<Pawn>(this, "White");
    white_pawn5 = std::make_unique<Pawn>(this, "White");
    white_pawn6 = std::make_unique<Pawn>(this, "White");
    white_pawn7 = std::make_unique<Pawn>(this, "White");
    white_pawn8 = std::make_unique<Pawn>(this, "White");

    /* Crear piezas y asignarlas a su posicion de inicio */
    creationOfPieces();

}

void Board::creationOfPieces(){

    /*
     * Creacion de piezas y colocarlos en el tablero
     * mediante posiciones
     */

    // Piezas negras
    black_rook1->move(0,0);
    black_rook1->show();
    black_rook2->move(560,0);
    black_rook2->show();
    black_knight1->move(80,0);
    black_knight1->show();
    black_knight2->move(480,0);
    black_knight2->show();
    black_bishop1->move(160,0);
    black_bishop1->show();
    black_bishop2->move(400,0);
    black_bishop2->show();
    black_king->move(320,0);
    black_king->show();
    black_queen->move(240,0);
    black_queen->show();
    black_pawn1->move(0,80);
    black_pawn1->show();
    black_pawn2->move(80,80);
    black_pawn2->show();
    black_pawn3->move(160,80);
    black_pawn3->show();
    black_pawn4->move(240,80);
    black_pawn4->show();
    black_pawn5->move(320,80);
    black_pawn5->show();
    black_pawn6->move(400,80);
    black_pawn6->show();
    black_pawn7->move(480,80);
    black_pawn7->show();
    black_pawn8->move(560,80);
    black_pawn8->show();

   // Piezas blancas
    white_rook1->move(0,560);
    white_rook1->show();
    white_rook2->move(560,560);
    white_rook2->show();
    white_knight1->move(80,560);
    white_knight1->show();
    white_knight2->move(480,560);
    white_knight2->show();
    white_bishop1->move(160,560);
    white_bishop1->show();
    white_bishop2->move(400,560);
    white_bishop2->show();
    white_king->move(240,560);
    white_king->show();
    white_queen->move(320,560);
    white_queen->show();
    white_pawn1->move(0,480);
    white_pawn1->show();
    white_pawn2->move(80,480);
    white_pawn2->show();
    white_pawn3->move(160,480);
    white_pawn3->show();
    white_pawn4->move(240,480);
    white_pawn4->show();
    white_pawn5->move(320,480);
    white_pawn5->show();
    white_pawn6->move(400,480);
    white_pawn6->show();
    white_pawn7->move(480,480);
    white_pawn7->show();
    white_pawn8->move(560,480);
    white_pawn8->show();
}
