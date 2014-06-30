#ifndef COORDINATE_XYZ_H
#define COORDINATE_XYZ_H

#include <QObject>

class Coordinate_XYZ : public QObject
{
    Q_OBJECT
public:
    explicit Coordinate_XYZ(QObject *parent=0,double *coordinate_X=0,
                            double *coordinate_Y=0, double *coordinate_Z=0 );
//Getters
    double getCoordinate_X();
    double getCoordinate_Y();
    double getCoordinate_Z();
signals:

public slots:
//Setters
    void setCoordinate_X(double *coordinate_X);
    void setCoordinate_Y(double *coordinate_Y);
    void setCoordinate_Z(double *coordinate_Z);


private:
    double *_coordinate_X;
    double *_coordinate_Y;
    double *_coordinate_Z;


};

#endif // COORDINATE_XYZ_H
