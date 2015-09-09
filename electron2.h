//electron2.h
//Determination of new ELECTRON class

#ifndef ELECTRON2_H
#define ELECTRON2_H

#include <math.h>
#include <iostream>

    class Electron{
        friend std::ostream &operator<<(std::ostream &, const Electron &);
        friend std::istream &operator>>(std::istream &, Electron &);
    public:
        Electron(
            double = 50, double = 50, double = 0,

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
		void set_temp_xy(double, double);
        void set_z( double);
        void set_energy( double);
        void fill_Rmatrix(double, double, double, double, double, double, double, double, double);
//get functions
        double get_x() const {  return Coordinate[0];}
        double get_y() const {  return Coordinate[1];}
        double get_x1() const {  return x1;}
        double get_y1() const {  return y1;}
        double get_z() const {  return Coordinate[2];}
        double get_energy() const {  return electron_energy;}
		
        void rotate(double phi, double sin_th, double cos_th); /* electron coordinate system rotation function */
        double e_step(double lenght); /*electron move step appliment */
		
    private:
        double	Coordinate[3];
        double	Ort[9];
        double  electron_energy;
		double 	x1, y1;
    }; //end of ELECTRON class

#endif
