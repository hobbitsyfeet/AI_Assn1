#include "Geometry.h"
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include <ctime>
#include <iostream>
#include <cassert>
/** HELPER FUNCTIONS **/

/*
double distance(const Point &A,const Point B){
	return sqrt(pow((A.x - B.x),2) + pow((A.y - B.y),2));
}*/


/** LINE CLASS **/
line::line(double p1x, double p1y, double p2x, double p2y){
	A.x = p1x;
	A.y = p1y;
	B.x = p2x;
	B.y = p2y;
}
line::line(const Point &p1, const Point &p2){
	A.x = p1.x;
	A.y = p1.y;
	B.x = p2.x;
	B.y = p2.y;
}
double line::length(){
	return sqrt(pow((A.x - B.x),2) + pow((A.y - B.y),2));
}

double line::slope(){
	return (B.y - A.y) / (B.x - A.x);
}

double line::angle(){
	double angle = atan(slope())*180/M_PI;
	if(angle < 0)
		return angle + 360;
	return angle;
}

/** POLYGON CLASS **/
polygon::polygon(int originX, int originY, int size){
	origin.x = originX;
	origin.y = originY;
  this->size = size;
}

polygon::polygon(const Point &p1, int size){
	origin.x = p1.x;
	origin.y = p1.y;
  this->size = size;
}


//equal will generate equalateral shapes, points will determine how many
// vertices the shape will have.
void polygon::generatePoints(bool regular, int points){
  assert(points >= 3);
	std::cout<<"Generating Points For New Polygon\n";
  //srand(time(0));
	Point tempPoint;

	//create number of points in hull
	while(vertices.size() < points){
		//regular points
		if(regular == true){
    		double angle = vertices.size() * 2 * M_PI / points;
    		tempPoint.x = size * cos(angle);
    		tempPoint.y = size * sin(angle);
		}//end if regular

		//initial point, no need to restrict
		else if(vertices.size() == 0){
			tempPoint.x = (rand() % size) - size/2;
			tempPoint.y = (rand() % size) - size/2;
		}//end else if vertecies empty

		//prevents duplicate points
		else{
			tempPoint.x = (rand() % size) - size/2;
			tempPoint.y = (rand() % size) - size/2;
			for(int i = 0; i < vertices.size(); i++){
				bool equal_x = false;
				bool equal_y = false;
					while(equal_x == true && equal_y == true){
						tempPoint.x = (rand() % size) - size/2;
						tempPoint.y = (rand() % size) - size/2;
					}
				}
			}//end else

    //align with origin
    tempPoint.x += origin.x;
    tempPoint.y += origin.y;

		vertices.push_back(tempPoint);
	}
	//only makes sense to make a shape with 3 points
	if(vertices.size() > 3){
		//create convex hull from given points
		vertices = makeConvexHull(vertices);
	}
	//display vertex results
	display();
}

void polygon::display(){
	for(int i = 0; i < vertices.size(); i++){
		std::cout<<'('<<vertices[i].x;
		std::cout<<','<<vertices[i].y;
		std::cout<<") ";
	}
	std::cout<<'\n';
	return;
}
