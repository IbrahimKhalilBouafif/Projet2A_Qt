#include "connexion.h"

connexion::connexion(){}

bool connexion::ouvrirconnexion()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("wassim");//inserer nom de l'utilisateur
    db.setPassword("1919");//inserer mot de passe de cet utilisateur

    if (db.open())
    test=true;
    return  test;
}

void connexion::fermnerconnexion()
{db.close();}
