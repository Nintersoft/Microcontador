#ifndef JNLSOBRE_H
#define JNLSOBRE_H

#include "windows.h"

#include <QMainWindow>

namespace Ui {
class jnlSobre;
}

class jnlSobre : public QMainWindow
{
    Q_OBJECT

public:
    explicit jnlSobre(QWidget *parent = 0);
    ~jnlSobre();

private:
    Ui::jnlSobre *ui;

private slots:
    void troca_de_idioma();
    void define_versao();

};

#endif // JNLSOBRE_H
