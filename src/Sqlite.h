/*
 * Sqlite.h
 *
 *  Created on: Dec 12, 2012
 *      Author: cameron
 */

#ifndef SQLITE_H_
#define SQLITE_H_

#include "Data.h"


class Share;

#include "sqlite3.h"
#include <cstdlib>

class Sqlite {
private:
	sqlite3 *dbHandle;
	sqlite3_stmt *insert;
	sqlite3_stmt *query;
public:
	Sqlite();
	virtual ~Sqlite();

	void insertData(Data *dt);
	Data *getData(int index);

	void initialiseDatabase();
};

#endif /* SQLITE_H_ */
