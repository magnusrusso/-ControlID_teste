#include "ultimos_cadastros.h"
#include "tela_inicial.h"
#include "ui_tela_inicial.h"

#include <QSql>
#include <QSqlQuery>


void ultimos_cadastros()
{

    QSqlQuery query;
    query.prepare("select * from usuarios");

    if(query.exec()){

        tela_inicial::ui->visual_qtb->clear();
           int cont = 0;

        while(query.next()){

         tela_inicial::ui->visual_qtb->setColumnCount(2);

         tela_inicial::ui->visual_qtb->insertRow(cont);
         tela_inicial::ui->visual_qtb->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
         tela_inicial::ui->visual_qtb->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));

         QStringList topo ={"Id","Nome","Senha","N° Cartão","Biometria"};
         tela_inicial::ui->visual_qtb->setHorizontalHeaderLabels(topo);
          cont++;



     tela_inicial::ui->visual_qtb->setColumnWidth(0,20);
     tela_inicial::ui->visual_qtb->verticalHeader()->setVisible(false);

     tela_inicial::ui->visual_qtb->setSelectionBehavior(QAbstractItemView::SelectRows);

        }
    }


}
