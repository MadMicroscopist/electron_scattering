//Material.h
//Determination of new class Material

#ifndef MATERIAL_H
#define MATERIAL_H
#include <random>
#include <ctime>
inline double rndMy()
{
	std::random_device rd;
    std::mt19937_64 gen(time(NULL));
	return (1 - std::generate_canonical<double, 10>(gen) );
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
}; //end of class

#endif
