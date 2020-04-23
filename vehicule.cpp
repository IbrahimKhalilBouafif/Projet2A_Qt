#include "vehicule.h"
#include "ui_mainproject.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDialog>
vehicule::vehicule()
{
    this->matricule="";
    this->marque="";
    this->agent="";
    this->couleur="";
    this->zone="";
}
vehicule::vehicule(QString mat,QString marq,QString ag,QString col,QString zone)
{
    this->matricule=mat;
    this->marque=marq;
    this->agent=ag;
    this->couleur=col;
    this->zone=zone;
}
bool vehicule::ajouter_veh()
{
    QSqlQuery query;
    query.prepare("INSERT INTO vehicule (matricule,marque,agent,couleur,zone) VALUES (:matricule,:marque,:agent,:couleur,:zone)");
    query.bindValue(":matricule",matricule);
    query.bindValue(":marque",marque);
    query.bindValue(":agent",agent);
    query.bindValue(":couleur",couleur);
    query.bindValue(":zone",zone);
    return query.exec();
}
QSqlQueryModel * vehicule::afficher_veh()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("agent"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("zone"));
    return model;
}
QSqlQueryModel * vehicule::afficher_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select matricule from vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    return model;
}
bool vehicule::modifier_veh(QString mat,QString marq,QString ag,QString col,QString zone)
{
    QSqlQuery query;
    query.prepare("UPDATE vehicule SET matricule= :matricule,marque = :marque,agent = :agent,couleur = :couleur,zone = :zone  WHERE matricule= :matricule ");
    query.bindValue(":matricule",mat);
    query.bindValue(":marque",marq);
    query.bindValue(":agent",ag);
    query.bindValue(":couleur",col);
    query.bindValue(":zone",zone);
    return    query.exec();
}
bool vehicule::supprimer_veh(QString idd)
{
    QSqlQuery query;

    query.prepare("Delete from vehicule where matricule = :id ");
    query.bindValue(":id", idd);
    return    query.exec();
}
QSqlQueryModel * vehicule::rechercher_veh_dynamique(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM vehicule where matricule like '"+a+"' ||'%'");
    query.bindValue(":id",a);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("agent"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("zone"));
        return model;
}
QSqlQueryModel * vehicule::tri_veh()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM vehicule ORDER BY zone");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("agent"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("zone"));
    return model;
}
void vehicule::stat(QCustomPlot *customPlot)
{
    QSqlQuery query,query1;

int i =0;
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(255,255,255));
    gradient.setColorAt(0.38, QColor(255,255,255));
    gradient.setColorAt(1, QColor(255,255,255));
    customPlot->setBackground(QBrush(gradient));
 QCPBars *fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);
 //fossil->setName("Fossil fuels");
 fossil->setPen(QPen(QColor(0, 0, 255).lighter(170)));
 fossil->setBrush(QColor(0, 0, 255));
    // create empty bar chart objects:
   /* QCPBars *regen = new QCPBars(widget->xAxis, widget->yAxis);
    QCPBars *nuclear = new QCPBars(widget->xAxis, widget->yAxis);

    regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
    regen->setStackingGap(1);
    nuclear->setStackingGap(1);
    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("Fossil fuels");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
    nuclear->setName("Nuclear");
    nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    nuclear->setBrush(QColor(250, 170, 20));
    regen->setName("Regenerative");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:
    nuclear->moveAbove(fossil);
    regen->moveAbove(nuclear);*/

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
      QVector<double> fossilData;
    query.prepare("SELECT DISTINCT matricule FROM vehicule");
    query.exec();


    while(query.next())
    {


     labels.append(query.value(0).toString());
     i++;
     ticks.append(i);

     query1.prepare("SELECT matricule,sum(marque) FROM vehicule where marque = '"+query.value(0).toString()+"' Group By matricule");
     query1.exec();
     while (query1.next()) {
       fossilData.append(query1.value(0).toDouble());

     }

    }


    //ticks << 1 << 2 << 3 ;
  //  labels << "5000" << "10000" << "15000" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 8);
    customPlot->xAxis->setBasePen(QPen(Qt::black));
    customPlot->xAxis->setTickPen(QPen(Qt::black));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::black);
    customPlot->xAxis->setLabelColor(Qt::black);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 20);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Bénefice des publicités en 2019");
    customPlot->yAxis->setBasePen(QPen(Qt::black));
    customPlot->yAxis->setTickPen(QPen(Qt::black));
    customPlot->yAxis->setSubTickPen(QPen(Qt::black));
    customPlot->yAxis->grid()->setSubGridVisible(true);
   customPlot->yAxis->setTickLabelColor(Qt::black);
    customPlot->yAxis->setLabelColor(Qt::black);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
   customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:

   fossilData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;

   fossil->setData(ticks, fossilData);
  /* nuclear->setData(ticks, nuclearData);
    regen->setData(ticks, regenData);*/

    // setup legend:
    //widget->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = QFont();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

