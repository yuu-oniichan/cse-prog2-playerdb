#include "database.h"
#include <ctype.h>

int main() {
	char choice, temp_name[30];
	int looping = 1;
	int num = 0;
	Player temp;
	Database data;
	Create(&data);
	
	while(looping) {
		fprintf_s(stdout, "\nA simple player database\n\n" 
			"(1) Add a player\n" 
			"(2) Show all players\n" 
			"(3) Search player(s) by name\n" 
			"(4) Exit the program\n\n"
			"Please select a function...>");

		fscanf_s(stdin, " %c", &choice, 1);
		fseek(stdin, 0, SEEK_END);
		fprintf_s(stdout, "\n");
	
		switch(choice) {
			case('1'):
				Input(&temp);
				Add(&data, temp);
				break;
			case('2'):
				Output(&data);
				break;
			case('3'):
				fprintf(stdout, "Please input the name of the player...>");
				fscanf_s(stdin, " %s", &temp_name, 30);
				fprintf(stdout, "Searching for %s...\n", temp_name);
				num = Search(&data, temp_name);
				if (num == -1) {
					fprintf(stdout, "%s is not found.\n\n", temp_name);
					break;
				} else {
					Output(data.dataheap[num]);
					fprintf(stdout, "\nNext action(Remove/reInput/None)...>");
					fscanf_s(stdin, " %c", &choice, 1);
					choice = tolower(choice);
					fseek(stdin, 0, SEEK_END);
					switch(choice) {
						case('i'):
							Input(&temp);
							Add(&data, temp);
						case('r'):
							Remove(&data, num);
						case('n'):
							break;
						default:
							fprintf(stdout, "INVALID CHOICE.\n\n");
							break;
					}
				}
				break;
			case('4'):
				fprintf_s(stdout, "Thank you, goodbye!\n\n");
				looping = 0;
				break;
			default:
				fprintf(stdout, "INVALID CHOICE. PLEASE TRY AGAIN.\n\n");
		}
	}

	Close(&data);
	system("pause");
}