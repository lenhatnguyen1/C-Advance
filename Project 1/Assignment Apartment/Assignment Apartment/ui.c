/*
- File name: ui.c
- Author: Le Nhat Nguyen
- Feature: source file for UI
- Created at: 09/7/24
- Updated at: 11/7/24
*/
#include <stdio.h>
#include <stdarg.h>
#include "ui.h"

void displayMenu(int optionCount, const char* options[]) {
	printf("----------------------------------------------\n");
	printf("---------| RESIDENT MANAGER PROGRAM |---------\n");
	printf("----------------------------------------------\n");
	for (int i = 1; i <= optionCount; i++) {
		printf("%d. %s\n", i, options[i - 1]);
	}
	printf("0. Exit\n");
	printf("----------------------------------------------\n");
	printf("Choose 1 option\n");
}

void processMenuOption(int option) {
	switch (option) {
	case 1:
		showMember();
		break;
	case 2:
		addMember();
		break;
	case 3:
		updateMember();
		break;
	case 4:
		deleteMember();
		break;
	case 5:
		findMember();
		break;
	default:
		printf("Invalid option. Please try again.\n");
		break;
	}
}