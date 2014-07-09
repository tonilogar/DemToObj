//    ToolsPcot
//    Copyright (C) {2014}  {Antonio López García}
//    tologar@gmail.com

//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
    ReadCoordinates_Txt fileTxt;
    CreateObj obj;
//fileTxt.readFileMetTxt("E://public//TrabajosQT//repositoriosLocalesGit//catalunya_3D//COORDENADESDemToObjCompara.TXT");
//qDebug()<< datosMetTxt.value("NODATAVALUE").toString();
obj.createObj("D://antonio//trabajos//programacion//folferOut//demToObj//COORDENADESTALLPETIT_10x5.TXT","D://antonio//trabajos//programacion//folferOut//demToObj//COORDENADESTALLPETIT_10x501.obj");
}
