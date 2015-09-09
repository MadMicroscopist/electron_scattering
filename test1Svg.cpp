#include "electron2.h"
//#include "simple_svg_1.0.0.hpp"
//#include <iostream>

//void svgDraw(svg::Document*, double, double, double); // test function for svg-objects 
/*void svgDraw(svg::Document *doc, double, double, double)
{
	*doc << svg::Line(svg::Point(0,0), svg::Point(10,20), svg::Stroke(0.5, svg::Color::Black));
} */
int main()
{
	Electron e1;
	svg::Dimensions dimensions(100, 100);
	svg::Document doc("test1svg.svg", svg::Layout(dimensions, svg::Layout::BottomLeft));
	svg::Document *ptrDoc = &doc;
	//doc << svg::Line(svg::Point(0,0), svg::Point(10,20), svg::Stroke(0.5, svg::Color::Black));
	//svgDraw(ptrDoc);
	svgDraw(ptrDoc, e1.get_x(), e1.get_y(), dimensions.width/2);
	doc.save();
return 0;
}


