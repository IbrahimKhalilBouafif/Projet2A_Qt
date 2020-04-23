#include "mainproject.h"
#include "ui_mainproject.h"
#include "vehicule.h"
#include "circuit.h"
#include "statistiques.h"
#include <QMessageBox>
#include "smtp.h"
mainproject::mainproject(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainproject)
{

    ui->setupUi(this);
    ui->tableView_colis_7->setModel(tmpveh.afficher_veh());
    ui->tableView_circuit->setModel(tmpcir.afficher_cir());
    ui->comboBox_5->setModel(tmpcir.afficher_cir());
    ui->comboBox_10->setModel(tmpveh.afficher_veh());
    QRegExp rx("[A-Za-z_]+");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_Marque->setValidator(validator);
    ui->lineEdit_Couleur->setValidator(validator);
    ui->lineEdit_Agent->setValidator(validator);
    ui->lineEdit_Zone->setValidator(validator);
    QRegExp rx1("[a-zA-Z0-9_]{10}");
    QValidator *validator1 = new QRegExpValidator(rx1, this);
    ui->lineEdit_Matricule->setValidator(validator1);
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
    ui->comboBox_10->setModel(tmpveh.afficher_veh());

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
    ui->comboBox_5->setModel(tmpcir.afficher_cir());

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

void mainproject::on_pushButton_ajouter_v_clicked()
{
    QString matricule = ui->lineEdit_Matricule->text();
    QString marque = ui->lineEdit_Marque->text();
    QString couleur = ui->lineEdit_Couleur->text();
    QString agent = ui->lineEdit_Agent->text();
    QString zone = ui->lineEdit_Zone->text();

    vehicule v(matricule,marque,couleur,agent,zone);
    bool test=v.ajouter_veh();
    if(test)
    {
        QString objet="AJOUT VEHICULE";
        QString message=" Votre vehicule a été ajouté avec succés" ;
        Smtp* smtp = new Smtp("smart.rapid.post@gmail.com","projet2a", "smtp.gmail.com",465);
        connect (smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
        smtp->sendMail("smart.rapid.post@gmail.com", "wassim.ridene@esprit.tn" , objet, message);


        QMessageBox::information(nullptr, QObject::tr("Ajouter une vehicule"),
                          QObject::tr("vehicule ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->tableView_colis_7->setModel(tmpveh.afficher_veh());

}

void mainproject::on_lineEdit_94_textEdited(const QString &arg1)
{
    vehicule a;
    ui->tableView_colis_7->setModel(tmpveh.rechercher_veh_dynamique(arg1));
}

void mainproject::on_pushButton_modif_v_clicked()
{
    QString matricule = ui->lineEdit_mMv->text();
    QString marque = ui->lineEdit_mmv->text();
    QString couleur = ui->lineEdit_mcv->text();
    QString agent = ui->lineEdit_mav->text();
    QString zone = ui->lineEdit_mzv->text();
    vehicule v;
    bool test=v.modifier_veh(matricule,marque,agent,couleur,zone);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifie une annonce"),
                          QObject::tr("vehicule modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_colis_7->setModel(tmpveh.afficher_veh());
}

void mainproject::on_pushButton_Supprimer_Vehicule_clicked()
{
    //QString id = ui->lineEdit_94->text();
    QString id = ui->comboBox_10->currentText();
    bool test=tmpveh.supprimer_veh(id);
    ui->tableView_colis_7->setModel(tmpveh.afficher_veh());
    ui->comboBox_10->setModel(tmpveh.afficher_veh());
}

void mainproject::on_pushButton_ajout_circuit_clicked()
{
    QString id = ui->lineEdit_ID_circuit->text();
    QString zone_debut = ui->lineEdit_zone_debut->text();
    QString zone_fin = ui->lineEdit_zone_fin->text();
    QString agent = ui->lineEdit_Agent_circuit->text();
    QString matricule_vehicule = ui->lineEdit_Matricule_circuit->text();

    circuit c(id,zone_debut,zone_fin,agent,matricule_vehicule);
    bool test=c.ajouter_cir();
    if(test)
    {
        QString objet="AJOUT CIRCUIT";
        QString message=" Votre circuit a été ajouté avec succés" ;
        Smtp* smtp = new Smtp("smart.rapid.post@gmail.com","projet2a", "smtp.gmail.com",465);
        connect (smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
        smtp->sendMail("smart.rapid.post@gmail.com", "wassim.ridene@esprit.tn" , objet, message);

        QMessageBox::information(nullptr, QObject::tr("Ajouter une circuit"),
                          QObject::tr("circuit ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    ui->tableView_circuit->setModel(tmpcir.afficher_cir());
}

void mainproject::on_pushButton_modif_circuit_clicked()
{
    QString id = ui->lineEdit_m_id_circuit->text();
    QString zone_debut = ui->lineEdit_m_zonedebut_circuit->text();
    QString zone_fin = ui->lineEdit_m_zonefin_circuit->text();
    QString agent = ui->lineEdit_m_agent_circuit->text();
    QString matricule_vehicule = ui->lineEdit_m_matricule_circuit->text();
    circuit c;
    bool test=c.modifier_cir(id,zone_debut,zone_fin,agent,matricule_vehicule);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifie une circuit"),
                          QObject::tr("circuit modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_circuit->setModel(tmpcir.afficher_cir());
}

void mainproject::on_pushButton_Supprimer_Circuit_clicked()
{
    QString id = ui->comboBox_5->currentText();
    bool test=tmpcir.supprimer_cir(id);
    ui->tableView_circuit->setModel(tmpcir.afficher_cir());
    ui->comboBox_5->setModel(tmpcir.afficher_cir());
}

void mainproject::on_lineEdit_rech_circuit_textEdited(const QString &arg1)
{
    circuit a;
    ui->tableView_circuit->setModel(tmpcir.rechercher_cir_dynamique(arg1));
}

void mainproject::on_pushButton_Rechercher_Vehicule_clicked()
{

    ui->tableView_colis_7->setModel(tmpveh.tri_veh());
}

void mainproject::on_pushButton_rech_circuit_clicked()
{
    ui->tableView_circuit->setModel(tmpcir.tri_cir());
}

void mainproject::on_stat_clicked()
{
    ui->stackedWidget->setCurrentIndex(30);
    vehicule v;
    v.stat(ui->widget_stat_vehicule);
}




