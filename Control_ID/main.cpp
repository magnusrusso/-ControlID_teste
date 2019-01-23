#include "tela_inicial.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    tela_inicial w;
    w.show();

    return a.exec();
}
