#ifndef JNLCONFIG_H
#define JNLCONFIG_H

#include "jnlmensagem.h"
#include "jnlsobre.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class jnlConfig;
}

class jnlConfig : public QMainWindow
{
    Q_OBJECT

public:
    explicit jnlConfig(QWidget *parent = 0);
    ~jnlConfig();

    const static int PT = 0;
    const static int EN = 1;

private slots:
    void on_btSalvar_clicked();
    void on_pushButton_clicked();
    void on_bjAjMidia_clicked();
    void on_btAbrirMidia_clicked();
    void importa_jnlMsg(jnlMensagem*);
    void importa_jnlSbr(jnlSobre*);
    void troca_de_idioma();
    void importa_config(QString, bool, bool, int);
    void on_btSobre_clicked();

signals:
    void enviaTempo(int, bool, bool, bool, QString, QString, bool);

private:
    Ui::jnlConfig *ui;
    jnlMensagem* jnlMsg = NULL;
    jnlSobre * jnlSbr = NULL;
};

#endif // JNLCONFIG_H
