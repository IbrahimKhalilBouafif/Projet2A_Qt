#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainproject.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    mainproject *p= new mainproject();
    p->show();
    this->hide();
}
