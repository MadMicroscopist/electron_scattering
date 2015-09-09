//test1electron.cpp

#include <iostream>
#include "simple_svg_1.0.0.hpp"
#include "electron2.h"

void svgDraw(Electron*, svg::Document*, double, double, double); // test function for svg-objects 

int main()
{
	svg::Dimensions dimensions(100, 100);
	svg::Document doc("test1svg.svg", svg::Layout(dimensions, svg::Layout::TopLeft));
	svg::Document *ptrDoc = &doc;
	Electron e1;
	Electron *ptrElectron = &e1;
	double new_x, new_y;
	std::cout << "Insert x" << std::endl;
	std::cin >> new_x;
	std::cout << "Insert y" << std::endl;
	std::cin >> new_y;
	e1.set_xy(new_x, new_y);

	svgDraw(ptrElectron, ptrDoc, e1.get_x(), e1.get_y(), dimensions.width/2);
	doc.save();
return 0;
}

void svgDraw(Electron *el, svg::Document *doc, double x1, double y1, double const width2)
{
	*doc << svg::Line(svg::Point(width2+ el->get_x1(), el->get_y1()), svg::Point(width2 + x1, y1), svg::Stroke(0.5, svg::Color::Black));
	el->set_temp_xy(x1, y1);
}