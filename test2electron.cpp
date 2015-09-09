//test1electron.cpp

#include <iostream>
#include "simple_svg_1.0.0.hpp"
#include "electron2.h"
#include "betheMaterial.h"

void svgDraw(Electron*, svg::Document*, double, double, double); // test function for svg-objects 

int main()
{
	svg::Dimensions dimensions(100, 100);
	svg::Document doc("test1svg.svg", svg::Layout(dimensions, svg::Layout::TopLeft));
	svg::Document *ptrDoc = &doc;
	Electron e1;
	Electron *ptrElectron = &e1;
	betheMaterial m1;
	//int N;
	//std::cout << "Insert step number" << std::endl;
	//std::cin >> N;

	for (int i=0; i < 25; i++)
	{
		double E1 = e1.get_energy();
		std::cout << E1 << "\t" <<  e1.get_x() << "\t" << e1.get_y() << "\t" << e1.get_z() << "\t" <<  std::endl;
		double theta1 = m1.receive_theta(E1);
		e1.rotate(m1.receive_phi(), sin(theta1*3.14/180), cos(theta1*3.14/180));
		e1.set_energy(E1 - m1.calculate_E_loss(E1, e1.e_step( m1.calculate_step( E1 ) ) ) );
		svgDraw(ptrElectron, ptrDoc, e1.get_x(), e1.get_y(), dimensions.width/2);
	}
	doc.save();
return 0;
}

void svgDraw(Electron *el, svg::Document *doc, double x1, double y1, double const width2)
{
	*doc << svg::Line(svg::Point(width2+ el->get_x1()*1e8, el->get_y1()*1e8), svg::Point(width2 + x1*1e8, y1*1e8), svg::Stroke(0.1, svg::Color::Black));
	el->set_temp_xy(x1, y1);
}