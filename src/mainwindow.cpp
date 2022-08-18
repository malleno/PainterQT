#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamescene.h"
#include "mousefilter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Field->setScene(new GameScene());
    ui->Field->viewport()->installEventFilter(new MouseFilter(ui->Field, dynamic_cast<GameScene*>(ui->Field->scene())));

}

MainWindow::~MainWindow()
{
    delete ui;
}
