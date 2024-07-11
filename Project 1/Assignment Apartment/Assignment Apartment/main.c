/*
				Project Infomation
Project: Apartment resident information management

Introduction: Develop a C program to manage resident information in the apartment building

Author: Le Nhat Nguyen

Features: 
- Add, delete, update member
- Find member by UID/license plate

Requirements:
- Project Work
- Available to extend

Created at: 06/7/24

Updated at: 08/7/24

Language: C
*/

/*
File Infomation
- File name: main.c
- Author: Le Nhat Nguyen
- Feature: main file of project
- Created at: 06/7/2024
- Updated at: 08/7/24
*/
#include <stdio.h>
#include "ui.h"
#include "member.h"

int main() {
	int option;
	while (1) {
		displayMenu();
		if (scanf_s("%d", &option) != 1) {
			// Xử lý lỗi khi nhập không đúng định dạng
			printf("Invalid input. Please enter a number.\n");
			// Xóa buffer để tránh vòng lặp vô hạn
			while (getchar() != '\n');
			continue;
		}
		getchar(); // Loại bỏ ký tự Enter khỏi buffer

		if (option == 0) {
			break;
		}
		else {
			switch (option) {
			case 1:
				showMember();
				break;
			case 2:
				addMember();
				break;
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
		
	}
	
}