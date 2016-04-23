#ifndef _DATABASE_H_
#define _DATABASE_H_

#include "player.h"

typedef struct {

	// the number of Player objects stored
	int size;
	int capacity;

	// a pointer to an allocated memory location of Player objects
	Player *dataheap;

} Database;

Database Create();
int Add(Database*, Player);
void Output(const Database*);
int Search(const Database*, const char*);
int Remove(Database*, int ind);
int Copy(Database*, const Database*);
void Close(Database*);

#endif