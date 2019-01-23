#include "sincroniza.h"
#include "valid.h"

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QtSql>


void sincroniza(int& contador,QString& sessionCode)
{
    QSqlQuery query;
    query.prepare("select count(id) from usuarios");
    if(query.exec())
    {
       qDebug () << "verificando usuarios...";

       while(query.next()){
           contador = query.value(0).toInt();
           qDebug () << "BD contados: " << contador;
       }
    }else{
        qDebug () << "erro verificar: " << query.lastError();
    }

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
   int equip_cont = obj["users"].toArray().count();
   qDebug() << "equipamentos contados: " << equip_cont;
    replycrg->deleteLater();

    if(contador == equip_cont){
        QMessageBox::information(nullptr,"Info","Status do Banco de Dados\n SINCRONIZADO");
    }
    else{
        QMessageBox::warning(nullptr,"Warning","Status do Banco de Dados\n NÃO SINCRONIZADO");

        QSqlQuery query;

        query.exec("select id,nome from usuarios");
        while(query.next()){

            int id_bd = query.value(0).toInt();
            QString nome_bd = query.value(1).toString();
            qDebug()<<id_bd;
            qDebug()<<nome_bd;


            QUrl urlcadastro(QString("http://192.168.0.129/create_objects.fcgi?session="+sessionCode));
            QNetworkRequest requestcadastro(urlcadastro);
            requestcadastro.setHeader(QNetworkRequest::ContentTypeHeader,
                              "application/json; charset=utf=8");

            QJsonObject cadastro;
            cadastro.insert("id", id_bd);
            cadastro.insert("name",nome_bd);
            cadastro.insert("registration","");

            QJsonArray array;
            array.push_back(cadastro);

            QJsonObject obj;
            obj.insert("object","users");
            obj.insert("values",array);


               QNetworkAccessManager tsted;
               QNetworkReply *replyed = tsted.post(requestcadastro, QJsonDocument(obj).toJson());

               while(!replyed->isFinished()){

                   qApp->processEvents();
               }

               QByteArray response_data2 = replyed->readAll();

               QJsonDocument registro2 = QJsonDocument::fromJson(response_data2);

               qDebug() << registro2;
               replyed->deleteLater();

               //inicio p2---

               QUrl urlgrupos(QString("http://192.168.0.129/create_objects.fcgi?session="+sessionCode));
               QNetworkRequest requestgrupo(urlgrupos);
               requestgrupo.setHeader(QNetworkRequest::ContentTypeHeader,
                                 "application/json; charset=utf=8");


               QJsonObject inserir;
               inserir.insert("user_id", id_bd);
               inserir.insert("group_id",1);

               QJsonArray grupos;
               grupos.push_back(inserir);

               QJsonObject user_grupos;
               user_grupos.insert("object","user_groups");
               user_grupos.insert("values",grupos);


               QNetworkAccessManager menagegrupo;
               QNetworkReply *repl = menagegrupo.post(requestgrupo, QJsonDocument(user_grupos).toJson());

               while(!repl->isFinished()){

                   qApp->processEvents();
               }

               QByteArray respostagrupos = replyed->readAll();

               QJsonDocument mgp = QJsonDocument::fromJson(respostagrupos);

               qDebug() << mgp;
               replyed->deleteLater();

        }


    }   // ->>>>>>>>>>>>>>>>>>>>>>> FINAL ELSE (verificação de sincronismo) <<<<<<<<<<<<<<<<<<<<<<<<<


} // ->>>>>>>>>>>>>>> final função <<<<<<<<<<<<<<<<<<<<<<<<<<
