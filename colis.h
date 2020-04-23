#ifndef COLIS_H
#define COLIS_H
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

class Colis
{

private:
    int id,expediteur;
    QString destinataire,objet,dimension;
    int poids;
    QString statut;
public:
    Colis();
    Colis(int,int,QString,QString,QString,int,QString);
    int get_id(){return id;}
    int get_expediteur(){return expediteur;}
    QString get_destinataire(){return destinataire;}
    QString get_objet(){return objet;}
    QString get_dimension(){return dimension;}
    int get_poids(){return poids;}
    QString get_statut(){return statut;}
    bool ajouter();
    QSqlQueryModel * afficher(QString search);
    bool supprimer(int);
    bool modifier(int);
    void pdf(int);
    void stat(QCustomPlot*);
    QSqlQueryModel * tri();



};

#endif // COLIS_H
