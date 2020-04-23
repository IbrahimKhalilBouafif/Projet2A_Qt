#include "mainproject.h"
#include "ui_mainproject.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "colis.h"
#include <QMessageBox>
#include "courrier.h"
#include "smtp.h"
#include "mainwindow.h"

mainproject::mainproject(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainproject)
{

    ui->setupUi(this);
    QWidget::setWindowTitle("Smart Rapid Post");
    QWidget::setWindowIcon(QIcon(":/new/icon/logo.png"));
    ui->tableView_colis->setModel(tmpcolis.afficher(ui->lineEdit_73->text()));
    ui->tableView_courrier->setModel(tmpcourrier.afficher(ui->lineEdit_recherche_courrier->text()));
    QSqlQuery qry;
    qry.prepare("select * from tempo");
    qry.exec();
    int id;


    while(qry.next())
    {
        id= qry.value(0).toInt();
    }
    qry.prepare("DROP TABLE tempo");
    qry.exec();
    if(id==0)
    {
        //admin
    }
    else{
        //Employee
    }

}

mainproject::~mainproject()
{
    delete ui;
}

void mainproject::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void mainproject::reset_style_sheet()
{
    QList<QGroupBox *> list = ui->scrollArea->findChildren<QGroupBox *>();
    for(int i=0;i<list.size();i++)
    {
        list.at(i)->setStyleSheet("border:0px;");
    }
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
    QSqlQuery qry;
    qry.prepare("select id from client");
    qry.exec();
    ui->comboBox_expediteur_colis->clear();
    while(qry.next())
        ui->comboBox_expediteur_colis->addItem(qry.value(0).toString());
}
 int idd;
void mainproject::on_pushButton_Modifier_Colis_clicked()
{
   idd =ui->tableView_colis->model()->index(ui->tableView_colis->currentIndex().row(),0).data().toInt();
    ui->stackedWidget->setCurrentIndex(2);
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select id from client");
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("select * from Colis where ID = :id");
    query.bindValue(":id",idd);
    query.exec();

    ui->comboBox_expediteur_colis_m->setModel(model);
    while (query.next()) {
        ui->comboBox_expediteur_colis_m->setCurrentText(query.value(1).toString());
        ui->lineEdit_destinataire_colis_m->setText(query.value(2).toString());
        ui->lineEdit_objet_colis_m->setText(query.value(3).toString());
        ui->lineEdit_dimension_colis_m->setText(query.value(4).toString());
        ui->lineEdit_poids_colis_m->setText(query.value(5).toString());
        ui->comboBox_statut_colis_m->setCurrentText(query.value(6).toString());
    }
}

void mainproject::on_pushButton_Courrier_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    reset_style_sheet();
    ui->horizontalGroupBox_12->setStyleSheet("border:0px;background-color: rgb(0, 0, 95);");
}

void mainproject::on_pushButton_Colis_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    reset_style_sheet();
    ui->horizontalGroupBox_2->setStyleSheet("border:0px;background-color: rgb(0, 0, 95);");
}

void mainproject::on_pushButton_Ajouter_Courrier_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    QSqlQuery qry;
    qry.prepare("select id from client");
    qry.exec();
    ui->comboBox_expediteur_courrier->clear();
    while(qry.next())
        ui->comboBox_expediteur_courrier->addItem(qry.value(0).toString());
}

