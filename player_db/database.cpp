#include "database.h"

/** 
 * initialize a database object
 */
Database Create() {
	Database newdb;
	newdb.size = 0;
	newdb.capacity = 0;
	newdb.dataheap = NULL;
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
	// check for db validity
	if (data == NULL) {
		fprintf(stderr, "Add DB ptr invalid error.\n");
		return 0;
	} 

	// if allocated already has space
	if (data->capacity > data->size) {
		data->dataheap[data->size + 1] = person;
	}
	// if need to create space
	else if (data->capacity == data->size) {
		Player *newdb = (Player *)malloc(sizeof(Player)*++(data->capacity));

		// check for allocation success
		if (newdb == NULL) {
			fprintf(stderr, "Add Out of Memory Error.\n");
			data->capacity--;
			return 0;
		}

		if (data->size) {
			for (int i = 0; i < data->size; i++) {
				newdb[i] = data->dataheap[i];
			}
			free(data->dataheap);
		}
		newdb[data->size] = person;
		data->dataheap = newdb;
	}	// unreachable unless error: size > capacity	else {		fprintf(stderr, "Add DB Bounds Critical Error.\n");		return 0;	}

	data->size++;
	return 1;
}

/**
 * display all Players in a Database object
 *
 */
void Output(const Database* data) {
	
	fprintf(stdout, "There are %d records:\n\n", data->size);

	for (int i = 0; i < data->size; i++) {
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
	if (db->size == 0) {
		return -1;
	}
	int cmp;

	for (int i = 0; i < db->size; i++) {
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
	if (ind > db->size || ind < 0) {
		return 0;
	}

	// chk if needs moving: skipped on size 1, and last element index
	if (db->size > 1 && ind != db->size-1) {
		for (int i = ind; i < db->size; i++) {
			db->dataheap[i] = db->dataheap[i + 1];
		}
	}
	db->size--;
	return 1;
}

int Copy(Database *newdb, const Database *olddb) {
	return 0;
}

void Close(Database *db) {
	free(db->dataheap);
	db->capacity = 0;
	db->size = 0;
}