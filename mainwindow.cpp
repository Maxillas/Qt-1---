#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    window  = new QWidget;
    window->resize(500,500);
    timer = new QTimer(this);
    int interval = QRandomGenerator::global()->bounded(100,1000);
    timer->start(interval);

    auto createButton = [=](){

        QPushButton * button = new QPushButton(".", window);

        int x = QRandomGenerator::global()->bounded(window->frameGeometry().width() - 30);
        int y = QRandomGenerator::global()->bounded(100);

        button->move(x, y);
        button->resize(30,30);
        button->show();
        button->setStyleSheet("background-color: blue");

        int buttonSpeed = QRandomGenerator::global()->bounded(1000);
        speedChangeTimer = new QTimer(button);
        speedChangeTimer->start(buttonSpeed);

        auto movebutton = [=](){
            int speed = 5;
            if (button->y() + 60 >= window->frameGeometry().height()) {
                window->setWindowTitle("You Lose!");
                window->setStyleSheet("background-color: red");
            } else button->move(button->x(), button->y() + speed);

            QPoint CoursorGlobal = QCursor::pos();
            QPoint CoursorWidget = window->mapFromGlobal(CoursorGlobal);

            if ((CoursorWidget.x() <= button->x() + 30) && (CoursorWidget.x() >= button->x())
            && (CoursorWidget.y() <= button->y() + 30) && (CoursorWidget.y() >= button->y())) {

                speedChangeTimer->start(buttonSpeed/10);

            }
        };

        QObject::connect(speedChangeTimer, QTimer::timeout, button, movebutton);



        auto deletebutton = [=](){
            delete button;
        };

        QObject::connect(button, &QPushButton::clicked, button, deletebutton);

    };

    QObject::connect(timer, QTimer::timeout, this, createButton);




    window->show();

}

MainWindow::~MainWindow()
{
    //delete window; //Нужно ли?
   // delete button;
}
