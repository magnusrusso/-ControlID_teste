#include "clientes.h"
#include "ui_clientes.h"
#include "insert_bd.h"
#include "excluir.h"
#include "modific.h"
#include "novocadastro.h"
#include "tela_inicial.h"

#include <QtSql>
#include <QMessageBox>


clientes::clientes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientes)
{
    ui->setupUi(this);



    QSqlQuery query;
    query.prepare("select * from usuarios");

    if(query.exec()){

           ui->local->clear();

        int cont = 0;


        while(query.next()){


            ui->local->setColumnCount(5);
            ui->local->insertRow(cont);
            ui->local->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
            ui->local->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
            ui->local->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
            ui->local->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
            ui->local->setItem(cont,4,new QTableWidgetItem(query.value(4).toString()));
            ui->local->item(cont,2)->setTextAlignment(Qt::AlignCenter);
            ui->local->item(cont,3)->setTextAlignment(Qt::AlignCenter);
            ui->local->item(cont,4)->setTextAlignment(Qt::AlignCenter);

            ui->local->setRowHeight(cont,30);
            ui->local->setColumnWidth(0,55);
            ui->local->setColumnWidth(1,200);
            ui->local->setColumnWidth(2,301);
            ui->local->setColumnWidth(3,150);
            ui->local->setColumnWidth(4,110);


            QStringList topo ={"  Id  ","Nome","Senha","N° Cartão","Biometria"};
            ui->local->setHorizontalHeaderLabels(topo);
             cont++;
    }

        ui->local->verticalHeader()->setVisible(false);

        ui->local->setSelectionBehavior(QAbstractItemView::SelectRows);

    }
    else{
        qDebug ()<< "Erro na seleção" << query.lastError().text();
    }

    //teste novo---------------------

    QSqlQuery query2;
    query2.prepare("select count(id) from usuarios");
    if(query2.exec()){
        qDebug() <<"consulta feita" ;
    }else{
        qDebug()<<query2.lastError() << "error consultar";
    }
    if(query2.next()){
        int count = query2.value(0).toInt();
        qDebug() <<"sucesso ...1/3" << count;
        int p = 0;
        while(p != count){
            p++;
            if(query2.exec("select id from usuarios where senha is null")){
                    if(query2.next()){
                        QString b = query2.value(0).toString();
                         qDebug() << "sucesso 2/2";
                        qDebug() <<b;
                        query2.exec("update usuarios set senha='X' where id="+b+"");

                        qDebug()<<"sucesso 3/3";

                    }

            }else {
                  qDebug() <<"erro 2/3" << query2.lastError();
             }

            if(query2.exec("select id from usuarios where wcartao is null")){
                qDebug() << "sucesso 2/2";
                    if(query2.next()){
                        QString b = query2.value(0).toString();
                        qDebug() <<b;
                        query2.exec("update usuarios set wcartao='X' where id="+b+"");

                        qDebug()<<"sucesso 3/3";
                    }
            }else {
                  qDebug() <<"erro 2/3" << query2.lastError();
             }

            if(query2.exec("select id from usuarios where biometria is null")){
                    if(query2.next()){
                        QString b = query2.value(0).toString();
                         qDebug() << "sucesso 2/2";
                        qDebug() <<b;
                        query2.exec("update usuarios set biometria='SEM BIO' where id="+b+"");

                        qDebug()<<"sucesso 3/3";

                    }

            }else {
                  qDebug() <<"erro 2/3" << query2.lastError();
             }

        }
    }else{
        qDebug() << query2.lastError()<< "erro 1/3";

    }


 // fim teste -------------------------------------------
    //--------------------------------

}

clientes::~clientes()
{
    delete ui;
}

void clientes::on_excluir_clicked()
{
    //delete linha
   int id = 0;
   int linha = ui->local->currentRow();
   id_excluir = ui->local->item(linha,0)->text();
   id = ui->local->item(linha,0)->text().toInt();


   QSqlQuery query;
   if(id != 0){
   query.exec("delete from usuarios where id="+QString::number(id));
   query.exec("delete from dados where id="+QString::number(id));
   query.exec("delete from imagem_usuarios where id="+QString::number(id));

       QMessageBox::information(this,"info","Deletado com sucesso!");
       excluir emp = *new excluir(id_excluir);

       qDebug () << "valor ::  "<<id_excluir;
       this->close();
       clientes clientes;
       clientes.exec();

   }else{

       qDebug () << "Error" << query.lastError().text();
   }

   }

   void clientes::on_local_cellDoubleClicked()
{

}

void clientes::on_editar_clicked()
{

    int linha = ui->local->currentRow();
    idd = ui->local->item(linha,0)->text();
    novocadastro novocadastro(this,idd);
    novocadastro.exec();


}
