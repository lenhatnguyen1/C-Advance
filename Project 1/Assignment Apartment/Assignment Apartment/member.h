/*
- File name: member.h
- Author: Le Nhat Nguyen
- Feature: header file for member
- Created at: 06/7/24
- Updated at: 08/7/24
*/

#pragma once
#ifndef MEMBER_H
#define	MEMBER_H
typedef struct {
	char uid[20]; // UID of RFID
	char roomNumber[10]; // Room ID
	char name[50]; // Name
	char licensePlate[20]; // Plate
} Member;

typedef struct MemberNode {
	Member data;
	struct MemberNode* next;
} MemberNode;

void showMember();

void addMember();

void updateMember();

void deleteMember();

void findMember();

#endif // !MEMBER_H
