/*
- File name: ui.h
- Author: Le Nhat Nguyen
- Feature: header file for UI
- Created at: 09/7/24
- Updated at: 11/7/24
*/
#pragma once
#ifndef UI_H
#define	UI_H

const char* menuOptions[];

/* Displays the menu options to the user */
void displayMenu(int optionCount, const char* options[]);


/* Process user choice, call function has the corresponding function  */
void processMenuOption(int option);
#endif // !UI_H
