/*
 * Data.h
 *
 *  Created on: May 26, 2013
 *      Author: cameron
 */

#ifndef DATA_H_
#define DATA_H_

#include <libgpsmm.h>

class Data {
private:
	double time;
	double altitude;
	double latitude;
	double longitude;
	double heading;
	double angle;
public:
	Data(double time, double altitude, double latitude, double longitude, double heading, double angle);
	Data(const gps_data_t *dt, double angle);
	virtual ~Data();

	bool isLocked();
	void print();

	double getAltitude() const;
	void setAltitude(double altitude);
	double getAngle() const;
	void setAngle(double angle);
	double getHeading() const;
	void setHeading(double heading);
	double getLatitude() const;
	void setLatitude(double latitude);
	double getLongitude() const;
	void setLongitude(double longitude);
	double getTime() const;
	void setTime(double time);
};

#endif /* DATA_H_ */
