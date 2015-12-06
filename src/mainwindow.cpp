#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMenu();
    setEditor();

    setCentralWidget(editor);
    setWindowTitle(tr("QFDS"));

    connect(editor, &QTextEdit::textChanged, this, &MainWindow::fileChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::openFile(const QString &file)
{

    QString fileName = file;

    if (fileName.isNull())
        fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "FDS Files (*.fds)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text))
            editor->setPlainText(file.readAll());
        lastFileName = fileName;
        file.close();
    }
}
void MainWindow::newFile()
{
    if (fileSaved){
        QMessageBox msgBox;
        msgBox.setText(tr("The document has been modified."));
        msgBox.setInformativeText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::Save:
            // Save was clicked
            break;
        case QMessageBox::Discard:
            // Don't Save was clicked
            editor->clear();
            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            break;
        default:
            // should never be reached
            break;
        }
    } else {
        editor->clear();
    }
}

void MainWindow::saveFile()
{
    if (lastFileName.isEmpty())
        saveFileAs();
    else
        saveFileAs(QString(lastFileName));
}

void MainWindow::saveFileAs(const QString &file)
{
    QString filename;
    if (!file.isEmpty()){
        filename = (file);
    } else {
        filename = QFileDialog::getSaveFileName(this, tr("Save File"), "", "FDS Files (*.fds)");

    }
    if (!filename.isEmpty()) {
        QFile file(filename);
        if (file.open(QFile::ReadWrite | QFile::Text)){

            file.write(editor->toPlainText().toUtf8());

        }
        file.close();
    }
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About QFDS"),
                       tr("<p>The <b>QFDS v0.0.1</b> a simple application" \
                          "that helps you to work with FDS</p>"));
}

void MainWindow::fileChanged()
{
    // editor changed
    fileSaved = false;
}

void MainWindow::setEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(11);

    editor = new QTextEdit;
    editor->setFont(font);

    hightlighter = new QFDSHighlighter(editor->document());

}

void MainWindow::setMenu()
{
    // main menu
    QMenu *fileMenu = new QMenu(tr("&File"), this);
    menuBar()->addMenu(fileMenu);
    fileMenu->addAction(tr("&New"), this, SLOT(newFile()), QKeySequence::New);
    fileMenu->addAction(tr("&Open..."), this, SLOT(openFile()), QKeySequence::Open);
    fileMenu->addAction(tr("&Save"), this, SLOT(saveFile()), QKeySequence::Save);
    fileMenu->addAction(tr("Save as"), this, SLOT(saveFileAs()), QKeySequence::SaveAs);
    fileMenu->addAction(tr("E&xit"), qApp, SLOT(quit()), QKeySequence::Quit);

    // help menu
    QMenu *helpMenu = new QMenu(tr("&Help"), this);
    menuBar()->addMenu(helpMenu);
    helpMenu->addAction(tr("&About"), this, SLOT(about()));
    helpMenu->addAction(tr("About &Qt"), qApp, SLOT(aboutQt()));
}

