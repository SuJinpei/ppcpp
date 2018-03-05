#pragma once

struct Point {
    int x, y;
};

bool operator==(Point &a, Point& b) {return a.x == b.x && a.y == b.y;}
bool operator!=(Point &a, Point& b) {return !(a==b);}

