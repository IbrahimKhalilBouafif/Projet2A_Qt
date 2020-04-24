#include "mainproject.h"
#include "ui_mainproject.h"
#include <QPainter>
#include <QTableView>
#include <QPdfWriter>
#include "QMessageBox"
#include <QPixmap>
#include "statistique.h"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>



mainproject::mainproject(QWidget *employe) :
    QMainWindow(employe),
    ui(new Ui::mainproject)
{
    ui->setupUi(this);
    ui->tableView_affemploye->setModel(tmpemploye.afficher());
    //ui->lineEdit_idd->setMaxLength(3);
    //ui->lineEdit_ide->setMaxLength(3);

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
    QSqlQueryModel *modal = new QSqlQueryModel ();
    QSqlQuery q;
    q.prepare("select ID from departement");
    q.exec();
    modal->setQuery(q);
    ui->comboBox_dep->setModel(modal);

}



void mainproject::on_pushButton_Ajouter_Departement_clicked()
{
    ui->stackedWidget->setCurrentIndex(28);
}


void mainproject::on_pushButton_Modifier_Departement_clicked()
{
    ui->stackedWidget->setCurrentIndex(29);
    QSqlQueryModel *modal = new QSqlQueryModel ();
    QSqlQuery q;
    q.prepare("select ID from departement");
    q.exec();
    modal->setQuery(q);
    ui->comboBox_moddep->setModel(modal);
}


