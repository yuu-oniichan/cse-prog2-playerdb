#include "database.h"
#include <ctype.h>

int main()
{
	Database db;
	Player jeremy, kobe, james, wade;

	strcpy_s(jeremy.name, "Jeremy");
	strcpy_s(kobe.name, "Kobe");
	strcpy_s(james.name, "James");
	strcpy_s(wade.name, "Wade");

	// ...
	Create(&db); // capacity = size = 0
	if (Add(&db, jeremy)) { printf("successful!"); } // use the return value of Add()
	else { printf("Insufficient memory!"); }
	Add(&db, kobe); // capacity = size = 2
	Add(&db, james); // capacity = size = 3
	Output(&db);
	Remove(&db, Search(&db, "Jeremy")); // 假設自 db 成功刪除 jeremy
	Output(&db); // 會列印兩筆資料，kobe 與 james; capacity = 3, size = 2
	Add(&db, jeremy); // 這次呼叫不會配置記憶體; capacity = size = 3
	Add(&db, wade); // 這次呼叫會配置記憶體; capacity = size = 4
	Close(&db); // capacity = size = 0
	return 0;
}