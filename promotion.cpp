#include "promotion.h"
#include <QDebug>
#include "connexion.h"
#include <QString>


promotion::promotion()
{
    id="";
    pourcentage=0;
    duree=0;
    id_evenement=0;

}


promotion::promotion(QString id,int pourcentage,int duree,int id_evenement)
{
    this->id=id;
  this->pourcentage=pourcentage;

    this->duree=duree;
    this->id_evenement=id_evenement;


}
QString promotion::get_id(){return  id;}
int promotion::get_pourcentage(){return pourcentage;}
int promotion::get_duree(){return duree;}
int promotion::get_idevenement(){return id_evenement;}
bool promotion::ajouterpromo()
{
QSqlQuery query;
query.prepare("INSERT INTO promotion (ID, POURCENTAGE, DUREE, ID_EVENEMENT) "
                    "VALUES (:id, :pourcentage, :duree,:id_evenement)");
query.bindValue(":id", id);
query.bindValue(":pourcentage", pourcentage);
query.bindValue(":duree", duree);
query.bindValue(":id_evenement", id_evenement);


return    query.exec();
}

QSqlQueryModel * promotion::afficher2()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from promotion");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Pourcentage "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Duree"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_Evenement"));

    return model;
}
bool promotion::supprimer(QString idd)
{
QSqlQuery query;
query.prepare("Delete from promotion where ID = :id ");
query.bindValue(":id", idd);
return    query.exec();
}
/*QSqlQueryModel * promotion ::recherche(QString a)
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* model=new QSqlQueryModel();
    qry->prepare("select * from evenement where ID='"+a+"' ||'%' ");
      qry->bindValue(":id",a);
    qry->exec();
    model->setQuery(*qry);
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("pourcentage"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_evenement"));

  return model;
    QSqlQueryModel * model= new QSqlQueryModel();
      QSqlQuery query;
      query.prepare("SELECT * FROM circuit where ID like '"+id+"' ||'%'");
      query.bindValue(":id",a);
      query.exec();
      model->setQuery(query);
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("pourcentage"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_evenement"));
          return model;

}*/
QSqlQueryModel* promotion ::recherche(QString a)
{

    QSqlQuery* qry = new QSqlQuery();
     QSqlQueryModel* model=new QSqlQueryModel();
    qry->prepare("select * from promotion where ID='"+a+"' ");
    qry->exec();
    model->setQuery(*qry);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("pourcentage"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id_evenement"));

  return model;

}
bool promotion::update1(QString idd)
{
    QSqlQuery query;
    query.prepare("Update promotion set pourcentage= :pourcentage , duree= :duree , ID_EVENEMENT= :id_evenement where ID = :id ");
    query.bindValue(":id", idd) ;
    query.bindValue(":pourcentage", pourcentage);
    query.bindValue(":duree", duree);
    query.bindValue(":id_evenement",id_evenement);

    return    query.exec();
}

