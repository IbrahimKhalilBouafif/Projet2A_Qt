#ifndef MAINPROJECT_H
#define MAINPROJECT_H

#include <QMainWindow>

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

    void on_pushButton_enregistrerClient_clicked();

    void on_pushButton_SupprimerC_clicked();

    void on_Button_SuppClient_clicked();

    void on_Button_Modifier_Client_clicked();

    void on_pushButton_RechercheC_clicked();

    void on_Tri_Client_parNom_clicked();

    void on_Ajouter_Carte_clicked();

    void on_Modfier_Carte_clicked();

    void on_pushButton_SupprimerCarte_clicked();

    void on_Button_SuppCarte_clicked();

    void on_Tri_Carte_parRef_clicked();

    void on_pushButton_RechercherCarte_clicked();



    void on_pushButton_clicked();
    void on_tableView_Client_activated(const QModelIndex &index);

     void on_tableView_carte_activated(const QModelIndex &index);



     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

private:
    Ui::mainproject *ui;
};

#endif // MAINPROJECT_H
