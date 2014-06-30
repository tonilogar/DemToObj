#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "readcoordinates_txt.h"
#include "createobj.h"
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
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    ReadCoordinates_Txt fileTxt;
    CreateObj obj;
};

#endif // MAINWINDOW_H