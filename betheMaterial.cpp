//betheMaterial.cpp
//Determination of functions of betheMaterial class

#include <math.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "betheMaterial.h"

double const N_Avogadro = 6.02*1e23;    //Avogadro number

//betheMaterial class Chose Constructor
betheMaterial::betheMaterial()
{
    std::cout << "Choose needed material." << std::endl;
    std::cout << "Enter corresponding number:" << std::endl;
    std::cout << "1 - Si" << "\t" << "2 - Al" << "\t" <<  std::endl;
    int choise;
    std::cin >> choise;
    double mZ, mA, mJ, mRh;
    switch (choise) {
        case 1:
		{
			//Si
			std::cout << "Material parameters for Si was chosen." << std::endl;
			char Si_name[] = "eMcsSi.dat";
			set_material_parameters(14, 28, 178, 2.33, Si_name);
		} break;

        case 2:
		{
			//Al
			std::cout << "Material parameters for Al was chosen." << std::endl;
			char Al_name[] = "eMcsAl.dat";
			set_material_parameters(13, 27, 170, 2.70, Al_name);
        } break;

		default:
        {
		    std::cout << "Error: wrong number. Default material parameters for Si was chosen." << std::endl;
      		char Si_name[] = "eMcsSi.dat";
			set_material_parameters(14, 28, 178, 2.33, Si_name);
		} break;
    }   //end of switch
}
/*
//betheMaterial class Common Constructor
betheMaterial::betheMaterial(double mZ, double mA, double mJ, double mRh)
{
    set_material_Z(mZ);
    set_material_A(mA);
    set_meanIP(mJ);
    set_material_density(mRh);
}   //end of Constructor
*/

//set atomic number
void betheMaterial::set_material_Z(double mZ)
{
    if( (mZ > 0)&&(mZ<140) ) material_Z = mZ;
	else material_Z = 14;
}   //end of function

//set atomic weight
void betheMaterial::set_material_A(double mA)
{
    if (mA > 0) material_A = mA;
	else material_A = 28;
}   //end of function

//set mean ionization potential of material
void betheMaterial::set_meanIP(double mJ)
{
	if (mJ > 0) meanIP = mJ;
	else meanIP = 178;
}   //end of function

//set density of material
void betheMaterial::set_material_density(double mRh)
{
	if (mRh > 0) material_density = mRh;
	else material_density = 2.33;
}   //end of function

//set parameters of material
void betheMaterial::set_material_parameters(double mZ, double mA, double mJ, double mRh, char* ptrLine)
{
    set_material_Z(mZ);
    set_material_A(mA);
    set_meanIP(mJ);
    set_material_density(mRh);
	load_Data(ptrLine);
}

//calculate step lenght
double betheMaterial::calculate_step( double E_inst )
{
    double eMcs = receive_total_cs(E_inst);
	double mean_lenght = get_material_A() / ( N_Avogadro *get_material_density() * eMcs);
    double lenght = -mean_lenght*log(rndMy());
    if (lenght > 1000*mean_lenght) lenght = 1000*mean_lenght;
    return lenght;
}	//end of function

//function for electron energy loss calculation
double betheMaterial::calculate_E_loss(double E_i, double step_lenght)
{
	return 7.85*1e4*( (get_material_Z() * get_material_density() )/( get_material_A() * E_i/1000 )) * log( ( 1.166* (E_i + 0.85 * get_meanIP()) ) / get_meanIP() )*step_lenght;
}	//end of function
