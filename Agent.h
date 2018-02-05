#ifndef AGENT_H
#define AGENT_H

#include<vector>
#include"Geometry.h"
#include"ConvexHull.h"

struct agent{
  //agent(Point startPoint);
  std::vector<Point>  actions(Point);  // returns a vector of accessable points
  Point CurrentPoint;
	//std::vector<Point>* environmentObsticals;	

	void searchBFS();
	void searchDFS();
  //std::vector<Point> *environmentShapes; //the agent needs to know about the env it
                                    //interacts with.
};

#endif //AGENT_H
