#include "jnlconfig.h"
#include "ui_jnlconfig.h"

jnlConfig::jnlConfig(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jnlConfig)
{
    ui->setupUi(this);
}

jnlConfig::~jnlConfig()
{
    delete ui;
}

void jnlConfig::on_btSalvar_clicked()
{
    int tempo = ui->csHora->value() * 3600 + ui->csMin->value() * 60 +ui->csSeg->value();
    emit enviaTempo(tempo);
    this->hide();
}

void jnlConfig::importa_jnlMsg(jnlMensagem* jnlMensg)
{
    jnlMsg = jnlMensg;
}

void jnlConfig::on_pushButton_clicked()
{
    jnlMsg->show();
}
