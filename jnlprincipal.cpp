#include "jnlprincipal.h"
#include "ui_jnlprincipal.h"

jnlPrincipal::jnlPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jnlPrincipal)
{
    ui->setupUi(this);
    QWidget::setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    this->setGeometry(120, 120, 230, 180);
    this->move(QApplication::desktop()->availableGeometry().center() - this->rect().center());
    this->setFixedSize(this->size());
    reprodutor = new QMediaPlayer(this);

    camIdioma = QApplication::applicationDirPath();
    camIdioma.append("/idiomas/");
    config = new QSettings("Nintersoft","Microcontador");

    if (config->childGroups().contains("geral", Qt::CaseInsensitive)) lerConfig();

}

jnlPrincipal::~jnlPrincipal()
{
    delete ui;
}

void jnlPrincipal::timerEvent(QTimerEvent *){
    if (ui->tmpRes->intValue() != 1 && ui->tmpRes->intValue() != 0)
    {
        ui->tmpRes->display(ui->tmpRes->intValue() - 1);
        ui->bProg->setValue(ui->tmpRes->intValue());
    }
    else
    {
        if (ui->tmpRes->intValue() == 1)
        {
            ui->tmpRes->display(ui->tmpRes->intValue() - 1);
            ui->bProg->setValue(ui->tmpRes->intValue());
        }
        this->activateWindow();
        QMessageBox cxMens;
        if (mensagemCont == NULL) cxMens.setText(tr("O tempo limite da contagem foi atingido!"));
        else cxMens.setText(mensagemCont);
        cxMens.setIcon(QMessageBox::Information);
        if (reprodutor->isAudioAvailable())
        {
            reprodutor->play();
            cxMens.exec();
        }
        else cxMens.exec();
        ui->bProg->setMaximum(0);
        ui->bProg->setValue(0);
        contador.stop();
    }
}

void jnlPrincipal::on_btInicio_clicked()
{
    if (!contador.isActive())
    {
        ui->tmpRes->display(ui->tmpTot->value());
        ui->bProg->setMaximum(ui->tmpTot->value());
        ui->bProg->setValue(ui->tmpTot->value());
        contador.start(1000,this);
    }
}

void jnlPrincipal::on_btZerar_clicked()
{
    if (contador.isActive())
    {
        QMessageBox confirmar;
        confirmar.setText(tr("Você está certo disso?"));
        confirmar.setIcon(QMessageBox::Question);
        confirmar.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
        confirmar.setDefaultButton(QMessageBox::Cancel);
        if (confirmar.exec() == QMessageBox::Yes){
            contador.stop();
            ui->tmpRes->display(ui->tmpTot->value());
            ui->bProg->setMaximum(ui->tmpTot->value());
            ui->bProg->setValue(ui->tmpTot->value());
        }
    }
    else
    {
        reprodutor->stop();
        ui->tmpRes->display(ui->tmpTot->value());
        ui->bProg->setMaximum(ui->tmpTot->value());
        ui->bProg->setValue(ui->tmpTot->value());
    }
}

