#include "employe.h"
#include <QDebug>


employe::employe()
{

}

employe::employe(int id,QString nom,QString prenom,int age,QString sexe,QString disponibilite,QString departement )
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->sexe=sexe;
    this->disponibilite=disponibilite;
    this->departement=departement;



}

int employe::get_id(){return  id;}
QString employe::get_nom(){return  nom;}
QString employe::get_prenom(){return  prenom;}
int employe::get_age(){return  age;}
QString employe::get_sexe(){return  sexe;}
QString employe::get_disponibilite(){return  disponibilite;}
QString employe::get_departement(){return  departement;}




bool employe::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO employe (NOM, PRENOM,AGE,SEXE,DISPONIBILITE,DEPARTEMENT) "
                    "VALUES (:nom, :prenom, :age, :sexe, :disponibilite, :departement)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":age", age);
query.bindValue(":sexe", sexe);
query.bindValue(":disponibilite", disponibilite);
query.bindValue(":departement", departement);


return    query.exec();
}

QSqlQueryModel * employe::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from employe");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Age"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Sexe"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Disponibilite"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Departement"));

    return model;
}


QSqlQueryModel *employe::trier_nomasc1()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY NOM ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Disponibilite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Departement"));
    return model;
}
QSqlQueryModel *employe::trier_nomdesc1()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY NOM DESC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Disponibilite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Departement"));
    return model;
}
QSqlQueryModel *employe::trier_idasc1()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY ID ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Disponibilite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Departement"));

    return model;
}
QSqlQueryModel *employe::trier_iddesc1()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe ORDER BY ID DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Disponibilite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Departement"));

    return model;
}
QSqlQueryModel *employe::trier_disponibilite1()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM employe WHERE DISPONIBILITE = 'Oui' ");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Disponibilite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Departement"));

    return model;
}








bool employe::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from employe where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}



bool employe::modifier(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE employe SET NOM = :nom,PRENOM = :prenom,AGE = :age,SEXE = :sexe,DISPONIBILITE = :disponibilite,DEPARTEMENT = :departement where ID = :id");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
    query.bindValue(":sexe",sexe);
    query.bindValue(":disponibilite",disponibilite);
    query.bindValue(":departement", departement);
    query.bindValue(":id", res);
    return    query.exec();
}

QSqlQueryModel *employe::rechercherparnom1(const QString &c)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from employe where (NOM LIKE '"+c+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Disponibilite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Departement"));

    return model;
}

/*QSqlQueryModel * employe::Find_Employe(QString id)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT id,nom,prenom,age,sexe,disponibilite,departement FROM employe WHERE id='"+id+"'");
    query.bindValue(0,id);
    query.exec();
    model->setQuery(query);
    return model;
}
*/

QSqlQueryModel * employe::Find_Employe()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT id,nom,prenom,age,sexe,disponibilite,departement FROM employe");
    //query.bindValue(0,id);
    query.exec();
    model->setQuery(query);
    return model;
}
