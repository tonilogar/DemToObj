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

#include "createobj.h"
#include <QStringList>
#include <QStringList>
#include <QList>
CreateObj::CreateObj(QObject *parent) :
    QObject(parent)
{
}
void CreateObj::createObj(QString pathFileTxtCoordenadas,QString pathFileObj)
{
    //Crear fichero obj
    QFile ficheroObj(pathFileObj);
    ficheroObj.open(QIODevice::Text | QIODevice::ReadWrite| QIODevice::Append);
    QTextStream outficheroObj(&ficheroObj);


    ReadCoordinates_Txt *_readCoordi=new ReadCoordinates_Txt(this);
    QVariantMap _datosMet=_readCoordi->readFileMetTxt(pathFileTxtCoordenadas);
    qDebug()<< _datosMet << "_datosMet";
    int totalColumna=_datosMet.value("NCOLS").toInt();
    int totalFila=_datosMet.value("NROWS").toInt();
    float distancia=_datosMet.value("CELLSIZE").toFloat();
    int nData=_datosMet.value("NODATAVALUE").toInt();
    float x=0;
    float y=0;
    float z;
    float totalColumnaObj=totalColumna;

    //UV
    float xVt=-1;
    float yVt=1;
    float xVtCorte=0;
    float yVtCorte=0;

    //f
    float xa=1;
    float xb=xa+1;

    float ya=xa+totalColumna;
    float yb=xb+totalColumna;

    outficheroObj <<"mtllib plane.mtl" << endl;
    outficheroObj <<"o Plane" << endl;

    QList <float *> listaDeAlturas= _readCoordi->getListPunteroFloatZ_X();

    foreach(float *element, listaDeAlturas)
    {
        z=*element;
        qDebug()<< *element << "*element";
//        if(z==nData)
//                {
//                    z=0;
//                }
        qDebug()<< z << "*element";
        outficheroObj <<"v "<< x << " "<< z << " "<< y << endl;
        qDebug()<< x << "x";
        qDebug()<< distancia << "distancia";
        x=x+distancia;
        qDebug()<< x << "x+distancia";
        if(x==totalColumna*distancia)
        {
            x=0;
            y++;
        }
 }
    foreach(float *element, listaDeAlturas)
    {
        outficheroObj <<"vt "<< xVt <<" "<< yVt << endl;
        xVtCorte=xVt/totalColumna;
        //xVtCorte=xVt/(totalColumna-1);
        xVt=xVt-xVtCorte;

        yVtCorte=yVt/totalFila;
        yVt=yVt-yVtCorte;

 }
    outficheroObj <<"usemtl Material.001"<< endl;
    outficheroObj <<"s off"<< endl;

    for(int i=0; i<(totalColumna-1)*(totalFila-1); i++)
    {
       outficheroObj <<"f "<< xa<<"/"<< xa <<" "<< xb<<"/"<< xb <<" "<< yb<<"/"<< yb <<" "<< ya<<"/"<< ya<< endl;
        xa++;
        xb++;
        ya++;
        yb++;
       if(xa==totalColumnaObj)
       {
           totalColumnaObj=totalColumnaObj+totalColumnaObj;
           xa++;
           xb++;
           ya++;
           yb++;
}
    }
ficheroObj.close();
 qDebug()<< "obj creado";
}
