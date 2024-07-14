/*
- File name: member.c
- Author: Le Nhat Nguyen
- Feature: source file for member
- Created at: 2024.07.06
- Updated at: 2024.07.15
*/

#include "../include/member.h"
#include <stdio.h>
#include <stdlib.h>

// Create a new MemberNode
MemberNode* createMemberNode(Member member) {
	MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
	newNode->data = member;
	newNode->next = NULL;
	return newNode;
}

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