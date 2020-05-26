#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>
#include <QDate>

class Client
{  public:
    Client() ;
    Client(QString ,QString ,QString,QString, int,QString);
    QString get_CIN( ){return CIN ;}
    int get_num() {return numero ;}
    QString get_nom(){ return  nom;}
    QString get_prenom() {return prenom ;}
    QString get_email(){return  email ;}
    QString get_adresse(){return  adresse ;}
    void setNom(QString);
    void setPrenom(QString);
    void setCIN(int);
    void setNum(int);
    void setEmail(QString);
    bool ajouter(Client c);
    bool modifier (QString CIN,Client C );
    bool supprimer(QString cinn);
    QSqlQueryModel * afficher();
    QSqlQueryModel *recherchernomclient(const QString &);
    QSqlQueryModel *tri();

    private:
    QString CIN ;
    int numero ;

    QString nom , prenom , email,adresse ;
};

#endif // CLIENT_H
