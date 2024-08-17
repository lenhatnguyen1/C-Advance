/*
* File: UI.cpp
* Author: Le Nhat Nguyen
* Date: 16/08/2024
* Description: This is source file for user interface
*/

#include "../Header/UI.hpp"
#include "../Header/student.hpp"
#include <iostream>

using namespace std;


/*
* Function: displayHome
* Description: This function display the home screen and handle the user choice
* Input: manager (object)
* Output: None
*/
void UI::displayHome(StudentManager& manager) {
    int choice;
    do {
        cout << "Quan ly sinh vien" << endl;
        cout << "1. Them sinh vien" << endl;
        cout << "2. Sua thong tin sinh vien" << endl;
        cout << "3. Xoa sinh vien" << endl;
        cout << "4. Tim kiem sinh vien" << endl;
        cout << "5. Sap xep sinh vien" << endl;
        cout << "6. In ra danh sach sinh vien" << endl;
        cout << "0. Thoat" << endl;
        cout << "Vui long chon chuc nang: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.editStudent();
                break;
            case 3:
                manager.deleteStudent();
                break;
            case 4:
                manager.searchStudent();
                break;
            case 5:
                manager.sortStudents();
                break;
            case 6:
                manager.displayStudents();
                break;
            case 0:
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
        }
        cout << endl;
    } while (choice != 0);
}
