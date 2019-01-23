#include "novocadastro.h"
#include "ui_novocadastro.h"
#include "cadastro_cartao.h"
#include "valid.h"
#include "insert_bd.h"
#include "cadastro_rein.h"
#include "id_aleatorio.h"

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
#include <QtSql>
#include <QFileDialog>
#include <QDesktopServices>

novocadastro::novocadastro(QWidget *parent,QString idd) :
    QDialog(parent),
    ui(new Ui::novocadastro)

{

    ui->setupUi(this);
    ui->txt_rg->setEnabled(false);
    ui->txt_cpf->setEnabled(false);
    ui->txt_cidade->setEnabled(false);
    ui->txt_pais->setEnabled(false);
    ui->txt_nascimento->setEnabled(false);
    ui->txt_telefone->setEnabled(false);
    ui->txt_email->setEnabled(false);
    ui->cb_estado->setEnabled(false);
    ui->txt_rua->setEnabled(false);
    ui->txt_bairro->setEnabled(false);
    ui->cadastrar_dados->setEnabled(false);
    ui->b_salvar_foto->setEnabled(false);
    ui->frame_foto->setEnabled(false);
    ui->cadastrar->setEnabled(false);
    ui->id->setEnabled(false);
    ui->nome->setEnabled(false);
    ui->b_foto_web->setEnabled(false);


    ui->id->setText(idd);
    qDebug() << idd;

    QString id_imagem = ui->id->text();

    QSqlQuery query;
    query.exec("select * from dados where id='"+idd+"'");
    if(query.next()){

         nome = query.value(1).toString();
         ui->nome->setText(nome);
         nasc = query.value(2).toString();
         ui->txt_nascimento->setText(nasc);
         rg = query.value(3).toString();
         ui->txt_rg->setText(rg);
         cpf = query.value(4).toString();
         ui->txt_cpf->setText(cpf);
         tel = query.value(5).toString();
         ui->txt_telefone->setText(tel);
         rua = query.value(6).toString();
         ui->txt_rua->setText(rua);
         bair = query.value(7).toString();
         ui->txt_bairro->setText(bair);
         cid = query.value(8).toString();
         ui->txt_cidade->setText(cid);
        //QString est = query.value(9).toString();
       // ui->nome->setText(nome);
        pais = query.value(10).toString();
        ui->txt_pais->setText(pais);
        email = query.value(11).toString();
        ui->txt_email->setText(email);

            if( !query.exec( "select imagedata from imagem_usuarios where id='"+id_imagem+"'" )){
                    qDebug() << "Error getting image from table:\n" << query.lastError();
            }else{
                query.first();
                QByteArray outByteArray = query.value( 0 ).toByteArray();
                QPixmap outPixmap = QPixmap();
                outPixmap.loadFromData( outByteArray );
                 ui->imagem_user->setPixmap(outPixmap);
            }
    }


}

novocadastro::~novocadastro()
{
    delete ui;
}

