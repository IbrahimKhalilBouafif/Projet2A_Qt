#include "departement.h"
#include <QDebug>


departement::departement()
{

}

departement::departement(int id,QString nom,QString responsable,int nb_employes)
{

    this->id=id;
    this->nom=nom;
    this->responsable=responsable;
    this->nb_employes=nb_employes;


}

int departement::get_id(){return  id;}
QString departement::get_nom(){return  nom;}
QString departement::get_responsable(){return  responsable;}
int departement::get_nb_employes(){return  nb_employes;}


bool departement::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO departement (NOM, RESPONSABLE, NB_EMPLOYES) "
                    "VALUES (:nom, :responsable, :nb_employes)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":responsable", responsable);
query.bindValue(":nb_employes", nb_employes);

return    query.exec();
}

QSqlQueryModel * departement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from departement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Département"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_Employes"));

    return model;
}

bool departement::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from departement where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}



bool departement::modifier(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE departement SET NOM = :nom,RESPONSABLE = :responsable,NB_EMPLOYES = :nb_employes where ID = :id");
    query.bindValue(":nom",nom);
    query.bindValue(":responsable",responsable);
    query.bindValue(":nb_employes",nb_employes);
    query.bindValue(":id", res);
    return    query.exec();
}

QSqlQueryModel *departement::rechercherparnom(const QString &c)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from departement where (NOM LIKE '"+c+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Département"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_Employes"));

    return model;
}






QSqlQueryModel *departement::trier_nomasc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM departement ORDER BY NOM ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Département"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_Employes"));
    return model;
}
QSqlQueryModel *departement::trier_nomdesc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM departement ORDER BY NOM DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Département"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_Employes"));
    return model;
}
QSqlQueryModel *departement::trier_idasc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM departement ORDER BY ID ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Département"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_Employes"));

    return model;
}
QSqlQueryModel *departement::trier_iddesc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM departement ORDER BY ID DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Département"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_Employes"));

    return model;
}
QSqlQueryModel *departement::trier_nbempasc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM departement ORDER BY NB_Employes ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Département"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_Employes"));

    return model;
}
QSqlQueryModel *departement::trier_nbempdesc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM departement ORDER BY NB_Employes DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Département"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_Employes"));

    return model;
}

QSqlQueryModel * departement::Find_Departement()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT id,nom,responsable,nb_employes FROM departement ");
   // query.bindValue(0,id);
    query.exec();
    model->setQuery(query);
    return model;
}

