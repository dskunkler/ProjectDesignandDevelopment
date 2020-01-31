#include "point2.h"


int Point2::Quadrant(){
    if(x == 0 && y == 0){
        return 0;
    }
    if(x >= 0){
        if (y >= 0){
            if(x == 0){
                return 2;
            }
            else{
                return 1;
            }
        }
        else{
            return 4;
        }
    }
    else{
        if(y<= 0){
            return 3;
        }
        else{
            return 2;
        }
    }
}

double Point2::DistanceBetween(Point2 otherP){
    return sqrt(pow(otherP.x-this->x,2) + pow(otherP.y-this->y,2));

}

void Point2::Print(){
    cout << "x = "<< x <<", y = " << y << endl;
}