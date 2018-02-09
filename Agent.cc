#include "Agent.h"
#include <vector>
#include"Geometry.h"
#include"ConvexHull.h"
#include <iostream>
#include <cmath>

  std::vector<Point> agent::actions(Point* current){
		// points which are accessable in environment
    std::vector<Point> accessablePoints, rejectList;
		//a copy of environment to work with
		std::vector<polygon> tempPolys = *environmentShapes;
		//Point tempPoint1, tempPoint2;

		//std::vector<line> testLines;
		line tempLine1, tempLine2, testLine;
    //for each shape
		for (int i = 0; i < tempPolys.size(); i++){
			std::cout<<"newShape : Point Number:"<<tempPolys[i].vertices.size()<<std::endl;
      //for each vertex in current shape
			for (int j = 0; j < tempPolys[i].vertices.size(); j++){

        //first and last polygon has no edges, dont calculate
            if(j+1 == tempPolys[i].vertices.size()){

              //we dont want to point to the starting.
              //last-->first vertex
              if( i != 0){
                tempLine1.set(*current, tempPolys[i].vertices[j]);
                tempLine2.set(*current, tempPolys[i].vertices[0]);
                tempLine1.display();
                std::cout<<" ANGLE<"<<tempLine1.angle()<<">";
                std::cout<<" AND ";
                tempLine2.display();
                std::cout<<" ANGLE<"<<tempLine2.angle()<<">";
                std::cout<<'\n';

              }
            }//end if on last-->first vertex
            //else the edges have not made full connection yet.
            else{
              tempLine1.set(*current, tempPolys[i].vertices[j]);
              tempLine2.set(*current, tempPolys[i].vertices[j+1]);
              tempLine1.display();
              std::cout<<" ANGLE["<<tempLine1.angle()<<"]";
              std::cout<<" AND ";
              tempLine2.display();
              std::cout<<" ANGLE["<<tempLine2.angle()<<"]";
              std::cout<<'\n';
            }//end else general edge

            //calculated outside edges, now check if there is any point which exists inside
            for (int numShapes2 = 0; numShapes2 < tempPolys.size(); numShapes2++){
              //for each vertex in current shape
              for (int numVertex2 = 0; numVertex2 < tempPolys[numShapes2].vertices.size(); numVertex2++){
                testLine.set(*current,tempPolys[numShapes2].vertices[numVertex2]);
                //std::cout<<"\nTESTING is "<<tempLine1.angle()<<" < " << testLine.angle() <<" < "<<tempLine2.angle();;

                //depending on how the angles differ clockwise/counterclockwise.
                bool testAngle = round(testLine.angle()) < round(tempLine1.angle()) && round(testLine.angle()) > round(tempLine2.angle());
                bool testAngle2 = (round(testLine.angle()) > round(tempLine1.angle()) && round(testLine.angle()) < round(tempLine2.angle()));
                //length determines if it's behind.
                bool testlength = (round(testLine.length()) < round(tempLine1.length()) && (round(testLine.length()) < round(tempLine2.length())));
                //bool samePoint = (tempLine1.p1.x == testLine.p2.x);
              //  if(!testlength)
                  //std::cout<<"!!";
               //std::cout<<'['<<tempLine1.length()<<'|'<<testLine.length()<<'|'<<tempLine2.length()<<"]\n";

                //if the testangle exists between the two lines, reject it
                //if((testAngle && !testlength && !samePoint) || (testAngle2 && !testlength && !samePoint)){
                if((testAngle && !testlength ) || (testAngle2 && !testlength)){
                  std::cout<<"rejecting <"<<testLine.angle()<<">";
                  testLine.p2.display();
                  std::cout<<'\n';
                  //reject the point on the 2nd coord of the line
                  bool reject = true;
                  //make sure we don't reject it and prevent twice filling the list
                  for(int rejectCheck = 0; rejectCheck < rejectList.size(); rejectCheck++){
                    if(rejectList[rejectCheck] == testLine.p2){
                      reject = false;
                    }
                  }//end for rejectCheck
                  if(reject == true){
                    rejectList.push_back(testLine.p2);
                  }
                }
              }//end numVertex2
            }//end numshapes2
			}//end of polygon's vertices
		}//end tempPolys

    std::cout<<"Accessable:\n";
    //accessable points = inverse rejectList, iterate every point and add what's not on reject
    for (int i = 0; i < tempPolys.size(); i++){//each shape
      //for each vertex in current shape
      for (int j = 0; j < tempPolys[i].vertices.size(); j++){
        bool reject = false;
        //if compare current vertex to what's on reject list
        for(int rejectCheck = 0; rejectCheck < rejectList.size(); rejectCheck++){
          //rejectList[rejectCheck].display();
          if(rejectList[rejectCheck] == tempPolys[i].vertices[j]){
            reject = true;
          }//end if the point exists in reject list
        }//end for reject check
        if(reject == false){
          accessablePoints.push_back(tempPolys[i].vertices[j]);
        }//end if reject is false

      }//end vertex
    }//end shape
    return accessablePoints;
  }

void agent::AStar(){

}

void agent::searchBFS(){
	return;
}

void agent::searchDFS(){
	return;
}
