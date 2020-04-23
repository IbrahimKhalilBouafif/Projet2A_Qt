#ifndef MAINPROJECT_H
#define MAINPROJECT_H

#include <QMainWindow>
#include "colis.h"
#include "courrier.h"
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


    void on_pushButton_AjoutColis_clicked();

    void on_pushButton_SupprimerColis_clicked();

    void on_pushButton_ModifierColis_clicked();

    void on_lineEdit_73_textEdited(const QString &arg1);

    void on_pushButton_Ajout_Courrier_clicked();

    void on_lineEdit_recherche_courrier_textEdited(const QString &arg1);

    void on_pushButton_Supprimer_Courrier_clicked();

    void on_pushButton_modifier_courrier_clicked();

    void on_pushButton_131_clicked();

    void on_pushButton_128_clicked();

    void on_pushButton_stat_clicked();

    void on_pushButton_tri_colis_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_stat_courrier_clicked();

    void on_commandLinkButton_clicked();

private:
    void reset_style_sheet();
    Ui::mainproject *ui;
    Colis tmpcolis;
    Courrier tmpcourrier;
};

#endif // MAINPROJECT_H
