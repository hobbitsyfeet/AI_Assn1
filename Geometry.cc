#include "Geometry.h"
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include <ctime>
#include <iostream>
#include <cassert>

void vertex::set(int x, int y){
  this->x = x;
  this->y = y;
  return;
}

polygon::polygon(int originX, int originY, int size){
origin.set(originX, originY);
  this->size = size;
}

//equal will generate equalateral shapes, points will determine how many
// vertecies the shape will have.
void polygon::generatePoints(bool equal, int points){
  assert(points >= 3);
  srand(time(0));
  vertex tempVertex;
//  float clockwise;

  //generate vertecies for number of points told
  for(int counter = 0; counter < points; counter++){

    std::cout<<"number of vertecies in this shape is: ";
    std::cout<<vertecies.size()<<'\n';

    int sizex = (rand() % size) - size/2;
    int sizey = (rand() % size) - size/2;
    // random within size
    while((sizex - origin.x) == 0){  //prevent dividing by 0 later
      sizex = (rand() % size) - size/2;
    }


    //align with origin
    sizex += origin.x;
    sizey += origin.y;

    double rad;
    rad = sqrt((pow(sizex,2))+(pow(sizey,2)));
    std::cout<<rad;

	   double Thta;
	    Theta = atan(y/x);
      std::cout<<theta;

    std::cout<<sizex<<','<<sizey<<'\n';
    //assign temp
    tempVertex.set(sizex,sizey);

    //if first point, plot the point.
    if(counter == 0){
      vertecies.push_back(tempVertex);
    }

    // calculate angles to make sure it generate in a clockwise motion
    else{
      double rad;
      rad = sqrt((pow(x,2))+(pow(y,2)));
      return rad;

      double dy = vertecies.front().y - origin.y ;
      double dx = vertecies[0].x - origin.x;
      double m1 = dy/dx;
      std::cout<<"slope:"<<m1<<'\n';
       dy = tempVertex.y - origin.y ;
       dx = tempVertex.x - origin.x;
      double m2 = dy/dx;

      std::cout<<"slope:"<<m2<<'\n';
      double angle = atan(abs((m2 - m1)/ 1 + m2*m1));
      angle = angle * 180 / 3.14159;
      std::cout<<"ANGLE"<<angle<<'\n';

      if(angle > 180){
        counter -= 1;
        std::cout<<"REJECTED";
      }
      else{
        vertecies.push_back(tempVertex);
      }
    }

  } // end counter loop

  return;
}
void polygon::generateHull(){
  return;
}
