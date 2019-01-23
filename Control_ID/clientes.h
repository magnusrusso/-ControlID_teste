#ifndef CLIENTES_H
#define CLIENTES_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class clientes;
}

class clientes : public QDialog
{
    Q_OBJECT

public:
    explicit clientes(QWidget *parent = nullptr);
    ~clientes();
    QString id_excluir;
    QString nome = "";
    QString cartao = "";
    QString sessionCode;
    QString idd ;

public slots:

void on_local_cellDoubleClicked();


private slots:
    void on_excluir_clicked();

    void on_editar_clicked();

private:
    Ui::clientes *ui;
};

#endif // CLIENTES_H
