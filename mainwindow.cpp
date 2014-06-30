#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//fileTxt.readFileMetTxt("E://public//TrabajosQT//repositoriosLocalesGit//catalunya_3D//COORDENADES.TXT");
//qDebug()<< datosMetTxt.value("NODATAVALUE").toString();
obj.createObj("E://public//TrabajosQT//repositoriosLocalesGit//catalunya_3D//DemToObj//COORDENADESCENTER.TXT","E://public//TrabajosQT//repositoriosLocalesGit//catalunya_3D//DemToObj//COORDENADESCENTER.obj");
}
