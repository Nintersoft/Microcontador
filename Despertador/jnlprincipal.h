#ifndef JNLPRINCIPAL_H
#define JNLPRINCIPAL_H

#include "jnlconfig.h"
#include "jnlmensagem.h"

#include <QMainWindow>
#include <QBasicTimer>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QMediaPlayer>

namespace Ui {
class jnlPrincipal;
}

class jnlPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit jnlPrincipal(QWidget *parent = 0);
    ~jnlPrincipal();

private:
    Ui::jnlPrincipal *ui;
    QBasicTimer contador;
    QMediaPlayer* reprodutor;
    jnlConfig* jnlConf = NULL;
    jnlMensagem* jnlMsg = NULL;
    QString mensagemCont = NULL;

protected:
    void timerEvent(QTimerEvent *event);

signals:
    void exporta_jnlMsg(jnlMensagem*);

private slots:
    void on_btInicio_clicked();
    void on_btZerar_clicked();
    void on_btConf_clicked();
    void recebeTempo(int, bool, bool, bool, QString);
    void importa_mensagem(QString);
};

#endif // JNLPRINCIPAL_H
