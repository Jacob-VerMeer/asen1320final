#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include "coord.h"

using namespace std;

int main(){
    
// Create two objects of the coord class for each spacecraft 
Coord Sat1;
Coord Sat2;

// Read in data from Sat1Position.csv and Sat2Position.csv, GSPosition.csv
ifstream Sat1Position;
ifstream Sat2Position;
ifstream GSPosition;
Sat1Position.open("Sat1Position.csv");
Sat2Position.open("Sat2Position.csv");
GSPosition.open("GSPosition.csv");

// Create objects for file output 
ofstream visibility1;
    visibility1.open("Sat1Visibility.csv", ofstream::app);

ofstream visibility2;
    visibility2.open("Sat2Visibility.csv", ofstream::app);


// Master for loop, Reads position data and computes visibilityFlag
for (int i=0; i<=1441; i++){   
    
    string Sat1X, Sat1Y, Sat1Z, Sat2X, Sat2Y, Sat2Z, GSX, GSY, GSZ;

    getline(Sat1Position, Sat1X, ',');
    getline(Sat1Position, Sat1Y, ',');
    getline(Sat1Position, Sat1Z);

    getline(Sat2Position, Sat2X, ',');
    getline(Sat2Position, Sat2Y, ',');
    getline(Sat2Position, Sat2Z);

    getline(GSPosition, GSX, ',');
    getline(GSPosition, GSY, ',');
    getline(GSPosition, GSZ);

 // Use the stod function to convert strings created by getline to double type variables  
    double xg = stod(GSX);
    double yg = stod(GSY);
    double zg = stod(GSZ);

    double RGS[] = {xg, yg, zg};

    double xs1 = stod(Sat1X);
    double ys1 = stod(Sat1Y);
    double zs1 = stod(Sat1Z);

    double RS1[] = {xs1, ys1, zs1};

    double xs2 = stod(Sat2X);
    double ys2 = stod(Sat2Y);
    double zs2 = stod(Sat2Z);

    double RS2[] = {xs2, ys2, zs2};
// Call class member functions to determine the visibility

    Sat1.setPoints(RS1, RGS);
    Sat1.setFlag();

    Sat2.setPoints(RS2, RGS);
    Sat2.setFlag();
    
    // Output to new csv file  
    visibility1 << Sat1.accessVis() << endl;
    visibility2 << Sat2.accessVis() << endl;

}

// Close your files kids
Sat1Position.close();
Sat2Position.close();
GSPosition.close();
visibility1.close();
visibility2.close();
    return 0;
}
