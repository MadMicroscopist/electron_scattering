//FTI_Mott_io.cpp
//Determination of function for FTI data files reading (code)

#include <math.h>
#include <iostream>
#include <fstream>
#include "material.h"

//Material class constructor
Material::Material()
{
    std::cout << "Material object is created." << std::endl;
	R = 0.5;
}   //end of constructor

/*Function for filling an array for differential Mott elastic cross section values
Array size A[35][50]
A[*][0] - theta angle axis from 0 to 180
A[0][*] - energy axis from 30keV to 50eV
A[35][*] - Mott total cross section values
A[1][1]-A[34][49] - differential Mott cross section values*/
void Material::load_Data(char* ptrLine)
{
    std::ifstream file_in;
    file_in.open(ptrLine);
    for (int j=0; j < 50; j++)
    {
        for (int i = 0; i < 35; i++)
        {
            file_in >> Array[i][j];
        }
    }
    file_in.close();
	fill_probability();

	std::ofstream file_out;
	file_out.open("test.dat");
	for(int j = 0; j < 50; j++)
	{
		for (int i =0; i < 35; i++)
		{
			if (i==34) file_out << Array[i][j] << std::endl;
			else file_out << Array[i][j] << "\t";
		}
	}
	file_out.close();
}

/*Function for recalculation differential cross section values to probability density values */
void Material::fill_probability()
{
	double TempArray[34]; //temporary array, TempArray[0] - sum
	TempArray[0] = 0;
	for (int j = 1; j < 50; j++)
	{
		TempArray[1] = Array[1][0] * Array[1][j];
        TempArray[0] += TempArray[1];
		for (int i=2; i < 34; i++ )
		{
			//S = 0.5*c*(a+b)
			TempArray[i] = 0.5*(Array[i][0] - Array[i-1][0]) * ( Array[i][j] + Array[i-1][j]);
            TempArray[0] += TempArray[i];
		}
		if ( TempArray[0] != 0)
		{
			Array[1][j] = TempArray[1]/TempArray[0];
			for (int i = 2; i < 34; i++)	Array[i][j] = TempArray[i]/TempArray[0] + TempArray[i-1];
		}
		//std::cout << TempArray[0] << "\t";
        TempArray[0] = 0;
	}
}

void Material::set_Rnd(double rr)
{
	R = rr;
}

/*Function for instant theta angle value determination */
double Material::receive_theta(double E_i)
{
	double rnd = rndMy(get_Rnd());
	set_Rnd(rnd);
    int col, row;
    col = column_search(rnd);
	row = row_search (E_i);
	if (row < 0 && col < 0)
	{
		double temp1, temp2, temp3;
		temp1 = (rnd - Array[-col-1][-row]) * (Array[-col][0] - Array[-col-1][0]) / (Array[-col][-row] - Array[-col-1][-row]) +	Array[-col-1][0];
		temp2 = (rnd - Array[-col-1][-row-1]) * (Array[-col][0] - Array[-col-1][0]) / (Array[-col][-row-1] - Array[-col-1][-row-1]) + Array[-col-1][0];
        temp3 =	(E_i - Array[0][-row]) * (temp2 - temp1) / ( Array[0][-row-1] - Array[0][-row]) + temp1;
        return temp3;
	}
	else if (row < 0 && col > 0)
	{
        double temp3 =	(E_i - Array[0][-row]) * (Array[col][-row-1] - Array[col][-row]) / ( Array[0][-row-1] - Array[0][-row]) + Array[col][-row];
        return temp3;
	}
	else if (row > 0 && col < 0)
	{
        double temp3 =	(rnd - Array[-col-1][row]) * (Array[-col][0] - Array[-col-1][0]) / (Array[-col][row] - Array[-col-1][row]) +	Array[-col-1][0];
        return temp3;
	}
	else
	{
        double temp3 = Array[col][0];
        return temp3;
	}
}

/* Function to get phi angle value*/
double Material::receive_phi()
{
    double rr = rndMy(get_Rnd());
	set_Rnd(rr);
	return (rr*360-180)/3.14 ;
}

/* Function for total elastic Mott cross section determination for instant energy value */
double Material::receive_total_cs(double E_i)
{
	int row = row_search (E_i);
	if (row < 0) return (E_i - Array[0][-row]) * (Array[34][-row-1] - Array[34][-row]) / ( Array[0][-row-1] - Array[0][-row]) + Array[34][-row];
	else return Array[34][row];
}

/*Function for determination of instant theta angle location in table */
int Material::column_search (double rnd)
{
	for (int i = 1; i < 34; i++ )
	{

		if (rnd < Array[i][0])
		{
			return	-i;
			break;
		}
		else if (rnd == Array[i][0])
		{
			return i;
			break;
		}
		else if (i == 33 && rnd > Array[33][0])
		{
			return 33;
			break;
		}
	}
}

/*Function for determination of instant energy value location in table */
int Material::row_search (double E_i)
{
	for (int i =1 ; i < 50; i++ )
	{

		if (E_i > Array[0][i])
		{
			return	-i;
			break;
		}
		else if (E_i == Array[0][i])
		{
			return i;
			break;
		}
		else if (i == 49 && E_i < Array[0][49])
		{
			return 49;
			break;
		}
	}
}
