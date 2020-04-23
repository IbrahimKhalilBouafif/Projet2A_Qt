#ifndef MAINPROJECT_H
#define MAINPROJECT_H

#include <QMainWindow>
#include "vehicule.h"
#include "circuit.h"
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

    void on_pushButton_ajouter_v_clicked();

    void on_lineEdit_94_textEdited(const QString &arg1);

    void on_pushButton_modif_v_clicked();

    void on_pushButton_Supprimer_Vehicule_clicked();

    void on_pushButton_ajout_circuit_clicked();

    void on_pushButton_modif_circuit_clicked();

    void on_pushButton_Supprimer_Circuit_clicked();

    void on_lineEdit_rech_circuit_textEdited(const QString &arg1);

    void on_pushButton_Rechercher_Vehicule_clicked();

    void on_pushButton_rech_circuit_clicked();

    void on_stat_clicked();



private:
    Ui::mainproject *ui;
    vehicule tmpveh;
    circuit tmpcir;

};

#endif // MAINPROJECT_H
