//vElectron.cpp
//Determination of functions of vElectron class

#include "vElectron.h"

vElectron::vElectron()
{
    set_xy_temp(Coordinate[0], Coordinate[1]);
} //end of constructor

//set functions
void vElectron::set_xy_temp( double temp_x, double temp_y)
{
    x1 = temp_x;
    y1 = temp_y;
}   //end of function
