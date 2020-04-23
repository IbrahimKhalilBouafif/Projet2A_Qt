#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainproject.h"
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSslSocket>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("Login Smart Rapid Post");
    QWidget::setWindowIcon(QIcon(":/new/icon/logo.png"));
    qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString user=ui->lineEdit->text();
    QString mdp=ui->lineEdit_2->text();
    QSqlQuery qry;
    qry.prepare("select ID from COMPTE where LOGIN = :user AND MDP = :mdp");
    qry.bindValue(":user",user);
    qry.bindValue(":mdp",mdp);
    qry.exec();
    int verif=-1;
    while(qry.next())
        verif=qry.value(0).toInt();
    if(verif!=-1){
        qry.prepare("CREATE TABLE tempo(ID number) ");
        qry.exec();
        qry.prepare("insert into tempo values('"+QString::number(verif)+"')");
        qry.exec();
        mainproject *p= new mainproject();
        p->show();
        this->hide();
    }
    else{
        QMessageBox::critical(this,"Error","Utilisateur ou mot de passe est incorrect");
    }
}
