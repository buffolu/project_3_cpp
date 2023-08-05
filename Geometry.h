#pragma once
#include <iomanip>
#include <iostream>

// angle units conversion functions
double to_radians(double theta_d);
double to_degrees(double theta_r);
// class declarations
typedef struct Point {
    double x;
    double y;
    Point(double x, double y);
    Point();
    void print() const;
    bool operator==(const Point &rhs);
    bool operator!=(const Point &rhs);
    static double distance(Point a, Point b);
    static double getAngle(Point a, Point b);

    static Point advance(Point point, double speed, double angle,int flag =0);
    static Point advance(Point beginning, Point target, double speed);
} Point;
struct Polar_vector;
typedef struct Cartesian_vector {
    Cartesian_vector(const struct Polar_vector &pv);
    Cartesian_vector();
    void operator=(const struct Polar_vector &pv);
    double delta_x;
    double delta_y;
} Cartesian_vector;
typedef struct Polar_vector {
    Polar_vector(const Cartesian_vector &cv);
    Polar_vector();
    void operator=(const Cartesian_vector &cv);
    double r;
    double theta;
} Polar_vector;
