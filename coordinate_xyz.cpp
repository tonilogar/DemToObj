#include "coordinate_xyz.h"

Coordinate_XYZ::Coordinate_XYZ(QObject *parent,double *coordinate_X,
                               double *coordinate_Y, double *coordinate_Z) :
    QObject(parent)
{
}
//Getters
double Coordinate_XYZ::getCoordinate_X()
{
 return *_coordinate_X;
}

double Coordinate_XYZ::getCoordinate_Y()
{
  return *_coordinate_Y;
}
double Coordinate_XYZ::getCoordinate_Z()
{
 return *_coordinate_Z;
}



//Setters
void Coordinate_XYZ::setCoordinate_X(double *coordinate_X)
{
*_coordinate_X= *coordinate_X;
}

void Coordinate_XYZ::setCoordinate_Y(double *coordinate_Y)
{
 *_coordinate_Y= *coordinate_Y;
}

void Coordinate_XYZ::setCoordinate_Z(double *coordinate_Z)
{
 *_coordinate_Z= *coordinate_Z;
}