void jnlPrincipal::on_btConf_clicked()
{
    if (jnlConf != NULL) jnlConf->show();
    else{
        jnlConf = new jnlConfig(this);
        connect(jnlConf, SIGNAL(enviaTempo(int, bool, bool, bool, QString, QString, bool)), this, SLOT(recebeTempo(int, bool, bool, bool, QString, QString, bool)));
        jnlConf->setFixedSize(jnlConf->size());
        jnlConf->show();

        jnlMsg = new jnlMensagem(this);
        connect(this, SIGNAL(exporta_jnlMsg(jnlMensagem*)), jnlConf, SLOT(importa_jnlMsg(jnlMensagem*)));
        connect(jnlMsg, SIGNAL(exporta_mensagem(QString)), this, SLOT(importa_mensagem(QString)));
        emit exporta_jnlMsg(jnlMsg);
        jnlMsg->setFixedSize(jnlMsg->size());

        jnlSbr = new jnlSobre(this);
        connect(this, SIGNAL(exporta_jnlSbr(jnlSobre*)), jnlConf, SLOT(importa_jnlSbr(jnlSobre*)));
        connect(this, SIGNAL(checar_versao()), jnlSbr, SLOT(define_versao()));
        emit exporta_jnlSbr(jnlSbr);
        jnlSbr->setFixedSize(jnlSbr->size());

        if (config->childGroups().contains("geral", Qt::CaseInsensitive)){
            connect(this, SIGNAL(exporta_config(QString,bool,bool,int)), jnlConf, SLOT(importa_config(QString,bool,bool,int)));
            config->beginGroup("geral");
            emit exporta_config(config->value("midia").toString(), config->value("barra").toBool(),
                                config->value("tempo").toBool(), config->value("idioma").toInt());
            config->endGroup();
        }

        connect(this, SIGNAL(mudanca_de_idioma()), jnlConf, SLOT(troca_de_idioma()));
        connect(this, SIGNAL(mudanca_de_idioma()), jnlMsg, SLOT(troca_de_idioma()));
        connect(this, SIGNAL(mudanca_de_idioma()), jnlSbr, SLOT(troca_de_idioma()));
    }
}

