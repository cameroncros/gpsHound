/*
 * GPS.cpp
 *
 *  Created on: May 18, 2013
 *      Author: cameron
 */

#include "GPS.h"
#include <iostream>

#include <libgpsmm.h>

GPS::GPS() {
	gpsdata = NULL;
	gps_rec = new gpsmm("localhost", DEFAULT_GPSD_PORT);

	if (gps_rec->stream(WATCH_ENABLE|WATCH_JSON) == NULL) {
		std::cerr << "No GPSD running.\n";
	}
}

const struct gps_data_t* GPS::getGpsdata() const {
	while (!gps_rec->waiting(50000000));
	return gps_rec->read();
}

GPS::~GPS() {
	gps_stream(gpsdata, WATCH_DISABLE, NULL);
	gps_close(gpsdata);
}

