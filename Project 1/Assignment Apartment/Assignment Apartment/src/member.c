/*
- File name: member.c
- Author: Le Nhat Nguyen
- Feature: source file for member
- Created at: 2024.07.06
- Updated at: 2024.07.15
*/

#include "../include/member.h"
#include "../include/constant.h"
#include <stdio.h>
#include <stdlib.h>  // Include for malloc and free
#include <string.h>  // Include if you need string operations

// Create a new MemberNode
MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    if (newNode == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

// Function to read and display member information from "ResidentData.csv"
void showMember() {
    FILE* file;
    errno_t err;

    // Open file for reading
    err = fopen_s(&file, FILE_NAME_DIRECTION, "r");
    if (err != 0) {
        perror("Error opening file");
        return;
    }

    char line[256]; // Buffer to hold each line read from the file

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // Initialize variables for strtok_s
        char* next_token;
        char* token = strtok_s(line, ",", &next_token);
        if (token == NULL) {
            // Handle empty line or other errors
            continue;
        }

        // Initialize a Member struct to store data
        Member member;

        // Copy data into member struct fields using strcpy_s
        strcpy_s(member.uid, sizeof(member.uid), token);

        token = strtok_s(NULL, ",", &next_token);
        if (token == NULL) {
            // Handle missing token or other errors
            continue;
        }
        strcpy_s(member.roomNumber, sizeof(member.roomNumber), token);

        token = strtok_s(NULL, ",", &next_token);
        if (token == NULL) {
            // Handle missing token or other errors
            continue;
        }
        strcpy_s(member.name, sizeof(member.name), token);

        token = strtok_s(NULL, ",", &next_token);
        if (token == NULL) {
            // Handle missing token or other errors
            continue;
        }
        strcpy_s(member.licensePlate, sizeof(member.licensePlate), token);

        // Print member data
        printf("UID: %s\n", member.uid);
        printf("Room Number: %s\n", member.roomNumber);
        printf("Name: %s\n", member.name);
        printf("License Plate: %s\n", member.licensePlate);
        printf("\n");
    }

    // Close the file
    fclose(file);
}

void addMember(const char* filename, Member member) {
    FILE* file = NULL;
    errno_t err = fopen_s(&file, filename, "a");
    if (err != 0 || file == NULL) {
        printf("Cannot open file\n");
        return;
    }
    fprintf(file, "%s,%s,%s,%s\n", member.uid, member.roomNumber, member.name, member.licensePlate);
    fclose(file);
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

void printMember(const Member* member) {
    printf("UID: %s\n", member->uid);
    printf("Room Number: %s\n", member->roomNumber);
    printf("Name: %s\n", member->name);
    printf("License Plate: %s\n", member->licensePlate);
}
