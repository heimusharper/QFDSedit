#include "qfdssettingsdialog.h"
#include "ui_qfdssettingsdialog.h"

QFdsSettingsDialog::QFdsSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QFdsSettingsDialog)
{
    ui->setupUi(this);
}

QFdsSettingsDialog::~QFdsSettingsDialog()
{
    delete ui;
}
