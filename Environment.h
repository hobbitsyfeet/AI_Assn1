#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "ConvexHull.h"
#include "Geometry.h"
#include "Agent.h"
#include <vector>

class environment{
public:
  environment(int max_x, int max_y, int numberOfShapes);
  void reset(); //resets the map, agent allocation and history.
  void generateWolrd();
  agent problemSolver;
  //public so agent can determine actions
  std::vector<polygon> shapes; //the list of shapes that exist

private:
  Point envVolume; //from (0,0) the top right corner defines max (x,y) values
  int numShapes;
};
#endif //ENVIRONMENT_H
