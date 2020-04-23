#include "circuit.h"

circuit::circuit()
{
    this->id="";
    this->zone_debut="";
    this->zone_fin="";
    this->agent="";
    this->matricule_vehicule="";
}
circuit::circuit(QString id,QString zd,QString zf,QString ag,QString mv)
{
    this->id=id;
    this->zone_debut=zd;
    this->zone_fin=zf;
    this->agent=ag;
    this->matricule_vehicule=mv;
}
bool circuit::ajouter_cir()
{
    QSqlQuery query;
    query.prepare("INSERT INTO circuit (id,zone_debut,zone_fin,agent,matricule_vehicule) VALUES (:id,:zone_debut,:zone_fin,:agent,:matricule_vehicule)");
    query.bindValue(":id",id);
    query.bindValue(":zone_debut",zone_debut);
    query.bindValue(":agent",agent);
    query.bindValue(":zone_fin",zone_fin);
    query.bindValue(":matricule_vehicule",matricule_vehicule);
    return query.exec();
}
QSqlQueryModel * circuit::afficher_cir()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from circuit");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("zone_debut"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("zone_fin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("agent"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("matricule_vehicule"));
    return model;
}
QSqlQueryModel * circuit::afficher_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select ID from circuit");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    return model;
}

bool circuit::modifier_cir(QString id,QString zone_debut,QString zone_fin,QString agent,QString matricule_vehicule)
{
    QSqlQuery query;
    query.prepare("UPDATE circuit SET id= :id,zone_debut = :zone_debut,zone_fin = :zone_fin,agent = :agent,matricule_vehicule = :matricule_vehicule  WHERE id= :id ");
    query.bindValue(":id",id);
    query.bindValue(":zone_debut",zone_debut);
    query.bindValue(":zone_fin",zone_fin);
    query.bindValue(":agent",agent);
    query.bindValue(":matricule_vehicule",matricule_vehicule);
    return    query.exec();
}
bool circuit::supprimer_cir(QString idd)
{
    QSqlQuery query;

    query.prepare("Delete from circuit where id = :id ");
    query.bindValue(":id", idd);
    return    query.exec();
}
QSqlQueryModel * circuit::rechercher_cir_dynamique(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM circuit where id like '"+a+"' ||'%'");
    query.bindValue(":id",a);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("zone_debut"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("zone_fin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("agent"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("matricule_vehicule"));
        return model;
}
QSqlQueryModel * circuit::tri_cir()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM circuit ORDER BY id");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("zone_debut"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("zone_fin"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("agent"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("matricule_vehicule"));
    return model;
}
