#include "client.h"
#include <QDebug>
#include "cnx.h"
Client::Client()
{
CIN ="";
nom="";
prenom="";
email="";
numero=0;
adresse="";

}
Client::Client(QString CIN,QString nom,QString prenom ,QString email , int numero,QString adresse)
{
  this->CIN=CIN;
  this->nom=nom;
  this->prenom=prenom;
  this->email=email;
  this->numero=numero ;
  this->adresse=adresse ;

}


bool Client::ajouter(Client C)
{
    QSqlQuery query;
    query.prepare("INSERT INTO TABCLIENT (CIN, NOM, PRENOM, EMAIL, NUMERO ,ADRESSE) "
                        "VALUES (:cin, :nom, :prenom, :email, :numero , :adresse)");
    query.bindValue(":cin",C.get_CIN());
    query.bindValue(":nom",C.get_nom());
    query.bindValue(":prenom",C.get_prenom());
    query.bindValue(":email",C.get_email());
    query.bindValue(":numero",C.get_num());
    query.bindValue(":adresse",C.get_adresse());
    return query.exec();
}


QSqlQueryModel * Client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from TABCLIENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("numero"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    return model;
}

bool Client::supprimer(QString CINN)
{
QSqlQuery query;
//QString CIN= QString::number(cinn);
query.prepare("Delete from tabclient where CIN = :CIN ");
query.bindValue(":CIN", CINN);
return    query.exec();
}

bool Client::modifier(QString CIN,Client C)
{
    QSqlQuery query;

       query.prepare("UPDATE TABCLIENT SET NOM =:nom , PRENOM =:prenom , EMAIL =:email ,NUMERO =:numero,ADRESSE =:adresse WHERE CIN =:cin ");
       query.bindValue(":cin", C.get_CIN());
       query.bindValue(":nom", C.get_nom());
       query.bindValue(":prenom",C.get_prenom());
       query.bindValue(":email", C.get_email());
       query.bindValue(":numero", C.get_num());
       query.bindValue(":adresse",C.get_adresse());
    return query.exec();
}
QSqlQueryModel *Client::tri()
{
QSqlQuery *q = new QSqlQuery();
QSqlQueryModel *model = new QSqlQueryModel();
q->prepare("SELECT * FROM TABCLIENT ORDER BY NOM");
q->exec();
model->setQuery(*q);
return model;
}


QSqlQueryModel *Client::recherchernomclient(const QString &id)
{

//QString cinn= QString::number(cin);
QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT * FROM TABCLIENT WHERE (cin LIKE '"+id+"%')");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("Numero"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
return model;

}
