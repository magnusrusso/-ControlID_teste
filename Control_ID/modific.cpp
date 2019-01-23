#include "modific.h"
#include "valid.h"
#include "clientes.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

void modific(QString& sessionCode,QString& id,QString& nome)
{
    int i = id.toInt();
    valid(sessionCode);

    QUrl modificar(QString("http://192.168.0.129/modify_objects.fcgi?session="+sessionCode));
    QNetworkRequest respmodifc(modificar);
    respmodifc.setHeader(QNetworkRequest::ContentTypeHeader,
                         "application/json; charset=utf-8");

    QJsonObject obj1;
    obj1.insert("name",nome);
    obj1.insert("id",i);

// where ------------
    QJsonObject objw{{"=",i}};
    QJsonObject objw1{{"id",objw}};

    QJsonObject obj;
    obj.insert("users",objw1);

// -----fim where ---------------

    QJsonObject modifica;
    modifica.insert("object","users");
    modifica.insert("values",obj1);
    modifica.insert("where",obj);

    QNetworkAccessManager mod;
    QNetworkReply *replymod = mod.post(respmodifc,QJsonDocument(modifica).toJson());

    while(!replymod->isFinished()){

        qApp->processEvents();
    }

    QByteArray response_data_mod = replymod->readAll();
    QJsonDocument modifica2 = QJsonDocument::fromJson(response_data_mod);

    qDebug() << modifica;
    qDebug () <<response_data_mod ;
    replymod->deleteLater();

}