void jnlPrincipal::recebeTempo(int tempo, bool barra, bool temptot, bool jan, QString md, QString nIdioma, bool salvar){

    int iIdioma;
    if (nIdioma == "pt") iIdioma = jnlConfig::PT;
    else iIdioma = jnlConfig::EN;

    if (salvar) salvarConfig(md, barra, temptot, iIdioma);

    if(contador.isActive())
    {
        QMessageBox cxMens;
        cxMens.setText(tr("O contador encontra-se ativado.\nZere-o antes de de reconfigurá-lo!"));
        cxMens.setIcon(QMessageBox::Information);
        cxMens.exec();
    }
    else {
        ui->tmpTot->display(tempo);
        ui->tmpRes->display(tempo);
        ui->bProg->setMaximum(tempo);
        ui->bProg->setValue(tempo);
    }

    if (!barra && ui->bProg->isVisible())
    {
        ui->bProg->hide();
        ui->txtProg->hide();
        ui->btConf->setGeometry(ui->btConf->geometry().x(),
                                ui->btConf->geometry().y() - ui->bProg->height() - ui->txtProg->height(),
                                ui->btConf->geometry().width(), ui->btConf->geometry().height());
        ui->btZerar->setGeometry(ui->btZerar->geometry().x(),
                                ui->btZerar->geometry().y() - ui->bProg->height() - ui->txtProg->height(),
                                ui->btZerar->geometry().width(), ui->btZerar->geometry().height());
        ui->btInicio->setGeometry(ui->btInicio->geometry().x(),
                                ui->btInicio->geometry().y() - ui->bProg->height() - ui->txtProg->height(),
                                ui->btInicio->geometry().width(), ui->btInicio->geometry().height());
        this->setFixedHeight(this->height()- ui->bProg->height() - ui->txtProg->height());
    }
    else if (barra && !ui->bProg->isVisible())
    {
        ui->bProg->show();
        ui->txtProg->show();
        ui->btConf->setGeometry(ui->btConf->geometry().x(),
                                ui->btConf->geometry().y() + ui->bProg->height() + ui->txtProg->height(),
                                ui->btConf->geometry().width(), ui->btConf->geometry().height());
        ui->btZerar->setGeometry(ui->btZerar->geometry().x(),
                                ui->btZerar->geometry().y() + ui->bProg->height() + ui->txtProg->height(),
                                ui->btZerar->geometry().width(), ui->btZerar->geometry().height());
        ui->btInicio->setGeometry(ui->btInicio->geometry().x(),
                                ui->btInicio->geometry().y() + ui->bProg->height() + ui->txtProg->height(),
                                ui->btInicio->geometry().width(), ui->btInicio->geometry().height());
        this->setFixedHeight(this->height()+ ui->bProg->height() + ui->txtProg->height());
    }
    if (!temptot && ui->tmpTot->isVisible())
    {
        ui->tmpTot->hide();
        ui->txtTot->hide();

        ui->txtProg->setGeometry(ui->txtProg->geometry().x(),
                                ui->txtProg->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->txtProg->geometry().width(), ui->txtProg->geometry().height());
        ui->bProg->setGeometry(ui->bProg->geometry().x(),
                                ui->bProg->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->bProg->geometry().width(), ui->bProg->geometry().height());

        ui->txtRes->setGeometry(ui->txtRes->geometry().x(),
                                ui->txtRes->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->txtRes->geometry().width(), ui->txtRes->geometry().height());
        ui->tmpRes->setGeometry(ui->tmpRes->geometry().x(),
                                ui->tmpRes->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->tmpRes->geometry().width(), ui->tmpRes->geometry().height());

        ui->btConf->setGeometry(ui->btConf->geometry().x(),
                                ui->btConf->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->btConf->geometry().width(), ui->btConf->geometry().height());
        ui->btZerar->setGeometry(ui->btZerar->geometry().x(),
                                ui->btZerar->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->btZerar->geometry().width(), ui->btZerar->geometry().height());
        ui->btInicio->setGeometry(ui->btInicio->geometry().x(),
                                ui->btInicio->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->btInicio->geometry().width(), ui->btInicio->geometry().height());

        this->setFixedHeight(this->height()- ui->tmpTot->height() - ui->txtTot->height());
    }
    else if (temptot && !ui->tmpTot->isVisible())
    {
        ui->tmpTot->show();
        ui->txtTot->show();

        ui->txtProg->setGeometry(ui->txtProg->geometry().x(),
                                ui->txtProg->geometry().y() + ui->tmpTot->height() + ui->txtTot->height(),
                                ui->txtProg->geometry().width(), ui->txtProg->geometry().height());
        ui->bProg->setGeometry(ui->bProg->geometry().x(),
                                ui->bProg->geometry().y() + ui->tmpTot->height() + ui->txtTot->height(),
                                ui->bProg->geometry().width(), ui->bProg->geometry().height());

        ui->txtRes->setGeometry(ui->txtRes->geometry().x(),
                                ui->txtRes->geometry().y() + ui->tmpTot->height() + ui->txtTot->height(),
                                ui->txtRes->geometry().width(), ui->txtRes->geometry().height());
        ui->tmpRes->setGeometry(ui->tmpRes->geometry().x(),
                                ui->tmpRes->geometry().y() + ui->tmpTot->height() + ui->txtTot->height(),
                                ui->tmpRes->geometry().width(), ui->tmpRes->geometry().height());

        ui->btConf->setGeometry(ui->btConf->geometry().x(),
                                ui->btConf->geometry().y() + ui->tmpTot->height() + ui->txtTot->height(),
                                ui->btConf->geometry().width(), ui->btConf->geometry().height());
        ui->btZerar->setGeometry(ui->btZerar->geometry().x(),
                                ui->btZerar->geometry().y() + ui->tmpTot->height() + ui->txtTot->height(),
                                ui->btZerar->geometry().width(), ui->btZerar->geometry().height());
        ui->btInicio->setGeometry(ui->btInicio->geometry().x(),
                                ui->btInicio->geometry().y() + ui->tmpTot->height() + ui->txtTot->height(),
                                ui->btInicio->geometry().width(), ui->btInicio->geometry().height());

        this->setFixedHeight(this->height()+ ui->tmpTot->height() + ui->txtTot->height());
    }
    if (!jan)
    {
        QMessageBox cxMens;
        cxMens.setText(tr("Infelizmente o Microcontador ainda não conta com o suporte de esconder-se da barra de tarefas..."));
        cxMens.setIcon(QMessageBox::Information);
        cxMens.exec();
    }

    reprodutor->setMedia(QUrl::fromUserInput(md));
    reprodutor->setVolume(100);

    if (nIdioma != idiomaAtual) lerIdioma(nIdioma);

}

void jnlPrincipal::importa_mensagem(QString msg)
{
    mensagemCont = msg;
}

void trocarTradutor(QTranslator &trad, const QString &localArq)
{
    QApplication::removeTranslator(&trad);
    if(trad.load(localArq)) QApplication::installTranslator(&trad);
}


