#ifndef CADASTRO_CARTAO_H
#define CADASTRO_CARTAO_H

#include <QDialog>

namespace Ui {
class cadastro_cartao;
}

class cadastro_cartao : public QDialog
{
    Q_OBJECT

public:
    explicit cadastro_cartao(QWidget *parent = nullptr);
    ~cadastro_cartao();

private:
    Ui::cadastro_cartao *ui;
};

#endif // CADASTRO_CARTAO_H
