#ifndef READCOORDINATES_TXT_H
#define READCOORDINATES_TXT_H

#include <QObject>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QStringList>

class ReadCoordinates_Txt : public QObject
{
    Q_OBJECT
public:
    explicit ReadCoordinates_Txt(QObject *parent = 0);
    QVariantMap readFileMetTxt(QString pathFileTxtCoordenadas);


signals:

public slots:


private:
//    int   _nCols;
//    int   _nRows;
//    double _xLlcenter;
//    double _yLlcenter;
//    float _cellSize;
//    int   _noDataValue;
//    QStringList _coordinateZ;

};

#endif // READCOORDINATES_TXT_H
