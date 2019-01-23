#include "tela_inicial.h"
#include "ui_tela_inicial.h"
#include "altera_hora.h"
#include "novocadastro.h"
#include "clientes.h"
#include "valid.h"
#include "sincroniza.h"

#include <QtSql>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QDesktopServices>
#include <QFileDialog>

static QSqlDatabase banco2 = QSqlDatabase::addDatabase("QSQLITE");

 tela_inicial::tela_inicial(QWidget *parent) :
    QMainWindow(parent),
   ui (new Ui::tela_inicial)
{

    ui->setupUi(this);
    // >>>>>>>>>>>>> ping conexão  <<<<<<<<<<<<<<<<<<


     QString m_sHostName = "192.168.0.129";
     QProcess *proc = new QProcess();
     proc->start("ping", QStringList() << QString(m_sHostName));
     QByteArray strdata = proc->readAllStandardOutput();
     qDebug() << strdata;
        // strdata = strdata.simplified();
         //strdata = strdata.trimmed();

    // QByteArray strdata = proc->readAllStandardError();

    //<<<<<<<<<<<<<<<<<fim ping conexão >>>>>>>>>>>>>>>>>

    //QString dir=qApp->applicationDirPath();
//    QString banco_de_dados = "D:\\Qt\\Control_ID\\build-Control_ID-Desktop_Qt_5_12_0_MinGW_64_bit-Debug\\debug\\dados\\dados_clientes.db";
      QString banco_de_dados = "D:\\Qt\\Control_ID\\dados_clientes.db";
    banco2.setDatabaseName(banco_de_dados);

    if(!banco2.open()){
        qDebug() << "Erro ao abrir o DB";

    }else{

        qDebug() << "o DB abiu corretamente";
    }

    // banco de dados --------------------- ^

    sincroniza(contador,sessionCode);


    ui->log->setEnabled(false);


    // >>>>>>>>>>>>>>> ultimos cadastros <<<<<<<<<<<<<<<<<<

    QSqlQuery query;
    query.prepare("select * from usuarios");

    if(query.exec()){

           ui->visual_qtb->clear();

        int cont = 0;


        while(query.next()){
    ui->visual_qtb->setColumnCount(2);
    ui->visual_qtb->insertRow(cont);
    ui->visual_qtb->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
    ui->visual_qtb->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));


    QStringList topo ={"Id","Nome"};
    ui->visual_qtb->setColumnWidth(0,24);
    ui->visual_qtb->setColumnWidth(1,105);
    ui->visual_qtb->setHorizontalHeaderLabels(topo);
     cont++;

        }

        ui->visual_qtb->verticalHeader()->setVisible(false);

        ui->visual_qtb->setSelectionBehavior(QAbstractItemView::SelectRows);
}

    // verificador hora --------------------------------------------/ ---------

    QString data = QDate(QDate::currentDate()).toString();
    QString time = QTime(QTime::currentTime()).toString();

    QStringRef subdia(&data, 8, 2);
    QStringRef subano(&data, 11, 4);
    QStringRef submes(&data, 4,3);
    QString meses = submes.toString();

    if (meses == "dez"){
            mes = 12;
    }if(meses == "jan"){
            mes = 1;
    }if(meses == "fev"){
            mes = 2;
    }if(meses == "mar"){
            mes = 3;
    }if(meses == "abr"){
            mes = 4;
    }if(meses == "mai"){
            mes = 5;
    }if(meses == "jun"){
            mes = 6;
    }if(meses == "jul"){
            mes = 7;
    }if(meses == "ago"){
            mes = 8;
    }if(meses == "set"){
            mes = 9;
    }if(meses == "out"){
            mes = 10;
    }if(meses == "nov"){
            mes = 11;
    }


    QStringRef subhora(&time, 0,2);
    QStringRef submin(&time, 3,2);

    int dia = subdia.toInt();
    int ano = subano.toInt();
    int hora = subhora.toInt();
    int minuto = submin.toInt();

     valid(sessionCode);


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
       valt.insert("second",0);



    QNetworkAccessManager alt;
    QNetworkReply *replyalt = alt.post(requestaltera, QJsonDocument(valt).toJson());
    while(!replyalt->isFinished()){
        qApp->processEvents();
    }

    QByteArray confirmaaltera;
    QJsonDocument altera2 = QJsonDocument::fromJson(confirmaaltera);
    replyalt->deleteLater();






    //----------------------------------------

}

