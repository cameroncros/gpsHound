/*
 * Triangle.cpp
 *
 *  Created on: May 27, 2013
 *      Author: cameron
 */

#include "Triangle.h"

#define PI 3.14159265359

#include <math.h>

Triangle::Triangle(Data *first, Data *second) {
	double a,b,u,w,lat,lon,cordAngle,firstx,firsty,secondx,secondy;

	this->first = first;
	this->second = second;

	firstx = first->getLatitude();
	firsty = first->getLongitude();
	secondx = second->getLatitude();
	secondy = second->getLongitude();

	cordAngle = atan((firstx-secondx)/(firsty-secondy));
	u = sqrt((firstx-secondx)*(firstx-secondx) + (firsty-secondy)*(firsty-secondy));
	a=first->getAngle()-first->getHeading()+cordAngle;
	b=second->getAngle()-second->getHeading()+cordAngle;
	w = u*sin(a)/sin(PI-a-b);
	lat= secondx+w*sin(b-cordAngle);
	lon= secondy+w*cos(b-cordAngle);
	third = new Data(0,0,lat,lon,0,0);
}

Triangle::~Triangle() {
	delete(third);
}

