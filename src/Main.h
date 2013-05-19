/*
 * Main.h
 *
 *  Created on: May 18, 2013
 *      Author: cameron
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "GPS.h"

class Main {
private:
	class GPS *gpsd;
public:
	Main();
	virtual ~Main();
};

#endif /* MAIN_H_ */
