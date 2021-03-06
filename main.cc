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

environment testEn(25,25,9);
testEn.generateWolrd();

//set our starting point to the first polygon's vertex.
//this polygon is specialy designated to be (0,0).
testEn.problemSolver.currentPoint = &testEn.shapes[5].vertices[2];

//init pass first point in.
tempPoints = testEn.problemSolver.actions(testEn.problemSolver.currentPoint);

for (int i = 0; i < tempPoints.size(); i++){
	tempPoints[i].display();
}
//line test(12,18, 13,12);
//test.display();
//std::cout<<" "<<test.angle();
  return 0;
}
