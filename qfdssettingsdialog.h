#ifndef QFDSSETTINGSDIALOG_H
#define QFDSSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class QFdsSettingsDialog;
}

class QFdsSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QFdsSettingsDialog(QWidget *parent = 0);
    ~QFdsSettingsDialog();

private:
    Ui::QFdsSettingsDialog *ui;
};

#endif // QFDSSETTINGSDIALOG_H
