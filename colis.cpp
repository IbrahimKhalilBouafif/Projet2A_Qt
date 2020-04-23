#include "colis.h"

Colis::Colis()
{
    id=0;
    expediteur=0;
    destinataire="";
    objet="";
    dimension="";
    poids=0;
    statut="";

}

Colis::Colis(int id,int expediteur,QString destinataire,QString objet,QString dimension,int poids,QString statut)
{
    this->id=id;
    this->expediteur=expediteur;
    this->destinataire=destinataire;
    this->objet=objet;
    this->dimension=dimension;
    this->poids=poids;
    this->statut=statut;
}

bool Colis::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO COLIS (id,expediteur,destinataire,objet,dimension,poids,statut)VALUES(:id,:expediteur,:destinataire,:objet,:dimension,:poids,:status)");
    query.bindValue(":id",id);
    query.bindValue(":expediteur",expediteur);
    query.bindValue(":destinataire",destinataire);
    query.bindValue(":objet",objet);
    query.bindValue(":dimension",dimension);
    query.bindValue(":poids",poids);
    query.bindValue(":status",statut);
    bool verif=query.exec();
    if(verif==false){
        qDebug()<<query.lastQuery();
        qDebug()<<query.lastError();
    }
    return verif;
}

QSqlQueryModel * Colis::afficher(QString search)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString qry="select * from colis where id like '%"+search+"%' or expediteur like '%"+search+"%' or destinataire like '%"+search+"%' or objet like '%"+search+"%' or dimension like '%"+search+"%' or poids like '%"+search+"%' or statut like '%"+search+"%'";

    model->setQuery(qry);
    return model;
}

bool Colis::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("DELETE from COLIS where ID = :id ");
    query.bindValue(":id",res);
    return query.exec();
}

bool Colis::modifier(int idd)
{
    QSqlQuery query;
    query.prepare("UPDATE COLIS SET expediteur=:expediteur,destinataire=:destinataire,objet=:objet,dimension=:dimension,poids=:poids,statut=:statut WHERE id=:idd");
    query.bindValue(":idd",idd);
    query.bindValue(":expediteur",expediteur);
    query.bindValue(":destinataire",destinataire);
    query.bindValue(":objet",objet);
    query.bindValue(":dimension",dimension);
    query.bindValue(":poids",poids);
    query.bindValue(":statut",statut);
    bool verif=query.exec();
    if(verif==false){
        qDebug()<<query.lastQuery();
        qDebug()<<query.lastError();
    }
    return verif;
}




QSqlQueryModel * Colis::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM colis ORDER BY id");
    return model;

}

