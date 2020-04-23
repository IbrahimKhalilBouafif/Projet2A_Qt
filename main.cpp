#include "mainwindow.h"

#include <QApplication>
#include "connexion.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connexion c;

    try{
        c.ouvrirconnexion();
        w.show();
    }catch(QString s){
        qDebug()<<s;}
    return a.exec();
}