void mainproject::on_pushButton_Modifier_Courrier_clicked()
{

    idd =ui->tableView_courrier->model()->index(ui->tableView_courrier->currentIndex().row(),0).data().toInt();
    ui->stackedWidget->setCurrentIndex(5);
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select id from client");
     QSqlQuery query;
     QString res= QString::number(idd);
     query.prepare("select * from Courrier where ID = :id");
     query.bindValue(":id",idd);
     query.exec();

     ui->comboBox_expediteur_courrier_m->setModel(model);
     while (query.next()) {
         ui->comboBox_expediteur_courrier_m->setCurrentText(query.value(1).toString());
         ui->lineEdit_destinataire_courrier_m->setText(query.value(2).toString());
         ui->comboBox_statut_courrier_m->setCurrentText(query.value(3).toString());
     }
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
    ui->stackedWidget->setCurrentIndex(8);
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
    ui->stackedWidget->setCurrentIndex(11);
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



void mainproject::on_pushButton_AjoutColis_clicked()
{
    QSqlQuery qry;
    qry.prepare("select id from colis ");
    qry.exec();
    int id;
    while(qry.next())
        id= qMax(id,qry.value(0).toInt());
    id++;
    //int id=ui->lineEdit_id_colis->text().toInt();
    int expediteur=ui->comboBox_expediteur_colis->currentText().toInt();
    QString destinataire=ui->lineEdit_destinataire_colis->text();
    QString objet=ui->lineEdit_objet_c->text();
    QString dimension=ui->lineEdit_dimension_colis->text();
    int poids=ui->lineEdit_poids_colis->text().toInt();
    QString statut=ui->comboBox_statut_colis->currentText();

    Colis c(id,expediteur,destinataire,objet,dimension,poids,statut);
    bool test=c.ajouter();
    if (test)
    {
        ui->tableView_colis->setModel(tmpcolis.afficher(ui->lineEdit_73->text()));
        QMessageBox::information(nullptr,"Ajout colis","Colis ajouté avec succés");

        QString objet="AJOUT DU COLIS";
        QString message=" Votre colis a été ajouté avec succés" ;
        Smtp* smtp = new Smtp("smart.rapid.post@gmail.com","projet2a", "smtp.gmail.com",465);
        connect (smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
        smtp->sendMail("smart.rapid.post@gmail.com", "khalil.bouafif@gmail.com" , objet, message);
        qDebug() << QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();

        QList<QLineEdit *> list = ui->scrollArea_2->findChildren<QLineEdit *>();
        for(int i=0;i<list.size();i++)
            list.at(i)->clear();
        ui->stackedWidget->setCurrentIndex(0);
    }
    else
        QMessageBox::warning(nullptr,"Error","Info non enregistré!");
}

void mainproject::on_pushButton_SupprimerColis_clicked()
{

    int id =ui->tableView_colis->model()->index(ui->tableView_colis->currentIndex().row(),0).data().toInt();
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer ce colis?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          bool test=tmpcolis.supprimer(id);
          if(test)
          {
              ui->tableView_colis->setModel(tmpcolis.afficher(ui->lineEdit_73->text()));
              QMessageBox::information(nullptr,"Suppression","Colis supprimé");

          }
      }

}



void mainproject::on_pushButton_ModifierColis_clicked()
{
    int id=idd;
    int expediteur=ui->comboBox_expediteur_colis_m->currentText().toInt();
    QString destinataire=ui->lineEdit_destinataire_colis_m->text();
    QString objet=ui->lineEdit_objet_colis_m->text();
    QString dimension=ui->lineEdit_dimension_colis_m->text();
    int poids=ui->lineEdit_poids_colis_m->text().toInt();
    QString status=ui->comboBox_statut_colis_m->currentText();

    Colis c(id,expediteur,destinataire,objet,dimension,poids,status);
    bool test=c.modifier(id);
    if (test)
    {
        ui->tableView_colis->setModel(tmpcolis.afficher(ui->lineEdit_73->text()));
        QMessageBox::information(nullptr,"Ajout colis","Colis modifié avec succés");
        QList<QLineEdit *> list = ui->scrollArea_3->findChildren<QLineEdit *>();
        for(int i=0;i<list.size();i++)
            list.at(i)->clear();
        ui->stackedWidget->setCurrentIndex(0);
    }
    else
        QMessageBox::warning(nullptr,"Error","Info non enregistré!");

}

void mainproject::on_lineEdit_73_textEdited(const QString &arg1)
{
    Colis c;
    ui->tableView_colis->setModel( c.afficher(ui->lineEdit_73->text()));
}

void mainproject::on_pushButton_Ajout_Courrier_clicked()
{
    QSqlQuery qry;
    qry.prepare("select id from courrier ");
    qry.exec();
    int id;
    while(qry.next())
        id= qMax(id,qry.value(0).toInt());
    id++;
    //int id=ui->lineEdit_id_colis->text().toInt();
    int expediteur=ui->comboBox_expediteur_courrier->currentText().toInt();
    QString destinataire=ui->lineEdit_destinataire_courrier->text();
    QString statut=ui->comboBox_statut_courrier->currentText();

    Courrier c(id,expediteur,destinataire,statut);
    bool test=c.ajouter();
    if (test)
    {
        ui->tableView_courrier->setModel(tmpcourrier.afficher(ui->lineEdit_recherche_courrier->text()));
        QMessageBox::information(nullptr,"Ajout courrier","Courrier ajouté avec succés");

        QString objet="AJOUT DU COURRIER";
        QString message=" Votre courrier a été ajouté avec succés" ;
        Smtp* smtp = new Smtp("smart.rapid.post@gmail.com","projet2a", "smtp.gmail.com",465);
        connect (smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
        smtp->sendMail("smart.rapid.post@gmail.com", "khalil.bouafif@gmail.com" , objet, message);

        QList<QLineEdit *> list = ui->scrollArea_4->findChildren<QLineEdit *>();
        for(int i=0;i<list.size();i++)
            list.at(i)->clear();
        ui->stackedWidget->setCurrentIndex(3);
    }
    else
        QMessageBox::warning(nullptr,"Error","Info non enregistré!");

}

void mainproject::on_lineEdit_recherche_courrier_textEdited(const QString &arg1)
{
    Courrier c;
    ui->tableView_courrier->setModel(c.afficher(ui->lineEdit_recherche_courrier->text()));
}

void mainproject::on_pushButton_Supprimer_Courrier_clicked()
{
    int id =ui->tableView_courrier->model()->index(ui->tableView_courrier->currentIndex().row(),0).data().toInt();
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Supprimer", "Etes vous sur de supprimer ce courrier?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
    bool test=tmpcourrier.supprimer(id);
    if(test)
    {
        ui->tableView_courrier->setModel(tmpcourrier.afficher(ui->lineEdit_recherche_courrier->text()));
        QMessageBox::information(nullptr,"Suppression","Courrier supprimé");
    }}
}

void mainproject::on_pushButton_modifier_courrier_clicked()
{
    int id=idd;
    int expediteur=ui->comboBox_expediteur_courrier_m->currentText().toInt();
    QString destinataire=ui->lineEdit_destinataire_courrier_m->text();
    QString statut=ui->comboBox_statut_courrier_m->currentText();

    Courrier c(id,expediteur,destinataire,statut);
    bool test=c.modifier(id);
    if (test)
    {
        ui->tableView_courrier->setModel(tmpcourrier.afficher(ui->lineEdit_recherche_courrier->text()));
        QMessageBox::information(nullptr,"Modifier courrier","Courrier modifié avec succés");
        QList<QLineEdit *> list = ui->scrollArea_5->findChildren<QLineEdit *>();
        for(int i=0;i<list.size();i++)
            list.at(i)->clear();
        ui->stackedWidget->setCurrentIndex(3);
    }
    else
        QMessageBox::warning(nullptr,"Error","Info non enregistré!");

}

void mainproject::on_pushButton_131_clicked()
{   
    int idd=-1;
    if(ui->tableView_courrier->currentIndex().row()!=-1)
        idd =ui->tableView_courrier->model()->index(ui->tableView_courrier->currentIndex().row(),0).data().toInt();
    Courrier c;
    c.pdf(idd);
}
void mainproject::on_pushButton_128_clicked()
{
    int idd=-1;
    if(ui->tableView_colis->currentIndex().row()!=-1)
        idd =ui->tableView_colis->model()->index(ui->tableView_colis->currentIndex().row(),0).data().toInt();
    Colis c;
    c.pdf(idd);
}

void mainproject::on_pushButton_stat_clicked()
{
    ui->stackedWidget->setCurrentIndex(30);
    Colis c;
    c.stat(ui->widget_2);
}

void mainproject::on_pushButton_tri_colis_clicked()
{
    ui->tableView_colis->setModel(tmpcolis.tri());
}

void mainproject::on_pushButton_2_clicked()
{
    ui->tableView_courrier->setModel(tmpcourrier.tri());
}

void mainproject::on_pushButton_stat_courrier_clicked()
{
    ui->stackedWidget->setCurrentIndex(30);
    Courrier c;
    c.stat(ui->widget_2);
}

void mainproject::on_commandLinkButton_clicked()
{
    MainWindow *p= new MainWindow();
    p->show();
    this->hide();
}
