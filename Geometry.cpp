#include "Geometry.h"
#include <cmath>
#include <ctgmath>
#include <limits>

const double pi = 2. * atan2(1., 0.);
double to_radians(double theta_d) { return theta_d * pi / 180.0; }

double to_degrees(double theta_r) { return theta_r * 180.0 / pi; }
// construct a Cartesian_vector from a Polar_vector
Cartesian_vector::Cartesian_vector(const Polar_vector &pv) {
    delta_x = pv.r * cos(pv.theta);
    delta_y = pv.r * sin(pv.theta);
}
Cartesian_vector::Cartesian_vector() {
    delta_x = 0.0;
    delta_y = 0.0;
}
void Cartesian_vector::operator=(const Polar_vector &pv) {
    delta_x = pv.r * cos(pv.theta);
    delta_y = pv.r * sin(pv.theta);
}
// construct a Polar_vector from a Cartesian_vector
Polar_vector::Polar_vector(const Cartesian_vector &cv) {
    r = sqrt((cv.delta_x * cv.delta_x) + (cv.delta_y * cv.delta_y));
    /* atan2 will return a negative angle for Quadrant III, IV, must translate
     * to I, II */
    theta = atan2(cv.delta_y, cv.delta_x);
    if (theta < 0.)
        theta = 2. * pi + theta; // normalize theta positive
}
Polar_vector::Polar_vector() {
    r = 0.0;
    theta = 0.0;
}
void Polar_vector::operator=(const Cartesian_vector &cv) {
    r = sqrt((cv.delta_x * cv.delta_x) + (cv.delta_y * cv.delta_y));
    /* atan2 will return a negative angle for Quadrant III, IV, must translate
     * to I, II */
    theta = atan2(cv.delta_y, cv.delta_x);
    if (theta < 0.)
        theta = 2. * pi + theta; // normalize theta positive
}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point() {
    x = 0.0;
    y = 0.0;
}

void Point::print() const {
    std::cout << std::setprecision(2) << "(" << x << ", " << y << ")";
}

bool Point::operator==(const Point &rhs) { return x == rhs.x && y == rhs.y; }

double Point::distance(Point a, Point b) {
    double x1 = a.x;
    double y1 = a.y;

    double x2 = b.x;
    double y2 = b.y;

    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// return angle as degrees
double Point::getAngle(Point a, Point b) {
    double angle = atan2(b.y - a.y, b.x - a.x) * 180 / M_PI;
    if (angle < 0) {
        angle += 360;
    }
    return angle;
}



Point Point::advance(Point point, double speed, double angle,int flag) {

    if (flag)
    {
        angle-=90;
    }

    double radians = to_radians(angle);
    double delta_x = speed / 10 * cos(radians);
    double delta_y = speed / 10 * sin(radians);
    double epsilon = std::numeric_limits<double>::epsilon();
    if (std::abs(delta_x) < epsilon) {
        delta_x = 0.0;
    }
    if (std::abs(delta_y) < epsilon) {
        delta_y = 0.0;
    }

    return {point.x + delta_x, point.y + delta_y};
}

Point Point::advance(Point beginning, Point target, double speed) {
    if (distance(beginning, target) * 10 <= speed) {
        return target;
    }

    double angle = getAngle(beginning, target);

    return advance(beginning, speed, angle);
}
