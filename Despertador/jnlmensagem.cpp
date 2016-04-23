#include "jnlmensagem.h"
#include "ui_jnlmensagem.h"

jnlMensagem::jnlMensagem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jnlMensagem)
{
    ui->setupUi(this);
}

jnlMensagem::~jnlMensagem()
{
    delete ui;
}

void jnlMensagem::on_btSalvar_clicked()
{
    QString mensagem = ui->txtMensagem->toPlainText();
    if (mensagem == "" || mensagem == tr("Digite sua mensagem aqui...")) emit exporta_mensagem(NULL);
    else emit exporta_mensagem(mensagem);
    this->hide();
}

void jnlMensagem::troca_de_idioma()
{
    ui->retranslateUi(this);
}
