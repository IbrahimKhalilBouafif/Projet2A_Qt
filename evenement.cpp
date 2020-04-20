#include "evenement.h"
#include <QDebug>
#include "connexion.h"
#include<QDate>

Evenement::Evenement()
{
    id=0;
    nom="";

  description="";
}
Evenement::Evenement(int id,QString nom,QString description,QDate date_debut,QDate date_fin)
{
    this->id=id;
  this->nom=nom;

    this->description=description;
    this->date_debut=date_debut;
    this->date_fin=date_fin;


}
QString Evenement::get_nom(){return  nom;}
QString Evenement::get_description(){return description;}
int Evenement::get_id(){return  id;}
QDate Evenement::get_datedebut(){return date_debut;}
QDate Evenement::get_datfin(){return date_fin;}

bool Evenement::ajouter()
{
QSqlQuery query;
//QString res= QString::number(id);
query.prepare("INSERT INTO evenement (NOM, DESCRIPTION,DATE_DEBUT,DATE_FIN) "
                    "VALUES (:nom, :description,:date_debut,:date_fin)");
//query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":description", description);
query.bindValue(":date_debut", date_debut);
query.bindValue(":date_fin", date_fin);


return    query.exec();
}
QSqlQueryModel * Evenement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from evenement");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_debut"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_fin"));

    return model;
}
bool Evenement::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from evenement where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
QSqlQueryModel * Evenement::tri()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from evenement ORDER BY NOM ASC");
/*model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_debut"));*/
    return model;
}

QSqlQueryModel* Evenement ::recherche(QString nom)
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* model=new QSqlQueryModel();
    qry->prepare("select * from evenement where NOM='"+nom+"' ");
    qry->exec();
    model->setQuery(*qry);

  return model;

}

QSqlQueryModel* Evenement ::count(QString id)
{
QSqlQueryModel* modal=new QSqlQueryModel();
QSqlQuery* query=new QSqlQuery();
query->prepare("SELECT * FROM evenement where id='"+id+"'");
query->exec();
modal->setQuery(*query);
return modal;

}



bool Evenement::update(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Update evenement set NOM= :nom , DESCRIPTION= :description , DATE_DEBUT= :date_debut , DATE_FIN= :date_fin where ID = :id ");
    query.bindValue(":id", res) ;
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":date_debut",date_debut);
    query.bindValue(":date_fin",date_fin);

    return    query.exec();
}
