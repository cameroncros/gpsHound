/*
 * Main.cpp
 *
 *  Created on: May 18, 2013
 *      Author: cameron
 */

#include "Main.h"
#include "GPS.h"
#include "Sqlite.h"
#include "Data.h"
#include <iostream>


Main::Main() {
	Data *datum;
	gpsd = new GPS();
	db = new Sqlite();
	std::cout << "Wait for lock";
	for (;;) {
		datum = new Data(gpsd->getGpsdata(), 0);
		if (!datum->isLocked()) {
			std::cout << ".";
			continue;
		}
		datum->print();
		db->insertData(datum);
		delete(datum);
		datum=NULL;

	}
	// TODO Auto-generated constructor stub

}

Main::~Main() {
	delete(gpsd);
	delete(db);
	gpsd=NULL;
	db=NULL;
	// TODO Auto-generated destructor stub
}

int main(int argc, char **argv) {
	new Main();
}

