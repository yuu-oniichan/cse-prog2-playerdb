#include "database.h"
#include <ctype.h>

int main()
{
	Database db1, db2;
	Player jeremy, kobe, james;

	strcpy_s(jeremy.name, "Jeremy");
	strcpy_s(kobe.name, "Kobe");
	strcpy_s(james.name, "James");

	// ...
	Create(&db1);
	Create(&db2);
	Add(&db1, jeremy);
	Add(&db1, kobe);
	Add(&db2, james);
	Output(&db2); // 會列印 james 的資料
	if (Copy(&db2, &db1)) { printf("db1 is copied to db2 successfully.\n"); }
	else { printf("db1 is not copied to db2 due to memory shortage.\n"); }
	Add(&db1, james);
	Remove(&db1, Search(&db1, "Jeremy")); // 假設自 db1 成功刪除 jeremy
	Output(&db1); // 會列印兩筆資料，kobe 與 james
	Output(&db2); // 會列印兩筆資料，jeremy 與 kobe
	Close(&db1); Close(&db2);
	return 0;
}