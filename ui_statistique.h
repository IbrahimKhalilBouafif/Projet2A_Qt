#ifndef UI_STATISTIQUE_H
#define UI_STATISTIQUE_H

#endif // UI_STATISTIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statistique
{
public:

    void setupUi(QWidget *statistique)
    {
        if (statistique->objectName().isEmpty())
            statistique->setObjectName(QStringLiteral("statistique"));
        statistique->setWindowModality(Qt::WindowModal);
        statistique->resize(400, 300);

        retranslateUi(statistique);

        QMetaObject::connectSlotsByName(statistique);
    } // setupUi

    void retranslateUi(QWidget *statistique)
    {
        statistique->setWindowTitle(QApplication::translate("statistique", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class statistique: public Ui_statistique {};
} // namespace Ui

QT_END_NAMESPACE

//#endif // UI_STATISTIQUE_H
