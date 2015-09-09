//Material.h
//Determination of new class Material

#ifndef MATERIAL_H
#define MATERIAL_H

#include <random>
#include <ctime>
#include <iostream>

#include <windows.h>
#include <Wincrypt.h>
inline double rndMy( double R)
{
	int T = static_cast<unsigned int>(time(NULL)*R);
	std::mt19937_64 gen( T );
	double r = (1 - std::generate_canonical<double, 10>(gen) );
	return r;
}

class Material{
    public:
        /*Constructor */
        Material(
        );  //end of constructor
        /*Function for instant theta angle value determination */
        double receive_theta(double E_i);
        double receive_phi();
		double receive_total_cs(double E_i);
//get and set functions
		double get_Rnd()const {return R;}
		void set_Rnd(double);
    protected:
		//Function which read Mott cross section values from file to array
        void load_Data(char* );
	private:
        double Array[35][50];   //array for elastic Mott cross section values

        /*Function for recalculation differential cross section values to probability density values */
        void fill_probability();

        /*Function for determination of instant theta angle location in table */
        int column_search (double rnd);

        /*Function for determination of instant energy value location in table */
        int row_search (double E_i);

		//Global random number storage variable
		double R;
}; //end of class

#endif
