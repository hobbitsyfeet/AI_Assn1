#ifndef Geometry_H
#define Geometry_H

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
//double distance(const Point &A, const Point& B);

class line{
public:
	line(double p1x, double p1y, double p2x, double p2y);
	line(const Point &p1, const Point &p2);
	double length();
	double slope();
	double angle();
	Point A, B;
};


class polygon{
public:
polygon(int originX, int originY, int size); //constructor creates origin of polygon
polygon(const Point &p1, int size);
	void generatePoints(bool regular, int points); //will orginize points to their shapes
	void generateHull();
	void display();
	std::vector<Point> vertecies;
//private:
  int size;
	Point origin; //origin will determine where the shape will be created
};


#endif //Geometry_H
