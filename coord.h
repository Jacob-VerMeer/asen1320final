#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Coord class definition
class Coord {
    public:
        void setFlag();
        bool accessVis();
        void setPoints(double[], double[]);
    private:
        double xs, ys, zs, xg, yg, zg;
        double maskingAngle;
        bool visibilityFlag;
};
