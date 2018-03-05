#include <iostream>

#include "Point.h"

using namespace std;

void compare(Point& a, Point& b) {
    if (a != b) {
        cout << "a != b" << endl;
    }
    else {
        cout << "a == b" << endl;
    }
}

Lines::Lines(initializer_list<pair<Point, Point>> lst) {
    for (auto p : lst) add(p.first, p.second);
}

int main(){
    Point a{1, 1}, b{2, 2}, c{1, 1};

    compare(a, b);
    compare(a, c);

    return 0;
}
