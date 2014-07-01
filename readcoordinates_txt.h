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

//Getters
QList <float *> getListPunteroFloatZ_X();


signals:

public slots:
//Setters
void setListPunteroFloatZ_X(QList <float *> listFloatZ);

private:

QList <float *> _listFloatZ;
};

#endif // READCOORDINATES_TXT_H
