#ifndef MAINPROJECT_H
#define MAINPROJECT_H
#include "employe.h"
#include "departement.h"
#include <QMainWindow>
#include <qcustomplot.h>

namespace Ui {
class mainproject;
}

class mainproject : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainproject(QWidget *parent = nullptr);
    ~mainproject();

private slots:
    void on_pushButton_14_clicked();









    void on_pushButton_Employe_clicked();

    void on_pushButton_Departement_clicked();

    void on_pushButton_Ajouter_Employe_clicked();

    void on_pushButton_Modifier_Employe_clicked();

    void on_pushButton_Ajouter_Departement_clicked();



    void on_pushButton_Modifier_Departement_clicked();

    void on_pushButton_Vehicule_clicked();

    void on_pushButton_Ajouter_Vehicule_clicked();

    void on_pushButton_Modifier_Vehicule_clicked();

    void on_pushButton_circuit_clicked();

    void on_pushButton_Ajouter_Circuit_clicked();



    void on_pushButton_Modifier_Circuit_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_Ajouter_Colis_clicked();

    void on_pushButton_Modifier_Colis_clicked();

    void on_pushButton_Courrier_clicked();

    void on_pushButton_Colis_clicked();

    void on_pushButton_Ajouter_Courrier_clicked();

    void on_pushButton_Modifier_Courrier_clicked();

    void on_pushButton_Client_clicked();

    void on_pushButton_AjoutClient_clicked();

    void on_pushButton_ModifierC_clicked();

    void on_pushButton_Carte_clicked();

    void on_pushButton_AjouterCarte_clicked();

    void on_pushButton_ModifierCarte_clicked();

    void on_pushButton_Evenements_clicked();

    void on_pushButton_Ajoutevent_clicked();

    void on_pushButton_modifierevent_clicked();





    void on_pushButton_Promo_clicked();

    void on_pushButton_ajoutpromo_clicked();

    void on_pushButton_modifierpromo_clicked();



    void on_pushButton_ajouterb_clicked();


    void on_pushButton_Supprimer_Employe_clicked();

    void on_pushButton_suprimerebase_clicked();



    void on_pushButton_ajouterdep_clicked();

    void on_pushButton_Supprimer_Departement_clicked();



    void on_pushButton_supdepb_clicked();

    void on_pushButton_73_clicked();

    void on_pushButton_69_clicked();

    void on_pushButton_Rechercher_departement_clicked();

    void on_pushButton_Rechercher_employe_clicked();

    void on__trie_2_clicked();

    void on_trie_2_clicked();

    void on_pushButton_trie1_clicked();

    void on_pushButton_pdfEmp_clicked();

    void on_tableView_affemploye_activated(const QModelIndex &index);

    void on_tableView_departement_activated(const QModelIndex &index);

    void on_pushButto_pdfDep_clicked();

    void on_pushButton_excel_clicked();

    void on_pushButton_excelemp_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_ide_inputRejected();

private:
    Ui::mainproject *ui;
    employe tmpemploye;
    departement tmpdepartement;

};

#endif // MAINPROJECT_H
