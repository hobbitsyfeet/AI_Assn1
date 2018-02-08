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
		std::vector<line> testLines;
		line tempLine;


		for (int i = 0; i < tempPolys.size(); i++){
			std::cout<<"newShape "<<tempPolys[i].vertices.size()<<std::endl;
			for (int j = 0; j < tempPolys[i].vertices.size(); j++){
				//first and last polygon has no edges, dont calculate
						if(j+1 == tempPolys[i].vertices.size()){
							//last-->first vertex
							if(i+1 != tempPolys.size() && i != 0){
								tempPoint1 = tempPolys[i].vertices[j];
								tempPoint2 = tempPolys[i].vertices[0];
								std::cout<<tempPoint1.x<<","<<tempPoint1.y<<"--->";
								std::cout<<tempPoint2.x<<","<<tempPoint2.y<<std::endl;
							}
						}//end if on last-->first vertex
						//else the edges have not made full connection yet.
						else{
							tempPoint1 = tempPolys[i].vertices[j];
							tempPoint2 = tempPolys[i].vertices[j+1];
							std::cout<<tempPoint1.x<<","<<tempPoint1.y<<"--->";
							std::cout<<tempPoint2.x<<","<<tempPoint2.y<<std::endl;
						}//end else general edge

						line tempLine(tempPoint1,tempPoint2);
						testLines.push_back(tempLine);
						//tempPoint1 and 2 are now properly assigned.
			}//end of polygon's vertices
		}//end tempPolys

		//determine all points within the angles of the two lines
		for(int lineCount = 0; lineCount < testLines.size(); lineCount++){

			//for every point, we need to determine whether it exists
			//between the two angles
			for (int i = 0; i < tempPolys.size(); i++){
				for (int j = 0; j < tempPolys[i].vertices.size(); j++){
					tempLine(tempPolys[i].vertices[j])

				}
			}
		}
		//now we have lines,
    return accessablePoints;
  }

void agent::searchBFS(){
	return;
}
void agent::searchDFS(){
	return;
}
