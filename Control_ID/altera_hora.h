#ifndef ALTERA_HORA_H
#define ALTERA_HORA_H

#include <QDialog>

namespace Ui {
class altera_hora;
}

class altera_hora : public QDialog
{
    Q_OBJECT

public:
    explicit altera_hora(QWidget *parent = nullptr);
    ~altera_hora();

    void showTime();

private slots:
    void on_altera_clicked();

private:
    Ui::altera_hora *ui;

    QString sessionCode;
};

#endif // ALTERA_HORA_H
