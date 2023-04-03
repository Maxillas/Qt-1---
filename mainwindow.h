#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QTimer>
#include <QVBoxLayout>
#include <QDebug>
#include <QRandomGenerator>
#include <QWidget>
#include <QCursor>
#include <QPointF>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget * window = nullptr;
    QTimer * timer = nullptr;
    QTimer * speedChangeTimer = nullptr;
    QTimer * runningCheckPoint = nullptr;
    QRandomGenerator * generator = nullptr;

};
#endif // MAINWINDOW_H
