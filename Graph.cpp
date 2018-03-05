#include <iostream>
#include "Graph.h"

using namespace Graph_lib;

void Shape::add(Point p) {
    std::cout << "Shape::add([" << p.x << ',' << p.y << "])\n";
}

Line::Line(Point p1, Point p2) {
    add(p1);
    add(p2);
}

void Lines::add(Point p1, Point p2) {
    Shape::add(p1);
    Shape::add(p2);
}

void Lines::draw_lines() const {
    if (color().visibility()) {
        for (int i=0; i<num_of_points(); i+=2)
            fl_line(point(i-1).x, point(i-1).y, point(i).x, point(i).y);
    }
}
