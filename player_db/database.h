#ifndef _DATABASE_H_
#define _DATABASE_H_

#include "player.h"
#include <vector>

using namespace std;

typedef struct {

	// the number of Player objects stored
	int headcount;

	// an array of Player objects
	vector<Player> dataheap;

} Database;

Database Create();
int Add(Database*, Player);
void Output(const Database*);
int Search(const Database *db, const char *name);
int Remove(Database *db, int ind);

#endif