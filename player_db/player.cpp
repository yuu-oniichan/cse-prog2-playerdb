#include "player.h"

/**
  *	display a Player object
  */
void Output(Player target) {
	fprintf_s(stdout, "%s %d (%c) %.1f%% %.1f%% %.1f%%\n",  target.name, target.no, target.position, 
		target.percentages[0], target.percentages[1], target.percentages[2]);
}


/**
  *	input a Player object from the keyboard
  */
void Input(Player* target) {
	fprintf_s(stdout, "Please input the required values:\n\n");

	fprintf_s(stdout, "Name: ");
	fscanf_s(stdin, "%s", &target->name, 30);

	fprintf_s(stdout, "No: ");
	fscanf_s(stdin, "%d", &target->no, 1);
	fseek(stdin, 0, SEEK_END);

	fprintf_s(stdout, "Position: ");
	fscanf_s(stdin, " %c", &target->position, 1);

	fprintf_s(stdout, "3 Percentages (FG, 3P, and FT): ");
	fscanf_s(stdin, "%lf %lf %lf", &target->percentages[0], &target->percentages[1], &target->percentages[2]);
}