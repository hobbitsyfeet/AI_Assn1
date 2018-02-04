
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
  }

void environment::generateWolrd(){

  Point tempPoint;
  bool goodShape = false;
  int shpSize;
  std::vector<polygon> tempPolys;


polygon endPointPoly(0,0,1);
tempPoint.set(0,0);
endPointPoly.vertecies.push_back(tempPoint);
tempPolys.push_back(endPointPoly); //push back final point in the env

  //start generating polygons
  for(int generated = 0; generated < numShapes; generated++){
    goodShape = false;
    while(!goodShape){
    //generate x,y origin for the current shape
    tempPoint.set(rand()% int(envVolume.x), rand()% int(envVolume.y) );

    //size of shape
  shpSize = 5 ; //size of a shape is randomly between 3-8

    //prevent shapes from overlapping any polygon in list
    for(int i = 0; i < tempPolys.size(); i++){
      line distanceCheck(tempPoint, tempPolys[i].origin);
      std::cout<<distanceCheck.length()<<"    ";

      if(distanceCheck.length() <= (shpSize + tempPolys[i].size)){
        goodShape = false; //regenerate another shapeES
        std::cout<<"REGENERATE\n";
        break;
      }// end distance check
      else{goodShape = true;}
    }//end overlap check
  }//end polygon generation
  //create polygon with generated dimentions

  std::cout<<"COMPLETE\n";
  polygon readyPolygon(tempPoint,shpSize);
  readyPolygon.generatePoints(false, (rand() % 7) + 3 ); //random poly with 3-7 points
  tempPolys.push_back(readyPolygon);
  std::cout<<"\n";
  }//end generatign polygon

  polygon startPoint(0,0,1);
  tempPoint.set(envVolume.x,envVolume.y);
  startPoint.vertecies.push_back(tempPoint);
  tempPolys.push_back(startPoint); //push back final point in the env
  return;
}