tela_inicial::~tela_inicial()
{
    delete ui;
}

void tela_inicial::on_sair_clicked()
{
    close();
}

void tela_inicial::on_conectar_clicked()
{

    QUrl myURL(QString("http://192.168.0.129/login.fcgi"));
    QNetworkRequest request(myURL);
    request.setHeader(QNetworkRequest::ContentTypeHeader,
                      "application/json; charset=utf-8" );
    QJsonObject json{

     {"login","admin"},
     {"password","admin"}

 };
    QNetworkAccessManager tst;
    QNetworkReply *reply = tst.post(request,QJsonDocument(json).toJson());

    while(!reply->isFinished()){

        qApp->processEvents();
    }
    QByteArray response_data = reply->readAll();

    QJsonDocument json2 = QJsonDocument::fromJson(response_data);

    ui->log->setText("Conectado <<<<>>>>>> Nova Session :"+response_data);
    qDebug () << response_data;
    reply->deleteLater();

}



void tela_inicial::on_acionar_clicked()
{
        valid(sessionCode);



                    // EXECUÇÃO DE RELE ---->

        QUrl equipURL(QString("http://192.168.0.129/execute_actions.fcgi?session="+sessionCode));
        QNetworkRequest requestt(equipURL);
        requestt.setHeader(QNetworkRequest::ContentTypeHeader, "application/json; charset=utf-8");

        QJsonObject action1{
            {"action","door"},
            {"parameters","door=1"}
        };

        QJsonArray actions;
        actions.push_back(action1);

        QJsonObject actions2{{"actions", actions}};

        QNetworkAccessManager tst2;
        QNetworkReply *reply2 = tst2.post(requestt,QJsonDocument(actions2).toJson());

        while(!reply2->isFinished()){

            qApp -> processEvents();

        }
        QByteArray response_data2 = reply2->readAll();
        QJsonDocument  action = QJsonDocument::fromJson(response_data2);

        ui->log->setText("Conectado"
                         "\nSession: >> "+sessionCode+
                         "\nRelê Acionado");
        qDebug ()<<response_data2;
        reply2->deleteLater();

}



void tela_inicial::on_alterar_clicked()
{
    altera_hora altera_hora;
    altera_hora.exec();

}

void tela_inicial::on_cadastrar_clicked()
    {

        ui->visual_qtb->update();

        novocadastro novocadastro;
        novocadastro.exec();

}

void tela_inicial::on_listar_clicked()
{

  ui->visual_qtb->show();
  clientes clientes;
  clientes.exec();

}

void tela_inicial::on_visual_qtb_cellDoubleClicked()
{

    int linha = ui->visual_qtb->currentRow();
    idd = ui->visual_qtb->item(linha,0)->text();
    novocadastro novocadastro(this,idd);
    novocadastro.exec();

}

void tela_inicial::on_atualiza_clicked()
{;
    ui->visual_qtb->clear();
    QSqlQuery query;
       query.prepare("select * from usuarios");


      ui->visual_qtb->clear();

       if(query.exec()){

         int cont = 0;

           while(query.next()){

       ui->visual_qtb->removeRow(cont);
       ui->visual_qtb->setColumnCount(2);
       ui->visual_qtb->insertRow(cont);
       ui->visual_qtb->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
       ui->visual_qtb->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
       cont++;
       QStringList topo ={"Id","Nome"};
       ui->visual_qtb->setHorizontalHeaderLabels(topo);

           }

           ui->visual_qtb->setColumnWidth(0,24);
           ui->visual_qtb->setColumnWidth(1,105);
           ui->visual_qtb->verticalHeader()->setVisible(false);

           ui->visual_qtb->setSelectionBehavior(QAbstractItemView::SelectRows);

       }

}
