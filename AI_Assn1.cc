#include <vector>
#include <iostream>
#include <cmath>    //functions for calcuating angles for convec polygons
#include <ctime>
#include <stdlib.h>     /* srand, rand */

#include "Geometry.h"
using namespace std;


int main(){
  srand(time(0));

std::vector<Point> points;
Point tempPoint;
int size = 10; //size no farther than 10 away from eachother
  for(int i = 0; i < 10; i++){
    int sizex = (rand() % size) - size/2;
    int sizey = (rand() % size) - size/2;
    tempPoint.x = sizex;
    tempPoint.y = sizey;
    points.push_back(tempPoint);
  }
points = makeConvexHull(points);


  for(int i = 0; i < points.size(); i++){
    cout<<points[i].x<<','<<points[i].y<<endl;
  }
  return 0;
}
