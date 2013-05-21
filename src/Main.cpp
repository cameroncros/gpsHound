/*
 * Main.cpp
 *
 *  Created on: May 18, 2013
 *      Author: cameron
 */

#include "Main.h"
#include "GPS.h"
#include <iostream>
#include <math.h>

Main::Main() {
	const gps_data_t *dt;
	data datastr;
	gpsd = new GPS();
	db = new Sqlite();
	while (true) {
		dt=gpsd->getGpsdata();
		if (isnan(dt->fix.altitude) ||
				isnan(dt->attitude.heading) ||
				isnan(dt->fix.latitude) ||
				isnan(dt->fix.longitude) ||
				isnan(dt->fix.time)) {
			continue;
		}
		std::cout << dt->attitude.heading
				<< ":" << dt->fix.altitude
				<< ":" << dt->fix.latitude
				<< ":" << dt->fix.longitude
				<< ":" << dt->fix.time
				<< std::endl;
		datastr.heading = dt->attitude.heading;
		datastr.altitude = dt->fix.altitude;
		datastr.latitude = dt->fix.latitude;
		datastr.longitude = dt->fix.longitude;
		datastr.time = dt->fix.time;
		db->insertData(&datastr);
	}
	// TODO Auto-generated constructor stub

}

Main::~Main() {
	delete(gpsd);
	delete(db);
	gpsd=NULL;
	// TODO Auto-generated destructor stub
}

int main(int argc, char **argv) {
	new Main();
}

