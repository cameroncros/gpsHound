/*
 * Triangle.h
 *
 *  Created on: May 27, 2013
 *      Author: cameron
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Data.h"

class Triangle {
	class Data *first;
	class Data *second;
	class Data *third;
public:
	Triangle(Data *first, Data *second);
	virtual ~Triangle();
};

#endif /* TRIANGLE_H_ */
