#include "excluir.h"
#include "clientes.h"
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
#include <QtSql>



excluir::excluir(QString& id_excluir)
{

        valid(sessionCode);


        QUrl carregar(QString("http://192.168.0.129//destroy_objects.fcgi?session="+sessionCode));
        QNetworkRequest requestcarrega(carregar);
        requestcarrega.setHeader(QNetworkRequest::ContentTypeHeader, "application/json; charset=utf-8" );

        int i = id_excluir.toInt();

        QJsonObject obj3{{"=",i}};
        QJsonObject obj2{{"id",obj3}};

        QJsonObject obj{
          {"users",obj2}
        };

        QJsonObject objcarrega{
        {"object","users"},
        {"where",obj}
        };

        QNetworkAccessManager crg;
        QNetworkReply *replycrg = crg.post(requestcarrega, QJsonDocument(objcarrega).toJson());

        while(!replycrg->isFinished()){

          qApp->processEvents();
        }

        QByteArray resposta = replycrg->readAll();
        QJsonDocument crg2 = QJsonDocument::fromJson(resposta);

        qDebug() << crg2;
        replycrg->deleteLater();

        }

