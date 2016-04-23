#include "jnlsobre.h"
#include "ui_jnlsobre.h"

jnlSobre::jnlSobre(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::jnlSobre)
{
    ui->setupUi(this);
}

jnlSobre::~jnlSobre()
{
    delete ui;
}

void jnlSobre::troca_de_idioma()
{
    ui->retranslateUi(this);
}

void jnlSobre::define_versao()
{
    ui->etqVersaoProg->setText(QApplication::applicationVersion());
}
