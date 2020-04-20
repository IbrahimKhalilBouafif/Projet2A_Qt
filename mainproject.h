#ifndef MAINPROJECT_H
#define MAINPROJECT_H
#include "evenement.h"
#include "promotion.h"



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

    void on_pushButton_SupprimerColis_clicked();

    void on_pushButton_supprimerevent_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_clicked();

    void on_pushButton_supprimerid_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_rechercheevenement_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_imprimer_clicked();

    void on_pushButton_pdf_clicked();


    void on_pushButton_56_clicked();

    void on_pushButton_supprimerpromo_clicked();

    void on_pushButton_recherchepromo_clicked();

    //void on_lineEdit_91_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_91_textEdited(const QString &arg1);

    void on_pushButton_57_clicked();

private:
    Ui::mainproject *ui;
    Evenement  tmpevenement;
    promotion tmppromotion;

};

#endif // MAINPROJECT_H
