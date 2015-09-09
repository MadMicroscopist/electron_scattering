//test3Mott.cpp
//test_of_FTI_Mott_io.h & cpp

#include <math.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include "electron.h"
#include "vElectron.h"
#include "material.h"
#include "betheMaterial.h"

int main()
{
    vElectron e1; //create an Electron class object
    betheMaterial m1; //create an betheMaterial class object

    //svg Drawing
    svg::Dimensions dimensions(100, 100);
    svg::Document doc("test1electron.svg", svg::Layout(dimensions, svg::Layout::TopLeft));
    for (int i = 0; i < 15; i++)
    {
        double rnd;
        std::srand(time(0));
        rnd = (double)(rand() % 1000000000)/100000;
        double x1 = e1.get_x();
        double y1 = e1.get_y();
        std::cout << "Initial electron has" << std::endl;
        std::cout << "x = " << e1.get_x() << "\t y = " << e1.get_y() << "\t z = " << e1.get_z() << "\t E_instant = " << e1.get_energy() << std::endl;

        double d_theta = m1.receive_theta(rnd, e1.get_energy());    //define theta value
        double step = m1.calculate_step(e1.get_energy());   //define step lenght
        std::srand(time(0));
        e1.rotate((double)(rand() % 1000000000)/100000, sin(d_theta), cos(d_theta));    //rotate electron vector
        e1.e_step(step*1e7);    //recalculate coordinates

        std::cout << "Step lenght is " << step*1e7 << " nm" << std::endl;
        std::cout << "Energy loss is " << m1.calculate_E_loss(e1.get_energy(), step)* 1000 << "eV" <<std::endl; //define energy loss value

        e1.set_energy(e1.get_energy() - m1.calculate_E_loss(e1.get_energy(), step)* 1000);  //change electron energy

        std::cout << "new electron has" << std::endl;
        std::cout << "x = " << e1.get_x() << "\t y = " << e1.get_y() << "\t z = " << e1.get_z() << "\t E_instant = " << e1.get_energy() << std::endl;
        doc << svg::Line(svg::Point(dimensions.width/2 + x1, y1), svg::Point(dimensions.width/2+e1.get_x(), e1.get_y()), svg::Stroke(.5, svg::Color::Red) );
    }

    doc.save();
return 0;
}
