#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class departement
{
public:
    departement();
    departement(int,QString,QString,int);
    int get_id();
    QString get_nom();
    QString get_responsable();
    int get_nb_employes();

    bool ajouter();
    QSqlQueryModel *  afficher();

    QSqlQueryModel* trier_nomasc();
    QSqlQueryModel* trier_nomdesc();
    QSqlQueryModel* trier_idasc();
    QSqlQueryModel* trier_iddesc();
    QSqlQueryModel* trier_nbempasc();
    QSqlQueryModel* trier_nbempdesc();




    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel *rechercherparnom(const QString &);
    QSqlQueryModel *Find_Departement();

    QString c ;
private:
    int id,nb_employes;
    QString nom,responsable;

};

#endif // DEPARTEMENT_H