void jnlPrincipal::lerIdioma(const QString &idioma)
{
    idiomaAtual = idioma;
    trocarTradutor(tradutor, QString(camIdioma + "Microcontador_%1.qm").arg(idioma));
}

void jnlPrincipal::lerConfig()
{
    config->beginGroup("geral");
    if (config->value("idioma").toInt() != jnlConfig::PT){
        lerIdioma("en");
        emit mudanca_de_idioma();
    }
    if (!config->value("barra").toBool()){
        ui->bProg->hide();
        ui->txtProg->hide();
        ui->btConf->setGeometry(ui->btConf->geometry().x(),
                                ui->btConf->geometry().y() - ui->bProg->height() - ui->txtProg->height(),
                                ui->btConf->geometry().width(), ui->btConf->geometry().height());
        ui->btZerar->setGeometry(ui->btZerar->geometry().x(),
                                ui->btZerar->geometry().y() - ui->bProg->height() - ui->txtProg->height(),
                                ui->btZerar->geometry().width(), ui->btZerar->geometry().height());
        ui->btInicio->setGeometry(ui->btInicio->geometry().x(),
                                ui->btInicio->geometry().y() - ui->bProg->height() - ui->txtProg->height(),
                                ui->btInicio->geometry().width(), ui->btInicio->geometry().height());
        this->setFixedHeight(this->height()- ui->bProg->height() - ui->txtProg->height());
    }
    if (!config->value("tempo").toBool()){
        ui->tmpTot->hide();
        ui->txtTot->hide();

        ui->txtProg->setGeometry(ui->txtProg->geometry().x(),
                                ui->txtProg->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->txtProg->geometry().width(), ui->txtProg->geometry().height());
        ui->bProg->setGeometry(ui->bProg->geometry().x(),
                                ui->bProg->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->bProg->geometry().width(), ui->bProg->geometry().height());

        ui->txtRes->setGeometry(ui->txtRes->geometry().x(),
                                ui->txtRes->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->txtRes->geometry().width(), ui->txtRes->geometry().height());
        ui->tmpRes->setGeometry(ui->tmpRes->geometry().x(),
                                ui->tmpRes->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->tmpRes->geometry().width(), ui->tmpRes->geometry().height());

        ui->btConf->setGeometry(ui->btConf->geometry().x(),
                                ui->btConf->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->btConf->geometry().width(), ui->btConf->geometry().height());
        ui->btZerar->setGeometry(ui->btZerar->geometry().x(),
                                ui->btZerar->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->btZerar->geometry().width(), ui->btZerar->geometry().height());
        ui->btInicio->setGeometry(ui->btInicio->geometry().x(),
                                ui->btInicio->geometry().y() - ui->tmpTot->height() - ui->txtTot->height(),
                                ui->btInicio->geometry().width(), ui->btInicio->geometry().height());

        this->setFixedHeight(this->height()- ui->tmpTot->height() - ui->txtTot->height());
    }
    if (config->value("midia").toString() != NULL){
        reprodutor->setMedia(QUrl::fromUserInput(config->value("midia").toString()));
        reprodutor->setVolume(100);
    }
    config->endGroup();
}

void jnlPrincipal::salvarConfig(QString locMidia, bool barra, bool tempo, int iIdioma)
{
    config->clear();
    config->beginGroup("geral");
    config->setValue("barra", barra);
    config->setValue("tempo", tempo);
    config->setValue("midia", locMidia);
    config->setValue("idioma", iIdioma);
    config->endGroup();
}

void jnlPrincipal::changeEvent(QEvent* evento)
{
    if(0 != evento) {
        switch(evento->type()) {

            case QEvent::LanguageChange:
                ui->retranslateUi(this);
                emit mudanca_de_idioma();
            break;

            case QEvent::LocaleChange:
            {
                QString local = QLocale::system().name();
                local.truncate(local.lastIndexOf('_'));
                lerIdioma(local);
            }
            break;
        }
    }
    QMainWindow::changeEvent(evento);
}
