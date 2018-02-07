#include "Agent.h"
#include <vector>
#include"Geometry.h"
#include"ConvexHull.h"
#include <iostream>

  std::vector<Point> agent::actions(Point *current){
		// points which are accessable in environment
    std::vector<Point> accessablePoints;
		//a copy of environment to work with
		std::vector<polygon> tempPolys = *environmentShapes;
		Point tempPoint1, tempPoint2;
		line tempLine;


		for (int i = 0; i < tempPolys.size(); i++){
			std::cout<<"newShape "<<tempPolys[i].vertices.size()<<std::endl;
			for (int j = 0; j < tempPolys[i].vertices.size()+1; j++){
				//we dont have any edges on the last polygon
				//if we are not, on the last polygon, calculate
						if(j == tempPolys[i].vertices.size()){
							//on the last iteration we create an edge from last vertex
							//to the first one.
							if(i+1 != tempPolys.size() && i != 0){
								tempPoint1 = tempPolys[i].vertices[0];
								tempPoint2 = tempPolys[i].vertices[j];
								std::cout<<tempPoint1.x<<" "<<tempPoint1.y<<std::endl;
							}
						}//end if on last vertex
						//else the edges have not made full connection yet.
						else{
							tempPoint1 = tempPolys[i].vertices[j];
							tempPoint2 = tempPolys[i].vertices[j+1];
							std::cout<<tempPoint1.x<<" "<<tempPoint1.y<<std::endl;
						}//end else general edge distance
			}//end of polygon's vertices
		}//end tempPolys
    return accessablePoints;
  }

void agent::searchBFS(){
	return;
}
void agent::searchDFS(){
	return;
}
