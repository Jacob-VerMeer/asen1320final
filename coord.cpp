#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include "coord.h"

using namespace std;

bool Coord::accessVis(){
    return visibilityFlag;
}
// Write a function to assign position inputs to private variables
void Coord::setPoints(double RS[], double RGS[]){
    xs = RS[0];
    ys = RS[1];
    zs = RS[2];
    xg = RGS[0];
    yg = RGS[1];
    zg = RGS[2];
}
// Compute VisibilityFlag 
void Coord::setFlag(){
    const double pi = 3.141592653589793;
    
    double xd = xs-xg;
    double yd = ys-yg;
    double zd = zs-zg;
    
    double Rgs = sqrt((xg*xg)+(yg*yg)+(zg*zg));
    double Rd = sqrt((xd*xd) + (yd*yd) + (zd*zd));
    double Rdgs = (xd*xg) + (yd*yg) + (zd*zg);
    double maskingAngleRad = (pi/2) - acos(Rdgs/(Rgs*Rd));
    maskingAngle = maskingAngleRad * (180/pi);
    
    if (maskingAngle > 10){
        visibilityFlag = true;
    }
    else{
        visibilityFlag = false;
    }
}