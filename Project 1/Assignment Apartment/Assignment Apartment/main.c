/*

************************************** Project Infomation ************************************

Project: Apartment resident information management

Introduction: Develop a C program to manage resident information in the apartment building

Author: Le Nhat Nguyen

Created at: 06/7/24

Updated at: 11/7/24

Language: C

***********************************************************************************************
*/

/*
- File name: main.c
- Author: Le Nhat Nguyen
- Feature: main file of project
- Created at: 06/7/24
- Updated at: 12/7/24
*/

/* Include the library and header file */
#include <stdio.h>
#include "ui.h"
#include "member.h"

int main() {
	const char* menuOptions[] = { // Declare the list of menu option
		"Show Member List",
		"Add Member",
		"Update Member",
		"Delete Member",
		"Find Member",
	};

	int menuSize = sizeof(menuOptions) / sizeof(menuOptions[0]); // Calculate menu size (to use in loop)

	int option; // The variable store the choice of user in menu

	while (1) {
		displayMenu(menuSize, menuOptions);
		if (scanf_s("%d", &option) != 1) {
			
			printf("Invalid input. Please enter a number.\n"); // Process if the input is not in menu option
			
			while (getchar() != '\n'); // Delete buffer to avoid infinity loop
			continue;
		}

		getchar(); // Remove character "Enter" of buffer
		
		// Exit the program if user choice is "0"
		if (option == 0) { 
			break;
		}
		// Process user choice
		processMenuOption(option);
		
	}
	
}