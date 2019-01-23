#include "insert_bd.h"
#include "novocadastro.h"
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
#include "novocadastro.h"


void insert_bd (QString& p_bio,QString& users,QString& numerocartao,QString& senhacript,QString& idp,QString& nome)
{
    QString bio;
    qDebug() <<p_bio;
    if(p_bio=="0"){
        bio = "SEM BIO";
    }else{
        bio = "OK";
    }

    QSqlQuery checkquery;
    checkquery.prepare("select count(id) from usuarios where id="+idp+" or id="+users+" or id="+p_bio+"");
 if(checkquery.exec())
{
qDebug() <<users<<p_bio<<idp;
   if(checkquery.next())
    {
    int count = checkquery.value(0).toInt();
    qDebug () << "resultado : " << count;

            if(count == 0){

                QSqlQuery query;
               query.prepare("insert into usuarios(nome,id,senha,wcartao,biometria) values"
                              "('"+nome+"','"+idp+"','"+senhacript+"','"+numerocartao+"','"+bio+"')");
                if(query.exec()){

                    qDebug () << "inserido no db";
                }else {


                   qDebug() << "erro ao inserir" << query.lastError();
                    return;

                        }

            }
            else {
                QSqlQuery query;
                if(query.exec("update usuarios set wcartao="+numerocartao+" where id="+users+" or id="+p_bio+""))
                {
                    qDebug()<<"correto cartão";
                }else{
                    qDebug()<<"erro update cartão" <<query.lastError();
                }

                if(query.exec("update usuarios set biometria='"+bio+"' where id="+p_bio+" or id="+users+""))
                {
                    qDebug() << "correto biometria";
                }else{
                    qDebug () << "error update biometria" << query.lastError();
                }

                if(query.exec("update usuarios set senha='"+senhacript+"' where nome='"+nome+"'"))
                {
                    qDebug() << "correto senha";
                }else{
                    qDebug () << "error update senha" << query.lastError();
                }


             }

    }

}
else
{
   qDebug ()  << "erro ao checar" << checkquery.lastError();
   qDebug () << "users -> cartao :::: " << users;
   qDebug ()<< "id -> senha  :::: " << idp;
   qDebug () << "id -> biometria :::: " << p_bio;
}


}

void inserir_sincronismo(QString& sessionCode)
{

    QSqlQuery query;

    query.exec("select id,nome from usuarios");
    while(query.next()){

        int id_bd = query.value(0).toInt();
        QString nome_bd = query.value(1).toString();
        qDebug()<<id_bd;
        qDebug()<<nome_bd;

        valid(sessionCode);

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


}



