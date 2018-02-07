
#include "Environment.h"
#include "Geometry.h"
#include <cmath>
#include <ctime>
#include <stdlib.h>     /* srand, rand */
#include <iostream>


  environment::environment(int max_x, int max_y, int numberOfShapes){
    envVolume.x = max_x;
    envVolume.y = max_y;
    numShapes = numberOfShapes;
		problemSolver.environmentShapes = &shapes;
  }

void environment::generateWolrd(){

  Point tempPoint;
  bool goodShape = false;
  int shpSize;
  std::vector<polygon> tempPolys;


polygon endPointPoly(0,0,1);
tempPoint.set(0,0);
endPointPoly.vertices.push_back(tempPoint);
tempPolys.push_back(endPointPoly); //push back final point in the env

std::cout<<"Generating Polygons\n";
  //start generating polygons dimentions
  for(int generated = 0; generated < numShapes; generated++){
    goodShape = false;
    while(!goodShape){
    //generate x,y origin for the current shape (+ 10 x, y so no negs generate.)
    tempPoint.set(rand()% int(envVolume.x) + 10, rand()% int(envVolume.y) + 10 );

    //size of shape
  shpSize = (rand()% 7)+3 ; //size of a shape is randomly between 3-10

    //prevent shapes from overlapping any polygon in list
    for(int i = 0; i < tempPolys.size(); i++){
			//std::cout<<"Distance Check: ";
      line distanceCheck(tempPoint, tempPolys[i].origin);
      //std::cout<<distanceCheck.length()<<" To Polygon "<<i<<'\n';

      if(distanceCheck.length() <= (shpSize + tempPolys[i].size + 1)){
        goodShape = false; //regenerate another shapeES
        //std::cout<<"REGENERATE ("<<i<<") Distance Required:";
				//std::cout<<shpSize + tempPolys[i].size + 2<<'\n';
        break;
      }// end distance check
      else{goodShape = true;}
    }//end overlap check
  }//end polygon generation

	//bool regularRand = rand()%2;
	bool regularRand = false;
	//std::cout<< regularRand<<"RegRandVal \n";
  //create polygon with generated dimentions
  polygon readyPolygon(tempPoint,shpSize);
  readyPolygon.generatePoints(regularRand, (rand() % 4) + 4 ); //random poly with 3-6 points
  tempPolys.push_back(readyPolygon);
  //std::cout<<"\n";
  }//end generatign polygon

  polygon startPoint(0,0,1);
  tempPoint.set(envVolume.x,envVolume.y);
  startPoint.vertices.push_back(tempPoint);
  tempPolys.push_back(startPoint); //push back final point in the env

	//assign shapes
	shapes = tempPolys;
  return;
}
