#ifndef INSERT_BD_H
#define INSERT_BD_H

#include "novocadastro.h"

#include <QObject>
#include <QtSql>

void insert_bd(QString& p_bio,QString& users,QString& numerocartao,QString& senhacript,QString& idp,QString& nome);

void inserir_sincronismo(QString& sessionCode);

#endif // INSERT_BD_H
