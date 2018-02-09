#include "Geometry.h"
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include <ctime>
#include <iostream>
#include <cassert>
/** HELPER FUNCTIONS **/

/*
double distance(const Point &p1,const Point p2){
	return sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2));
}*/


/** LINE CLp1SS **/
line::line(double p1x, double p1y, double p2x, double p2y){
	this->p1.x = p1x;
	this->p1.y = p1y;
	this->p2.x = p2x;
	this->p2.y = p2y;
}
line::line(const Point &p1, const Point &p2){
	this->p1.x = p1.x;
	this->p1.y = p1.y;
	this->p2.x = p2.x;
	this->p2.y = p2.y;
}
void line::set(const Point &p1, const Point &p2){
	this->p1.x = p1.x;
	this->p1.y = p1.y;
	this->p2.x = p2.x;
	this->p2.y = p2.y;
}
void line::display(){
	std::cout<<p1.x<<','<<p1.y<<"--->"<<p2.x<<','<<p2.y;
}

double line::length(){
	return sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2));
}

double line::slope(){
return (p2.y - p1.y) / (double)(p2.x - p1.x);
}

double line::angle(){
return atan2(p1.y - p2.y, p1.x - p2.x)*180/M_PI;
}

/** POLYGON CLp1SS **/
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
	//std::cout<<"Generating Points For New Polygon\n";
  //srand(time(0));
	Point tempPoint;


	//create number of points in hull
	while(vertices.size() < points ){
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
	//if the shape generated has only 2 points after hull
	//just create a new shape.
	if(vertices.size() < 3){
		generatePoints(regular,points);
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
