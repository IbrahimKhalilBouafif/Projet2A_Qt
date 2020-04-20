#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Evenement
{
public:
    Evenement();
    Evenement(int,QString,QString,QDate,QDate);
    QString get_nom();
    QString get_description();
    int get_id();
    QDate get_datedebut();
     QDate get_datfin();
 bool ajouter();
 QSqlQueryModel * afficher();
 QSqlQueryModel * tri();
 QSqlQueryModel* count(QString id);
 QSqlQueryModel * recherche(QString);

  bool supprimer(int);
    bool update(int);

    private:
    QString nom,description;
    int id;
    QDate date_debut;
        QDate date_fin;

};


#endif // EVENEMENT_H
