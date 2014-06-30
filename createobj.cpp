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
    double totalColumna=_datosMet.value("NCOLS").toDouble();
    double totalFila=_datosMet.value("NROWS").toDouble();
    double distancia=_datosMet.value("CELLSIZE").toDouble();
    double x=0;
    double y=0;
    double z;
    double totalColumnaObj=totalColumna;

    //UV
    double xVt=-1;
    double yVt=1;
    double xVtCorte=0;
    double yVtCorte=0;

    //f
    double xa=1;
    double xb=xa+1;

    double ya=xa+totalColumna;
    double yb=xb+totalColumna;
    QStringList listadoZ=_datosMet.value("LISTCOORZ").toStringList();
    outficheroObj <<"mtllib plane.mtl" << endl;
    outficheroObj <<"o Plane" << endl;
    foreach(QString element, listadoZ)
    {
        z=element.toDouble();
        if(z==_datosMet.value("NODATAVALUE").toDouble())
                {
                    z=0;
                }
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
//    foreach(QString element, listadoZ)
//    {
//        outficheroObj <<"vt "<< xVt <<" "<< yVt << endl;
//        xVtCorte=xVt/totalColumna;
//        //xVtCorte=xVt/(totalColumna-1);
//        xVt=xVt-xVtCorte;

//        yVtCorte=yVt/totalFila;
//        yVt=yVt-yVtCorte;

// }
//    outficheroObj <<"usemtl Material.001"<< endl;
//    outficheroObj <<"s off"<< endl;

//    for(int i=0; i<(totalColumna-1)*(totalFila-1); i++)
//    {
//       outficheroObj <<"f "<< xa<<"/"<< xa <<" "<< xb<<"/"<< xb <<" "<< yb<<"/"<< yb <<" "<< ya<<"/"<< ya<< endl;
//        xa++;
//        xb++;
//        ya++;
//        yb++;
//       if(xa==totalColumnaObj)
//       {
//           totalColumnaObj=totalColumnaObj+totalColumnaObj;
//           xa++;
//           xb++;
//           ya++;
//           yb++;
//}
//    }
ficheroObj.close();
 qDebug()<< "obj creado";
}