void novocadastro::on_cadastrar_clicked()
{


    if(verifica == 0){

        // ----------------------CARTÂOOO ---------------------------------
        //---------------------------------------------------------------
        //-----------------------------------------------------



        valid(sessionCode);


            //login e geração de nova sessão---------------------------------------


            // ------------------ CARTÃO POST ------------------------------


            if(ui->novo->currentText()=="Existente"){

                int id_cartao = ui->txtid->text().toInt();
                numerocartao = ui->txtcartao->text();
                users = ui->id->text();
                id_user = ui->id->text().toInt();
                if(users==""){
                    id_aleatorio(sessionCode,check);
                    qDebug() << check;
                    id_user = check;
                }

                // regra cartão ---------------------


                QStringRef subString(&numerocartao, 0, 3);
                QStringRef subString2(&numerocartao, 3,5);
                long long int part1 = subString.toUInt();
                long long int part2 = subString2.toUInt();
                long long int mult = part1 << 32;
                long long int resultcript = mult + part2;


                // ----------------------------------

                QUrl cadastrocartao(QString("http://192.168.0.129/create_objects.fcgi?session="+sessionCode));
                QNetworkRequest cartaoresposta(cadastrocartao);
                cartaoresposta.setHeader(QNetworkRequest::ContentTypeHeader,
                                  "application/json; charset=utf=8");
                QJsonObject cartao;
                cartao.insert("id",id_cartao);
                cartao.insert("value",resultcript);
                cartao.insert("user_id",id_user);

                QJsonArray arraycartao;
                arraycartao.push_back(cartao);

                QJsonObject cds;
                cds.insert("object","cards");
                cds.insert("values",arraycartao);

                QNetworkAccessManager cartt;
                QNetworkReply *replycartao = cartt.post(cartaoresposta, QJsonDocument(cds).toJson());

                while(!replycartao->isFinished()){

                    qApp->processEvents();
                }

                QByteArray arrayresposta = replycartao->readAll();

                QJsonDocument cartao2 = QJsonDocument::fromJson(arrayresposta);

                QMessageBox::information(this,"INFO","Cartão Cadastrado com Sucesso");


                qDebug () << cartao2;
                replycartao->deleteLater();

                insert_bd(p_bio,users,numerocartao,senhacript,idp,nome); // <<<<<<<<<<< inserir no bd


//else -----------------------------------------------------------------------------------------------------
                //------------------------------------------------------------------------


            }
            else

            {
                //------------------------------- -----------------------------




            nome = ui->nome->text();
            idp = ui->id->text();
            id = ui->id->text().toInt();
            if(idp==""){
                id_aleatorio(sessionCode,check);
                qDebug() << check;
                id = check;
            }

            QUrl urlcadastro(QString("http://192.168.0.129/create_objects.fcgi?session="+sessionCode));
            QNetworkRequest requestcadastro(urlcadastro);
            requestcadastro.setHeader(QNetworkRequest::ContentTypeHeader,
                              "application/json; charset=utf=8");

            QJsonObject cadastro;
            cadastro.insert("id", id);
            cadastro.insert("name",nome);
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

               QMessageBox::information(this,"INFO","Cadastrado com Sucesso");


               qDebug () << registro2;
               replyed->deleteLater();



               //inicio p2---

               QUrl urlgrupos(QString("http://192.168.0.129/create_objects.fcgi?session="+sessionCode));
               QNetworkRequest requestgrupo(urlgrupos);
               requestgrupo.setHeader(QNetworkRequest::ContentTypeHeader,
                                 "application/json; charset=utf=8");


               QJsonObject inserir;
               inserir.insert("user_id", id);
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


               qDebug () << mgp << "adicionado ao departamento";
               replyed->deleteLater();


              // final p2 ------------------------------------------------------------------

              ui->id->clear();
              ui->nome->clear();
              ui->senha->clear();


              int id_cartao = ui->txtid->text().toInt();
              numerocartao = ui->txtcartao->text();
               users = ui->id->text();
              id_user = ui->id->text().toInt();
              if(users==""){
                  id_aleatorio(sessionCode,check);
                  qDebug() << check;
                  id_user = check;
              }

              // regra cartão ---------------------


              QStringRef subString(&numerocartao, 0, 3);
              QStringRef subString2(&numerocartao, 3,5);
              long long int part1 = subString.toUInt();
              long long int part2 = subString2.toUInt();
              long long int mult = part1 << 32;
              long long int resultcript = mult + part2;


              // ----------------------------------

              QUrl cadastrocartao(QString("http://192.168.0.129/create_objects.fcgi?session="+sessionCode));
              QNetworkRequest cartaoresposta(cadastrocartao);
              cartaoresposta.setHeader(QNetworkRequest::ContentTypeHeader,
                                "application/json; charset=utf=8");
              QJsonObject cartao;
              cartao.insert("id",id_cartao);
              cartao.insert("value",resultcript);
              cartao.insert("user_id",id_user);

              QJsonArray arraycartao;
              arraycartao.push_back(cartao);

              QJsonObject cds;
              cds.insert("object","cards");
              cds.insert("values",arraycartao);

              QNetworkAccessManager cartt;
              QNetworkReply *replycartao = cartt.post(cartaoresposta, QJsonDocument(cds).toJson());

              while(!replycartao->isFinished()){

                  qApp->processEvents();
              }

              QByteArray arrayresposta = replycartao->readAll();

              QJsonDocument cartao2 = QJsonDocument::fromJson(arrayresposta);

              QMessageBox::information(this,"INFO","Cartão Cadastrado com Sucesso");


              qDebug () << cartao2;
              replycartao->deleteLater();

              insert_bd(p_bio,users,numerocartao,senhacript,idp,nome);

            }

}

    // SENHA ------------------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------------------------

    else if (verifica == 1){

        if(ui->novo->currentText()=="Novo"){


    //validação ---------------------------------

           valid(sessionCode);


        //login e geração de nova sessão---------------------------------------



        // HASH de senha --------------------------------------------

            nome = ui->nome->text();
            QString senha = ui->senha->text();
            if(senha == "" && nome == ""){
                QMessageBox::warning(this,"null","campo nulo.") ;
                return;
            }


            QUrl hash(QString("http://192.168.0.129/user_hash_password.fcgi?session="+sessionCode));
            QNetworkRequest requesthash(hash);
            requesthash.setHeader(QNetworkRequest::ContentTypeHeader,
                                  "application/json; charset=utf=8");

            QJsonObject password{
              {"password",senha}
            };

            QNetworkAccessManager hs;
            QNetworkReply *replyhs = hs.post(requesthash, QJsonDocument(password).toJson());
            while(!replyhs->isFinished()){

                qApp->processEvents();
            }

            QByteArray resposta = replyhs->readAll();
            QJsonDocument hs2 = QJsonDocument::fromJson(resposta);
            qDebug () << "Hash de senha feito!>";
            replyhs->deleteLater();

            if(hs2.isObject()){

                QJsonObject hass2 = hs2.object();
                auto iter2 = hass2.find("salt");
                if(iter2 != hass2.end()){
                    saltcript = iter2.value().toString();
                    qDebug () << "salt=" << saltcript;

                }
            }



            if(hs2.isObject())
            {
                QJsonObject hass = hs2.object();
                auto iter = hass.find("password");
                if(iter != hass.end())
                {
                    senhacript = iter.value().toString();
                    qDebug() << "senha cript=" << senhacript;
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


            // cadastro novo usuario --------------------------------------------
            idp = ui->id->text();
            id = ui->id->text().toInt();
            if(idp==""){
                id_aleatorio(sessionCode,check);
                qDebug() << check;
                id = check;
            }

            QUrl urlcadastro(QString("http://192.168.0.129/create_objects.fcgi?session="+sessionCode));
            QNetworkRequest requestcadastro(urlcadastro);
            requestcadastro.setHeader(QNetworkRequest::ContentTypeHeader,
                              "application/json; charset=utf=8");

            QJsonObject cadastro;
            cadastro.insert("id", id);
            cadastro.insert("name",nome);
            cadastro.insert("password",senhacript);
            cadastro.insert("salt",saltcript);
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

               QMessageBox::information(this,"INFO","Cadastrado com Sucesso");


               qDebug () << registro2;
               replyed->deleteLater();

               //inicio p2---

               QUrl urlgrupos(QString("http://192.168.0.129/create_objects.fcgi?session="+sessionCode));
               QNetworkRequest requestgrupo(urlgrupos);
               requestgrupo.setHeader(QNetworkRequest::ContentTypeHeader,
                                 "application/json; charset=utf=8");


               QJsonObject inserir;
               inserir.insert("user_id", id);
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


               qDebug () << mgp << "adicionado ao departamento";
               replyed->deleteLater();

              insert_bd(p_bio,users,numerocartao,senhacript,idp,nome);


              // final p2 ----

              ui->id->clear();
              ui->nome->clear();
              ui->senha->clear();
              return;
        }
        else{
            // >>>>>>>>>>>>>>>>>>>>>senha existente <<<<<<<<<<<<<<<<<<<
            // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>

           QString senha = ui->senha->text();
           nome = ui->nome->text();

           valid(sessionCode);

           QUrl hash(QString("http://192.168.0.129/user_hash_password.fcgi?session="+sessionCode));
           QNetworkRequest requesthash(hash);
           requesthash.setHeader(QNetworkRequest::ContentTypeHeader,
                                 "application/json; charset=utf=8");

           QJsonObject password{
             {"password",senha}
           };

           QNetworkAccessManager hs;
           QNetworkReply *replyhs = hs.post(requesthash, QJsonDocument(password).toJson());
           while(!replyhs->isFinished()){

               qApp->processEvents();
           }

           QByteArray resposta = replyhs->readAll();
           QJsonDocument hs2 = QJsonDocument::fromJson(resposta);
           qDebug () << "Hash de senha feito!>";
           replyhs->deleteLater();

           if(hs2.isObject()){

               QJsonObject hass2 = hs2.object();
               auto iter2 = hass2.find("salt");
               if(iter2 != hass2.end()){
                   saltcript = iter2.value().toString();
                   qDebug () << "salt=" << saltcript;

               }
           }



           if(hs2.isObject())
           {
               QJsonObject hass = hs2.object();
               auto iter = hass.find("password");
               if(iter != hass.end())
               {
                   senhacript = iter.value().toString();
                   qDebug() << "senha cript=" << senhacript;
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

           //valid(sessionCode);

           QUrl modificar(QString("http://192.168.0.129/modify_objects.fcgi?session="+sessionCode));
           QNetworkRequest respmodifc(modificar);
           respmodifc.setHeader(QNetworkRequest::ContentTypeHeader,
                                "application/json; charset=utf-8");

           QJsonObject obj1;
           obj1.insert("password",senhacript);
           obj1.insert("salt",saltcript);

       // where ------------
           QJsonObject objw1{{"name",nome}};

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

           insert_bd(p_bio,users,numerocartao,senhacript,idp,nome);

        }

    }
// biometria post------------------------
    // --------------------------------------

    else{

        ui->senha->setEnabled(false);


        if (ui->novo->currentText() == "Existente"){
        //validação ---------------------------------

            valid(sessionCode);


            //login e geração de nova sessão---------------------------------------


         // -----------------------------------------------------------------------------------------------------
        //--------------------------------------------------------------------------------------------------------
        //biometria

            long long int id_bio = ui->id->text().toLong();
            p_bio = ui->id->text();
            if(p_bio==""){
                id_aleatorio(sessionCode,check);
                qDebug() << check;
                id_bio = check;
            }

            QUrl biometria(QString ("http://192.168.0.129/remote_enroll.fcgi?session="+sessionCode));
            QNetworkRequest requestbio(biometria);
            requestbio.setHeader(QNetworkRequest::ContentTypeHeader,
                                 "application/json; charset=utf-8" );

            QJsonObject remote_enroll;
            remote_enroll.insert("type","biometry");
            remote_enroll.insert("user_id",id_bio);
            remote_enroll.insert("message","");
            remote_enroll.insert("save",true);




            QNetworkAccessManager bio;
            QNetworkReply *replybio = bio.post(requestbio,QJsonDocument(remote_enroll).toJson());

            while(!replybio->isFinished()){

                qApp->processEvents();
            }
            QByteArray resposta_biometria = replybio->readAll();

            QJsonDocument bio2 = QJsonDocument::fromJson(resposta_biometria);

            QMessageBox::information(this,"INFO","Cadastre sua Biometria na Leitora");

            qDebug () << bio2;
            replybio->deleteLater();

            insert_bd(p_bio,users,numerocartao,senhacript,idp,nome);


        }else   //<<<<<<< NOVO (COMBO BOX)

        {

            //validação ---------------------------------

                valid(sessionCode);


               // cadastro novo usuario --------------------------------------------
                nome = ui->nome->text();
                idp = ui->id->text();
                id = ui->id->text().toInt();
                if(idp==""){
                    id_aleatorio(sessionCode,check);
                    qDebug() << check;
                    id = check;
                }

                QUrl urlcadastro(QString("http://192.168.0.129/create_objects.fcgi?session="+sessionCode));
                QNetworkRequest requestcadastro(urlcadastro);
                requestcadastro.setHeader(QNetworkRequest::ContentTypeHeader,
                                  "application/json; charset=utf=8");

                QJsonObject cadastro;
                cadastro.insert("id", id);
                cadastro.insert("name",nome);
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

                   QMessageBox::information(this,"INFO","Cadastrado com Sucesso");


                   qDebug () << registro2;
                   replyed->deleteLater();

                   //inicio p2---

                   QUrl urlgrupos(QString("http://192.168.0.129/create_objects.fcgi?session="+sessionCode));
                   QNetworkRequest requestgrupo(urlgrupos);
                   requestgrupo.setHeader(QNetworkRequest::ContentTypeHeader,
                                     "application/json; charset=utf=8");


                   QJsonObject inserir;
                   inserir.insert("user_id", id);
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


                   qDebug () << mgp << "adicionado ao departamento";
                   replyed->deleteLater();


                  // final p2 ----

                  ui->id->clear();
                  ui->nome->clear();
                  ui->senha->clear();


                  //biometria

                      long long int id_bio = ui->id->text().toLong();
                      p_bio = ui->id->text();

                      QUrl biometria(QString ("http://192.168.0.129/remote_enroll.fcgi?session="+sessionCode));
                      QNetworkRequest requestbio(biometria);
                      requestbio.setHeader(QNetworkRequest::ContentTypeHeader,
                                           "application/json; charset=utf-8" );

                      QJsonObject remote_enroll;
                      remote_enroll.insert("type","biometry");
                      remote_enroll.insert("user_id",id_bio);
                      remote_enroll.insert("message","");
                      remote_enroll.insert("save",true);




                      QNetworkAccessManager bio;
                      QNetworkReply *replybio = bio.post(requestbio,QJsonDocument(remote_enroll).toJson());

                      while(!replybio->isFinished()){

                          qApp->processEvents();
                      }
                      QByteArray resposta_biometria = replybio->readAll();

                      QJsonDocument bio2 = QJsonDocument::fromJson(resposta_biometria);

                      QMessageBox::information(this,"INFO","Cadastre sua Biometria na Leitora");

                      qDebug () << bio2;
                      replybio->deleteLater();

                      insert_bd(p_bio,users,numerocartao,senhacript,idp,nome);





        }

    } //<<<<<<<<<< defini bio

    // ---------------------------------------------------------------------------------------------------------------------
    // ---------------------------------------------------------------------------------------------------------------------



    } //<< fecha cliked button





void novocadastro::on_escolha_activated(const QString &)
{



}

void novocadastro::on_novo_activated(const QString &)
{


    if(ui->novo->currentText() == "Existente"){

        ui->nome->setEnabled(false);
        ui->id->setEnabled(false);


    }else{

        ui->nome->setEnabled(true);
        ui->senha->setEnabled(true);
        ui->id->setEnabled(true);
    }

}

void novocadastro::on_escolha_currentTextChanged(const QString &)
{

    if(ui->escolha->currentText() == "Senha")

    {
        verifica = 1;
        ui->txtid->setEnabled(false);
        ui->txtcartao->setEnabled(false);
        ui->id->setEnabled(true);
        ui->senha->setEnabled(true);

    }

    else if (ui->escolha->currentText() == "Cartão")
    {
        verifica = 0;
        ui->txtid->setEnabled(true);
        ui->txtcartao->setEnabled(true);
        ui->id->setEnabled(true);
        ui->senha->setEnabled(false);

    }

    if(ui->escolha->currentText() == "Biometria")
    {
        verifica = 2;
        ui->txtid->setEnabled(false);
        ui->txtcartao->setEnabled(false);
        ui->id->setEnabled(true);
        ui->senha->setEnabled(false);

    }

}

void novocadastro::on_cadastrar_dados_clicked()
{
     nome = ui->nome->text();
     idd = ui->id->text();
     if(idd==""){
         id_aleatorio(sessionCode,check);
         qDebug() << check;
         idd = QString::number(check);
     }
     nasc = ui->txt_nascimento->text();
     rg = ui->txt_rg->text();
     cpf = ui ->txt_cpf->text();
     tel = ui->txt_telefone->text();
     rua = ui->txt_rua ->text();
     bair = ui->txt_bairro->text();
     cid = ui->txt_cidade->text();
     pais = ui->txt_pais->text();
     email = ui->txt_email->text();


     cadastro_rein(nasc,rg,cpf,tel,nome,rua,bair,cid,pais,email,idd);

     ui->cadastrar_dados->setEnabled(false);

     inserir_sincronismo(sessionCode);


}

void novocadastro::on_edit_cadastro_clicked()
{
    ui->txt_rg->setEnabled(true);
    ui->txt_cpf->setEnabled(true);
    ui->txt_cidade->setEnabled(true);
    ui->txt_pais->setEnabled(true);
    ui->txt_nascimento->setEnabled(true);
    ui->txt_telefone->setEnabled(true);
    ui->txt_email->setEnabled(true);
    ui->cb_estado->setEnabled(true);
    ui->txt_rua->setEnabled(true);
    ui->txt_bairro->setEnabled(true);
    ui->cadastrar_dados->setEnabled(true);
    ui->cadastrar->setEnabled(true);
    ui->id->setEnabled(true);
    ui->nome->setEnabled(true);


}

void novocadastro::on_b_edit_foto_clicked()
{


    ui->b_salvar_foto->setEnabled(true);
    QString filename = QFileDialog::getOpenFileName(this, tr("Abrir ficheiro"), "C:/", tr(""));
    QPixmap pix(filename);
    ui->imagem_user->setPixmap(pix);

    QString id_imagem = ui->id->text();

       QBuffer inBuffer( &inByteArray );
       inBuffer.open( QIODevice::WriteOnly );
       pix.save( &inBuffer, "PNG" ); // write inPixmap into inByteArray in PNG format

}

void novocadastro::on_b_salvar_foto_clicked()
{
    QString id_imagem = ui->id->text();
    QSqlQuery query;
           query.prepare( "insert into imagem_usuarios (id,filename,imagedata) VALUES ('"+id_imagem+"','perfil.png', :imageData)" );
           query.bindValue( ":imageData", inByteArray );
           if( !query.exec() ){
               qDebug() << "Error inserting image into table:\n" << query.lastError();

           }else{
               QMessageBox::information(this,"OK","Imagem foi Salva!");
           }
          ui->b_salvar_foto->setEnabled(false);

}

void novocadastro::on_b_foto_web_clicked()
{


}
