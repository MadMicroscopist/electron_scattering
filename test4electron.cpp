//test1electron.cpp

#include <iostream>
#include "simple_svg_1.0.0.hpp"
#include "vElectron.h"
#include "betheMaterial.h"

void svgDraw(vElectron*, svg::Document*, double, double, double); // test function for svg-objects

int main()
{
	vElectron e1;
	vElectron *ptrElectron = &e1;
	betheMaterial m1;
	double BR = m1.betheRange(e1.get_energy() );
	//int N;
	//std::cout << "Insert step number" << std::endl;
	//std::cin >> N;

	svg::Dimensions dimensions(BR, BR/2);
	svg::Document doc("test1svg.svg", svg::Layout(dimensions, svg::Layout::TopLeft));
	svg::Document *ptrDoc = &doc;
	
	std::cout << "Bethe range is " << BR << std::endl;

	do
	{
		double E1 = e1.get_energy();
		std::cout << E1 << "\t" <<  e1.get_x() << "\t" << e1.get_y() << "\t" << e1.get_z() << "\t" <<  std::endl;
		//std::cout << E1 << "\t";
		double theta1 = m1.receive_theta(E1);
		//std::cout << theta1 << std::endl;
		e1.rotate(m1.receive_phi(), m1.receive_theta(E1));
		e1.set_energy(E1 - 1e3*m1.calculate_E_loss(E1, e1.e_step( m1.calculate_step( E1 ) ) ) );
		svgDraw(ptrElectron, ptrDoc, e1.get_x(), e1.get_z(), dimensions.width/2);
	} while (e1.get_z() > 0 && e1.get_energy()>= 50);
	doc.save();
return 0;
}

void svgDraw(vElectron *el, svg::Document *doc, double x1, double z1, double const width2)
{
	*doc << svg::Line(svg::Point(width2+ el->get_x1()*1e9, el->get_z1()*1e9), svg::Point(width2 + x1*1e9, z1*1e9), svg::Stroke(0.1, svg::Color::Black));
	el->set_xz_temp(x1, z1);
}
