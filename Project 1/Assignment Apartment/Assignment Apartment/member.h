/*
File Infomation
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
	char uid[20]; // UID của RFID
	char roomNumber[10]; // Số phòng
	char name[50]; // Tên
	char licensePlate[20]; // Biển Số Xe
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
