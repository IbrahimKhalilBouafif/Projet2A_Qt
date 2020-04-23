#ifndef COURRIER_H
#define COURRIER_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QDebug>
#include<QFile>
#include <QDesktopServices>
#include <QUrl>
#include "qcustomplot.h"
#include <QFont>
class Courrier
{
private:
    int id,expediteur;
    QString destinataire,statut;
public:
    Courrier();
    Courrier(int,int,QString,QString);
    int get_id(){return  id;}
    int get_expediteur(){return expediteur;}
    QString get_destinataire(){return destinataire;}
    bool ajouter();
    QSqlQueryModel * afficher(QString search);
    bool supprimer(int);
    bool modifier(int);
    void pdf(int);
    QSqlQueryModel * tri();
    void stat(QCustomPlot*);

};

#endif // COURRIER_H
