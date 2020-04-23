#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>


class circuit
{
private:
    QString id;
    QString zone_debut;
    QString zone_fin;
    QString agent;
    QString matricule_vehicule;
public:
    circuit();
    circuit(QString,QString,QString,QString,QString);
    bool ajouter_cir();
    QSqlQueryModel * afficher_cir();
    bool supprimer_cir(QString);
    bool modifier_cir(QString,QString,QString,QString,QString);
    QSqlQueryModel * rechercher_cir_dynamique(QString a);
    QSqlQueryModel * tri_cir();
    QSqlQueryModel * afficher_id();

};

#endif // CIRCUIT_H
