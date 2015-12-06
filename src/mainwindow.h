#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTextEdit>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>

#include "qfdshighlighter.h"
#include "qhighlightercolortheme.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    int openFile(const QString &file = QString());
    void newFile();
    void saveFile();
    void saveFileAs(const QString &file = QString());
    void about();
    void fileChanged();
private:

    void setEditor();
    void setMenu();
    QString lastFileName = "";

    Ui::MainWindow *ui;
    QTextEdit *editor;
    QFDSHighlighter *hightlighter;
    bool fileSaved = true;
};

#endif // MAINWINDOW_H
