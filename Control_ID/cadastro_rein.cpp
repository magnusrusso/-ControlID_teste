#include "cadastro_rein.h"
#include "novocadastro.h"

#include <QtSql>

void cadastro_rein(QString& nasc,QString& rg,QString& cpf,QString& tel,QString& nome,QString& rua,QString& bair,QString& cid,QString& pais,QString& email,QString& idd)
{
    qDebug()<<"rodando";
    QSqlQuery query;
    if(query.exec("select count(id) from dados where id='"+idd+"'")){
        if(query.next()){
            int count = query.value(0).toInt();
                    qDebug() << "verificado :" << count;
            if(count != 1){
                query.prepare("insert into dados(id,nome,nascimento,rg,cpf,telefone,rua,bairro,cidade,estado,pais,email) values"
                "('"+idd+"','"+nome+"','"+nasc+"','"+rg+"','"+cpf+"','"+tel+"','"+rua+"','"+bair+"','"+cid+"','','"+pais+"','"+email+"')");
                query.exec();
                      qDebug()<<"inseriu com sucesso"<< nome;
                query.exec("insert into usuarios(id,nome) values('"+idd+"','"+nome+"')");

            }else{

                query.exec("update dados set nome='"+nome+"' where id='"+idd+"'");
                query.exec("update dados set nascimento='"+nasc+"' where id='"+idd+"'");
                query.exec("update dados set rg='"+rg+"' where id='"+idd+"'");
                query.exec("update dados set cpf='"+cpf+"' where id='"+idd+"'");
                query.exec("update dados set telefone='"+tel+"' where id='"+idd+"'");
                query.exec("update dados set rua='"+rua+"' where id='"+idd+"'");
                query.exec("update dados set bairro='"+bair+"' where id='"+idd+"'");
                query.exec("update dados set cidade='"+cid+"' where id='"+idd+"'");
                query.exec("update dados set pais='"+pais+"' where id='"+idd+"'");
                query.exec("update dados set email='"+email+"' where id='"+idd+"'");
            }
        }else{
             qDebug() << " erro no next" << query.lastError();
            }
    }else{
        qDebug() << "erro ao verificar" << query.lastError();
    }

}
