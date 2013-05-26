/*
 * Data.cpp
 *
 *  Created on: May 26, 2013
 *      Author: cameron
 */

#include "Data.h"
#include <libgpsmm.h>
#include <math.h>
#include <iostream>

Data::Data(double time, double altitude, double latitude, double longitude, double heading, double angle) {
	this->time=time;
	this->altitude=altitude;
	this->latitude=latitude;
	this->longitude=longitude;
	this->heading=heading;
	this->angle=angle;
}

Data::Data(const gps_data_t *dt, double angle) {
	this->heading = dt->attitude.heading;
	this->altitude = dt->fix.altitude;
	this->latitude = dt->fix.latitude;
	this->longitude = dt->fix.longitude;
	this->time = dt->fix.time;
	this->angle = angle;
}

bool Data::isLocked() {
	if (isnan(altitude) ||
			isnan(heading) ||
			isnan(latitude) ||
			isnan(longitude) ||
			isnan(time)) {
		return false;
	}
	return true;
}

void Data::print() {
	std::cout << heading
			<< " - " << altitude
			<< " - " << latitude
			<< " - " << longitude
			<< " - " << time
			<< std::endl;
}

double Data::getAltitude() const {
	return altitude;
}

void Data::setAltitude(double altitude) {
	this->altitude = altitude;
}

double Data::getAngle() const {
	return angle;
}

void Data::setAngle(double angle) {
	this->angle = angle;
}

double Data::getHeading() const {
	return heading;
}

void Data::setHeading(double heading) {
	this->heading = heading;
}

double Data::getLatitude() const {
	return latitude;
}

void Data::setLatitude(double latitude) {
	this->latitude = latitude;
}

double Data::getLongitude() const {
	return longitude;
}

void Data::setLongitude(double longitude) {
	this->longitude = longitude;
}

double Data::getTime() const {
	return time;
}



void Data::setTime(double time) {
	this->time = time;
}

Data::~Data() {
	// TODO Auto-generated destructor stub
}

