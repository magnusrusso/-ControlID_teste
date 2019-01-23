#ifndef EXCLUIR_H
#define EXCLUIR_H

#include "novocadastro.h"

#include <QObject>
#include <QtSql>

class excluir
{
public:
    explicit excluir(QString& id_excluir);
    QString sessionCode;
};

#endif // EXCLUIR_H
