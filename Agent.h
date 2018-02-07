#ifndef AGENT_H
#define AGENT_H

#include<vector>
#include"Geometry.h"
#include"ConvexHull.h"

struct agent{
  std::vector<Point>  actions(Point*);  // returns a vector of accessable points


	//std::vector<Point>* environmentObsticals;
	void searchBFS();
	void searchDFS();

  std::vector<polygon> *environmentShapes; //the agent needs to know about the env it
	Point *currentPoint;
};

#endif //AGENT_H
