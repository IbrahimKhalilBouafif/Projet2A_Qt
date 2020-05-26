#include "mainproject.h"
#include "ui_mainproject.h"
#include "mainwindow.h"
#include "client.h"
#include "carte.h"
#include "cnx.h"
#include "smtp.h"
#include <QMessageBox>
#include <QDebug>
#include <QComboBox>
#include <QTextStream>
#include <QPixmap>
#include <QDebug>
#include"QMessageBox"
#include<QPropertyAnimation>
#include<random>
#include"QPainter"
#include"QFont"
#include"QPen"
#include"QPdfWriter"
#include"QTextDocumentWriter"
#include"QDesktopServices"
#include"QtPrintSupport/QPrinter"
#include <QPropertyAnimation>




mainproject::mainproject(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainproject)
{
    ui->setupUi(this);



    QSqlQueryModel * model1=new QSqlQueryModel();
    model1->setQuery("Select CIN from TABCLIENT");
    ui->comboBox_cinM->setModel(model1);

    QSqlQueryModel * model100=new QSqlQueryModel();
    model100->setQuery("Select CIN from TABCLIENT");
    ui->comboBox_CinClientA->setModel(model100);

    QSqlQueryModel * model300=new QSqlQueryModel();
    model300->setQuery("Select ref from TABCARTE");
    ui->input_cinClient->setModel(model300);




    Carte ca;
    ui->tableView_carte->setModel(ca.afficher());//refresh

    Client c;
    ui->tableView_Client->setModel(c.afficher());//refresh




}

mainproject::~mainproject()
{
    delete ui;
}

void mainproject::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}










void mainproject::on_pushButton_Employe_clicked()
{
    ui->stackedWidget->setCurrentIndex(24);
}

void mainproject::on_pushButton_Departement_clicked()
{
    ui->stackedWidget->setCurrentIndex(27);
}

void mainproject::on_pushButton_Ajouter_Employe_clicked()
{
    ui->stackedWidget->setCurrentIndex(25);
}

void mainproject::on_pushButton_Modifier_Employe_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);
}

void mainproject::on_pushButton_Ajouter_Departement_clicked()
{
    ui->stackedWidget->setCurrentIndex(28);
}


void mainproject::on_pushButton_Modifier_Departement_clicked()
{
    ui->stackedWidget->setCurrentIndex(31);

}

void mainproject::on_pushButton_Vehicule_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);

}

void mainproject::on_pushButton_Ajouter_Vehicule_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);

}

void mainproject::on_pushButton_Modifier_Vehicule_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);

}

void mainproject::on_pushButton_circuit_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);

}

void mainproject::on_pushButton_Ajouter_Circuit_clicked()
{
    ui->stackedWidget->setCurrentIndex(22);

}



void mainproject::on_pushButton_Modifier_Circuit_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);

}







void mainproject::on_pushButton_Ajouter_Colis_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void mainproject::on_pushButton_Modifier_Colis_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void mainproject::on_pushButton_Courrier_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void mainproject::on_pushButton_Colis_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void mainproject::on_pushButton_Ajouter_Courrier_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void mainproject::on_pushButton_Modifier_Courrier_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void mainproject::on_pushButton_Client_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void mainproject::on_pushButton_AjoutClient_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void mainproject::on_pushButton_ModifierC_clicked()
{
    //ui->stackedWidget->setCurrentIndex(8);
    QMessageBox::information(this,"Pour Modifier il Faut","Double clique sur la Cin dans le tableau");

}


void mainproject::on_pushButton_Carte_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);


}

void mainproject::on_pushButton_AjouterCarte_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);



}

void mainproject::on_pushButton_ModifierCarte_clicked()
{
    //ui->stackedWidget->setCurrentIndex(11);
    QMessageBox::information(this,"Pour Modifier il Faut","Double clique sur la Ref dans le tableau");

    QSqlQueryModel * model1=new QSqlQueryModel();
    model1->setQuery("Select CIN from TABCLIENT");
    ui->comboBox_cinM->setModel(model1);
}

void mainproject::on_pushButton_Evenements_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void mainproject::on_pushButton_Ajoutevent_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void mainproject::on_pushButton_modifierevent_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}






