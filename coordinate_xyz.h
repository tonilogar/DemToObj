#ifndef COORDINATE_XYZ_H
#define COORDINATE_XYZ_H

#include <QObject>

class Coordinate_XYZ : public QObject
{
    Q_OBJECT
public:
    explicit Coordinate_XYZ(QObject *parent=0,float *coordinate_X=0,
                            float *coordinate_Y=0, float *coordinate_Z=0 );
//Getters
    float getCoordinate_X();
    float getCoordinate_Y();
    float getCoordinate_Z();
signals:

public slots:
//Setters
    void setCoordinate_X(float *coordinate_X);
    void setCoordinate_Y(float *coordinate_Y);
    void setCoordinate_Z(float *coordinate_Z);


private:
    float *_coordinate_X;
    float *_coordinate_Y;
    float *_coordinate_Z;


};

#endif // COORDINATE_XYZ_H
