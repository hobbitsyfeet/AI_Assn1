#include <vector>
#include <iostream>
#include <cmath>    //functions for calcuating angles for conline polygons
#include <ctime>
#include <stdlib.h>     /* srand, rand */

#include "Geometry.h"
#include "ConvexHull.h"

using namespace std;

int main(){

	polygon testPoly(10,10,10);
	polygon testPoly2(10,15,5);
	testPoly.generatePoints(true, 5);

  return 0;
}
