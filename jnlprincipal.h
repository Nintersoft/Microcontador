#ifndef JNLPRINCIPAL_H
#define JNLPRINCIPAL_H

#include "jnlconfig.h"
#include "jnlmensagem.h"
#include "jnlsobre.h"

#include <QMainWindow>
#include <QBasicTimer>
#include <QDesktopWidget>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QTranslator>
#include <QSettings>

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
    jnlSobre* jnlSbr = NULL;
    QString mensagemCont = NULL;
    QString idiomaAtual = "pt";
    QString camIdioma = NULL;
    QTranslator tradutor;
    QSettings* config;

protected:
    void timerEvent(QTimerEvent *evento);
    void changeEvent(QEvent* evento);
    void lerIdioma(const QString& idioma);
    void lerConfig();
    void salvarConfig(QString, bool, bool, int);

signals:
    void exporta_jnlMsg(jnlMensagem*);
    void exporta_jnlSbr(jnlSobre*);
    void exporta_config(QString, bool, bool, int);
    void mudanca_de_idioma();
    void checar_versao();

private slots:
    void on_btInicio_clicked();
    void on_btZerar_clicked();
    void on_btConf_clicked();
    void recebeTempo(int, bool, bool, bool, QString, QString, bool);
    void importa_mensagem(QString);

};

#endif // JNLPRINCIPAL_H
