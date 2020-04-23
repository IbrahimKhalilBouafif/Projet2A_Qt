#include "statistiques.h"
#include "ui_statistiques.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
statistiques::statistiques(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);

    QSqlQuery query,query1;

int i =0;
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(255,255,255));
    gradient.setColorAt(0.38, QColor(255,255,255));
    gradient.setColorAt(1, QColor(255,255,255));
    ui->widget->setBackground(QBrush(gradient));
 QCPBars *fossil = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
 //fossil->setName("Fossil fuels");
 fossil->setPen(QPen(QColor(0, 0, 255).lighter(170)));
 fossil->setBrush(QColor(0, 0, 255));
    // create empty bar chart objects:
   /* QCPBars *regen = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
    QCPBars *nuclear = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);

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
    ui->widget->xAxis->setTicker(textTicker);
    ui->widget->xAxis->setTickLabelRotation(60);
    ui->widget->xAxis->setSubTicks(false);
    ui->widget->xAxis->setTickLength(0, 4);
    ui->widget->xAxis->setRange(0, 8);
    ui->widget->xAxis->setBasePen(QPen(Qt::black));
    ui->widget->xAxis->setTickPen(QPen(Qt::black));
    ui->widget->xAxis->grid()->setVisible(true);
    ui->widget->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->widget->xAxis->setTickLabelColor(Qt::black);
    ui->widget->xAxis->setLabelColor(Qt::black);

    // prepare y axis:
    ui->widget->yAxis->setRange(0, 20);
    ui->widget->yAxis->setPadding(5); // a bit more space to the left border
    ui->widget->yAxis->setLabel("Bénefice des publicités en 2019");
    ui->widget->yAxis->setBasePen(QPen(Qt::black));
    ui->widget->yAxis->setTickPen(QPen(Qt::black));
    ui->widget->yAxis->setSubTickPen(QPen(Qt::black));
    ui->widget->yAxis->grid()->setSubGridVisible(true);
    ui->widget->yAxis->setTickLabelColor(Qt::black);
    ui->widget->yAxis->setLabelColor(Qt::black);
    ui->widget->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->widget->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:

   fossilData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;

   fossil->setData(ticks, fossilData);
  /* nuclear->setData(ticks, nuclearData);
    regen->setData(ticks, regenData);*/

    // setup legend:
    //ui->widget->legend->setVisible(true);
    ui->widget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->widget->legend->setBrush(QColor(255, 255, 255, 100));
    ui->widget->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->widget->legend->setFont(legendFont);
    ui->widget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}

statistiques::~statistiques()
{
    delete ui;
}
