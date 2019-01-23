#include "cadastro_cartao.h"
#include "ui_cadastro_cartao.h"

cadastro_cartao::cadastro_cartao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastro_cartao)
{
    ui->setupUi(this);

    // --  Style ---- background and button ----

    QPixmap fundo("C:\\Users\\Usuario\\Documents\\Control_ID\\backgrond.jpg");
        fundo = fundo.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, fundo);
        this->setPalette(palette);

        ui->cadastrocartao->setStyleSheet("background-color: rgb(30, 144, 255);"
                                  "padding: 2 px;border-style : outside;border-width: 1px;"
                                  "border-radius: 0px;min-width: 2em;"
                                  "color: rgb(255, 255, 255);""font: bold;""font-size: 10px ;");
}

cadastro_cartao::~cadastro_cartao()
{
    delete ui;
}
