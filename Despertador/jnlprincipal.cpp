#include "jnlprincipal.h"
#include "ui_jnlprincipal.h"

jnlPrincipal::jnlPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jnlPrincipal)
{
    ui->setupUi(this);
    QWidget::setWindowFlags(Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    this->setGeometry(120, 120, 230, 190);
    this->move(QApplication::desktop()->availableGeometry().center() - this->rect().center());
    this->setFixedSize(this->size());
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
        if (mensagemCont == NULL) cxMens.setText("O tempo limite da contagem foi atingido!");
        else cxMens.setText(mensagemCont);
        cxMens.setIcon(QMessageBox::Information);
        cxMens.exec();
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
        confirmar.setText("Você está certo disso?");
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
}

void jnlPrincipal::on_btConf_clicked()
{
    if (jnlConf != NULL) jnlConf->show();
    else{
        jnlConf = new jnlConfig(this);
        connect(jnlConf, SIGNAL(enviaTempo(int)), this, SLOT(recebeTempo(int)));
        jnlConf->setFixedSize(jnlConf->size());
        jnlConf->show();

        jnlMsg = new jnlMensagem(this);
        connect(this, SIGNAL(exporta_jnlMsg(jnlMensagem*)), jnlConf, SLOT(importa_jnlMsg(jnlMensagem*)));
        emit exporta_jnlMsg(jnlMsg);
        jnlMsg->setFixedSize(jnlMsg->size());

        connect(jnlMsg, SIGNAL(exporta_mensagem(QString)), this, SLOT(importa_mensagem(QString)));
    }
}

void jnlPrincipal::recebeTempo(int tempo){
    if(contador.isActive())
    {
        QMessageBox cxMens;
        cxMens.setText("O contador encontra-se ativado.\nZere-o antes de de reconfigurá-lo!");
        cxMens.setIcon(QMessageBox::Information);
        cxMens.exec();
    }
    else {
        ui->tmpTot->display(tempo);
        ui->tmpRes->display(tempo);
        ui->bProg->setMaximum(tempo);
        ui->bProg->setValue(tempo);
    }
}

void jnlPrincipal::importa_mensagem(QString msg)
{
    mensagemCont = msg;
}
