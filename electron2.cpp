//electron2.cpp
//Determination of functions of ELECTRON class

#include <math.h>
#include <iostream>
#include "electron2.h"

//ELECTRON class Constructor
Electron::Electron(double e_x, double e_y, double e_z,
    double ort0, double ort1, double ort2, double ort3, double ort4, double ort5, double ort6, double ort7, double ort8,
    double e_energy)
{
        set_coordinates(e_x, e_y, e_z);
        fill_Rmatrix(ort0, ort1, ort2, ort3, ort4, ort5, ort6, ort7, ort8);
        set_energy(e_energy);
		set_temp_xy(e_x, e_y);
} //end of Constructor

//Set coordinates
void Electron::set_coordinates(double e_x, double e_y, double e_z)
{
    set_xy(e_x, e_y);
    set_z(e_z);
}   //end of function

//Initialize Rotation matrix
void Electron::fill_Rmatrix(double ort0, double ort1, double ort2, double ort3, double ort4, double ort5, double ort6, double ort7, double ort8)
{
    Ort[0] = ort0;  Ort[3] = ort3;  Ort[6] = ort6;
    Ort[1] = ort1;  Ort[4] = ort4;  Ort[7] = ort7;
    Ort[2] = ort2;  Ort[5] = ort5;  Ort[8] = ort8;
}   //end of function

//Set initial energy value
void Electron::set_energy(double e_energy)
{
    electron_energy = (e_energy > 0)?e_energy:10;
}   //end of function

//Set x- and y-coordinate values
void Electron::set_xy(double e_x, double e_y)
{
    Coordinate[0] = e_x;
    Coordinate[1] = e_y;
}   //end of function

//Set z-coordinate value
void Electron::set_z(double e_z)
{
    Coordinate[2] = (e_z >= 0)?e_z:0;
}   //end of function

void Electron::set_temp_xy(double e_x, double e_y)
{
    x1 = e_x;
    y1 = e_y;
}   //end of function

//Rotate electron coordinate system
void Electron::rotate(double phi, double sin_th, double cos_th)
{
    double	cc =	cos_th * cos(phi);
	double	sc =	sin_th * cos(phi);
	double	cs =	cos_th * sin(phi);
	double	ss =	sin_th * sin(phi);
	for (int i=0; i<3 ; i++)
	{
		double e1 = 	cc * Ort[i] 	+ cs * Ort[i+3] 	- sin_th * Ort[i+6];
		double e2 = 	-sin_th * Ort[i]+ cos(phi) * Ort[i+3];
		double e3 =  	sc * Ort[i] 	+ ss * Ort[i+3] 	+ cos_th * Ort[i+6];
        Ort[i]	    =	e1;
        Ort[i+3]	=	e2;
        Ort[i+6]	=	e3;
	}
}

//Change electron coordinates to next step position
double Electron::e_step(double lenght)
{
    double z_temp = Coordinate[2]+ Ort[8] * lenght;
    if (z_temp <= 0 && Coordinate[2] != 0)
    {
        lenght = lenght* Coordinate[2]/(Coordinate[2] - z_temp);
        Coordinate[2] = 0;
    }
    else  Coordinate[2] = z_temp;
    for (int i=0; i<2; i++)
    {
        Coordinate[i]	=+	Ort[i+6] * lenght;
    }
	return lenght;
}

//OVERRIDE input operation >>
std::istream &operator>>(std::istream &input_stream, Electron &el)
{
    for(long i = 0; i <3; i++) input_stream >> el.Coordinate[i];
    for(long i = 0; i <9; i++) input_stream >> el.Ort[i];
    input_stream >> el.electron_energy;
    return input_stream;
}   //end of function

//OVERRIDE output operation <<
std::ostream &operator<<(std::ostream &output_stream, const Electron &el)
{
    for(long i = 0; i <3; i++)
    {
        output_stream << el.Coordinate[i] << "\t";
    }
    for(long i = 0; i <9; i++)
    {
        output_stream << el.Ort[i] << "\t";
    }
    output_stream << el.electron_energy << "\t";
    return output_stream;
}   //end of function
