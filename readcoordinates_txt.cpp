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

#include "readcoordinates_txt.h"

ReadCoordinates_Txt::ReadCoordinates_Txt(QObject *parent) :
    QObject(parent)
{
}
QVariantMap ReadCoordinates_Txt::readFileMetTxt(QString pathFileTxtCoordenadas)
{
    QVariantMap datosMetTxt;

    //Leer fichero ascii
    QFile ficheroAsci(pathFileTxtCoordenadas);
    ficheroAsci.open(QIODevice::Text | QIODevice::ReadOnly);
    QTextStream outficheroAsci(&ficheroAsci);

    //Asignanar valor a la variable _nCols
    QString numeroColumnas = outficheroAsci.readLine().replace("NCOLS","");//Leo la primera linea
    numeroColumnas = numeroColumnas.trimmed();//Elimino espacios en blanco al principio y final de la cadena
    int _nCols=numeroColumnas.toInt();
    qDebug()<< _nCols <<"_nCols";
    datosMetTxt.insert("NCOLS",_nCols);

    //Asignanar valor a la variable _nrows
    QString numeroFilas = outficheroAsci.readLine().replace("NROWS ","");
    numeroFilas = numeroFilas.trimmed();
    int _nRows=numeroFilas.toInt();
    qDebug()<< _nRows <<"_nRows";
    datosMetTxt.insert("NROWS",_nRows);

    //Asignanar valor a la variable _nrows _xLlcenter
    QString coordenadasPixelX = outficheroAsci.readLine().replace("XLLCENTER ","");
    coordenadasPixelX = coordenadasPixelX.trimmed();
    qDebug()<< coordenadasPixelX <<"_coordenadasPixelX";
    float _xLlcenter=coordenadasPixelX.toFloat();
    qDebug()<< _xLlcenter <<"_xLlcenter";
    datosMetTxt.insert("XLLCENTER",_xLlcenter);

    //Asignanar valor a la variable _nrows _yLlcenter
    QString coordenadasPixelY = outficheroAsci.readLine().replace("YLLCENTER ","");
    coordenadasPixelY = coordenadasPixelY.trimmed();
    qDebug()<< coordenadasPixelY <<"coordenadasPixelY";
    float _yLlcenter=coordenadasPixelY.toFloat();
    qDebug()<< _yLlcenter <<"_yLlcenter";
    datosMetTxt.insert("YLLCENTER",_yLlcenter);

    //Asignanar valor a la variable _nrows _cellsize
    QString distanciaVertices = outficheroAsci.readLine().replace("CELLSIZE  ","");
    distanciaVertices = distanciaVertices.trimmed();
    float _cellSize=distanciaVertices.toFloat();
    qDebug()<< _cellSize <<"_cellSize";
    datosMetTxt.insert("CELLSIZE",_cellSize);

    //Asignanar valor a la variable _nrows _noDataValue
    QString noData = outficheroAsci.readLine().replace("NODATA_VALUE  ","");
    noData = noData.trimmed();
    noData.simplified();
    int _noDataValue=noData.toInt();
    qDebug()<< _noDataValue <<"_noDataValue";
    datosMetTxt.insert("NODATAVALUE",_noDataValue);


    _listFloatZ;
    float *_punteroZ;
    while(!outficheroAsci.atEnd())
    {
        outficheroAsci >> *_punteroZ;
        _listFloatZ << _punteroZ;

}
    ficheroAsci.close();
    return datosMetTxt;
}

QList <float *> ReadCoordinates_Txt::getListPunteroFloatZ_X()
{
return _listFloatZ;
}

void ReadCoordinates_Txt::setListPunteroFloatZ_X(QList <float *> listFloatZ)
{
 _listFloatZ=listFloatZ;
}
