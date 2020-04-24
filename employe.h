#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employe
{
public:
    employe();
    employe(int,QString,QString,int,QString,QString,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    int get_age();
    QString get_sexe();
    QString get_disponibilite();
    QString get_departement();


    bool ajouter();
    QSqlQueryModel *  afficher();

    QSqlQueryModel* trier_nomasc1();
    QSqlQueryModel* trier_nomdesc1();
    QSqlQueryModel* trier_idasc1();
    QSqlQueryModel* trier_iddesc1();
    QSqlQueryModel* trier_disponibilite1();



    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel *rechercherparnom1(const QString &);
    QSqlQueryModel *Find_Employe();
private:

    int id,age;
    QString nom,prenom,sexe,departement,disponibilite;

};

#endif // EMPLOYE_H



