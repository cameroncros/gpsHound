/*
 * Sqlite.cpp
 *
 *  Created on: Dec 12, 2012
 *      Author: cameron
 */

#include "Sqlite.h"

#include <sqlite3.h>
#include <cstdlib>
#include <iostream>





Sqlite::Sqlite() {
	dbHandle = NULL;
	int out;
	sqlite3_config(SQLITE_CONFIG_URI, 1);
	std::string sqlString;
	std::string dbFile;
	dbFile = "file:";
	dbFile.append(getenv("HOME"));
	dbFile.append("/files.db");
	out = sqlite3_open_v2(dbFile.c_str(), &dbHandle, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE | SQLITE_OPEN_FULLMUTEX, NULL);
	if (out != SQLITE_OK || dbHandle == NULL) {
		std::cerr << "(" << __FILE__ << ":" << __LINE__ << ") " << out << dbFile.c_str() << " - " << sqlite3_errmsg(dbHandle) << std::endl;
	}
	initialiseDatabase();

	sqlString = "INSERT INTO gpsdata (time,latitude,longitude,altitude,heading) "
			"VALUES (?,?,?,?,?);";
	out = sqlite3_prepare_v2(dbHandle, sqlString.c_str(), sqlString.length(), &insert, NULL);
	if (out != SQLITE_OK) {
		std::cerr << "(" << __FILE__ << ":" << __LINE__ << ") " << out << " - " << sqlite3_errmsg(dbHandle) << std::endl;
	}
	sqlString = "SELECT * FROM gpsdata "
			"WHERE pkey IS ?;";
	out = sqlite3_prepare_v2(dbHandle, sqlString.c_str(), sqlString.length(), &query, NULL);
	if (out != SQLITE_OK) {
		std::cerr << "(" << __FILE__ << ":" << __LINE__ << ") " << out << " - " << sqlite3_errmsg(dbHandle) << std::endl;
	}
	// TODO Auto-generated constructor stub

}

Sqlite::~Sqlite() {
	sqlite3_finalize(insert);
	sqlite3_finalize(query);
	sqlite3_close(dbHandle);
	// TODO Auto-generated destructor stub
}

void Sqlite::initialiseDatabase() {
	if (sqlite3_exec(dbHandle, "CREATE TABLE IF NOT EXISTS gpsdata ("
			"pkey INTEGER PRIMARY KEY AUTOINCREMENT,"
			"altitude FLOAT NOT NULL,"
			"longitude FLOAT NOT NULL,"
			"latitude FLOAT NOT NULL,"
			"heading FLOAT NOT NULL,"
			"time INTEGER NOT NULL"
			")", NULL, 0, NULL ) ) {
		std::cerr << "(" << __FILE__ << ":" << __LINE__ << ") " << sqlite3_errmsg(dbHandle) << std::endl;
	}
}

void Sqlite::insertData(data* dt) {
	int out;

	sqlite3_bind_double (insert, 1, dt->time);
	sqlite3_bind_double (insert, 2, dt->latitude);
	sqlite3_bind_double (insert, 3, dt->longitude);
	sqlite3_bind_double (insert, 4, dt->altitude);
	sqlite3_bind_double (insert, 5, dt->heading);

	while ((out = sqlite3_step(insert)) != SQLITE_DONE) {
		if (out == SQLITE_ERROR) {
			std::cerr << "(" << __FILE__ << ":" << __LINE__ << ") "<< sqlite3_errmsg(dbHandle) << std::endl;
			throw std::exception();
		}
	}
	sqlite3_reset(insert);
}

data *Sqlite::getData(int index) {
	int out;
	data *dtr = NULL;
	sqlite3_bind_int (query, 1, index);
	while ((out = sqlite3_step(query)) != SQLITE_DONE) {
		if (out == SQLITE_ERROR) {
			std::cerr << "(" << __FILE__ << ":" << __LINE__ << ") "<< sqlite3_errmsg(dbHandle) << std::endl;
			throw std::exception();
		}
		if (out == SQLITE_ROW) {
			dtr = new data;
			dtr->time = sqlite3_column_double(query, 1);
			dtr->heading = 	sqlite3_column_double(query, 2);
			dtr->latitude = sqlite3_column_double(query, 3);
			dtr->longitude = sqlite3_column_double(query, 4);

		}
	}
	sqlite3_reset(query);
	return dtr;

}
