//betheMaterial.cpp
//Determination of functions of betheMaterial class

#include <math.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "betheMaterial.h"

double const N_Avogadro = 6.02*1e23;    //Avogadro number

//betheMaterial class Chose Constructor
betheMaterial::betheMaterial()
{
    std::cout << "Choose needed material." << std::endl;
    std::cout << "Enter corresponding number:" << std::endl;
    std::cout << "1 - Si" << "\t" << "2 - Al" << "\t" <<  "3 - C" << "\t"
    << "4 - Cu" << "\t" << "5 - Au" << "\t" << "6 - Pt" << "\t" << std::endl;
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

        case 3:
		{
			//C
			std::cout << "Material parameters for C was chosen." << std::endl;
			char C_name[] = "eMcsC.dat";
			set_material_parameters(6, 12, 79.1, 2.25, C_name);
        } break;

        case 4:
        {
            //Cu
            std::cout << "Material parameters for Cu was chosen." << std::endl;
            char Cu_name[] = "eMcsCu.dat";
            set_material_parameters(29, 63.5, 332, 8.96, Cu_name);
        } break;

        case 5:
        {
            //Au
            std::cout << "Material parameters for Au was chosen." << std::endl;
            char Au_name[] = "eMcsAu.dat";
            set_material_parameters(79, 197, 789, 19.30, Au_name);
        } break;

        case 6:
        {
            //Pt
            std::cout << "Material parameters for Pt was chosen." << std::endl;
            char Pt_name[] = "eMcsPt.dat";
            set_material_parameters(78, 195, 792, 21.45, Pt_name);
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

//function for material Bethe range calculation
double betheMaterial::betheRange(double E_i)
{
	return( 27.6*get_material_A()*pow(E_i*1e-3, 1.67)/(get_material_density()*pow(get_material_Z(), 0.89)/4) );
}

//calculate step lenght
double betheMaterial::calculate_step( double E_inst )
{
    double eMcs = receive_total_cs(E_inst);
	double mean_lenght = get_material_A() / ( N_Avogadro *get_material_density() * eMcs); //cm
    //std::srand(time(0));
    double random_value = rndMy(get_Rnd());
	set_Rnd(random_value);
    double lenght = -mean_lenght*log(random_value);
	std::cout << lenght << std::endl;
    if (lenght > 1000*mean_lenght) lenght = 1000*mean_lenght;
    return lenght;
}	//end of function

//function for electron energy loss calculation
double betheMaterial::calculate_E_loss(double E_i, double step_lenght)
{
	//E_i in keV, step_lenght in cm
	double dE = 7.85*1e4*( (get_material_Z() * get_material_density() )/( get_material_A() * E_i*1e-3 )) * log( ( 1.166* (E_i + 0.85 * get_meanIP()) ) / get_meanIP() )*step_lenght;
	std::cout << dE << std::endl;
    return dE;
}	//end of function
