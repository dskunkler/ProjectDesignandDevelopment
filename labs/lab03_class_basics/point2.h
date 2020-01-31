#ifndef POINT2_H
#define POINT2_H

#include <math.h>
#include <iostream>
using namespace std;

class Point2{

    public:
        Point2(double _x = 0, double _y = 0){x = _x, y = _y;}
        double DistanceBetween(Point2 otherP);
        int Quadrant();
        void Print();

    private:
        double x;
        double y;
};


#endif