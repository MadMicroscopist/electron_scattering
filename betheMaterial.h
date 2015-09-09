//betheMaterial.h
//Determination of new class betheMaterial which parent class is Material

#ifndef BETHEMATERIAL_H
#define BETHEMATERIAL_H

#include "material.h"

class betheMaterial : public Material{
    public:
//Choise constructor
        betheMaterial(

        );  //end of constructor

//set functions
        void set_material_Z( double);
        void set_material_A( double);
        void set_meanIP(double);
        void set_material_density( double);
//get functions
        double get_material_Z() const {return material_Z;}
        double get_material_A() const {return material_A;}
        double get_meanIP() const {return meanIP;}
        double get_material_density() const {return material_density;}
//function for electron step lenght calculation
        double calculate_step( double E_i );
//function for electron energy loss calculation
		double calculate_E_loss(double E_i, double step_lenght);
    private:
		void set_material_parameters(double, double, double, double, char*);
        double  material_Z;
        double  material_A;
        double  meanIP;
        double  material_density;
};

#endif
