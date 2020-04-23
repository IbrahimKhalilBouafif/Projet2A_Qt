#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainproject.h"
#include <QMessageBox>
#include <QSsl>
#include <QSslSocket>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    mainproject *p= new mainproject();
    if(ui->lineEdit->text()=="wassim"&&ui->lineEdit_2->text()=="wassim")
    p->show();
    else {
        QMessageBox::information(nullptr, QObject::tr("Erreur"),
                          QObject::tr("mot de passe ou login fausse.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    this->hide();
}