void Colis::pdf(int idd)
{
    if(idd!=-1){
    QSqlQuery qry;
    qry.prepare("SELECT * FROM COLIS WHERE ID=:idd");
    qry.bindValue(":idd",idd);
    qry.exec();
     system("del /f D:\\template\\example.pdf");
     system("del /f D:\\template\\Data.html");
        QFile filein(QString("D:\\template\\colis.htm")) ;
        filein.open(QFile::ReadOnly);
        QTextStream in(&filein);
        QString text=in.readAll();
        while(qry.next()){
            QSqlQuery qry2;
            qry2.prepare("select NOM,PRENOM from CLIENT where ID=:id2");
            qry2.bindValue(":id2",qry.value(1).toInt());
            qry2.exec();
            QString fullname;
            while(qry2.next())
                fullname=qry2.value(1).toString()+" "+qry2.value(0).toString();
            QString txt=" <tr style='height:18.2pt'>"
                        "  <td width=37 valign=top style='width:28.1pt;border:solid windowtext 1.0pt;"
                        "  border-top:none;padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                        "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                        "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+qry.value(0).toString()+"</span></p>"
                        "  </td>"
                        "  <td width=123 valign=top style='width:92.0pt;border-top:none;border-left:"
                        "  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;"
                        "  padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                        "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                        "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+fullname+"</span></p>"
                        "  </td>"
                        "  <td width=123 valign=top style='width:92.05pt;border-top:none;border-left:"
                        "  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;"
                        "  padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                        "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                        "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+qry.value(2).toString()+"</span></p>"
                        "  </td>"
                        "  <td width=111 valign=top style='width:83.1pt;border-top:none;border-left:"
                        "  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;"
                        "  padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                        "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                        "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+qry.value(3).toString()+"</span></p>"
                        "  </td>"
                        "  <td width=97 valign=top style='width:73.05pt;border-top:none;border-left:"
                        "  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;"
                        "  padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                        "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                        "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+qry.value(4).toString()+"</span></p>"
                        "  </td>"
                        "  <td width=75 valign=top style='width:56.55pt;border-top:none;border-left:"
                        "  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;"
                        "  padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                        "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                        "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+qry.value(5).toString()+"</span></p>"
                        "  </td>"
                        "  <td width=133 valign=top style='width:99.65pt;border-top:none;border-left:"
                        "  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;"
                        "  padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                        "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                        "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+qry.value(6).toString()+"</span></p>"
                        "  </td>"
                        " </tr> <!--1-->";
                        text.replace("<!--1-->",txt);
        }
        QString filename="D:\\template\\Data.html";
        QFile file( filename );
        if ( file.open(QIODevice::ReadWrite) )
        {
            QTextStream stream( &file );
            stream << text << endl;
        }

        system("D:\\template\\wkhtmltopdf.exe -T 0 -B 0 --page-width 210mm --page-height 297mm \"D:\\template\\Data.html\" D:\\template\\example.pdf");
        // system("del /f C:\\sqlite\\test12.pdf");
        QDesktopServices::openUrl(QUrl("file:///D:/template/example.pdf"));

    }
    else{
        QSqlQuery qry;
        qry.prepare("SELECT * FROM COLIS ");
        qry.exec();
         system("del /f D:\\template\\example.pdf");
         system("del /f D:\\template\\Data.html");
            QFile filein(QString("D:\\template\\colis.htm")) ;
            filein.open(QFile::ReadOnly);
            QTextStream in(&filein);
            QString text=in.readAll();
            while(qry.next()){
                QSqlQuery qry2;
                qry2.prepare("select NOM,PRENOM from CLIENT where ID=:id2");
                qry2.bindValue(":id2",qry.value(1).toInt());
                qry2.exec();
                QString fullname;
                while(qry2.next())
                    fullname=qry2.value(1).toString()+" "+qry2.value(0).toString();
                QString txt=" <tr style='height:18.2pt'>"
                            "  <td width=37 valign=top style='width:28.1pt;border:solid windowtext 1.0pt;"
                            "  border-top:none;padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                            "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                            "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+qry.value(0).toString()+"</span></p>"
                            "  </td>"
                            "  <td width=123 valign=top style='width:92.0pt;border-top:none;border-left:"
                            "  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;"
                            "  padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                            "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                            "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+fullname+"</span></p>"
                            "  </td>"
                            "  <td width=123 valign=top style='width:92.05pt;border-top:none;border-left:"
                            "  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;"
                            "  padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                            "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                            "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+qry.value(2).toString()+"</span></p>"
                            "  </td>"
                            "  <td width=111 valign=top style='width:83.1pt;border-top:none;border-left:"
                            "  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;"
                            "  padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                            "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                            "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+qry.value(3).toString()+"</span></p>"
                            "  </td>"
                            "  <td width=97 valign=top style='width:73.05pt;border-top:none;border-left:"
                            "  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;"
                            "  padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                            "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                            "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+qry.value(4).toString()+"</span></p>"
                            "  </td>"
                            "  <td width=75 valign=top style='width:56.55pt;border-top:none;border-left:"
                            "  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;"
                            "  padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                            "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                            "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+qry.value(5).toString()+"</span></p>"
                            "  </td>"
                            "  <td width=133 valign=top style='width:99.65pt;border-top:none;border-left:"
                            "  none;border-bottom:solid windowtext 1.0pt;border-right:solid windowtext 1.0pt;"
                            "  padding:0cm 5.4pt 0cm 5.4pt;height:18.2pt'>"
                            "  <p class=MsoNormal align=center style='margin-bottom:0cm;margin-bottom:.0001pt;"
                            "  text-align:center;line-height:normal'><span style='font-size:14.0pt'>"+qry.value(6).toString()+"</span></p>"
                            "  </td>"
                            " </tr> <!--1-->";
                            text.replace("<!--1-->",txt);
            }
            QString filename="D:\\template\\Data.html";
            QFile file( filename );
            if ( file.open(QIODevice::ReadWrite) )
            {
                QTextStream stream( &file );
                stream << text << endl;
            }

            system("D:\\template\\wkhtmltopdf.exe -T 0 -B 0 --page-width 210mm --page-height 297mm \"D:\\template\\Data.html\" D:\\template\\example.pdf");
            // system("del /f C:\\sqlite\\test12.pdf");
            QDesktopServices::openUrl(QUrl("file:///D:/template/example.pdf"));
    }
}
void Colis::stat(QCustomPlot *customPlot)
{
    QSqlQuery query,query1;
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    customPlot->clearPlottables();
    customPlot->clearGraphs();
    customPlot->replot();

    customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
   // QCPBars *regen = new QCPBars(customPlot->xAxis, customPlot->yAxis);
   // QCPBars *nuclear = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    QCPBars *fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);
  //  regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
  //  nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
  //  regen->setStackingGap(1);
    //nuclear->setStackingGap(1);
    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("Colis");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
  //  nuclear->setName("Nuclear");
  //  nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
  //  nuclear->setBrush(QColor(250, 170, 20));
   // regen->setName("Regenerative");
  //  regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
  //  regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:
  //  nuclear->moveAbove(fossil);
 //   regen->moveAbove(nuclear);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    query.prepare("SELECT COUNT(DISTINCT id) FROM colis where statut = 'En transit'");
    query.exec();
    int trans;
    while(query.next())
    {
        trans=query.value(0).toInt();
    }
    query.prepare("SELECT COUNT(DISTINCT id) FROM colis where statut = 'ReÃ§u'");
    query.exec();
    int recu;
    while(query.next())
    {
        recu=query.value(0).toInt();
    }




    ticks << 1 << 2 ;
    labels << "En transit" << "Reçu" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 8);
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 20);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Nombre des colis en transit et reçu");
    customPlot->yAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setTickPen(QPen(Qt::white));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(Qt::white);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData, nuclearData, regenData;
    fossilData  << trans << recu;
   // nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossilData);
  //  nuclear->setData(ticks, nuclearData);
 //   regen->setData(ticks, regenData);

    // setup legend:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = QFont();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}
