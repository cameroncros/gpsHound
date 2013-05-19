/*
 * Main.cpp
 *
 *  Created on: May 18, 2013
 *      Author: cameron
 */

#include "Main.h"
#include "GPS.h"
#include "iostream"

Main::Main() {
	const gps_data_t *data;
	gpsd = new GPS();
	while (true) {
		data=gpsd->getGpsdata();
		std::cout << data->attitude.heading
				<< ":" << data->fix.altitude
				<< ":" << data->fix.latitude
				<< ":" << data->fix.longitude
				<< ":" << data->fix.time
				<< std::endl;
	}
	// TODO Auto-generated constructor stub

}

Main::~Main() {
	delete(gpsd);
	gpsd=NULL;
	// TODO Auto-generated destructor stub
}

int main(int argc, char **argv) {
	new Main();
}

