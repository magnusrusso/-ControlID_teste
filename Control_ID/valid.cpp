#include "valid.h"
#include "novocadastro.h"
#include "clientes.h"

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QApplication>


void valid(QString& sessionCode)
{

    // VALIDAÇÃO ------------------------------------->

   QUrl urlverifica(QString("http://192.168.0.129/session_is_valid.fcgi?session="+sessionCode));
   QNetworkRequest request2(urlverifica);
   request2.setHeader(QNetworkRequest::ContentTypeHeader,"applicantion/json; charset=utf-8");

   QNetworkAccessManager vrf;
   QNetworkReply *replyvrf = vrf.post(request2,QJsonDocument().toJson());

   while(!replyvrf->isFinished()){

       qApp -> processEvents();
   }

   QByteArray reponse_datavrf = replyvrf->readAll();


   replyvrf->deleteLater();


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

   qDebug () << "sessão iniciada";
   reply->deleteLater();

   if(json2.isObject())
   {
       QJsonObject obj1 = json2.object();
       auto iter = obj1.find("session");
       if(iter != obj1.end())
       {
           sessionCode = iter.value().toString();

       }
       else
       {
           qDebug() << "Erro.......1";
           return;
       }
   }
   else
   {
       qDebug() << "Erro.......2";
       return;
   }

}
