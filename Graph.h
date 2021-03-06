#pragma once

#include "Point.h"

namespace Graph_lib {

struct Color {
    enum Color_type {
        red = FL_RED,
        blue = FL_BLUE,
        green = FL_GREEN,
        yellow = FL_YELLOW,
        white = FL_WHITE,
        black = FL_BLACK,
        magenta = FL_MAGENTA,
        cyan = FL_CYAN,
        dark_red = FL_DARK_RED,
        dark_green = FL_DARK_GREEN,
        dark_yellow = FL_DARK_YELLOW,
        dark_blue = FL_DARK_BLUE,
        dark_magenta = FL_DARK_MAGENTA,
        dark_cyan = FL_DARK_CYAN
    };

    enum Transparency {invisible = 0, visible=255};

    Color(Color_type cc):c{FL_Color(cc)}, v{visible} {}
    Color(Color_type cc, Transparency vv):c{FL_Color(cc)}, v{vv} {};
    Color(int cc):c{FL_Color(cc)}, v{visible} {}
    Color(Transparency vv):c{FL_Color(), v{vv}} {}

    int as_int() const {return c;}

    char visibility() const {return v;}
    void set_visibility(Transparency vv) {v=vv;}

private:
    char v;
    FL_Color c;
};

struct Line_style {
    enum Line_stype_type {
        solid = FL_SOLID,
        dash = FL_DASH,
        dot = FL_DOT,
        dashdot = FL_DASHDOT,
        dashdotdot = FL_DASHDOTDOT
    };

    Line_style(Line_style_type ss):s{ss}, w{0} {}
    Line_style(Line_stype_type lst, int ww):s{lst}, w{ww} {}
    Line_style(int ss) : s{ss}, w{0} {}

    int width() const { return w; }
    int style() const { return s; }

private:
    int s;
    int w;
};

struct Shape {
    void add(Point p);
};

struct Line : Shape {
    Line(Point p1, Point p2);
};

struct Lines : Shape {
    Lines() {};
    Lines(initializer_list<pair<Point, Point>> lst);

    void draw_lines() const;
    void add(Point p1, Point p2);
};

}
