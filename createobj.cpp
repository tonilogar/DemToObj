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
#include <math.h>
CreateObj::CreateObj(QObject *parent) :
    QObject(parent)
{
    column=0;
    fila=0;
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
    int verticesTotales=totalColumna*totalFila;
    float x=0;
    float y=0;
    float z;



    //f
    float xa=1;
    float xb=xa+1;
    float ya=xa+totalColumna;
    float yb=xb+totalColumna;
    outficheroObj <<"mtllib plane.mtl" << endl;
    outficheroObj <<"o Plane" << endl;
    QList <float> listaDeAlturas=_readCoordi->getListPunteroFloatZ_X();

    foreach(float element, listaDeAlturas)
    {
        z=element;
        //qDebug()<< z << "z";
        outficheroObj <<"v "<< x << " "<< z << " "<< y << endl;
        x=x+distancia;
        if(x==totalColumna*distancia)
        {
            x=0;
            y=y+distancia;
        }
    }

    //UV
    double uVx=0;
    double uVy=1;
    //qDebug() <<  uVx << "uVx";
    //qDebug() <<  uVy << "uVy";
    for (double i=totalFila ; i > 0; i--)
    {
        if(uVy<=0)
        {
         uVy=1;
        }
        uVy=uVy-fila;
        fila=1.00000/(totalFila-1);
        for (double j=0; j < totalColumna ; j++)//Mientras que f sea
        {
            if(uVx>=1)
            {
             uVx=0;
             outficheroObj << "vt "<< uVx << " " << uVy << " "<< endl; //añado al fichero obj
            }
            else
            {
            uVx=uVx+column;
            column=1.00000/(totalColumna-1);
            outficheroObj << "vt "<< uVx << " " << uVy << " "<< endl; //añado al fichero obj
            }
        }
    }

    //UV Combinar vertices y coordenadas de mapeado
    outficheroObj <<"usemtl Material.001"<< endl;
    outficheroObj <<"s off"<< endl;
    int vertice = 1;
    for (int i=totalColumna ; i < verticesTotales; i++)
    {
        for (int f=1; f<totalColumna ; f++)//Mientras que f sea
        {
            i++;
            outficheroObj << "f "<< vertice << "/" << vertice << " "; //añado al fichero obj
            vertice = vertice+1;
            outficheroObj << vertice << "/" << vertice  << " "<< (vertice+totalColumna) << "/" << (vertice+totalColumna) << " "<< (vertice+totalColumna-1)<< "/" << (vertice+totalColumna-1) <<  endl;
            //qDebug() <<  f << "f";
            //qDebug() <<  vertice << "vertice";
        }
        vertice = vertice+1; // sumo 1 para pasar al vertice de la siguiente fila
    }

    ficheroObj.close();
    qDebug()<< "obj creado";
}
