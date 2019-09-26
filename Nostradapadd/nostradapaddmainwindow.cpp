#include "nostradapaddmainwindow.h"
#include "ui_nostradapaddmainwindow.h"

NostradapaddMainWindow::NostradapaddMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NostradapaddMainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->txtEditor);
    setWindowTitle(fileName);
}

NostradapaddMainWindow::~NostradapaddMainWindow()
{
    delete ui;
}

void NostradapaddMainWindow::on_newDocument_triggered()
{
    fileName = "New Document";
    setWindowTitle(fileName);
    ui->txtEditor->setText(QString());
}

void NostradapaddMainWindow::on_openDocument_triggered()
{
    fileName = QFileDialog::getOpenFileName(this, "choose a file");
    QFile file(fileName);
    if (!file.open(QFile::ReadWrite | QFile::Text)) {
        QMessageBox::critical(this, "error", "an error occured while trying to open the chosen file" + file.errorString());
    } else {
        QTextStream in(&file);
        QString text = in.readAll();
        ui->txtEditor->setText(text);
        QFileInfo fi(fileName);
        QString filename = fi.baseName();
        setWindowTitle(filename);
        file.close();
    }
}
