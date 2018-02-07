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
//srand(time(0)); // seed the program's random
srand(1); //constant seed for debugging
//polygon testPoly(0,0, 10);
//testPoly.generatePoints(false, 20);
//100x100 map
std::vector<Point> tempPoints;

environment testEn(50,50,5);
testEn.generateWolrd();

//set our starting point to the first polygon's vertex.
//this polygon is specialy designated to be (0,0).
testEn.problemSolver.currentPoint = &testEn.shapes[0].vertices[0];

//init pass first point in.
tempPoints = testEn.problemSolver.actions(testEn.problemSolver.currentPoint);

for (int i = 0; i < tempPoints.size(); i++){
	std::cout<<tempPoints[i].display();
}
  return 0;
}
