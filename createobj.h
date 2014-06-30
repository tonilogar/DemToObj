#ifndef CREATEOBJ_H
#define CREATEOBJ_H

#include <QObject>
#include <QVariantMap>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include "readcoordinates_txt.h"

class CreateObj : public QObject
{
    Q_OBJECT
public:
    explicit CreateObj(QObject *parent = 0);
    void createObj(QString pathFileTxtCoordenadas,QString pathFileObj);
signals:

public slots:

};

#endif // CREATEOBJ_H
