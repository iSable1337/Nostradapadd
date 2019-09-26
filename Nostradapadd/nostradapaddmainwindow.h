#ifndef NOSTRADAPADDMAINWINDOW_H
#define NOSTRADAPADDMAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QString>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>

namespace Ui {
class NostradapaddMainWindow;
}

class NostradapaddMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NostradapaddMainWindow(QWidget *parent = 0);
    ~NostradapaddMainWindow();

private slots:
    void on_newDocument_triggered();

    void on_openDocument_triggered();

private:
    Ui::NostradapaddMainWindow *ui;
    QString fileName = "New Document";
};

#endif // NOSTRADAPADDMAINWINDOW_H