void mainproject::on_pushButton_Promo_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void mainproject::on_pushButton_ajoutpromo_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void mainproject::on_pushButton_modifierpromo_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void mainproject::on_pushButton_enregistrerClient_clicked()
{


    QString CIN=ui->lineEdit_cinClient->text();
    QString nom= ui->lineEdit_nomClient->text();
    QString prenom= ui->lineEdit_prenomClient->text();
    QString email= ui->lineEdit_emailClient->text();
    int numero = ui->lineEdit_numClient->text().toInt();
    QString adresse=ui->lineEdit_adresseClient->text();
    Client c(CIN,nom,prenom,email,numero,adresse);
    qDebug()<< adresse ;
    qDebug()<< email ;

    int lengthCin=CIN.length();

    qDebug()<< lengthCin ;


if(lengthCin<=8)
{
    bool test= c.ajouter(c);
  if(test)

{
      ui->tableView_Client->setModel(c.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
else
{

QMessageBox::critical(this,"Erreur","Cin est depasse 8 chiffre ");
}
QFile file("C:/Users/maram/Historique.txt");
                        if (!file.open(QIODevice::WriteOnly | QIODevice::Append |QIODevice::Text))
                            return;
                        QTextStream cout(&file);
                        QString message2="\n L'historique des avis"
                                         " à ajouter :"+CIN+" "+prenom+" "+nom+" "+email+" "+numero+" "+adresse+" ";
                        cout << message2;
                        QFile File ("C:/Users/maram/Historique.txt");
                                if (!file.open(QIODevice::ReadOnly))
                                {
                                    QMessageBox::information(0,"info",file.errorString());
                                }
                                QTextStream in (&file);
                                ui->textBrowser->setText(in.readAll());

}

void mainproject::on_pushButton_SupprimerC_clicked()
{
 ui->stackedWidget->setCurrentIndex(30);

 QSqlQueryModel * model300=new QSqlQueryModel();
 model300->setQuery("Select CIN from TABCLIENT");
 ui->input_idClient_a_supprimer->setModel(model300);

}

void mainproject::on_Button_SuppClient_clicked()
{
    QString CIN=ui->input_idClient_a_supprimer->currentText();
    Client c;

    qDebug()<< CIN;
    bool test= c.supprimer(CIN);
    if(test)

  {
        ui->tableView_Client->setModel(c.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  QSqlQueryModel * model300=new QSqlQueryModel();
  model300->setQuery("Select CIN from TABCLIENT");
  ui->input_idClient_a_supprimer->setModel(model300);

  }
    else
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}


void mainproject::on_Button_Modifier_Client_clicked()
{

    QString CIN=ui->lineEdit_idClientM->text();
    QString nom= ui->lineEdit_nomClientM->text();
    QString prenom= ui->lineEdit_prenomClientM->text();
    QString email= ui->lineEdit_emailClientM->text();
    int numero = ui->lineEdit_numClientM->text().toInt();
    QString adresse=ui->lineEdit_adresseclientM->text();
    Client c(CIN,nom,prenom,email,numero,adresse);

    bool test= c.modifier(CIN,c);
  if(test)

{
      ui->tableView_Client->setModel(c.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                  QObject::tr("client Modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::information(nullptr, QObject::tr("Modifier un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void mainproject::on_pushButton_RechercheC_clicked()
{

    Client c;
   QString  id =ui->lineEdit_RechercheClient->text();

   qDebug()<< id ;
   ui->tableView_Client->setModel(c.recherchernomclient(id));
}

void mainproject::on_Tri_Client_parNom_clicked()
{
    Client c;
    ui->tableView_Client->setModel(c.tri());
}



void mainproject::on_Ajouter_Carte_clicked()
{

    QString ref=ui->lineEdit_refCarte->text();
    int CIN =ui->comboBox_CinClientA->currentText().toInt();
    int nbpoints = ui->lineEdit_nbPoints->text().toUInt();
    Carte ca(ref,CIN,nbpoints);

    int lengthreference=ref.length();

    qDebug()<< lengthreference ;
    qDebug()<< CIN ;
if(lengthreference>0 && nbpoints>0)
{
    bool test= ca.ajouter(ca);
  if(test)

{
      ui->tableView_carte->setModel(ca.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une carte "),
                  QObject::tr("carte ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->stackedWidget->setCurrentIndex(9);

}
  else
      QMessageBox::information(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
if(ref<=0)
{
    QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                QObject::tr("Erreur Reference est Null Ou negative !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
if(nbpoints<=0)
{
    QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                QObject::tr("Erreur nbpoints est Null Ou negative !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}



}

void mainproject::on_Modfier_Carte_clicked()
{

    QString REF=ui->lineEdit_refCarteM->text();
    int cinClient = ui->comboBox_cinM->currentText().toInt();
    int nbpoints = ui->lineEdit_nbPointM->text().toUInt();

    Carte ca(REF,cinClient,nbpoints);

  int lengthreference=REF.length();

  if(lengthreference>0 && nbpoints>0)
  {
    bool test= ca.modifier(REF,ca);
  if(test)

{
      ui->tableView_carte->setModel(ca.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un carte"),
                  QObject::tr("carte Modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->stackedWidget->setCurrentIndex(9);

}
  else
      QMessageBox::information(nullptr, QObject::tr("Modifier un carte"),
                  QObject::tr("Erreur !.\n"

                              "Click Cancel to exit."), QMessageBox::Cancel);

}

  if(REF<=0)
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur Reference est Null Ou negative !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  }
  if(nbpoints<=0)
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une carte"),
                  QObject::tr("Erreur nbpoints est Null Ou negative !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  }



}

void mainproject::on_pushButton_SupprimerCarte_clicked()
{
     ui->stackedWidget->setCurrentIndex(31);
}

void mainproject::on_Button_SuppCarte_clicked()
{

    QString reff=ui->input_cinClient->currentText();
    Carte ca;
    bool test= ca.supprimer(reff);
    if(test)

  {
        QSqlQueryModel * model300=new QSqlQueryModel();
        model300->setQuery("Select ref from TABCARTE");
        ui->input_cinClient->setModel(model300);

        ui->tableView_carte->setModel(ca.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
 ui->stackedWidget->setCurrentIndex(9);

  }
    else
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void mainproject::on_Tri_Carte_parRef_clicked()
{
    Carte ca;
    QMessageBox::information(this,"Tri Carte","Tri croissant selon le Nombre des Points");
    ui->tableView_carte->setModel(ca.tri());
}


void mainproject::on_pushButton_RechercherCarte_clicked()
{

    Carte ca;
   QString  id =ui->lineEdit_RecherchCarte->text();

   qDebug()<< id ;
   ui->tableView_carte->setModel(ca.rechercherrefcarte(id));

}


void mainproject::on_pushButton_clicked()
{
Smtp* smtp = new Smtp("smart.rapid.post@gmail.com", "projet2a", "smtp.gmail.com", 465);
 connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
 smtp->sendMail("smart.rapid.post@gmail.com", "maram.benameur@esprit.tn" , "Smart Rapid Post, Nouvelle carte de fidelite!","Bienvenue! Vous-ete UN CLIENT fidele!");
}



void mainproject::on_tableView_Client_activated(const QModelIndex &index)
{

    int verif=0;
     QString val=ui->tableView_Client->model()->data(index).toString();
     QSqlQuery q;
     q.prepare("select * from TABCLIENT where cin='"+val+"'");
     if(q.exec())
       while (q.next()) {
                   ui->lineEdit_idClientM->setText(q.value(0).toString());
                   ui->lineEdit_nomClientM->setText(q.value(1).toString());
                   ui->lineEdit_prenomClientM->setText(q.value(2).toString());
                   ui->lineEdit_emailClientM->setText(q.value(3).toString());
                   ui->lineEdit_numClientM->setText(q.value(4).toString());
                   ui->lineEdit_adresseclientM->setText(q.value(5).toString());
                         verif=1;

                         qDebug()<< verif;
                         }
     if(verif==1)
     {

       ui->stackedWidget->setCurrentIndex(8);
     }
     else
     {
         QMessageBox::information(nullptr, QObject::tr("Information Sur la Modification"),
                     QObject::tr("double clique sur la Cin \n"
                                 "Pour Le Modifier."), QMessageBox::Cancel);
     }


}

void mainproject::on_tableView_carte_activated(const QModelIndex &index)
{
    int verif=0;
     QString val=ui->tableView_carte->model()->data(index).toString();
     QSqlQuery q;
     q.prepare("select * from TABCARTE where ref='"+val+"'");
     if(q.exec())
       while (q.next()) {
                   ui->lineEdit_refCarteM->setText(q.value(0).toString());
                   ui->lineEdit_nbPointM->setText(q.value(2).toString());
                         verif=1;

                         qDebug()<< verif;
                         }
     if(verif==1)
     {
         QSqlQueryModel * model1=new QSqlQueryModel();
         model1->setQuery("Select CIN from TABCLIENT");
         ui->comboBox_cinM->setModel(model1);

       ui->stackedWidget->setCurrentIndex(11);
     }
     else
     {
         QMessageBox::information(nullptr, QObject::tr("Information Sur la Modification"),
                     QObject::tr("double clique sur la ref \n"
                                 "Pour Le Modifier."), QMessageBox::Cancel);
     }
}



void mainproject::on_pushButton_4_clicked()
{
    QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("output.pdf");
        printer.setPageMargins(12, 16, 12, 20, QPrinter::Millimeter);
        printer.setFullPage(false);

        QPainter painter(&printer);

        double xscale = printer.pageRect().width() / double(ui->tableView_Client->width());
        double yscale = printer.pageRect().height() / double(ui->tableView_Client->height());
        double scale = qMin(xscale, yscale);
        painter.translate(printer.paperRect().center());
        painter.scale(scale, scale);
        painter.translate(-ui->tableView_Client->width()/2, -ui->tableView_Client->height()/2);
        ui->tableView_Client->render(&painter);

}

void mainproject::on_pushButton_5_clicked()
{
    QFile file ("C:/Users/maram/Historique.txt");
                if (!file.open(QIODevice::ReadOnly))
                {
                    QMessageBox::information(0,"info",file.errorString());
                }
                QTextStream in (&file);
                ui->textBrowser->setText(in.readAll());
    }


