//vElectron.cpp
//Determination of functions of vElectron class

#include "vElectron.h"

vElectron::vElectron()
{
    set_xz_temp(Coordinate[0], Coordinate[2]);
} //end of constructor

//set functions
void vElectron::set_xz_temp( double temp_x, double temp_z)
{
    x1 = temp_x;
    z1 = temp_z;
}   //end of function
