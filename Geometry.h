#ifndef Geometry_H
#define Geometry_h

#include <vector>
#include "ConvexHull.h"

// vertex rendered obsolete by convexHull algorithm
/*
struct vertex{
  int x, y;
  vertex* edge; //each vertex will have an edge
  void set(int x, int y);
};
*/
class polygon{
public:
polygon(int originX, int originY, int size); //constructor creates origin of polygon
void generatePoints(bool equal, int points); //will orginize points to their shapes
void generateHull();
std::vector<Point> vertecies;
//private:
  int size;
  //vertex origin; //center of the shape of which the points will be generated
};

#endif //Geometry_H
