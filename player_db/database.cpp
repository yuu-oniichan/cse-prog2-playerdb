#include "database.h"

/** 
 * initialize a database object
 */
void Create(Database *newdb) {
	newdb->size = 0;
	newdb->capacity = 0;
	newdb->dataheap = NULL;
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
		data->dataheap[data->size] = person;
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
	}
	// unreachable unless error: size > capacity
	else {
		fprintf(stderr, "Add DB Bounds Critical Error.\n");
		return 0;
	}

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

/**
* Make a copy of a Database.
* Assumes validity of both database initializations.
* 
* @ returns 1 if successful
* @ otherwise, it returns 0
*
*/
int Copy(Database *newdb, const Database *olddb) {
	// check if pointers are valid
	if (newdb == NULL || olddb == NULL) {
		fprintf(stderr, "Copy Param Error.\n");
		return 0;
	}

	// checks if space is sufficient
	if (newdb->capacity < olddb->size) {
		Player *newp = (Player *)malloc(sizeof(Player)*(olddb->size));

		// check for allocation success
		if (newp == NULL) {
			fprintf(stderr, "Copy Out of Memory Error.\n");
			return 0;
		}
		
		// check if need to free old memory
		if (newdb->capacity > 0) {
			free(newdb->dataheap);
		}

		// assigns memory, updates capacity
		newdb->dataheap = newp;
		newdb->capacity = olddb->size;
	}
	
	// if olddb is not empty, fill newdb
	if (olddb->size > 0) {
		for (int i = 0; i < olddb->size; i++) {
			newdb->dataheap[i] = olddb->dataheap[i];
		}
	}

	newdb->size = olddb->size;
	return 1;
}

void Close(Database *db) {
	free(db->dataheap);
	db->capacity = 0;
	db->size = 0;
}