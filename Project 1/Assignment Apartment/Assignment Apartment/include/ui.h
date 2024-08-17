/*
- File name: ui.h
- Author: Le Nhat Nguyen
- Feature: header file for UI
- Created at: 2024.07.09
*/
#pragma once
#ifndef UI_H
#define UI_H

#ifndef _COUNTOF
#define _COUNTOF(array) (sizeof(array) / sizeof(array[0]))
#endif

/* Displays the menu options to the user */
void displayMenu(int iOptionCount, const char* cOptions[]);

/* Process user choice, call function has the corresponding function */
void processUserOption(int iOption);

#endif // UI_H
