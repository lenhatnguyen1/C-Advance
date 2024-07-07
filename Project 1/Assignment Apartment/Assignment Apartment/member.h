#pragma once
#ifndef MEMBER_H
#define	MEMBER_H
typedef struct {
	char uid[20]; // UID của RFID
	char roomNumber[10]; // Số phòng
	char name[50]; // Tên
	char licensePlate[20]; // Biển Số Xe
} Member;


#endif // !MEMBER_H
