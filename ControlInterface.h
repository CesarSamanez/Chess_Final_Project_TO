#ifndef CONTROLINTERFACE_H
#define CONTROLINTERFACE_H

#include <QWidget>
#include <iostream>

namespace Ui {
class ControlInterface;
}

class ControlInterface : public QWidget
{
    Q_OBJECT

public:
    explicit ControlInterface(QWidget *parent = nullptr);
    void UpdateTurn(const std::string color);
    void UpdateCounterPieces(const std::string typeOfPiece, const std::string colorOfPiece);
    ~ControlInterface();

private:
    Ui::ControlInterface *ui;
};

#endif // CONTROLINTERFACE_H