void mainproject::on_pushButton_Modifier_Employe_clicked()
{
    ui->stackedWidget->setCurrentIndex(26);

    QSqlQueryModel *modal = new QSqlQueryModel ();
    QSqlQuery q;
    q.prepare("select ID from employe");
    q.exec();
    modal->setQuery(q);
    ui->comboBox_modemp->setModel(modal);

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


void mainproject::on_pushButton_Supprimer_Employe_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QSqlQueryModel *modal = new QSqlQueryModel ();
    QSqlQuery q;
    q.prepare("select ID from employe");
    q.exec();
    modal->setQuery(q);
    ui->comboBox_sup->setModel(modal);
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



void mainproject::on_pushButton_ajouterb_clicked()
{

    //int id = ui->lineEdit_ide->text().toInt();
    QString nom= ui->lineEdit_nome->text();
    QString prenom= ui->lineEdit_prenome->text();
    int age= ui->lineEdit_agee->text().toInt();
    QString sexe= ui->sexee_2->currentText();
    QString disponibilite= ui->disponibilitee_2->currentText();
    QString departement= ui->comboBox_dep->currentText();


    employe e(id,nom,prenom,age,sexe,disponibilite,departement);
    bool test=e.ajouter();
    if(test)
  {ui->tableView_affemploye->setModel(tmpemploye.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un employe"),
                    QObject::tr("employe AJOUTE.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
  ui->stackedWidget->setCurrentIndex(24);

  }


  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void mainproject::on_pushButton_suprimerebase_clicked()
{
    ui->tableView_affemploye->setModel(tmpemploye.afficher());
    int id = ui->comboBox_sup->currentText().toInt();
    bool test=tmpemploye.supprimer(id);
    if(test)
    {ui->tableView_affemploye->setModel(tmpemploye.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un departement"),
                    QObject::tr("departement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->stackedWidget->setCurrentIndex(24);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employé"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void mainproject::on_pushButton_ajouterdep_clicked()
{

    int id = ui->lineEdit_idd->text().toInt();
    QString nom= ui->lineEdit_nomd->text();
    QString responsable= ui->lineEdit_resd->text();
    int nb_employes= ui->lineEdit_nbd->text().toInt();



  departement d(id,nom,responsable,nb_employes);
  bool test=d.ajouter();
  if(test)
{ui->tableView_departement->setModel(tmpdepartement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un departement"),
                  QObject::tr("Departement AJOUTE.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->stackedWidget->setCurrentIndex(27);
}
}

void mainproject::on_pushButton_Supprimer_Departement_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QSqlQueryModel *modal = new QSqlQueryModel ();
    QSqlQuery q;
    q.prepare("select ID from departement");
    q.exec();
    modal->setQuery(q);
    ui->comboBox_departement->setModel(modal);
}


void mainproject::on_pushButton_supdepb_clicked()
{

    ui->tableView_departement->setModel(tmpdepartement.afficher());
    int id = ui->comboBox_departement->currentText().toInt();
    bool test=tmpdepartement.supprimer(id);
    if(test)
    {ui->tableView_departement->setModel(tmpdepartement.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un departement"),
                    QObject::tr("departement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->stackedWidget->setCurrentIndex(27);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un departement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}



void mainproject::on_pushButton_73_clicked()
{

        int id = ui->comboBox_moddep->currentText().toInt();
        QString nom= ui->lineEdit_moddepn->text();
        QString responsable= ui->lineEdit_moddepr->text();
         int nb_employes= ui->lineEdit_moddepnb->text().toInt();


        departement d(id,nom,responsable,nb_employes);
      bool test=d.modifier(id);
      if(test)
    {ui->tableView_departement->setModel(tmpdepartement.afficher());


    QMessageBox::information(nullptr, QObject::tr("Modifier departement"),
                      QObject::tr("departement modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    ui->stackedWidget->setCurrentIndex(27);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier departement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }








void mainproject::on_pushButton_69_clicked()
{

        int id = ui->comboBox_modemp->currentText().toInt();
        QString nom= ui->lineEdit_modempn->text();
        QString prenom= ui->lineEdit13_modempp->text();
        int age= ui->lineEdit_modempa->text().toInt();
        QString sexe= ui->comboBox_modemps->currentText();
        QString disponibilite= ui->comboBox_modempd->currentText();
        QString departement= ui->lineEdit_mdemp->text();

        employe e(id,nom,prenom,age,sexe,disponibilite,departement);
      bool test=e.modifier(id);
      if(test)
    {ui->tableView_affemploye->setModel(tmpemploye.afficher());


    QMessageBox::information(nullptr, QObject::tr("Modifier employe"),
                      QObject::tr("employe modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    ui->stackedWidget->setCurrentIndex(24);
    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier employe"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }

void mainproject::on_pushButton_Rechercher_departement_clicked()
{

    QString str=ui->lineEdit_chercherdep->text();
    ui->tableView_departement->setModel(tmpdepartement.rechercherparnom(str));


}

void mainproject::on_pushButton_Rechercher_employe_clicked()
{

            QString str=ui->lineEdit_empch->text();
            ui->tableView_affemploye->setModel(tmpemploye.rechercherparnom1(str));
}



void mainproject::on_trie_2_clicked()
{

    departement d;
    if( ui->comboBox_trie_2->currentText() == "NOM A-Z") // TRIE par NOMasc
        {ui->tableView_departement->setModel(d.trier_nomasc());
        QMessageBox::information(nullptr, QObject::tr("Trier"),
                              QObject::tr("Table trie par Nom asc.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if( ui->comboBox_trie_2->currentText() == "NOM Z-A") // TRIE par NOMdesc
        {ui->tableView_departement->setModel(d.trier_nomdesc());
        QMessageBox::information(nullptr, QObject::tr("Trier"),
                              QObject::tr("Table trie par Nom desc.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if( ui->comboBox_trie_2->currentText() == "ID ASC") // TRIE par IDasc
    {
        ui->tableView_departement->setModel(d.trier_idasc());
        QMessageBox::information(nullptr, QObject::tr("Trier"),
                              QObject::tr("Table trie par ID asc.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if( ui->comboBox_trie_2->currentText() == "ID DESC") // TRIE par IDdesc
    {
        ui->tableView_departement->setModel(d.trier_iddesc());
        QMessageBox::information(nullptr, QObject::tr("Trier"),
                              QObject::tr("Table trie par ID desc.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if( ui->comboBox_trie_2->currentText() == "NB_EMP ASC") // TRIE par nbetageasc
    {
        ui->tableView_departement->setModel(d.trier_nbempdesc());
        QMessageBox::information(nullptr, QObject::tr("Trier"),
                              QObject::tr("Table trie par nb_emp asc.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if( ui->comboBox_trie_2->currentText() == "NB_EMP DESC") // TRIE par nbetagedesc
    {
        ui->tableView_departement->setModel(d.trier_nbempdesc());
        QMessageBox::information(nullptr, QObject::tr("Trier"),
                              QObject::tr("Table trie par nb_emp desc.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }









}

void mainproject::on_pushButton_trie1_clicked()
{

    employe e;
    if( ui->comboBox_trie_1->currentText() == "NOM A-Z") // TRIE par NOMasc
        {ui->tableView_affemploye->setModel(e.trier_nomasc1());
        QMessageBox::information(nullptr, QObject::tr("Trier"),
                              QObject::tr("Table trie par Nom asc.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if( ui->comboBox_trie_1->currentText() == "NOM Z-A") // TRIE par NOMdesc
        {ui->tableView_affemploye->setModel(e.trier_nomdesc1());
        QMessageBox::information(nullptr, QObject::tr("Trier"),
                              QObject::tr("Table trie par Nom desc.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if( ui->comboBox_trie_1->currentText() == "ID ASC") // TRIE par IDasc
    {
        ui->tableView_affemploye->setModel(e.trier_idasc1());
        QMessageBox::information(nullptr, QObject::tr("Trier"),
                              QObject::tr("Table trie par ID asc.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if( ui->comboBox_trie_1->currentText() == "ID DESC") // TRIE par IDdesc
    {
        ui->tableView_affemploye->setModel(e.trier_iddesc1());
        QMessageBox::information(nullptr, QObject::tr("Trier"),
                              QObject::tr("Table trie par ID desc.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
    if( ui->comboBox_trie_1->currentText() == "DISPONIBLE") // TRIE par emp disponible
    {
        ui->tableView_affemploye->setModel(e.trier_disponibilite1());
        QMessageBox::information(nullptr, QObject::tr("Trier"),
                              QObject::tr("Table trie emp disponible.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }





}


void mainproject::on_tableView_affemploye_activated(const QModelIndex &index)
{
    QString val=ui->tableView_affemploye->model()->data(index).toString();
                QSqlQuery q;
                q.prepare("select * from employe where ID='"+val+"'");
                if(q.exec())
                {
                    while (q.next())
                    {
                    ui->lineEdit_pdfe->setText(q.value(0).toString());
                    }
                }



}




void mainproject::on_pushButton_pdfEmp_clicked()
{


    QPdfWriter pdf("C:/ert/test.pdf");
            QPainter painter;
            if (! painter.begin(&pdf))
            {
                // failed to open file
                                qWarning("failed to open file, is it writable?");

            }
            QString id =ui->lineEdit_pdfe->text();
            const time_t ctt = time(0);
            QSqlQuery query;
            query.exec("SELECT id,nom,prenom,age,sexe,disponibilite,departement FROM employe WHERE id='"+id+"'");

                    while (query.next())
                          {

                        QString id = query.value(0).toString();
                        QString nom = query.value(1).toString();
                        QString prenom= query.value(2).toString();
                        QString age = query.value(3).toString();
                        QString sexe = query.value(4).toString();
                        QString disponibilite = query.value(5).toString();
                        QString departement = query.value(6).toString();


                painter.drawText(2200,3500,id);
                painter.drawText(2200,4000,nom);
                painter.drawText(2200,4500,prenom);
                painter.drawText(2200,5000,age);
                painter.drawText(2200,5500,sexe);
                painter.drawText(2200,6000,disponibilite);
                painter.drawText(2200,6500,departement);



                painter.setPen(Qt::blue);
                painter.setPen(Qt::black);
                painter.drawText(500,2000,asctime(localtime(&ctt)));
                painter.drawText(500,3500,"Identifiant:");
                painter.drawText(500,4000,"Nom :");
                painter.drawText(500,4500,"Prenom:");
                painter.drawText(500,5000,"Age:");
                painter.drawText(500,5500,"Sexe :");
                painter.drawText(500,6000,"Disponibilite:");
                painter.drawText(500,6500,"Departement:");

            }
                     QMessageBox::information (this,"PDF","Export fait avec succès!");

}







void mainproject::on_tableView_departement_activated(const QModelIndex &index)
{

    QString val=ui->tableView_departement->model()->data(index).toString();
                QSqlQuery q;
                q.prepare("select * from departement where ID='"+val+"'");
                if(q.exec())
                {
                    while (q.next())
                    {
                    ui->lineEdit_pdfdep->setText(q.value(0).toString());
                    }
                }

}

void mainproject::on_pushButto_pdfDep_clicked()
{


    QPdfWriter pdf("C:/ert/departement.pdf");
            QPainter painter;
            if (! painter.begin(&pdf))
            {
                // failed to open file
                                qWarning("failed to open file, is it writable?");

            }
            QString id =ui->lineEdit_pdfdep->text();
            const time_t ctt = time(0);
            QSqlQuery query;
            query.exec("SELECT id,nom,responsable,nb_employes FROM departement WHERE id='"+id+"'");

                    while (query.next())
                          {

                        QString id = query.value(0).toString();
                        QString nom = query.value(1).toString();
                        QString responsable= query.value(2).toString();
                        QString nb_employes = query.value(3).toString();



                painter.drawText(2200,3500,id);
                painter.drawText(2200,4000,nom);
                painter.drawText(2200,4500,responsable);
                painter.drawText(2200,5000,nb_employes);




                painter.setPen(Qt::blue);
                painter.setPen(Qt::black);
                painter.drawText(500,2000,asctime(localtime(&ctt)));
                painter.drawText(500,3500,"Identifiant:");
                painter.drawText(500,4000,"Nom :");
                painter.drawText(500,4500,"Responsable:");
                painter.drawText(500,5000,"Nb_employes:");


            }
                     QMessageBox::information (this,"PDF","Export fait avec succès!");









}








void mainproject::on_pushButton_excel_clicked()
{

    departement D;
       QString id=ui->lineEdit_pdfdep->text();
       QSqlQueryModel * model=new QSqlQueryModel();
       model=D.Find_Departement();
       QString textData= "id ; nom ; responsable ; nb_employes \n";
       int rows=model->rowCount();
       int columns=model->columnCount();
       for (int i = 0; i < rows; i++)
       {
           for (int j = 0; j < columns; j++)
           {
               textData += model->data(model->index(i,j)).toString();
               textData +=" ; ";
           }
           textData += "\n";
       }
       QString fileName = QFileDialog::getSaveFileName(this, "Export Excel", QString(), "*.csv");
       if (!fileName.isEmpty())
           if (QFileInfo(fileName).suffix().isEmpty())
               fileName.append(".csv");
       QFile csvfile(fileName);
       if(csvfile.open(QIODevice::WriteOnly|QIODevice::Truncate))
       {
           QTextStream out(&csvfile);
           out<<textData;
       }
       csvfile.close();


}

void mainproject::on_pushButton_excelemp_clicked()
{

    employe E;
       QString id=ui->lineEdit_pdfe->text();
       QSqlQueryModel * model=new QSqlQueryModel();
       model=E.Find_Employe();
       QString textData= "id ; nom ; prenom ; age ; sexe ; disponibilite ; departement \n";
       int rows=model->rowCount();
       int columns=model->columnCount();
       for (int i = 0; i < rows; i++)
       {
           for (int j = 0; j < columns; j++)
           {
               textData += model->data(model->index(i,j)).toString();
               textData +=" ; ";
           }
           textData += "\n";
       }
       QString fileName = QFileDialog::getSaveFileName(this, "Export Excel", QString(), "*.csv");
       if (!fileName.isEmpty())
           if (QFileInfo(fileName).suffix().isEmpty())
               fileName.append(".csv");
       QFile csvfile(fileName);
       if(csvfile.open(QIODevice::WriteOnly|QIODevice::Truncate))
       {
           QTextStream out(&csvfile);
           out<<textData;
       }
       csvfile.close();


}




void mainproject::on_pushButton_clicked()
{

    statistique *s = new statistique();
    s->show();

}

void mainproject::on_lineEdit_ide_inputRejected()
{
    //ui->lineEdit_ide->setMaxLength(3);

}
