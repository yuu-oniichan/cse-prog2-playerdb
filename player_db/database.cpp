#include "database.h"

/** 
 * initialize a database object
 */
Database Create() {
	Database newdb;
	newdb.headcount = 0;
	return newdb;
}

/** 
 * add a Player into a Database.
 *
 * It returns 1 if a player is added successfully.
 * Otherwise, it returns 0
 *
 */
int Add(Database* data, Player person) {

	if (data != NULL) {
		data->dataheap.push_back(person);
		data->headcount++;
		return 1;
	} 
	else {
		return 0;
	}
}

/**
 * display all Players in a Database object
 *
 */
void Output(const Database* data) {
	
	fprintf(stdout, "There are %d records:\n\n", data->headcount);

	for (int i = 0; i < data->headcount; i++) {
		Output(data->dataheap[i]);
	}

	fprintf(stdout, "\n");
	system("pause");
}


/**  
 *  Search for a Player in the database db.
 *   
 *	@ It returns the index of the (first) Player with the searched name in the array.
 *	@ It returns -1 if there is no Player with the searched name.
 *
 */
int Search(const Database* db, const char* name) {
	if (db->headcount == 0) {
		return -1;
	}
	int cmp;

	for (int i = 0; i < db->headcount; i++) {
		cmp = strncmp(db->dataheap[i].name, name, 30);
		if (cmp == 0) {
			return i;
		}
	}
	return -1;
}


/**
 * remove a player with index ind from the database db.
 *  
 * @ returns 0 if ind is illegal
 * @ otherwise, it returns 1
 *
 */
int Remove(Database *db, int ind) {
	if (ind > db->headcount || ind < 0) {
		return 0;
	}

	db->dataheap.erase(db->dataheap.begin()+ind);
	db->headcount--;
	return 1;
}