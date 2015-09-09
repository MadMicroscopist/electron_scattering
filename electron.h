//electron.h
//Determination of new ELECTRON class

#ifndef ELECTRON_H
#define ELECTRON_H

#include <math.h>
#include <iostream>

    class Electron{
        friend std::ostream &operator<<(std::ostream &, const Electron &);
        friend std::istream &operator>>(std::istream &, Electron &);
    public:
        Electron(
            double = 0, double = 0, double = 0,

            double =	1,
            double =	0,
            double =	0,
            double =	0,
            double =	1,
            double =	0,
            double =	0,
            double =	0,
            double =	1,

            double =    20000
        ); //end of constructor

//set functions
        void set_coordinates(double, double, double);
        void set_xy( double, double);
        void set_z( double);
        void set_energy( double);
        void fill_Rmatrix(double, double, double, double, double, double, double, double, double);
//get functions
        double get_x() const {  return Coordinate[0];}
        double get_y() const {  return Coordinate[1];}
        double get_z() const {  return Coordinate[2];}
        double get_energy() const {  return electron_energy;}
		bool get_e_status() const {	 return BSE;}

        void rotate(double phi, double theta); /* electron coordinate system rotation function */

        double e_step(double lenght); /*electron move step appliment */

		void backScattering();
    protected:
        double	Coordinate[3];
    private:
        double	Ort[9];
        double  electron_energy;
		bool BSE;
    }; //end of ELECTRON class

#endif
