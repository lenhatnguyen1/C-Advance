/*
* File name: member.c
* Author: Le Nhat Nguyen
* Feature: source file for member action
* Created at: 2024.07.06
*/

#include "../include/member.h"
#include "../include/constant.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a new MemberNode
MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    if (newNode == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

// Append a new node to the linked list
void appendMemberNode(MemberNode** head, Member member) {
    MemberNode* newNode = createMemberNode(member);
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        MemberNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Read a member from a line of CSV
Member parseMemberFromLine(char* line) {
    Member member;
    char* next_token;
    char* token = strtok_s(line, ",", &next_token);

    if (token != NULL) strcpy_s(member.uid, sizeof(member.uid), token);
    token = strtok_s(NULL, ",", &next_token);
    if (token != NULL) strcpy_s(member.roomNumber, sizeof(member.roomNumber), token);
    token = strtok_s(NULL, ",", &next_token);
    if (token != NULL) strcpy_s(member.name, sizeof(member.name), token);
    token = strtok_s(NULL, ",", &next_token);
    if (token != NULL) strcpy_s(member.licensePlate, sizeof(member.licensePlate), token);

    return member;
}

// Function to read and display member information from "ResidentData.csv"
void displayMemberList() {
    FILE* file;
    errno_t err = fopen_s(&file, FILE_NAME_DIRECTION, "r");
    if (err != 0) {
        perror("Error opening file");
        return;
    }

    char line[256];
    MemberNode* head = NULL;

    printf("\n* Member List *\n\n");

    while (fgets(line, sizeof(line), file)) {
        Member member = parseMemberFromLine(line);
        appendMemberNode(&head, member);
    }
    fclose(file);

    MemberNode* current = head;
    while (current != NULL) {
        printMember(&current->data);
        current = current->next;
    }

    // Free the linked list
    while (head != NULL) {
        MemberNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// Add a new member to the file and display updated list
void addMember(const char* filename, Member member) {
    FILE* file = NULL;
    errno_t err = fopen_s(&file, filename, "a");
    if (err != 0 || file == NULL) {
        printf("Cannot open file\n");
        return;
    }
    fprintf(file, "%s,%s,%s,%s\n", member.uid, member.roomNumber, member.name, member.licensePlate);
    fclose(file);
    printf("New member added successfully!\n");
    displayMemberList();
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

// Print member details
void printMember(const Member* member) {
    printf("UID: %s\n", member->uid);
    printf("Room Number: %s\n", member->roomNumber);
    printf("Name: %s\n", member->name);
    printf("License Plate: %s\n", member->licensePlate);
}
