#include "mainwindow.h"

#include <QApplication>
#include "connection.h"
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./logo.png"));
    MainWindow w;
    Connection cnx;
    bool t=cnx.createconnect();
    if(t)
        w.show();
    else
        QMessageBox::critical(nullptr,"Error","DataBase connection doesnt open!!!");
    return a.exec();
}
