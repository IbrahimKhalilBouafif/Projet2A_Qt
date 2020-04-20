#include "mainproject.h"
#include "ui_mainproject.h"
#include "evenement.h"
#include "promotion.h"
#include "statistiques.h"

#include <QMessageBox>
#include <QPrintDialog>
#include <QPrinter>
#include <QTextStream>
#include <QTextDocument>
#include <iostream>
#include<QString>
#include<QFileDialog>
#include<QDate>




mainproject::mainproject(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainproject)
{
    ui->setupUi(this);
    ui->tableView_colis_5->setModel(tmpevenement.afficher());

    ui->tableView_colis_6->setModel(tmppromotion.afficher2());

    QSqlQueryModel * model1= new QSqlQueryModel();
           model1->setQuery("select ID from evenement")  ;
           ui->comboBox_5->setModel(model1) ;
           ui->comboBox_11->setModel(model1) ;


                  ui->comboBox_10->setModel(model1) ;




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
    ui->stackedWidget->setCurrentIndex(15);


}






void mainproject::on_pushButton_Promo_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
}

void mainproject::on_pushButton_ajoutpromo_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);

    QSqlQueryModel * model1= new QSqlQueryModel();
           model1->setQuery("select ID from evenement")  ;
           ui->comboBox_5->setModel(model1) ;
}

void mainproject::on_pushButton_modifierpromo_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}

void mainproject::on_pushButton_SupprimerColis_clicked()
{

}

void mainproject::on_pushButton_supprimerevent_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);

}

