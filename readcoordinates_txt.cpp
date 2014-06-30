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
    double _xLlcenter=coordenadasPixelX.toDouble();
    qDebug()<< _xLlcenter <<"_xLlcenter";
    datosMetTxt.insert("XLLCENTER",_xLlcenter);

    //Asignanar valor a la variable _nrows _yLlcenter
    QString coordenadasPixelY = outficheroAsci.readLine().replace("YLLCENTER ","");
    coordenadasPixelY = coordenadasPixelY.trimmed();
    qDebug()<< coordenadasPixelY <<"coordenadasPixelY";
    double _yLlcenter=coordenadasPixelY.toDouble();
    qDebug()<< _yLlcenter <<"_yLlcenter";
    datosMetTxt.insert("YLLCENTER",_yLlcenter);

    //Asignanar valor a la variable _nrows _cellsize
    QString distanciaVertices = outficheroAsci.readLine().replace("CELLSIZE  ","");
    distanciaVertices = distanciaVertices.trimmed();
    double _cellSize=distanciaVertices.toFloat();
    qDebug()<< _cellSize <<"_cellSize";
    datosMetTxt.insert("CELLSIZE",_cellSize);

    //Asignanar valor a la variable _nrows _noDataValue
    QString noData = outficheroAsci.readLine().replace("NODATA_VALUE  ","");
    noData = noData.trimmed();
    noData.simplified();
    int _noDataValue=noData.toInt();
    qDebug()<< _noDataValue <<"_noDataValue";
    datosMetTxt.insert("NODATAVALUE",_noDataValue);

    QStringList lineList;

    while(!outficheroAsci.atEnd())
    {
        QString line=outficheroAsci.readAll();
        qDebug()<< line <<"linereadAll";
        line=line.replace("	"," ");//Cambio los tabuladores por espacios
        qDebug()<< line <<"linereplace";
        line=line.simplified();//Eliminar espacios en blanco del principio y del final cambio los elementos considerados como espacios por espacios
        qDebug()<< line <<"line.simplified()";
        line=line.replace(",",".");//Cambio la comas por puntos
        qDebug()<< line <<"line.replace";
        lineList = line.split(" ");
        qDebug()<< lineList <<"line.split";
        lineList.removeAll(NULL);
        qDebug()<< lineList.count() <<"lineList.count()" << endl;
        foreach (QString element, lineList)
        {
            qDebug()<< element <<"line" << endl;
            if(element==noData)
            {
                qDebug()<< noData <<"noData";
                element="0";
                qDebug()<< element <<"line000" << endl;
            }
        }
        qDebug()<< lineList.count() <<"lineList.count()" << endl;
    }
    ficheroAsci.close();
    datosMetTxt.insert("LISTCOORZ",lineList);
    return datosMetTxt;
}

