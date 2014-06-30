
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
