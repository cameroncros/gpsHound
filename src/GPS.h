/*
 * GPS.h
 *
 *  Created on: May 18, 2013
 *      Author: cameron
 */

#ifndef GPS_H_
#define GPS_H_

#include <libgpsmm.h>



class GPS {
private:
	gpsmm *gps_rec;
	struct gps_data_t *gpsdata;
public:
	GPS();
	virtual ~GPS();
	const struct gps_data_t* getGpsdata() const;
};

#endif /* GPS_H_ */
