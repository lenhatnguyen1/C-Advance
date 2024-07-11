/*
File Infomation
- File name: member.c
- Author: Le Nhat Nguyen
- Feature: source file for member
- Created at: 06/7/24
- Updated at: 08/7/24
*/

#include "member.h"
#include <stdio.h>
#include <stdlib.h>

// Ví dụ: Hàm in thông tin Member
void printMember(const Member* member) {
    printf("UID: %s\n", member->uid);
    printf("Room Number: %s\n", member->roomNumber);
    printf("Name: %s\n", member->name);
    printf("License Plate: %s\n", member->licensePlate);
}

void showMember() {
	printf("Show Member\n");
}

void addMember() {
	printf("Add Member\n");
}

void updateMember() {
	printf("Update Member\n");
}

void deleteMember() {
	printf("Delete Member\n");
}

void findMember() {
	printf("Find Member\n");
}