void mainproject::on_pushButton_52_clicked()
{


        QString nom= ui->lineEdit_nom->text();
        QString description= ui->lineEdit_description->text();
           QDate date_debut= ui->dateEdit->date();
           QDate date_fin= ui->dateEdit_3->date();
            int id ;


      Evenement e(id,nom,description,date_debut,date_fin);
      bool test=e.ajouter();
      if(test)
    {
            ui->tableView_colis_5->setModel(tmpevenement.afficher());

    QMessageBox::information(nullptr, QObject::tr("Ajouter un evenement"),
                      QObject::tr("Evenement ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un evenement"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void mainproject::on_pushButton_clicked()
{

    statistiques s;
    s.show();
    s.exec();


}

void mainproject::on_pushButton_supprimerid_clicked()
{


        int id = ui->comboBox_11->currentText().toInt() ;
        bool test=tmpevenement.supprimer(id);
        if(test)
        {
              ui->tableView_colis_5->setModel(tmpevenement.afficher());
            QMessageBox::information(nullptr, QObject::tr("Supprimer un évenement"),
                        QObject::tr("Evenement supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un évenement"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);





}

void mainproject::on_pushButton_tri_clicked()
{
    ui->tableView_colis_5->setModel(tmpevenement.tri());


}





void mainproject::on_pushButton_rechercheevenement_clicked()
{

    QString nom = ui->lineEdit_88->text();
        ui->tableView_colis_5->setModel(tmpevenement.recherche(nom));
}

void mainproject::on_pushButton_53_clicked()
{
    int id=ui->lineEdit->text().toInt()  ;




    QString nom= ui->lineEdit_90->text();

    QString description= ui->lineEdit_12->text();
       QDate date_debut= ui->dateEdit_2->date();
       QDate date_fin= ui->dateEdit_4->date();
QString id1=ui->lineEdit->text();
  Evenement e(id,nom,description,date_debut,date_fin);
  QSqlQueryModel* modal=e.count(id1);
  int n=modal->rowCount();
  qDebug()<<"Le nombre"<<n;
  if(n!=0)
   {

  bool test=e.update(id);
  if(test)
{

        ui->tableView_colis_5->setModel(tmpevenement.afficher());

QMessageBox::information(nullptr, QObject::tr("modifier un evenement"),
                  QObject::tr("Evenement modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un evenement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un evenement"),
                  QObject::tr("Id non existant  !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}



void mainproject::on_pushButton_imprimer_clicked(){
{

    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tableView_colis_5->model()->rowCount();
            const int columnCount = ui->tableView_colis_5->model()->columnCount();
            QString TT = QDate::currentDate().toString("yyyy/MM/dd");
            out <<"<html>\n"
                  "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                << "<title>ERP - Evenements LIST<title>\n "
                << "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"
                "<h1 style=\"text-align: center;\"><strong> ****LISTE DES Evenements **** "+TT+"</strong></h1>"
                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                  "</br> </br>";
            // headers
            out << "<thead><tr bgcolor=#d6e5ff>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tableView_colis_5->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tableView_colis_5->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++) {
                out << "<tr>";
                for (int column = 0; column < columnCount; column++) {
                    if (!ui->tableView_colis_5->isColumnHidden(column)) {
                        QString data =ui->tableView_colis_5->model()->data(ui->tableView_colis_5->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table>\n"
                "</body>\n"
                "</html>\n";

            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);

            QPrinter printer;

            QPrintDialog *baba = new QPrintDialog(&printer, NULL);
            if (baba->exec() == QDialog::Accepted) {
                document->print(&printer);
            }

            delete document;

}
}

void mainproject::on_pushButton_pdf_clicked()
{

    QString strStream;
            QTextStream out(&strStream);


    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    const int rowCount = ui->tableView_colis_5->model()->rowCount();
    const int columnCount = ui->tableView_colis_5->model()->columnCount();
    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
    out <<"<html>\n"
          "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        << "<title>ERP - Evenements LIST<title>\n "
        << "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<h1 style=\"text-align: center;\"><strong> ****LISTE DES Evenements **** "+TT+"</strong></h1>"
        "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
          "</br> </br>";
    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tableView_colis_5->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_colis_5->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView_colis_5->isColumnHidden(column)) {
                QString data =ui->tableView_colis_5->model()->data(ui->tableView_colis_5->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table>\n"
        "</body>\n"
        "</html>\n";

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.print(&printer);

}



void mainproject::on_pushButton_56_clicked()
{

    QString id = ui->lineEdit_2->text();
    int pourcentage= ui->lineEdit_92->text().toInt();
    int duree= ui->lineEdit13_12->text().toInt();
       int id_evenement=ui->comboBox_5->currentText().toInt() ;



  promotion p(id,pourcentage,duree,id_evenement);
  bool test=p.ajouterpromo();
  if(test)
{

        ui->tableView_colis_6->setModel(tmppromotion.afficher2());

        QSqlQueryModel * model1= new QSqlQueryModel();
               model1->setQuery("select ID from evenement")  ;
               ui->comboBox_5->setModel(model1) ;

QMessageBox::information(nullptr, QObject::tr("Ajouter une promotion"),
                  QObject::tr("promotion ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un promotion"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void mainproject::on_pushButton_supprimerpromo_clicked()
{

    QString id = ui->lineEdit_91->text();
    bool test=tmppromotion.supprimer(id);

    if(test)
    {
        ui->tableView_colis_6->setModel(tmppromotion.afficher2());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une promotion"),
                    QObject::tr("promotion supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une promotion"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void mainproject::on_pushButton_recherchepromo_clicked()
{
}

/*void mainproject::on_lineEdit_91_cursorPositionChanged(int arg1, int arg2)
{

}*/

void mainproject::on_lineEdit_91_textEdited(const QString &arg1)
{

    promotion a;
    ui->tableView_colis_6->setModel(tmppromotion.recherche(arg1));
}

void mainproject::on_pushButton_57_clicked()
{

    QString id=ui->lineEdit12_13->text() ;




    int pourcentage= ui->lineEdit_93->text().toInt();

    int duree= ui->lineEdit13_13->text().toInt();
       int id_evenement=ui->comboBox_10->currentText().toInt() ;

  promotion p(id,pourcentage,duree,id_evenement);


  bool test=p.update1(id);
  if(test)
{
ui->tableView_colis_6->setModel(tmppromotion.afficher2());

QMessageBox::information(nullptr, QObject::tr("modifier un promotion"),
                  QObject::tr("promotion modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un promotion"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
  }

