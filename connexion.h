#ifndef CONNEXION_H
#define CONNEXION_H


#include <QSqlDatabase>

class connexion
{
private:
    QSqlDatabase db;
public:
    connexion();
    bool ouvrirconnexion();
    void fermnerconnexion();
};
#endif // CONNEXION_H
