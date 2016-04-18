#ifndef JNLCONFIG_H
#define JNLCONFIG_H

#include "jnlmensagem.h"

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

private slots:
    void on_btSalvar_clicked();
    void importa_jnlMsg(jnlMensagem*);
    void on_pushButton_clicked();

    void on_bjAjMidia_clicked();

    void on_btAbrirMidia_clicked();

signals:
    void enviaTempo(int, bool, bool, bool, QString);

private:
    Ui::jnlConfig *ui;
    jnlMensagem* jnlMsg = NULL;
};

#endif // JNLCONFIG_H
