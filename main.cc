#include <vector>
#include <iostream>
#include <cmath>    //functions for calcuating angles for conline polygons
#include <ctime>
#include <stdlib.h>     /* srand, rand */

#include "Geometry.h"
#include "ConvexHull.h"
#include "environment.h"

using namespace std;

int main(){
srand(time(0)); // seed the program's random
//polygon testPoly(0,0, 10);
//testPoly.generatePoints(false, 20);
//100x100 map with 5 shapes
environment testEn(50,50,5);
testEn.generateWolrd();

  return 0;
}
