#include "id_aleatorio.h"
#include "valid.h"

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QApplication>

void id_aleatorio(QString& sessionCode,int& check)
{

    valid(sessionCode);

       QUrl carregar(QString("http://192.168.0.129//load_objects.fcgi?session="+sessionCode));
       QNetworkRequest requestcarrega(carregar);
       requestcarrega.setHeader(QNetworkRequest::ContentTypeHeader, "application/json; charset=utf-8" );

       QJsonArray array{"id"};

       QJsonObject objcarrega{
       {"object","users"},
       {"fields",array}

   };

       QNetworkAccessManager crg;
       QNetworkReply *replycrg = crg.post(requestcarrega, QJsonDocument(objcarrega).toJson());

       while(!replycrg->isFinished()){
           qApp->processEvents();

       }

       QByteArray resposta = replycrg->readAll();
       QJsonDocument crg2 = QJsonDocument::fromJson(resposta);

       QJsonObject obj = crg2.object();
       int limit_contador = obj["users"].toArray().count();
       qDebug() << limit_contador;
       int cont_n_id = 0;
       check = 0 ;
       //funciona conversão e separe
       QJsonArray v = obj["users"].toArray();

       while(limit_contador!=cont_n_id){

       QJsonObject obk = v.takeAt(0).toObject();
       QJsonDocument doc(obk);
       QString strJson(doc.toJson(QJsonDocument::Compact));

       QStringRef teste(&strJson,6,4);
       QString k = teste.toString();
       std::string str = k.toStdString();
       const char* p = str.c_str();
       int chars = (atoi)(p);
       if(check == chars){
           qDebug() << "check não é esse :" << check;
           check = chars + 1;

       }else{
           qDebug() <<" check achou " << check;

       }

       qDebug() << check;
       cont_n_id++;
   }
       replycrg->deleteLater();

}
