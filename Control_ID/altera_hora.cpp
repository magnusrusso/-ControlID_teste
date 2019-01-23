#include "altera_hora.h"
#include "ui_altera_hora.h"
#include "valid.h"
#include "insert_bd.h"

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

altera_hora::altera_hora(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::altera_hora)
{
    ui->setupUi(this);

        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &altera_hora::showTime);
        timer->start(1000);
}


altera_hora::~altera_hora()
{
    delete ui;
}


void altera_hora::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    ui->lcdNumber->display(text);

}

void altera_hora::on_altera_clicked()
{


    valid(sessionCode);



    int dia = ui->dia->text().toInt();
    int mes = ui->mes->text().toInt();
    int ano = ui->ano->text().toInt();
    int hora = ui->hora->text().toInt();
    int minuto = ui->minuto->text().toInt();
    int segundo = ui->segundo->text().toInt();


    QUrl altera(QString("http://192.168.0.129/set_system_time.fcgi?session="+sessionCode));
    QNetworkRequest requestaltera(altera);
    requestaltera.setHeader(QNetworkRequest::ContentTypeHeader,
                            "application/json; charset=utf=8");

    QJsonObject valt;

       valt.insert("day",dia);
       valt.insert("month",mes);
       valt.insert("year",ano);
       valt.insert("hour",hora);
       valt.insert("minute",minuto);
       valt.insert("second",segundo);



    QNetworkAccessManager alt;
    QNetworkReply *replyalt = alt.post(requestaltera, QJsonDocument(valt).toJson());
    while(!replyalt->isFinished()){
        qApp->processEvents();
    }

    QByteArray confirmaaltera;
    QJsonDocument altera2 = QJsonDocument::fromJson(confirmaaltera);

    QMessageBox::information(this,"info","Data / Hora Alterada");
    qDebug () << altera2;
    replyalt->deleteLater();
    ui->dia->setValue(1);
    ui->mes->setValue(1);
    ui->ano->setValue(1);
    ui->hora->setValue(00);
    ui->minuto->setValue(00);
    ui->segundo->setValue(00);

}
