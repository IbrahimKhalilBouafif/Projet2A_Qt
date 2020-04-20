   #ifndef PROMOTION_H
#define PROMOTION_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>


class promotion
{
public:
    promotion();

    promotion(QString,int,int,int);
    QString get_id();
    int get_pourcentage();
    int get_duree();
    int get_idevenement();


 bool ajouterpromo();

 QSqlQueryModel * afficher2();


  bool supprimer(QString);
   // bool update(int);
  QSqlQueryModel * recherche(QString);
  bool update1(QString);




    private:

    int pourcentage,duree,id_evenement;
    QString id;


};

#endif // PROMOTION_H
