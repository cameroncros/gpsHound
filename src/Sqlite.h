/*
 * Sqlite.h
 *
 *  Created on: Dec 12, 2012
 *      Author: cameron
 */

#ifndef SQLITE_H_
#define SQLITE_H_



class Share;

#include "sqlite3.h"
#include <cstdlib>

typedef struct data {
	double time;
	double altitude;
	double latitude;
	double longitude;
	double heading;
};

class Sqlite {
private:
	sqlite3 *dbHandle;
	sqlite3_stmt *insert;
	sqlite3_stmt *query;
public:
	Sqlite();
	virtual ~Sqlite();

	void insertData(data *dt);
	data *getData(int index);

	void initialiseDatabase();
};

#endif /* SQLITE_H_ */
