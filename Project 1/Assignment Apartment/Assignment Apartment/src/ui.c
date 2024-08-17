/*
* File name: ui.c
* Author: Le Nhat Nguyen
* Feature: source file for UI
* Created at: 2024.07.09
*/

#include <stdio.h>
#include <stdarg.h>
#include "../include/ui.h"
#include "../include/member.h"
#include "../include/constant.h"

void displayMenu(int iOptionCount, const char* cOptions[]) {
    printf("----------------------------------------------\n");
    printf("---------| RESIDENT MANAGEMENT |---------\n");
    printf("----------------------------------------------\n");
    for (int i = 1; i <= iOptionCount; i++) {
        printf("%d. %s\n", i, cOptions[i - 1]);
    }
    printf("0. Exit\n");
    printf("----------------------------------------------\n");
    printf("Choose 1 option\n");
}

void processUserOption(int iOption) {
    const char* filename = "ResidentData.csv";

    switch (iOption) {
    case 1:
        displayMemberList();
        break;

    case 2: {
        Member newMember;

        printf("Enter UID: ");
        if (scanf_s("%9s", newMember.uid, (unsigned)_COUNTOF(newMember.uid)) != 1) { // Limiting input length to prevent overflow
            printf("Invalid input for UID.\n");
            while (getchar() != '\n'); // Clear the input buffer
            break;
        }
        printf("Enter Room Number: ");
        if (scanf_s("%9s", newMember.roomNumber, (unsigned)_COUNTOF(newMember.roomNumber)) != 1) {
            printf("Invalid input for Room Number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            break;
        }
        printf("Enter Name: ");
        if (scanf_s("%49s", newMember.name, (unsigned)_COUNTOF(newMember.name)) != 1) {
            printf("Invalid input for Name.\n");
            while (getchar() != '\n'); // Clear the input buffer
            break;
        }
        printf("Enter License Plate: ");
        if (scanf_s("%19s", newMember.licensePlate, (unsigned)_COUNTOF(newMember.licensePlate)) != 1) {
            printf("Invalid input for License Plate.\n");
            while (getchar() != '\n'); // Clear the input buffer
            break;
        }

        addMember(FILE_NAME_DIRECTION, newMember);
        break;
    }

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
