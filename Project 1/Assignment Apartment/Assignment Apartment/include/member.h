/*
- File name: member.h
- Author: Le Nhat Nguyen
- Feature: header file for member
- Created at: 2024.07.06
- Updated at: 2024.07.15
*/

#pragma once
#ifndef MEMBER_H
#define MEMBER_H

typedef struct {
    char uid[20];          // UID of RFID
    char roomNumber[10];   // Room ID
    char name[50];         // Name
    char licensePlate[20]; // Plate
} Member;

typedef struct MemberNode {
    Member data;
    struct MemberNode* next;
} MemberNode;

// Create a new MemberNode
MemberNode* createMemberNode(Member member);

void showMember();
void addMember(const char* filename, Member member);
void updateMember();
void deleteMember();
void findMember();
void printMember(const Member* member);

#endif // MEMBER_H
