/*

************************************** Project Infomation ************************************

Project: Apartment resident information management

Author: Le Nhat Nguyen

Created at: 2024.07.06

Updated at: 2024.07.15

Language: C

***********************************************************************************************
*/

/*
- File name: main.c
- Author: Le Nhat Nguyen
- Feature: main file of project
- Created at: 06/7/24
- Updated at: 14/7/24
*/

/* Include the library and header file */
#include <stdio.h>
#include <stdlib.h>
#include "../include/ui.h"
#include "../include/member.h"
#include "../include/constant.h"

#ifndef _countof
#define _countof(array) (sizeof(array) / sizeof(array[0]))
#endif

int main() {
	// Declare the list of menu option
	const char* menuOptions[] = { 
		"Show Member List",
		"Add Member",
		"Update Member",
		"Delete Member",
		"Find Member",
	};

	// Calculate menu size (to use in loop)
	//int menuSize = sizeof(menuOptions) / sizeof(menuOptions[0]); 
	int menuSize = _countof(menuOptions);
	
	// The variable store the choice of user in menu
	int option;
	
	while (1) {
		displayMenu(menuSize, menuOptions);
		if (scanf_s("%d", &option) != 1) {
			
			printf("Invalid input. Please enter a number.\n"); // Process if the input is not in menu option
			
			while (getchar() != '\n'); // Delete buffer to avoid infinity loop
			continue;
		}
		
		// Exit the program if user choice is "0"
		if (option == 0) { 
			break;
		}   
		// Process user choice
		processUserOption(option);
		
	}
	
}