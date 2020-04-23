#ifndef VEHICULE_H
#define VEHICULE_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "qcustomplot.h"

class vehicule
{
private:
    QString matricule;
    QString marque;
    QString couleur;
    QString agent;
    QString zone;
public:
    vehicule();
    vehicule(QString,QString,QString,QString,QString);
    bool ajouter_veh();
    QSqlQueryModel * afficher_veh();
    bool supprimer_veh(QString);
    bool modifier_veh(QString,QString,QString,QString,QString);
    QSqlQueryModel * rechercher_veh_dynamique(QString a);
    QSqlQueryModel * tri_veh();
    void stat(QCustomPlot*);
    QSqlQueryModel * afficher_id();
};

#endif // VEHICULE_H
