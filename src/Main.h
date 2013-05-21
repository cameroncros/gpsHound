/*
 * Main.h
 *
 *  Created on: May 18, 2013
 *      Author: cameron
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "GPS.h"
#include "Sqlite.h"

class Main {
private:
	class GPS *gpsd;
	class Sqlite *db;
public:
	Main();
	virtual ~Main();
};

#endif /* MAIN_H_ */
