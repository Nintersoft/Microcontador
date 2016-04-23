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
    bool jan = false, barra = false, temptot = false, salvar = false;
    if (ui->cmBarra->isChecked()) barra = true;
    if (ui->cmTmpTot->isChecked()) temptot = true;
    if (ui->cmJanela->isChecked()) jan = true;
    QString midia = ui->edtMidia->text();
    QString idiomaSelec;
    if (ui->csIdiomaPt->isChecked()) idiomaSelec = "pt";
    else idiomaSelec = "en";
    if (ui->csSalvarPermanente->isChecked()) salvar = true;
    emit enviaTempo(tempo, barra, temptot, jan, midia, idiomaSelec, salvar);
    this->hide();
}

void jnlConfig::importa_jnlMsg(jnlMensagem* jnlMensg)
{
    jnlMsg = jnlMensg;
}

void jnlConfig::importa_jnlSbr(jnlSobre* jnlSobreNos)
{
    jnlSbr = jnlSobreNos;
}

void jnlConfig::on_pushButton_clicked()
{
    jnlMsg->show();
}

void jnlConfig::on_bjAjMidia_clicked()
{
    QMessageBox cxMens;
    cxMens.setText(tr("Selecione a mídia que deseja ser executada ao final da contagem.\nCaso não seja selecionada mídia alguma, apenas um toque de mensagem será reproduzido"));
    cxMens.setIcon(QMessageBox::Information);
    cxMens.exec();
}

void jnlConfig::on_btAbrirMidia_clicked()
{
    QString arquivo = QFileDialog::getOpenFileName(this, tr("Abrir mídia | Microcontador"), QDir::homePath(), tr("Arquivos de áudio (*.mp3 *.wac *.wma)"));
    ui->edtMidia->setText(arquivo);
}

void jnlConfig::troca_de_idioma()
{
    ui->retranslateUi(this);
}

void jnlConfig::on_btSobre_clicked()
{
    jnlSbr->show();
}

void jnlConfig::importa_config(QString cam, bool barra, bool tot, int cIdioma)
{
    ui->edtMidia->setText(cam);
    ui->cmBarra->setChecked(barra);
    ui->cmTmpTot->setChecked(tot);
    if (cIdioma == jnlConfig::PT) ui->csIdiomaPt->setChecked(true);
    else ui->csIdiomaEn->setChecked(true);
    ui->csSalvarPermanente->setChecked(true);
}
