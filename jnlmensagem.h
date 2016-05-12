#ifndef JNLMENSAGEM_H
#define JNLMENSAGEM_H

#include <QMainWindow>
#include <QDesktopWidget>

namespace Ui {
class jnlMensagem;
}

class jnlMensagem : public QMainWindow
{
    Q_OBJECT

public:
    explicit jnlMensagem(QWidget *parent = 0);
    ~jnlMensagem();

private slots:
    void on_btSalvar_clicked();
    void troca_de_idioma();

signals:
    void exporta_mensagem(QString);

private:
    Ui::jnlMensagem *ui;
};

#endif // JNLMENSAGEM_H
