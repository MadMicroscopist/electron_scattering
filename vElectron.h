//vElectron.h
//Determination of new VELECTRON_H class

#ifndef VELECTRON_H
#define VELECTRON_H

#include <iostream>
#include "electron.h"

    class vElectron : public Electron{
    public:
        vElectron(
        ); //end of constructor
//set functions
        void set_xy_temp( double, double);
//get functions
        double get_x1() const {  return x1;}
        double get_y1() const {  return y1;}

    private:
        double	x1, y1;
    }; //end of vELECTRON class

#endif
