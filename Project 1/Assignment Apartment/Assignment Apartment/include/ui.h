/*
- File name: ui.h
- Author: Le Nhat Nguyen
- Feature: header file for UI
- Created at: 2024.07.09
- Updated at: 2024.07.15
*/
#pragma once
#ifndef UI_H
#define UI_H

#ifndef _countof
#define _countof(array) (sizeof(array) / sizeof(array[0]))
#endif

/* Displays the menu options to the user */
void displayMenu(int optionCount, const char* options[]);

/* Process user choice, call function has the corresponding function */
void processUserOption(int option);

#endif // UI_H
